#pragma once
#include <iostream>
#include "point3d.h"

namespace Engine {
	namespace Types {
		/**
		* \brief Clase que representa un vector (dirección y magnitud) en un espacio de 3 dimensiones.
		*/
		class Vector3D
		{
		protected:
			Point3D point;

		public:
			Vector3D(Point3D p);
			Vector3D(float_t x, float_t y, float_t z);
			~Vector3D();

			Point3D getPoint() const;
			float_t getMagnitude() const;

			Vector3D clone() const;

			float_t angle(const Vector3D& rhs) const;

			bool operator==(const Vector3D& rhs) const;
			bool operator!=(const Vector3D& rhs) const;
			Vector3D operator-() const;
			Vector3D operator-(const Vector3D& rhs) const;
			Vector3D operator+(const Vector3D& rhs) const;

			Vector3D operator/(const float_t value) const;
			Vector3D operator*(const float_t value) const;
			Vector3D operator*(const Vector3D& rhs) const;

			friend std::ostream& operator<< (std::ostream& stream, const Vector3D& vector);

			static Vector3D flipOverX(const Vector3D* in);
			static Vector3D flipOverY(const Vector3D* in);
			static Vector3D flipOverZ(const Vector3D* in);

			static Vector3D getNull();
			static Vector3D xAxis();
			static Vector3D yAxis();
			static Vector3D zAxis();
		};
	}
}
