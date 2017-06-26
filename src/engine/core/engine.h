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
#include "../time/counter.h"

namespace Engine {
	namespace Core {
		static const unsigned short DEFAULT_MAX_FPS = 30;
		static const char DEFAULT_WINDOW_TITLE[] = "Engine";

		/**
		* \brief Clase principal del game engine. Es el encargado de manejar todos los graficos.
		*/
		class Engine : public Utils::Singleton<Engine>
		{
			friend class Utils::Singleton<Engine>;

		private:
			static Utils::Logger* logger;

			int windowPtr = NULL;
			IO::Controller *controller = NULL;
			Core::Scene *scenePtr = NULL;
			Types::Dimension2D *windowSize = NULL;
			Time::Counter* loopCounter;

			unsigned short maxFps = DEFAULT_MAX_FPS;
			bool showFps = false;
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

			/// <summary>
			/// Renderiza los FPS como texto encima del juego
			/// </summary>
			void renderFPS();

		public:

			/**
			* \brief Ejecuta una escena dentro del motor de juego.
			* \param scene Escena a ejecutar.
			*/
			void run(Core::Scene *scene);

			/**
			* \brief Establece el titulo de la ventana del juego.
			* \param title Texto del titulo.
			*/
			void setTitle(std::string title);

			/**
			* \brief Obtiene el titulo de la ventana del juego.
			* \return Texto del titulo.
			*/
			std::string getTitle() const;

			/**
			* \brief Establece el tamaño de la ventana del juego. Es importante indicar que si no se usa este metodo, la venta volverá a su tamaño al redimensionarla manualmente.
			* \param title Tamaño de la ventana.
			*/
			void resize(Types::Dimension2D *size);

			/**
			* \brief Obtiene el tamaño de la ventana del juego.
			* \return Tamaño de la ventana.
			*/
			Types::Dimension2D* getSize() const;

			/**
			* \brief Establece un limite de frames por segundo
			* \param frames Limite de frames por segundo
			*/
			void setFramerateLimit(unsigned short frames);

			/**
			* \brief Des/Activa la visualización del framerate en el juego
			* \param display TRUE para activar la visualización
			*/
			void displayFramerate(bool display);
		};
	}
}

#endif