#pragma once

#include <cmath>
#include "point2d.h"

namespace Engine {
	namespace Types {
		/**
		* \brief Clase que representa un punto en un espacio de 3 dimensiones.
		*/
		class Point3D : public Point2D
		{
		protected:
			float_t z;

		public:
			Point3D(float_t x, float_t y, float_t z);
			~Point3D();

			float_t getZ() const;
			void setZ(float_t z);

			Point3D clone() const;

			bool operator==(const Point3D& rhs) const;
			bool operator!=(const Point3D& rhs) const;
			Point3D operator-() const;
			Point3D operator-(const Point3D& rhs) const;
			
			float_t Point3D::distance(const Point3D& rhs) const;
		};
	}
}