#include "vector3d.h"
#include <cmath>

namespace Engine {
	namespace Types {
		Vector3D::Vector3D(Point3D p) : point(p)
		{
		}

		Vector3D::~Vector3D()
		{
		}

		Point3D Vector3D::getPoint() const { return *(this->point.clone()); }

		float_t Vector3D::getMagnitude() const
		{
			return sqrtf(powf(this->point.getX(), 2) + powf(this->point.getY(), 2) + powf(this->point.getZ(), 2));
		}

		Vector3D* Vector3D::clone() const
		{
			return new Vector3D(*(this->point.clone()));
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

		float_t Vector3D::angle(const Vector3D& rhs) const
		{
			Point3D rhsp = rhs.getPoint();
			float_t ep = this->point.getX() * rhsp.getX() +
				this->point.getY() * rhsp.getY() +
				this->point.getZ() * rhsp.getZ();
			return acosf(ep/(this->getMagnitude() + rhs.getMagnitude()));
		}

		Vector3D Vector3D::getNull() { return Vector3D(Point3D(0,0,0)); }
		Vector3D Vector3D::xAxis() { return Vector3D(Point3D(1, 0, 0)); }
		Vector3D Vector3D::yAxis() { return Vector3D(Point3D(0, 1, 0)); }
		Vector3D Vector3D::zAxis() { return Vector3D(Point3D(0, 0, 1)); }
	}
}