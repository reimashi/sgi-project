#pragma once

namespace Engine {
	namespace Core {
		/**
		* \brief Establece el titulo de la ventana del juego.
		* \param title Texto del titulo.
		*/
		class Material
		{
			friend class Object3D;
		public:
			Material();
			virtual ~Material();

			virtual void preDraw() = 0;
			virtual void postDraw() = 0;
		};
	}
}