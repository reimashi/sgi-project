#include "game_scene.h"
#include "engine/core/camera.h"

GameScene::GameScene() : Core::Scene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	this->table = new TableObject();
	this->addObject(this->table);

	this->puck = new PuckObject();
	this->addObject(this->puck);

	this->mallet = new MalletObject();
	this->addObject(this->mallet);

	this->camera->setTarget(Types::Point3D(0, 0, 0));
	this->camera->setPosition(Types::Point3D(0, 2.5, 3));
}

void GameScene::loop()
{
	float_t widthLimit = 4.6;
	float_t depthLimit = 9.2;
	Core::Engine *engine = &Core::Engine::getInstance();

	// Control del mallet con el ratón
	Types::Point2D mousePosition = this->controls->getMousePosition();
	float_t malletXLimit = widthLimit - this->mallet->getCollisionRadius();
	float_t malletZLimit = depthLimit - this->mallet->getCollisionRadius();
	float_t malletX = (mousePosition.getX() / engine->getSize()->getWidth() * malletXLimit * 2) - malletXLimit;
	float_t malletZ = (mousePosition.getY() / engine->getSize()->getHeight() * malletZLimit * 2) - malletZLimit;
	this->mallet->setPosition(Types::Point3D(malletX, this->mallet->getPosition().getY(), malletZ));

	resolveCollision(this->puck, this->mallet);

	// Si choca contra los laterales del campo
	bool colision = true;
	while (colision) {
		float_t width_max_limit = widthLimit - this->puck->getCollisionRadius();
		float_t width_min_limit = -widthLimit + this->puck->getCollisionRadius();
		float_t depth_max_limit = depthLimit - this->puck->getCollisionRadius();
		float_t depth_min_limit = -depthLimit + this->puck->getCollisionRadius();

		// Si el puck se intenta salir por la derecha.
		if (this->puck->getPosition().getX() > width_max_limit)
		{
			float_t diff = width_max_limit - (this->puck->getPosition().getX() - width_max_limit); // Calculamos cuanto se "ha pasado"
			while (diff > widthLimit) diff -= widthLimit;
			this->puck->setPosition(Types::Point3D(diff, this->puck->getPosition().getY(), this->puck->getPosition().getZ()));	// Establecemos la nueva posicion restando lo que se ha pasado
			this->puck->setVelocity(Types::Vector3D::flipOverX(&this->puck->getVelocity())); // Cambiamos la dirección del movimiento sobre el eje correspondiente
			std::cout << "Colision derecha" << std::endl;
			colision = true; // Activamos el flag de colision
		}
		else if (this->puck->getPosition().getX() < width_min_limit)
		{
			float_t diff = width_min_limit - (this->puck->getPosition().getX() - width_min_limit);
			while (diff < -widthLimit) diff += widthLimit;
			this->puck->setPosition(Types::Point3D(diff, this->puck->getPosition().getY(), this->puck->getPosition().getZ()));
			this->puck->setVelocity(Types::Vector3D::flipOverX(&this->puck->getVelocity()));
			std::cout << "Colision izqui" << std::endl;
			colision = true;
		}
		else if (this->puck->getPosition().getZ() > depth_max_limit)
		{
			float_t diff = depth_max_limit - (this->puck->getPosition().getZ() - depth_max_limit);
			while (diff > depthLimit) diff -= depthLimit;
			this->puck->setPosition(Types::Point3D(this->puck->getPosition().getX(), this->puck->getPosition().getY(), diff));
			this->puck->setVelocity(Types::Vector3D::flipOverZ(&this->puck->getVelocity()));
			std::cout << "Colision fondo" << std::endl;
			colision = true;
		}
		else if (this->puck->getPosition().getZ() < depth_min_limit)
		{
			float_t diff = depth_min_limit - (this->puck->getPosition().getZ() - depth_min_limit);
			while (diff < -depthLimit) diff += depthLimit;
			this->puck->setPosition(Types::Point3D(this->puck->getPosition().getX(), this->puck->getPosition().getY(), diff));
			this->puck->setVelocity(Types::Vector3D::flipOverZ(&this->puck->getVelocity()));
			std::cout << "Colision pantalla" << std::endl;
			colision = true;
		}
		else {
			colision = false;
		}
	}

	_sleep(30);
}

void GameScene::resolveCollision(PuckObject* puck, MalletObject* mallet)
{
	Types::Vector3D malletPosition = mallet->getPosition();
	Types::Vector3D puckPosition = puck->getPosition();

	float_t collisionDistance = mallet->getCollisionRadius() + puck->getCollisionRadius();

	// Vector de colisión
	Types::Vector3D delta = puckPosition - malletPosition;

	// Distancia entre los objetos
	float_t distance = delta.getMagnitude();

	std::cout << "Distancia con el mazo " << distance << " mazo " << mallet->getPosition() << " ficha " << puck->getPosition() << std::endl;
	// Para evitar divisiones por 0
	if (distance == 0.0) {
		delta = Types::Vector3D(collisionDistance, 0.0, 0.0);
		distance = collisionDistance;
	}


	// Si la distancia no es suficiente para la colisión, no se hace nada
	if (distance > collisionDistance)
	{
		return;
	}
	else {
		// Consideramos el mallet inamovible y movemos el puck para evitarlo
		Types::Vector3D mtd = delta * ((collisionDistance - distance) / distance);
		puckPosition = puckPosition + (mtd * 2);
		puck->setPosition(puckPosition.getPoint());


		std::cout << "Colision con el mazo" << std::endl;

		/*
		collision = collision / distance;
		std::cout << "collission vel " << collision.getPoint().getX() << " - " << collision.getPoint().getY() << std::endl;
		float_t aci = puck->getVelocity().dot(collision);
		Types::Vector2D collision2 = collision * aci;

		std::cout << "collission aci " << aci << std::endl;
		std::cout << "collission vel " << collision.getPoint().getX() << " - " << collision.getPoint().getY() << std::endl;
		std::cout << "collission vel " << collision2.getPoint().getX() << " - " << collision2.getPoint().getY() << std::endl;
		// Replace the collision velocity components with the new ones
		puck->setVelocity(collision * aci);*/
	}
}