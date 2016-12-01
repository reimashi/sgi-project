#include "point2d.h"

namespace Engine {
	namespace Types {
		Point2D::Point2D(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Point2D::~Point2D()
		{
		}

		float Point2D::getX() const {
			return this->x;
		}

		void Point2D::setX(float x) {
			this->x = x;
		}

		float Point2D::getY() const {
			return this->y;
		}

		void Point2D::setY(float y) {
			this->y = y;
		}
	}
}