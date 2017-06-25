#pragma once
#include "../types/vector3d.h"
#include "./object3d.h"

namespace Engine {
	namespace Core {
		/**
		* \brief Objeto 3D con movimiento.
		*/
		class MovableObject3D : public Object3D
		{
		private:
			Types::Vector3D velocity;

			float_t friction = 1;

		public:
			MovableObject3D(Mesh geom, Material* mat);
			~MovableObject3D();

			/**
			* \brief Obtiene la velocidad del objeto.
			* \return Vector de velocidad.
			*/
			Types::Vector3D getVelocity() const;

			/**
			* \brief Establece la velocidad del objeto.
			* \param vel Vector de velocidad.
			*/
			void setVelocity(Types::Vector3D vel);

			/**
			* \brief Obtiene la fricción del objeto.
			* \return Valor de fricción. 1, sin fricción; 0, fricción extrema.
			*/
			float_t getFriction() const;

			/**
			* \brief Obtiene la fricción del objeto.
			* \param friz Valor de fricción. 1, sin fricción; 0, fricción extrema.
			*/
			void setFriction(const float_t friz);

		protected:
			/**
			* \brief Invoca internamente el dibujado del objeto.
			* \param inhibit_draw Inhibir el dibujado de este objeto. Actualiza su estado pero no lo dibuja.
			* \param elapsed Tiempo transcurrido desde el ultimo dibujado de la escena.
			*/
			virtual void internalDraw(bool inhibit_draw = false, double elapsed = 0) override;
		};
	}
}