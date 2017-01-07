#pragma once

namespace Engine {
	namespace Core {
		class Scene
		{
		public:
			explicit Scene();

			virtual void loop() = 0;

			// setCamera
		};
	}
}