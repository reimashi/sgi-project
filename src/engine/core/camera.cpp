#include "camera.h"
#include "engine.h"
#include "../types/vector3d.h"

namespace Engine {
	namespace Core {
		Camera::Camera() : target(0, 0, 1)
		{
		}

		Camera::~Camera()
		{
		}

		void Camera::setFar(float_t val)
		{
			this->farv = val;
			this->change = true;
		}

		float_t Camera::getFar() const { return this->farv; }

		void Camera::setMode(int32_t mode)
		{
			this->mode = mode;
			this->change = true;
		}

		void Camera::setTarget(Types::Point3D target)
		{
			this->target = target;
			this->changePosition = true;
		}

		void Camera::draw()
		{
			// Si ha habido algun cambio de modo de camara, actualizamos el modo de camara de OpenGL
			if (this->change)
			{
				Engine* engPtr = &Engine::getInstance();
				Types::Dimension2D* windowSize = engPtr->getSize();

				switch (this->mode)
				{
				case Camera::ORTHOGONAL:
					glOrtho(-2.0, 2.0, -2.0*windowSize->getHeight() / windowSize->getWidth(), 2.0*windowSize->getHeight() / windowSize->getWidth(), -1.0, this->farv);
				case Camera::PERSPECTIVE:
				default:
					gluPerspective(60.0, static_cast<GLdouble>(windowSize->getWidth()) / static_cast<GLdouble>(windowSize->getHeight()), 0.0, this->farv);
				}

				this->change = false;
			}

			// Evitamos actualizacion de camara si no cambia, por rendimiento
			if (this->changePosition) {
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				gluLookAt(this->position.getX(), this->position.getY(), this->position.getZ(),
					this->target.getX(), this->target.getY(), this->target.getZ(), 0, 1, 0);
				this->changePosition = false;
			}
		}

		void Camera::rotate(float_t x, float_t y, float_t z)
		{
			SceneObject::rotate(x, y, z);
			this->changePosition = true;
		}

		void Camera::translate(float_t x, float_t y, float_t z)
		{
			SceneObject::translate(x, y, z);
			this->changePosition = true;
		}

		void Camera::setPosition(Types::Point3D pos)
		{
			SceneObject::setPosition(pos);
			this->changePosition = true;
		}
	}
}
