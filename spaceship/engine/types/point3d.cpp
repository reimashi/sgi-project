#include "point3d.h"

namespace Engine {
	namespace Types {
		Point3D::Point3D(float x, float y, float z) : Point2D(x, y)
		{
			this->z = z;
		}

		Point3D::~Point3D()
		{
		}

		float Point3D::getZ() const {
			return this->z;
		}

		void Point3D::setZ(float z) {
			this->z = z;
		}
	}
}