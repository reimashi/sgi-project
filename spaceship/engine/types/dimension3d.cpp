#include "dimension3d.h"

namespace Engine {
	namespace Types {
		Dimension3D::Dimension3D(std::int32_t width, std::int32_t height, std::int32_t depth) : Dimension2D(width, height)
		{
			this->depth = depth;
		}

		Dimension3D::~Dimension3D()
		{
		}

		std::int32_t Dimension3D::getDepth() const {
			return this->depth;
		}

		void Dimension3D::setDepth(std::int32_t depth) {
			this->depth = depth;
		}
	}
}