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

		/**
		* \brief Clase que representa un objeto de 3 dimensiones.
		*/
		class Object3D : public SceneObject
		{
		public:
			Object3D(Mesh geom = Mesh(), Material* mat = nullptr);
			~Object3D();

			/**
			* \brief Obtiene el radio de colision del objeto. (Sistema basico de colisiones basado en el radio)
			* \return Radio de colision.
			*/
			float_t getCollisionRadius() const;

			/**
			* \brief Establece el radio de colision del objeto. (Sistema basico de colisiones basado en el radio)
			* \param radius Radio de colision.
			*/
			void setCollisionRadius(const float_t radius);

		protected:
			Mesh geometry;
			Material* material;

			float_t collisionRadius = 0;

			void internalDraw(bool inhibit_draw = false, double elapsed = 0) override;
			virtual void draw() override;
		};
	}
}
