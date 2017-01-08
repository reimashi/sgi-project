#pragma once

#include "../io/controller.h"

namespace Engine {
	namespace Core {
		class Scene
		{
			friend class Engine;

		public:
			explicit Scene();

			virtual void loop() = 0;

		protected:
			IO::Controller* controls;

			/// <summary>
			/// Metodo que es llamado cuando la ventana pasa al primer plano
			/// </summary>
			virtual void onWindowFocus();

			/// <summary>
			/// Metodo que es llamado cuando la ventana pasa a un segundo plano
			/// </summary>
			virtual void onWindowBlur();
			// setCamera
		};
	}
}