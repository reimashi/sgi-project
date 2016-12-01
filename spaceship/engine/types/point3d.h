#pragma once
#include "point2d.h"

namespace Engine {
	namespace Types {
		class Point3D : Point2D
		{
		protected:
			float z;

		public:
			Point3D(float x, float y, float z);
			~Point3D();

			float getZ() const;
			void setZ(float z);
		};
	}
}