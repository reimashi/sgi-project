#pragma once

namespace Engine {
	namespace Core {
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