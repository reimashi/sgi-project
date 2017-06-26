#include "tga_image.h"
#include "../utils/logger.h"
#include <fstream>
#include <iostream>

namespace Engine {
	namespace IO {
		TGAImage::TGAImage() : width(0), height(0), pixelSize(1), imageData(nullptr)
		{
		}


		TGAImage::~TGAImage()
		{
		}

		int TGAImage::getWidth() const { return this->width; }
		int TGAImage::getHeight() const { return this->height; }
		int16_t TGAImage::getPixelSize() const { return this->pixelSize; }
		char* TGAImage::getDataPtr() const { return this->imageData; }

		TGAImage TGAImage::Load(std::string filename)
		{
			Utils::Logger* logger = Utils::Logger::getLogger(__FUNCTION__);
			TGAImage image;

			std::ifstream fileStream(filename, std::ios::in | std::ios::binary);

			char buffer[4];

			if (fileStream.is_open())
			{
				// Se ignora el ID de fichero
				fileStream.ignore(2);

				// Se lee el tipo de archivo
				char fileType = 0;
				fileStream.read(buffer, 1);
				fileType = buffer[0];

				// Solo se cogen los formatos no comprimidos
				if (fileType == 2 || fileType == 3)
				{
					// Se ignoran cabeceras que no necesitamos
					fileStream.ignore(9);

					// Leemos anchura
					fileStream.read(buffer, 2);
					short tmpshconv = *((short*)buffer);
					image.width = tmpshconv;
					fileStream.read(buffer, 2);
					tmpshconv = *((short*)buffer);
					image.height = tmpshconv;

					// Leemos profundidad de bit
					char bitDepth;
					fileStream.read(buffer, 2);
					bitDepth = buffer[0];

					// Determinamos el tamaño del color
					image.pixelSize = bitDepth / 8;
					image.imageSize = image.width * image.height * image.pixelSize;

					// Creamos el vector que guardará los datos
					image.imageData = new char[image.imageSize];

					// Read the image data.
					fileStream.read(image.imageData, image.imageSize);

					// Se cambia el orden de los colores de BGR a RGB
					char colorSwap;
					for (int i = 0; i < image.imageSize; i += image.pixelSize)
					{
						colorSwap = image.imageData[i];
						image.imageData[i] = image.imageData[i + 2];
						image.imageData[i + 2] = colorSwap;
					}
				}
				else std::cout << "Format error. Filetype: " << (int)fileType << std::endl;

				fileStream.close();
			}
			else logger->error("Unable to open file");

			return image;
		}
	}
}
