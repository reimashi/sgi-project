#include "engine.h"

namespace Engine {
	namespace Core {
		Utils::Logger* Engine::logger = Utils::Logger::getLogger("Engine::Core::Engine");

		Engine::Engine()
		{
			this->windowSize = new Types::Dimension2D(800, 600);

			char *myargv[1];
			int myargc = 1;
			myargv[0] = _strdup("Engine");

			glutInit(&myargc, myargv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize((int)windowSize->getWidth(), (int)windowSize->getHeight());
			glutInitWindowPosition(0, 0);
			this->windowPtr = glutCreateWindow("Engine");
		}

		Engine::~Engine()
		{
		}

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

		void Engine::loop() {
			glClear(GL_COLOR_BUFFER_BIT);

			if (this->scenePtr != NULL) {
				this->scenePtr->loop();
			}
			else {
				logger->error(__FUNCTION__, "No se ha definido una escena. Se ignora el loop");
			}

			glFlush();
		}

		// Public methods

		void Engine::run(Core::Scene *scene) {
			this->scenePtr = scene;

			glutDisplayFunc(this->loopCallback);
			glutReshapeFunc(this->reshapeCallback);

			glutMainLoop();
		}

		void Engine::setTitle(std::string title) {
			glutSetWindow(this->windowPtr);
			glutSetWindowTitle(title.c_str());
		}

		void Engine::resize(Types::Dimension2D *size) {
			glutSetWindow(this->windowPtr);
			this->windowSize = size;
			glutReshapeWindow((int)this->windowSize->getWidth(), (int)this->windowSize->getHeight());
		}

		Types::Dimension2D* Engine::getSize() const {
			return this->windowSize->clone();
		}
	}
}