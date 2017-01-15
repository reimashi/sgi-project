#include "engine.h"

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
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize((int)windowSize->getWidth(), (int)windowSize->getHeight());
			glutInitWindowPosition(0, 0);
			this->windowTitle = DEFAULT_WINDOW_TITLE;
			this->windowPtr = glutCreateWindow(DEFAULT_WINDOW_TITLE);
		}

		Engine::~Engine()
		{
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
					(*it)->internalDraw();
				}
			}
			else {
				logger->error(__FUNCTION__, "No se ha definido una escena. Se ignora el loop");
			}

			glFlush();

			// Preparamos el controlador para el proximo frame
			this->controller->startUpdate();

			// Control de FPS. Paramos el hilo de la logica hasta pasado el tiempo correspondiente.
			long double currTime = time(0);
			if (this->initTime == 0) this->initTime = currTime;
			else if (currTime < (this->initTime + (1000 / this->maxFps))) {
				Sleep((this->initTime + (1000 / this->maxFps)) - currTime);
			}
			this->initTime = time(0);

			// Pedimos a OpenGL que redibuje
			glutPostRedisplay();
		}

		// Public methods

		void Engine::run(Core::Scene *scene) {
			this->scenePtr = scene;

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
			this->windowSize = size;
			glutReshapeWindow((int)this->windowSize->getWidth(), (int)this->windowSize->getHeight());
		}

		Types::Dimension2D* Engine::getSize() const {
			return this->windowSize->clone();
		}

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

			if ((int)windowSize->getWidth() != (int)width || (int)windowSize->getHeight() != (int)height) {
				engine->resize(windowSize);
			}
			else {
				glViewport(0, 0, width, height);

				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();

				glOrtho(-2.0, 2.0, -2.0*(GLfloat)height / (GLfloat)width, 2.0*(GLdouble)height / (GLfloat)width, -2.0, 2.0);
				//gluPerspective(60.0, (GLdouble)width / (GLdouble)height, 1.0, 150.0);
			}
		}

		void Engine::mouseCallback(int button, int state, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(0xF200 + button));
			engine->controller->updateMouseMove(new Types::Point2D((float)x, (float)y));
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

			engine->controller->updateMouseMove(new Types::Point2D((float)x, (float)y));
		}

		void Engine::keyboardCallback(unsigned char key, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			if (key > 0x40 && key < 0x5B) { key += 0x20; }

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(key));
			engine->controller->updateMouseMove(new Types::Point2D((float)x, (float)y));
		}

		void Engine::keyboardSpecialCallback(int key, int x, int y) {
			Core::Engine *engine = &Core::Engine::getInstance();

			engine->controller->updateKeyPress(static_cast<IO::ControlKey>(0xF000 + key));
			engine->controller->updateMouseMove(new Types::Point2D((float)x, (float)y));
		}

#pragma endregion
	}
}