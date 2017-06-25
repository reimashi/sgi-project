#pragma once

#include <list>
#include <stdlib.h>
#include "../types/point3d.h"
#include "../utils/logger.h"
#include <GL/glut.h>

namespace Engine {
	namespace Core {
		/**
		 * \brief Representa cualquier elemento u objeto contenido en la escena.
		 */
		class SceneObject {
			friend class Engine;

		private:
			static Utils::Logger* logger;

		protected:
			/**
			 * \brief El objeto es visible
			 */
			bool visible;

			/**
			 * \brief Objetos hijos
			 */
			std::list<SceneObject*> childs;

			/**
			 * \brief Puntero al objeto padre, si existe
			 */
			SceneObject* parent = nullptr;

			/**
			 * \brief Rotaci�n del objeto con respecto a su padre
			 */
			Types::Point3D rotation;

			/**
			* \brief Posici�n del objeto con respecto a su padre
			*/
			Types::Point3D position;

			/**
			* \brief Escala del objeto
			*/
			float_t scaleFactor = 1;

			/**
			* \brief Establece si el objeto necesita ser recompilado en la proxima renderizacion
			*/
			bool recompile = true;

			/**
			* \brief Puntero a objeto compilado OpenGL
			*/
			GLuint openglPtr = 0;

			/**
			 * \brief Establece el objeto padre de este objeto.
			 * \param parent Instancia del objeto hijo.
			 */
			void setParent(SceneObject* parent);

			/**
			 * \brief Invoca internamente el dibujado del objeto.
			 * \param inhibit_draw Inhibir el dibujado de este objeto. Actualiza su estado pero no lo dibuja.
			 * \param elapsed Tiempo transcurrido desde el ultimo dibujado de la escena.
			 */
			virtual void internalDraw(bool inhibit_draw = false, double elapsed = 0);

			/**
			 * \brief Metodo especifico a sobreescribir para el dibujado de un objeto.
			 */
			virtual void draw();

			Types::Point3D getNormalizedPosition() const;
			Types::Point3D getNormalizedRotation() const;
			Types::Point3D SceneObject::getHeadParentPosition() const;

		public:
			SceneObject();
			virtual ~SceneObject();

			/**
			* \brief Rota el objeto
			* \param x Grados en el eje x a rotar
			* \param y Grados en el eje y a rotar
			* \param z Grados en el eje z a rotar
			*/
			virtual void rotate(float_t x, float_t y, float_t z);

			/**
			* \brief Traslada un objeto con respecto a su padre
			* \param x Unidades en el eje x a ser trasladado
			* \param y Unidades en el eje y a ser trasladado
			* \param z Unidades en el eje z a ser trasladado
			*/
			virtual void translate(float_t x, float_t y, float_t z);

			/**
			* \brief Escala el tama�o del objeto
			* \param sca Porcentage al que escalar
			*/
			virtual void scale(float_t sca);

			/**
			* \brief Mueve el objeto a una posici�n
			* \param x Coordenadas en el eje x
			* \param y Coordenadas en el eje y
			* \param z Coordenadas en el eje z
			*/
			virtual void setPosition(Types::Point3D pos);

			/**
			* \brief Mueve el objeto a una posici�n sobre el plano XY
			* \param x Coordenadas en el eje x
			* \param y Coordenadas en el eje y
			*/
			virtual void setPosition2D(Types::Point2D pos);

			/**
			* \brief Obtiene la posici�n del objeto respecto a la escena
			*/
			Types::Point3D getPosition() const;

			/**
			* \brief Obtiene la posici�n del objeto sobre el plano XY de la escena
			*/
			Types::Point2D getPosition2D() const;

			/**
			 * \brief A�ade un objeto hijo al objeto. Los objetos hijos se trasforman usando al padre como origen de coordenadas y por lo tanto se mueven de forma conjunta.
			 * \param child Instancia del objeto hijo.
			 */
			void addChild(SceneObject* child);

			/**
			 * \brief Elimina un objeto de la lista de objetos hijo.
			 * \param child Instancia del objeto hijo a eliminar.
			 */
			void removeChild(SceneObject* child);

			/**
			 * \brief Obtiene el objeto padre de este objeto.
			 * \return Objeto padre o NULL si no tiene padre.
			 */
			SceneObject* getParent() const;

			/**
			 * \brief Establece la visibilidad de un objeto.
			 * \param show TRUE para hacerlo visible.
			 */
			void setVisibility(bool show);

			/**
			 * \brief Comprueba si un objeto es visible.
			 * \return TRUE si es visible.
			 */
			bool isVisible() const;
		};
	}
}
