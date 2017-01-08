#include "dimension3d.h"

namespace Engine {
	namespace Types {
		Dimension3D::Dimension3D(float_t width, float_t height, float_t depth) : Dimension2D(width, height)
		{
			this->depth = depth;
		}

		Dimension3D::~Dimension3D()
		{
		}

		float_t Dimension3D::getDepth() const {
			return this->depth;
		}

		void Dimension3D::setDepth(float_t depth) {
			this->depth = depth;
		}

		Dimension3D* Dimension3D::clone() const {
			return new Dimension3D(this->getWidth(), this->getHeight(), this->getDepth());
		}

		bool Dimension3D::operator==(const Dimension3D& rhs) const
		{
			return (this->height == rhs.getHeight())
				&& (this->width == rhs.getWidth())
				&& (this->depth == rhs.getDepth());
		}

		bool Dimension3D::operator!=(const Dimension3D& rhs) const
		{
			return !operator==(rhs);
		}
	}
}