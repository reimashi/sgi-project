#pragma once

#include <iostream>
#include <string>
#include <cstdbool>
#include <gl/glut.h>

#include "./scene.h"
#include "../types/dimension2d.h"
#include "../utils/singleton.h"
#include "../utils/logger.h"

namespace Engine {
	namespace Core {
		class Engine : public Utils::Singleton<Engine>
		{
			friend class Utils::Singleton<Engine>;

		private:
			static Utils::Logger* logger;

			int windowPtr = NULL;
			Core::Scene *scenePtr = NULL;
			Types::Dimension2D *windowSize = NULL;

			Engine();
			~Engine();

			void loop();

			static void loopCallback();
			static void reshapeCallback(GLsizei width, GLsizei height);

		public:
			void run(Core::Scene *scene);
			void setTitle(std::string title);
			void resize(Types::Dimension2D *size);
			Types::Dimension2D* getSize() const;
		};
	}
}