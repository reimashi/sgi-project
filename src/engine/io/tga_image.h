#pragma once
#include <string>

namespace Engine {
	namespace IO {
		class TGAImage
		{
		private:
			int width;
			int height;
			int16_t pixelSize;

			char *imageData;
			long imageSize = 0;

		public:
			TGAImage();
			~TGAImage();

			int getWidth() const;
			int getHeight() const;
			int16_t getPixelSize() const;
			char* getDataPtr() const;

			static TGAImage Load(std::string filename);
		};
	}
}
