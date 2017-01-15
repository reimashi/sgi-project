#pragma once

#include <list>
#include <gl/glut.h>

#include "./geometry.h"
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
			Object3D(Geometry geom);
			~Object3D();

			void draw();

			void setVisibility(bool show);
			bool isVisible();

		private:
			Geometry geometry;

			GLuint glListPtr = 0;
			bool glCompiled = false;

			//void compile();
			bool visible;
		};
	}
}