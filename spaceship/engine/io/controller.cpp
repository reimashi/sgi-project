#include "controller.h"

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
				this->pressedKeys.emplace_back(key);
			}
		}

		bool Controller::isKeyPressed(ControlKey key) const {
			return (std::find(this->pressedKeys.begin(), this->pressedKeys.end(), key) != this->pressedKeys.end());
		}

		std::list<ControlKey> Controller::getPressedKeys() {
			std::list<IO::ControlKey> keys;
			std::copy(this->pressedKeys.begin(), this->pressedKeys.end(), std::back_inserter(keys));
			return keys;
		}

		Types::Point2D Controller::getMousePosition() const {
			return *this->mousePosition.clone();
		}
	}
}