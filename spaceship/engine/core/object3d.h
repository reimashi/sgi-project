#pragma once

#include <list>
#include <gl/glut.h>

#include "./mesh.h"
#include "./scene_object.h"
#include "../types/point3d.h"

namespace Engine {
	namespace Core {
		/// <summary>
		/// Clase que representa un objeto de 3 dimensiones.
		/// </summary>
		class Object3D : public SceneObject
		{
		public:
			Object3D(Mesh geom);
			~Object3D();

			void draw();

			void setVisibility(bool show);
			bool isVisible();

		private:
			Mesh geometry;

			GLuint glListPtr = 0;
			bool glCompiled = false;

			//void compile();
			bool visible;
		};
	}
}