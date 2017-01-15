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
			 * \param x Grados en el eje x a ser trasladado
			 * \param y Grados en el eje y a ser trasladado
			 * \param z Grados en el eje z a ser trasladado
			 */
			void translate(float_t x, float_t y, float_t z);

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