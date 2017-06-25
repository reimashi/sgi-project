#pragma once
#include <string>

namespace Engine {
	namespace IO {

		/**
		* \brief Clase que lee imagenes en formato TGA y los carga en memoria en formato bitmap.
		*/
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

			/**
			* \brief Obtiene el ancho de la imagen.
			* \return Ancho en pixeles.
			*/
			int getWidth() const;

			/**
			* \brief Obtiene el alto de la imagen.
			* \return Alto en pixeles.
			*/
			int getHeight() const;

			/**
			* \brief Obtiene el tamaño en memoria de un pixel.
			* \return Numero de bytes por pixel.
			*/
			int16_t getPixelSize() const;

			/**
			* \brief Obtiene los datos de imagen.
			* \return Puntero a memoria que guarda el bitmap.
			*/
			char* getDataPtr() const;

			/**
			* \brief Carga una imagen TGA en memoria desde un archivo.
			* \param filename Ruta del archivo.
			* \return Instancia en memoria de la imagen.
			*/
			static TGAImage Load(std::string filename);
		};
	}
}
