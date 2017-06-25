#pragma once
#include "../core/mesh.h"
#include <string>

namespace Engine {
	namespace Utils {
		/**
		* \brief Clase para manejar archivos OBJ
		*/
		class OBJLoader
		{
		public:
			OBJLoader();
			~OBJLoader();

			/**
			* \brief Carga un archivo de formato OBJ y crea un Mesh a partir de el.
			* \param path Ruta del archivo.
			* \brief Mesh con la forma geometrica del objeto contenido en el archivo.
			*/
			static Core::Mesh Load(std::string path);
		};
	}
}