#pragma once

#ifndef ENGINE_CORE_ENGINE_H
#define ENGINE_CORE_ENGINE_H

#include <iostream>
#include <string>
#include <cstdbool>
#include <stdlib.h>
#include <gl/glut.h>

#include "../io/controller.h"
#include "./scene.h"
#include "../types/dimension2d.h"
#include "../utils/singleton.h"
#include "../utils/logger.h"

namespace Engine {
	namespace Core {
		static const unsigned short DEFAULT_MAX_FPS = 60;
		static const char DEFAULT_WINDOW_TITLE[] = "Engine";

		class Engine : public Utils::Singleton<Engine>
		{
			friend class Utils::Singleton<Engine>;

		private:
			static Utils::Logger* logger;

			int windowPtr = NULL;
			IO::Controller *controller = NULL;
			Core::Scene *scenePtr = NULL;
			Types::Dimension2D *windowSize = NULL;
			long double initTime = 0;

			unsigned short maxFps = DEFAULT_MAX_FPS;
			std::string windowTitle;

			Engine();
			~Engine();

			void loop();

			/// <summary>
			/// Maneja el callback glutDisplayFunc de GLUT
			/// </summary>
			static void loopCallback();

			/// <summary>
			/// Maneja el callback glutReshapeFunc de GLUT
			/// </summary>
			static void reshapeCallback(GLsizei width, GLsizei height);

			/// <summary>
			/// Maneja el callback glutMouseFunc de GLUT
			/// </summary>
			static void mouseCallback(int button, int state, int x, int y);

			/// <summary>
			/// Maneja el callback glutEntryFunc de GLUT
			/// </summary>
			static void mouseEntryCallback(int state);

			/// <summary>
			/// Maneja los callback glutMotionFunc y glutPassiveMotionFunc de GLUT
			/// </summary>
			static void mouseMotionCallback(int x, int y);

			/// <summary>
			/// Maneja el callback glutKeyboardFunc de GLUT
			/// </summary>
			static void keyboardCallback(unsigned char key, int x, int y);

			/// <summary>
			/// Maneja el callback glutSpecialFunc de GLUT
			/// </summary>
			static void keyboardSpecialCallback(int key, int x, int y);

		public:
			void run(Core::Scene *scene);
			void setTitle(std::string title);
			std::string getTitle() const;
			void resize(Types::Dimension2D *size);
			Types::Dimension2D* getSize() const;
		};
	}
}

#endif