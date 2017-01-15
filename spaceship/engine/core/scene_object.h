#pragma once

#include <list>
#include "../types/point3d.h"
#include "../utils/logger.h"

namespace Engine {
	namespace Core {
		/**
		 * \brief Representa cualquier elemento u objeto contenido en la escena.
		 */
		class SceneObject {
			friend class Engine;

		protected:
			static Utils::Logger* logger;

			/**
			 * \brief Objetos hijos
			 */
			std::list<SceneObject*> childs;

			/**
			 * \brief Puntero al objeto padre, si existe
			 */
			SceneObject* parent = NULL;

			/**
			 * \brief Rotación del objeto con respecto a su padre
			 */
			Types::Point3D rotation;

			/**
			 * \brief Posición del objeto con respecto a su padre
			 */
			Types::Point3D position;

			/**
			 * \brief Establece el objeto padre de este objeto.
			 * \param parent Instancia del objeto hijo.
			 */
			void setParent(SceneObject* parent);

			/**
			 * \brief Invoca internamente el dibujado del objeto.
			 */
			void internalDraw();

			/**
			 * \brief Metodo especifico a sobreescribir para el dibujado de un objeto.
			 */
			virtual void draw();

			Types::Point3D getNormalizedPosition() const;
			Types::Point3D getNormalizedRotation() const;
			Types::Point3D SceneObject::getHeadParentPosition() const;

		public:
			SceneObject();
			~SceneObject();

			/**
			* \brief Rota el objeto
			* \param x Grados en el eje x a rotar
			* \param y Grados en el eje y a rotar
			* \param z Grados en el eje z a rotar
			*/
			void rotate(float_t x, float_t y, float_t z);

			/**
			* \brief Traslada un objeto con respecto a su padre
			* \param x Unidades en el eje x a ser trasladado
			* \param y Unidades en el eje y a ser trasladado
			* \param z Unidades en el eje z a ser trasladado
			*/
			void translate(float_t x, float_t y, float_t z);

			/**
			* \brief Mueve el objeto a una posición
			* \param x Coordenadas en el eje x
			* \param y Coordenadas en el eje y
			* \param z Coordenadas en el eje z
			*/
			void setPosition(Types::Point3D pos);

			/**
			 * \brief Añade un objeto hijo al objeto.
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
		};
	}
}