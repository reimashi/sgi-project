#include "./movable_object3d.h"
#include "../types/point3d.h"

namespace Engine {
	namespace Core {
		MovableObject3D::MovableObject3D(Mesh geom, Material* mat) : Object3D(geom, mat), velocity(Types::Point3D(0, 0, 0))
		{

		}

		MovableObject3D::~MovableObject3D()
		{

		}

		float_t MovableObject3D::getFriction() const { return this->friction; }
		void MovableObject3D::setFriction(const float_t friz) { this->friction = friz; }

		Types::Vector3D MovableObject3D::getVelocity() const
		{
			return this->velocity.clone();
		}

		void MovableObject3D::setVelocity(Types::Vector3D vel)
		{
			this->velocity = vel.clone();
		}

		void MovableObject3D::internalDraw(bool inhibit_draw, double elapsed) {
			// Calculamos el multiplicador para aplicar una concordancia temporal
			float_t multip = elapsed / 1000;

			// Se aplica un factor de rozamiento a la velocidad
			float_t friction_use = (1 - this->getFriction()) * multip;
			if (friction_use < 0) friction_use;
			this->setVelocity(this->getVelocity() - (this->getVelocity() * friction_use));

			// Se aplica el movimiento si el objeto tiene una velocidad
			this->translate(this->velocity.getPoint().getX() * multip, this->velocity.getPoint().getY() * multip, this->velocity.getPoint().getZ() * multip);

			Object3D::internalDraw(inhibit_draw, elapsed);
		}
	}
}