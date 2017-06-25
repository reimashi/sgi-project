#pragma once

#include <cmath>

namespace Engine {
	namespace Types {
		/**
		* \brief Clase que representa un punto en un espacio de 2 dimensiones.
		*/
		class Point2D
		{
		protected:
			float_t x;
			float_t y;

		public:
			Point2D(float_t x, float_t y);
			~Point2D();

			float_t getX() const;
			void setX(float_t x);

			float_t getY() const;
			void setY(float_t x);

			Point2D clone() const;

			bool operator==(const Point2D& rhs) const;
			bool operator!=(const Point2D& rhs) const;
			Point2D operator-() const;
			Point2D operator-(const Point2D& rhs) const;

			float_t Point2D::distance(const Point2D& rhs) const;
		};
	}
}