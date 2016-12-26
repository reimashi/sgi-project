#pragma once

#include <vector>
#include <gl/glut.h>

#include "../types/point3d.h"

namespace Engine {
	namespace Core {
		class SceneObject
		{
		public:
			SceneObject();
			~SceneObject();

			void draw();
		private:
			std::vector <Types::Point3D> vertex;

			GLuint glListPtr = 0;
			bool glCompiled = false;

			void compile();
		};
	}
}