#pragma once

#include "../core/material.h"
#include <cmath>

namespace Engine {
	namespace Materials {
		/**
		* \brief Material de tipo color solido
		*/
		class ColorMaterial : public Core::Material
		{
		protected:
			float_t red; 
			float_t green; 
			float_t blue;

			void preDraw() override;
			void postDraw() override;

		public:
			ColorMaterial(float_t r, float_t g, float_t b);
			~ColorMaterial();

			static ColorMaterial White();
			static ColorMaterial Blue();
			static ColorMaterial Red();
			static ColorMaterial Green();
			static ColorMaterial Black();
		};
	}
}
