#include "tga_material.h"
#include <iostream>

namespace Engine {
	namespace Materials {
		TGAMaterial::TGAMaterial(IO::TGAImage img) : image(img)
		{
			glGenTextures(1, &this->texturePtr);
			glBindTexture(GL_TEXTURE_2D, this->texturePtr);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glTexImage2D(GL_TEXTURE_2D, 0, image.getPixelSize(), image.getWidth(), image.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.getDataPtr());

			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}


		TGAMaterial::~TGAMaterial()
		{
		}

		void TGAMaterial::preDraw()
		{
			std::cout << "Deberia dibujar una textura" << std::endl;
			glColor3f(1, 1, 1);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, this->texturePtr);
		}

		void TGAMaterial::postDraw()
		{
			glDisable(GL_TEXTURE_2D);
		}
	}
}
