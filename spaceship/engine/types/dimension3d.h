#pragma once

#include "dimension2d.h"

namespace Engine {
	namespace Types {
		class Dimension3D : Dimension2D
		{
		protected:
			std::int32_t depth;

		public:
			Dimension3D(std::int32_t width, std::int32_t height, std::int32_t depth);
			~Dimension3D();

			std::int32_t getDepth() const;
			void setDepth(std::int32_t depth);

			Dimension3D* clone() const;
		};
	}
}