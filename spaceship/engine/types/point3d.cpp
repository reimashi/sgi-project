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
	}
}