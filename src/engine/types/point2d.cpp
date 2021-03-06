#include "point2d.h"

namespace Engine {
	namespace Types {
		Point2D::Point2D(float_t x, float_t y)
		{
			this->x = x;
			this->y = y;
		}

		Point2D::~Point2D()
		{
		}

		float_t Point2D::getX() const {
			return this->x;
		}

		void Point2D::setX(float_t x) {
			this->x = x;
		}

		float_t Point2D::getY() const {
			return this->y;
		}

		void Point2D::setY(float_t y) {
			this->y = y;
		}

		Point2D Point2D::clone() const {
			return Point2D(this->getX(), this->getY());
		}

		bool Point2D::operator==(const Point2D& rhs) const
		{
			return (this->x == rhs.getX())
				&& (this->y == rhs.getY());
		}

		bool Point2D::operator!=(const Point2D& rhs) const
		{
			return !operator==(rhs);
		}

		Point2D Point2D::operator-() const { return Point2D(-this->x, -this->y); }
		Point2D Point2D::operator-(const Point2D& rhs) const { return Point2D(rhs.x - this->x, rhs.y - this->y); }

		float_t Point2D::distance(const Point2D& rhs) const
		{
			return abs(sqrtf(
				powf(rhs.x - this->x, 2) +
				powf(rhs.y - this->y, 2)
			));
		}
	}
}