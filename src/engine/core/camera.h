#pragma once
#include "scene_object.h"

namespace Engine {
	namespace Core {

		/**
		* \brief Objeto de escena que representa una camara de visualizacion. Una escena puede contener varias camaras pero usar solo una de cada vez.
		*/
		class Camera : public SceneObject
		{
		private:
			float_t farv = 500.0;
			int32_t mode = Camera::PERSPECTIVE;
			bool change = true;
			bool changePosition = true;
			Types::Point3D target;

		public:
			/**
			* \brief Perspectiva ortogonal.
			*/
			static const int32_t ORTHOGONAL = 1;
			/**
			* \brief Perspectiva isometrica.
			*/
			static const int32_t PERSPECTIVE = 2;

			Camera();
			~Camera();

			/**
			* \brief Establece la distancia de dibujado de la camara.
			* \param value Distancia de dibujado.
			*/
			void setFar(float_t value);

			/**
			* \brief Obtiene la distancia de dibujado de la camara.
			* \return Distancia de dibujado.
			*/
			float_t getFar() const;

			/**
			* \brief Establece el tipo de perspectiva para la visualización de la camara.
			* \param value Modo de visualización.
			*/
			void setMode(int32_t value);

			/**
			* \brief Establece el punto hacia donde mira la camara.
			* \param target Punto objetivo.
			*/
			void setTarget(Types::Point3D target);

			void draw() override;

			void rotate(float_t x, float_t y, float_t z) override;
			void translate(float_t x, float_t y, float_t z) override;
			void setPosition(Types::Point3D pos) override;
		};
	}
}
