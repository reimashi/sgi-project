#include "color_material.h"

#include <gl/glut.h>
#include <iostream>

namespace Engine {
	namespace Materials {
		ColorMaterial::ColorMaterial(float_t r, float_t g, float_t b)
		{
			this->red = r;
			this->green = g;
			this->red = b;
		}

		ColorMaterial::~ColorMaterial()
		{
		}

		void ColorMaterial::preDraw()
		{
			glColor3f(this->red, this->green, this->blue);
		}

		void ColorMaterial::postDraw()
		{
			glColor3f(0, 0, 0);
		}

		// Colores predefinidos
		ColorMaterial ColorMaterial::White() { return ColorMaterial(1,1,1); }
		ColorMaterial ColorMaterial::Blue() { return ColorMaterial(0,0,1); }
		ColorMaterial ColorMaterial::Red() { return ColorMaterial(1,0,0); }
		ColorMaterial ColorMaterial::Green() { return ColorMaterial(0,1,0); }
		ColorMaterial ColorMaterial::Black() { return ColorMaterial(0,0,0); }
	}
}
