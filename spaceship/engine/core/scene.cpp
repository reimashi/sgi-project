#include "scene.h"

namespace Engine {
	namespace Core {
		Scene::Scene()
		{
			this->controls = &IO::Controller::getInstance();
		}

		void Scene::onWindowFocus() {}

		void Scene::onWindowBlur() {}

		void Scene::addObject(SceneObject* child) {
			if (!(std::find(this->objects.begin(), this->objects.end(), child) != this->objects.end())) {
				this->objects.push_back(child);
			}
		}

		void Scene::removeObject(SceneObject* child) {
			if ((std::find(this->objects.begin(), this->objects.end(), child) != this->objects.end())) {
				this->objects.remove(child);
			}
		}
	}
}