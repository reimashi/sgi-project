#pragma once

#include <cmath>

namespace Engine {
	namespace Types {
		class Dimension2D
		{
		protected:
			std::float_t width;
			std::float_t height;

		public:
			Dimension2D(std::float_t width, std::float_t height);
			~Dimension2D();

			std::float_t getWidth() const;
			void setWidth(std::float_t width);

			std::float_t getHeight() const;
			void setHeight(std::float_t x);

			Dimension2D* clone() const;
		};
	}
}