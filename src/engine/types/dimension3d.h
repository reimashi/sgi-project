#pragma once

#include <cmath>
#include "dimension2d.h"

namespace Engine {
	namespace Types {
		class Dimension3D : Dimension2D
		{
		protected:
			std::float_t depth;

		public:
			Dimension3D(std::float_t width, std::float_t height, std::float_t depth);
			~Dimension3D();

			std::float_t getDepth() const;
			void setDepth(std::float_t depth);

			Dimension3D* clone() const;

			bool operator==(const Dimension3D& rhs) const;
			bool operator!=(const Dimension3D& rhs) const;
		};
	}
}