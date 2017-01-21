#include "point3d.h"

namespace Engine {
	namespace Types {
		Point3D::Point3D(float_t x, float_t y, float_t z) : Point2D(x, y)
		{
			this->z = z;
		}

		Point3D::~Point3D()
		{
		}

		float_t Point3D::getZ() const {
			return this->z;
		}

		void Point3D::setZ(float_t z) {
			this->z = z;
		}

		Point3D Point3D::clone() const {
			return Point3D(this->getX(), this->getY(), this->getZ());
		}

		bool Point3D::operator==(const Point3D& rhs) const
		{
			return (this->x == rhs.getX())
				&& (this->y == rhs.getY())
				&& (this->z == rhs.getZ());
		}

		bool Point3D::operator!=(const Point3D& rhs) const
		{
			return !operator==(rhs);
		}

		float_t Point3D::distance(const Point3D& rhs) const
		{
			return abs(sqrtf(
				powf(rhs.x - this->x, 2) +
				powf(rhs.y - this->y, 2) +
				powf(rhs.z - this->z, 2)
			));
		}

		Point3D Point3D::operator-() const { return Point3D(-this->x, -this->y, -this->z); }
		Point3D Point3D::operator-(const Point3D& rhs) const { return Point3D(rhs.x - this->x, rhs.y - this->y, rhs.z - this->z); }
	}
}