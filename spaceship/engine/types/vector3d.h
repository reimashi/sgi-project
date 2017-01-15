#pragma once
#include "point3d.h"

namespace Engine {
	namespace Types {
		class Vector3D
		{
		protected:
			Point3D initial;
			Point3D terminal;

		public:
			Vector3D(Point3D init, Point3D term);
			~Vector3D();

			Point3D getInitialPoint() const;
			Point3D getTerminalPoint() const;
			float_t getMagnitude() const;

			Vector3D* clone() const;

			bool operator==(const Vector3D& rhs) const;
			bool operator!=(const Vector3D& rhs) const;
		};
	}
}
