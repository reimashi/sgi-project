#include "engine.h"

namespace Engine {
	namespace Core {

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
			Core::Engine *engine = &Core::Engine::getInstance();
			engine->loop();
		}

		void Engine::reshapeCallback(GLsizei width, GLsizei height) {
			Core::Engine *engine = &Core::Engine::getInstance();
			Types::Dimension2D* windowSize = engine->getSize();
			
			if ((int)windowSize->getWidth() != (int)width || (int)windowSize->getHeight() != (int)height) {
				engine->resize(windowSize);
			}
			else {
				glViewport(0, 0, width, height);

				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();

				gluPerspective(60.0, (GLdouble)width / (GLdouble)height, 1.0, 150.0);
			}
		}

		void Engine::loop() {
			if (this->scenePtr != NULL) {
				this->scenePtr->loop();
			}
			else {
				std::wcout << "La escena no es valida" << std::endl;
			}
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