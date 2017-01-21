#pragma once

#include <stdlib.h>
#include <gl/glut.h>
#include "../core/material.h"
#include "../io/tga_image.h"

namespace Engine {
	namespace Materials {
		class TGAMaterial : public Core::Material
		{
		private:
			GLuint texturePtr = 0;
			IO::TGAImage image;

		protected:
			void preDraw() override;
			void postDraw() override;

		public:
			TGAMaterial(IO::TGAImage img);
			~TGAMaterial();
		};

	}
}