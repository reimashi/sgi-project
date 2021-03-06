#pragma once

#include <list>
#include "scene_object.h"
#include "../io/controller.h"
#include "camera.h"

namespace Engine {
	namespace Core {
		/**
		* \brief Escena del juego
		*/
		class Scene
		{
			friend class Engine;

		private:
			bool inited = false;

		public:
			explicit Scene();

			/**
			* \brief Funci�n de inicializaci�n de la escena. Aqui se deben instanciar los objetos y cargar los archivos.
			*/
			virtual void init() = 0;

			/**
			* \brief Bucle principal del juego. Se ejecuta varias veces por segundo.
			*/
			virtual void loop() = 0;

		protected:
			IO::Controller* controls;

			std::list<SceneObject*> objects;

			Camera* camera;

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
			/// A�ade un objeto hijo al objeto.
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
