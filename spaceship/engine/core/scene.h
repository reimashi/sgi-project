#pragma once

#include <list>
#include "scene_object.h"
#include "../io/controller.h"

namespace Engine {
	namespace Core {
		class Scene
		{
			friend class Engine;

		private:
			bool inited = false;

		public:
			explicit Scene();

			virtual void init() = 0;
			virtual void loop() = 0;

		protected:
			IO::Controller* controls;

			std::list<SceneObject*> objects;

			/// <summary>
			/// Metodo que es llamado cuando la ventana pasa al primer plano
			/// </summary>
			virtual void onWindowFocus();

			/// <summary>
			/// Metodo que es llamado cuando la ventana pasa a un segundo plano
			/// </summary>
			virtual void onWindowBlur();
			// setCamera

			/// <summary>
			/// Añade un objeto hijo al objeto.
			/// </summary>
			/// <param name="child">Instancia del objeto hijo.</param>
			void addObject(SceneObject* child);

			/// <summary>
			/// Elimina un objeto de la lista de objetos hijo.
			/// </summary>
			/// <param name="child">Instancia del objeto hijo.</param>
			void removeObject(SceneObject* child);
		};
	}
}