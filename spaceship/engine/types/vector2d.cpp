#include "vector2d.h"
#include <cmath>

namespace Engine {
	namespace Types {
		Vector2D::Vector2D(Point2D p) : point(p)
		{
		}

		Vector2D::Vector2D(float_t x, float_t y) : Vector2D(Point2D(x, y))
		{
		}

		Vector2D::~Vector2D()
		{
		}

		Point2D Vector2D::getPoint() const { return *(this->point.clone()); }

		float_t Vector2D::getMagnitude() const
		{
			return sqrtf(powf(this->point.getX(), 2) + powf(this->point.getY(), 2));
		}

		Vector2D* Vector2D::clone() const
		{
			return new Vector2D(*(this->point.clone()));
		}

		bool Vector2D::operator==(const Vector2D& rhs) const {
			return (this->point == rhs.getPoint());
		}

		bool Vector2D::operator!=(const Vector2D& rhs) const {
			return !operator==(rhs);
		}

		Vector2D Vector2D::operator-() const {
			return Vector2D(Point2D(-this->point.getX(), -this->point.getY()));
		}

		Vector2D Vector2D::operator-(const Vector2D& rhs) const {
			return Vector2D(Point2D(this->point.getX() - rhs.getPoint().getX(), this->point.getY() - rhs.getPoint().getY()));
		}

		float_t Vector2D::angle(const Vector2D& rhs) const
		{
			Point2D rhsp = rhs.getPoint();
			float_t ep = this->point.getX() * rhsp.getX() +
				this->point.getY() * rhsp.getY();
			return acosf(ep/(this->getMagnitude() + rhs.getMagnitude()));
		}

		Vector2D Vector2D::getNull() { return Vector2D(Point2D(0, 0)); }
		Vector2D Vector2D::xAxis() { return Vector2D(Point2D(1, 0)); }
		Vector2D Vector2D::yAxis() { return Vector2D(Point2D(0, 1)); }
	}
}