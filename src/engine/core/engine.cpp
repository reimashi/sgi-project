#include "engine.h"
#include <iostream>
#include <sstream>
#include <windows.h>

namespace Engine {
	namespace Core {
		Utils::Logger* Engine::logger = Utils::Logger::getLogger("Engine::Core::Engine");

		Engine::Engine()
		{
			this->controller = &IO::Controller::getInstance();

			this->windowSize = new Types::Dimension2D(800, 600);

			char *myargv[1];
			int myargc = 1;
			myargv[0] = _strdup(DEFAULT_WINDOW_TITLE);

			glutInit(&myargc, myargv);
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
			glutInitWindowSize(static_cast<int>(windowSize->getWidth()), static_cast<int>(windowSize->getHeight()));
			glutInitWindowPosition(0, 0);
			this->windowTitle = DEFAULT_WINDOW_TITLE;
			this->windowPtr = glutCreateWindow(DEFAULT_WINDOW_TITLE);
		}

		Engine::~Engine()
		{
			delete this->windowSize;
		}

		void Engine::loop() {
			// Dibujo del frame
			if (this->scenePtr != NULL) {
				// Iniciamos la escena si aún no lo está
				if (!this->scenePtr->inited) {
					this->scenePtr->init();
					this->scenePtr->inited = true;
					logger->debug(__FUNCTION__, "Se ha inicializado la escena");
				}

				// Ejecutamos la logica del juego
				this->scenePtr->loop();

				// Dibujamos la escena
				glClear(GL_COLOR_BUFFER_BIT);

				for (std::list<SceneObject*>::iterator it = this->scenePtr->objects.begin(); it != this->scenePtr->objects.end(); ++it) {
					(*it)->internalDraw(false, 300); // TODO: Poner el counter bien
				}
			}
			else {
				logger->error(__FUNCTION__, "No se ha definido una escena. Se ignora el loop");
			}

			// Si la opción está activada, se muestran los FPS en pantalla
			if (this->showFps) this->renderFPS();

			// Se vacían los buffers y se voltean
			glFlush();
			glutSwapBuffers();

			// Preparamos el controlador para el proximo frame
			this->controller->startUpdate();

			// Control de FPS. Paramos el hilo de la logica hasta pasado el tiempo correspondiente.
			if (this->loopCounter->get() < (1000 / this->maxFps)) {
				long sleepTime = (this->loopCounter->get() - (1000 / this->maxFps));
				Sleep(static_cast<DWORD>(sleepTime));
			}

			// Actualizamos el tiempo de inicio de la escena
			this->loopCounter->reset();
			//this->initTime = static_cast<long int>(time(nullptr));

			// Pedimos a OpenGL que redibuje
			// NOTA: Comentar esta linea evita el dibujado continuo de la escena. Para las animaciones pero permite hacer debug frame a frame.
			glutPostRedisplay();
		}

		void Engine::run(Core::Scene *scene) {
			this->scenePtr = scene;
			this->loopCounter = new Time::Counter();

			glutDisplayFunc(Engine::loopCallback);
			glutReshapeFunc(Engine::reshapeCallback);
			glutMouseFunc(Engine::mouseCallback);
			glutEntryFunc(Engine::mouseEntryCallback);
			glutMotionFunc(Engine::mouseMotionCallback);
			glutPassiveMotionFunc(Engine::mouseMotionCallback);
			glutKeyboardFunc(Engine::keyboardCallback);
			glutSpecialFunc(Engine::keyboardSpecialCallback);

			glutMainLoop();
		}

		void Engine::setTitle(std::string title) {
			glutSetWindow(this->windowPtr);
			glutSetWindowTitle(title.c_str());
		}

		std::string Engine::getTitle() const {
			return this->windowTitle;
		}

		void Engine::resize(Types::Dimension2D *size) {
			glutSetWindow(this->windowPtr);
			delete this->windowSize;
			this->windowSize = size;
			glutReshapeWindow((int)this->windowSize->getWidth(), (int)this->windowSize->getHeight());
		}

		Types::Dimension2D* Engine::getSize() const {
			return this->windowSize->clone();
		}

		void Engine::renderFPS() {
			glColor3f(1.0f, 0.0f, 0.0f);
			glRasterPos2i(1, 1);
			
			std::stringstream ss;
			ss << this->maxFps << " FPS";

			std::string s = ss.str();

			void * font = GLUT_BITMAP_9_BY_15;

			for (std::string::iterator i = s.begin(); i != s.end(); ++i)
			{
				char c = *i;
				glutBitmapCharacter(font, c);
			}
		}

		void Engine::setFramerateLimit(unsigned short frames) { this->maxFps = frames; }

		void Engine::displayFramerate(bool display) { this->showFps = display; }

#pragma region Callbacks de GLUT

		void Engine::loopCallback() {
			logger->trace(__FUNCTION__, "Ejecucion del loop");

			Core::Engine *engine = &Core::Engine::getInstance();
			engine->loop();
		}

		void Engine::reshapeCallback(GLsizei width, GLsizei height) {
			logger->debug(__FUNCTION__, "Cambio de resolucion a " + std::to_string(width) + "x" + std::to_string(height));

			Core::Engine *engine = &Core::Engine::getInstance();
			Types::Dimension2D* windowSize = engine->getSize();

			if (static_cast<int>(windowSize->getWidth()) != static_cast<int>(width) || static_cast<int>(windowSize->getHeight()) != static_cast<int>(height)) {
				engine->resize(windowSize);
			}
			else {
				glViewport(0, 0, width, height);

				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
			}
		}

		void Engine::mouseCallback(int button, int state, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(0xF200 + button));
			engine->controller->updateMouseMove(Types::Point2D((float)x, (float)y));
		}

		void Engine::mouseEntryCallback(int state) {
			Core::Engine *engine = &Core::Engine::getInstance();

			if (engine->scenePtr != NULL) {
				if (state == GLUT_LEFT) engine->scenePtr->onWindowBlur();
				else if (state == GLUT_ENTERED) engine->scenePtr->onWindowFocus();
			}
		}

		void Engine::mouseMotionCallback(int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			engine->controller->updateMouseMove(Types::Point2D((float)x, (float)y));
		}

		void Engine::keyboardCallback(unsigned char key, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			if (key > 0x40 && key < 0x5B) { key += 0x20; }

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(key));
			engine->controller->updateMouseMove(Types::Point2D((float)x, (float)y));
		}

		void Engine::keyboardSpecialCallback(int key, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(0xF000 + key));
			engine->controller->updateMouseMove(Types::Point2D((float)x, (float)y));
		}

#pragma endregion
	}
}