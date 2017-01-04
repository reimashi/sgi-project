#include "dimension2d.h"

namespace Engine {
	namespace Types {
		Dimension2D::Dimension2D(float_t width, float_t height)
		{
			this->width = width;
			this->height = height;
		}

		Dimension2D::~Dimension2D()
		{
		}

		float_t Dimension2D::getWidth() const {
			return this->width;
		}

		void Dimension2D::setWidth(float_t width) {
			this->width = width;
		}

		float_t Dimension2D::getHeight() const {
			return this->height;
		}

		void Dimension2D::setHeight(float_t height) {
			this->height = height;
		}

		Dimension2D* Dimension2D::clone() const {
			return new Dimension2D(this->getWidth(), this->getHeight());
		}
	}
}