#include "vector3d.h"
#include <cmath>

namespace Engine {
	namespace Types {
		Vector3D::Vector3D(Point3D p) : point(p)
		{
		}

		Vector3D::Vector3D(float_t x, float_t y, float_t z) : Vector3D(Point3D(x, y, z))
		{
		}

		Vector3D::~Vector3D()
		{
		}

		Point3D Vector3D::getPoint() const { return this->point.clone(); }

		float_t Vector3D::getMagnitude() const
		{
			return sqrtf(powf(this->point.getX(), 2) + powf(this->point.getY(), 2) + powf(this->point.getZ(), 2));
		}

		Vector3D Vector3D::clone() const
		{
			return Vector3D(this->point.clone());
		}

		bool Vector3D::operator==(const Vector3D& rhs) const {
			return (this->point == rhs.getPoint());
		}

		bool Vector3D::operator!=(const Vector3D& rhs) const {
			return !operator==(rhs);
		}

		Vector3D Vector3D::operator-() const {
			return Vector3D(Point3D(-this->point.getX(), -this->point.getY(), -this->point.getZ()));
		}

		Vector3D Vector3D::operator-(const Vector3D& rhs) const {
			return Vector3D(Point3D(this->point.getX() - rhs.getPoint().getX(), this->point.getY() - rhs.getPoint().getY(), this->point.getZ() - rhs.getPoint().getZ()));
		}

		Vector3D Vector3D::operator+(const Vector3D& rhs) const {
			return Vector3D(Point3D(this->point.getX() + rhs.getPoint().getX(), this->point.getY() + rhs.getPoint().getY(), this->point.getZ() + rhs.getPoint().getZ()));
		}

		Vector3D Vector3D::operator/(const float_t value) const {
			return Vector3D(Point3D(this->point.getX() / value, this->point.getY() / value, this->point.getZ() / value));
		}

		Vector3D Vector3D::operator*(const float_t value) const {
			return Vector3D(Point3D(this->point.getX() * value, this->point.getY() * value, this->point.getZ() * value));
		}

		Vector3D Vector3D::operator*(const Vector3D& rhs) const {
			return Vector3D(Point3D(
				this->point.getY() * rhs.getPoint().getZ() - this->point.getZ() * rhs.getPoint().getY(),
				this->point.getZ() * rhs.getPoint().getX() - this->point.getX() * rhs.getPoint().getZ(),
				this->point.getX() * rhs.getPoint().getY() - this->point.getY() * rhs.getPoint().getX()));
		}

		float_t Vector3D::angle(const Vector3D& rhs) const
		{
			Point3D rhsp = rhs.getPoint();
			float_t ep = this->point.getX() * rhsp.getX() +
				this->point.getY() * rhsp.getY() +
				this->point.getZ() * rhsp.getZ();
			return acosf(ep/(this->getMagnitude() + rhs.getMagnitude()));
		}

		Vector3D Vector3D::flipOverX(const Vector3D* in) { return Vector3D(Point3D(-in->getPoint().getX(), in->getPoint().getY(), in->getPoint().getZ())); }
		Vector3D Vector3D::flipOverY(const Vector3D* in) { return Vector3D(Point3D(in->getPoint().getX(), -in->getPoint().getY(), in->getPoint().getZ())); }
		Vector3D Vector3D::flipOverZ(const Vector3D* in) { return Vector3D(Point3D(in->getPoint().getX(), in->getPoint().getY(), -in->getPoint().getZ())); }

		Vector3D Vector3D::getNull() { return Vector3D(Point3D(0,0,0)); }
		Vector3D Vector3D::xAxis() { return Vector3D(Point3D(1, 0, 0)); }
		Vector3D Vector3D::yAxis() { return Vector3D(Point3D(0, 1, 0)); }
		Vector3D Vector3D::zAxis() { return Vector3D(Point3D(0, 0, 1)); }

		std::ostream& operator<< (std::ostream& stream, const Vector3D& vector) {
			stream << "(Vector3D x:" << vector.getPoint().getX() << " y:" << vector.getPoint().getY() << " z:" << vector.getPoint().getZ() << ")";
			return stream;
		}
	}
}