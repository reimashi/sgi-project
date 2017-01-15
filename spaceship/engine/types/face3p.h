#pragma once
#include "point3d.h"
#include "vector3d.h"

namespace Engine {
	namespace Types {
		class Face3P
		{
		protected:
			Point3D pointA;
			Point3D pointB;
			Point3D pointC;
			Vector3D normal;

		public:
			Face3P(Point3D a, Point3D b, Point3D c, Vector3D v);
			~Face3P();

			Point3D getPointA() const;
			Point3D getPointB() const;
			Point3D getPointC() const;
			Vector3D getNormal() const;

			Face3P* clone() const;

			bool operator==(const Face3P& rhs) const;
			bool operator!=(const Face3P& rhs) const;
		};
	}
}