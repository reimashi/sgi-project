#pragma once

#include <cmath>

namespace Engine {
	namespace Types {
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

			Point2D* clone() const;

			bool operator==(const Point2D& rhs) const;
			bool operator!=(const Point2D& rhs) const;
		};
	}
}