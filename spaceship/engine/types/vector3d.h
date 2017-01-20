#pragma once
#include "point3d.h"

namespace Engine {
	namespace Types {
		class Vector3D
		{
		protected:
			Point3D point;

		public:
			Vector3D(Point3D p);
			~Vector3D();

			Point3D getPoint() const;
			float_t getMagnitude() const;

			Vector3D* clone() const;

			float_t angle(const Vector3D& rhs) const;

			bool operator==(const Vector3D& rhs) const;
			bool operator!=(const Vector3D& rhs) const;
			Vector3D operator-() const;
			Vector3D operator-(const Vector3D& rhs) const;

			static Vector3D getNull();
			static Vector3D xAxis();
			static Vector3D yAxis();
			static Vector3D zAxis();
		};
	}
}
