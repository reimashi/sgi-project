#pragma once
#include "point2d.h"

namespace Engine {
	namespace Types {
		/**
		* \brief Clase que representa un vector (direcci�n y magnitud) en un espacio de 2 dimensiones.
		*/
		class Vector2D
		{
		protected:
			Point2D point;

		public:
			Vector2D(Point2D p);
			Vector2D(float_t x, float_t y);
			~Vector2D();

			Point2D getPoint() const;
			float_t getMagnitude() const;

			Vector2D clone() const;

			float_t angle(const Vector2D& rhs) const;
			float_t dot(const Vector2D& rhs) const;

			bool operator==(const Vector2D& rhs) const;
			bool operator!=(const Vector2D& rhs) const;
			Vector2D operator-() const;
			Vector2D operator-(const Vector2D& rhs) const;
			Vector2D operator+(const Vector2D& rhs) const;
			Vector2D operator/(const float_t value) const;
			Vector2D operator*(const float_t value) const;

			static Vector2D flipOverX(const Vector2D* in);
			static Vector2D flipOverY(const Vector2D* in);

			static Vector2D getNull();
			static Vector2D xAxis();
			static Vector2D yAxis();
		};
	}
}
