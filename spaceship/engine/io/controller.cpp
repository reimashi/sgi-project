#include "controller.h"
#include <iostream>

namespace Engine {
	namespace IO {
		Controller::Controller() : mousePosition(0.0, 0.0)
		{
		}

		Controller::~Controller()
		{
		}

		void Controller::startUpdate() {
			if (!this->pressedKeys.empty()) this->pressedKeys.clear();
		}

		void Controller::updateMouseMove(Types::Point2D* position) {
			if (*position != this->mousePosition) this->mousePosition = *(position->clone());
		}

		void Controller::updateKeyPress(ControlKey key) {
			if (!this->isKeyPressed(key)) {
				this->pressedKeys.emplace_back(static_cast<int>(key));
			}
		}

		bool Controller::isKeyPressed(ControlKey key) const {
			int keycode = static_cast<int>(key);
			return (std::find(this->pressedKeys.begin(), this->pressedKeys.end(), static_cast<int>(key)) != this->pressedKeys.end());
		}

		Types::Point2D Controller::getMousePosition() const {
			return *this->mousePosition.clone();
		}
	}
}