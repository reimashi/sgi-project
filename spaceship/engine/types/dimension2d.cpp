#include "dimension2d.h"

namespace Engine {
	namespace Types {
		Dimension2D::Dimension2D(std::int32_t width, std::int32_t height)
		{
			this->width = width;
			this->height = height;
		}

		Dimension2D::~Dimension2D()
		{
		}

		std::int32_t Dimension2D::getWidth() const {
			return this->width;
		}

		void Dimension2D::setWidth(std::int32_t width) {
			this->width = width;
		}

		std::int32_t Dimension2D::getHeight() const {
			return this->height;
		}

		void Dimension2D::setHeight(std::int32_t height) {
			this->height = height;
		}
	}
}