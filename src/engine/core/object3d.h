#pragma once

#include <list>
#include <stdlib.h>
#include <gl/glut.h>

#include "./mesh.h"
#include "./scene_object.h"
#include "../types/point3d.h"
#include "../materials/color_material.h"

namespace Engine {
	namespace Core {
		class Material;

		/// <summary>
		/// Clase que representa un objeto de 3 dimensiones.
		/// </summary>
		class Object3D : public SceneObject
		{
		public:
			Object3D(Mesh geom = Mesh(), Material* mat = nullptr);
			~Object3D();

		protected:
			Mesh geometry;
			Material* material;

			void internalDraw(bool inhibit_draw = false) override;
			virtual void draw() override;
		};
	}
}
