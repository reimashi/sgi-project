#pragma once

#include <list>
#include "../types/point3d.h"

namespace Engine {
	namespace Core {
		/// <summary>
		/// Representa cualquier elemento u objeto contenido en la escena.
		/// </summary>
		class SceneObject {
		protected:
			std::list<SceneObject*> childs;
			SceneObject* parent = NULL;

			Types::Point3D rotation;
			Types::Point3D position;

			/// <summary>
			/// Establece el objeto padre de este objeto.
			/// </summary>
			/// <param name="child">Instancia del objeto hijo.</param>
			void setParent(SceneObject* parent);

		public:
			SceneObject();
			~SceneObject();

			void rotate(float_t x, float_t y, float_t z);
			void translate(float_t x, float_t y, float_t z);

			/// <summary>
			/// Añade un objeto hijo al objeto.
			/// </summary>
			/// <param name="child">Instancia del objeto hijo.</param>
			void addChild(SceneObject* child);

			/// <summary>
			/// Elimina un objeto de la lista de objetos hijo.
			/// </summary>
			/// <param name="child">Instancia del objeto hijo.</param>
			void removeChild(SceneObject* child);

			/// <summary>
			/// Obtiene el objeto padre de este objeto.
			/// </summary>
			/// <returns>Objeto padre o NULL si no tiene padre.</returns>
			SceneObject* getParent() const;
		};
	}
}