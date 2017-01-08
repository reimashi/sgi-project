#include "scene.h"

namespace Engine {
	namespace Core {
		Scene::Scene()
		{
			this->controls = &IO::Controller::getInstance();
		}

		void Scene::onWindowFocus() {}

		void Scene::onWindowBlur() {}
	}
}