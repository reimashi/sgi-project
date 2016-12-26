#pragma once

#include <cstdint>

namespace Engine {
	namespace Types {
		class Dimension2D
		{
		protected:
			std::int32_t width;
			std::int32_t height;

		public:
			Dimension2D(std::int32_t width, std::int32_t height);
			~Dimension2D();

			std::int32_t getWidth() const;
			void setWidth(std::int32_t width);

			std::int32_t getHeight() const;
			void setHeight(std::int32_t x);

			Dimension2D* clone() const;
		};
	}
}