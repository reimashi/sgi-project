#pragma once
#include "../core/mesh.h"
#include <string>

namespace Engine {
	namespace Utils {
		class OBJLoader
		{
		public:
			OBJLoader();
			~OBJLoader();

			static Core::Mesh Load(std::string path);
		};
	}
}