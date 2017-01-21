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
	this->puck->translate(-1.15, 0, 0);
	this->addObject(this->puck);

	this->mallet = new MalletObject();
	this->addObject(this->mallet);

	this->camera->setPosition(Types::Point3D(0, 1, -2.9));
}

void GameScene::loop()
{
	this->puck->updatePosition(23);
	this->mallet->updatePosition(23);

	// Obtenemos la posicion de los 3 elementos
	Types::Point2D malletAPosition = Types::Point2D(this->mallet->getPosition().getX(), this->mallet->getPosition().getZ());
	Types::Point2D malletBPosition = Types::Point2D(this->mallet->getPosition().getX(), this->mallet->getPosition().getZ());
	Types::Point2D puckPosition = Types::Point2D(this->puck->getPosition().getX(), this->puck->getPosition().getZ());

	float_t widthLimit = 4;
	float_t depthLimit = 8.5;
	float_t goalSize = 2.4;

	std::cout << "Puck: " << malletAPosition.getX() << " - " << malletAPosition.getY() << std::endl;

	// Calculamos si se ha salido del tablero, para anotar punto
	if (puckPosition.getY() < -(depthLimit + this->puck->getCollisionRadius()) || puckPosition.getY() > (depthLimit + this->puck->getCollisionRadius()))
	{
		// TODO: Anotar punto en marcador
		this->puck->setPosition(Types::Point3D(0, 0, -(depthLimit / 2)));
	}

	if (this->controls->isKeyPressed(IO::ControlKey::LEFT))
	{
		this->mallet->translate(-0.1, 0, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::RIGHT))
	{
		this->mallet->translate(0.1, 0, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::UP))
	{
		this->mallet->translate(0, 0, -0.1);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::DOWN))
	{
		this->mallet->translate(0, 0, 0.1);
	}

	//resolveCollision(this->puck, this->mallet);

	// Si choca contra los laterales del campo
	bool noColision = false;
	while (!noColision) {
		if (puckPosition.getX() < -widthLimit + this->puck->getCollisionRadius())
		{
			float_t diff = (-widthLimit + this->puck->getCollisionRadius()) - puckPosition.getX();
			if (diff > widthLimit) diff -= widthLimit;
			puckPosition =Types::Point2D(-widthLimit + diff, puckPosition.getY());
			this->puck->reverseDirectionX();
		}
		else if (puckPosition.getX() > widthLimit - this->puck->getCollisionRadius())
		{
			float_t diff = puckPosition.getX() - (widthLimit - this->puck->getCollisionRadius());
			if (diff > widthLimit) diff -= widthLimit;
			puckPosition = Types::Point2D(widthLimit - diff, puckPosition.getY());
			this->puck->reverseDirectionX();
		}
		else if (puckPosition.getY() < -depthLimit + this->puck->getCollisionRadius() &&
			puckPosition.getX() < -(widthLimit - (goalSize / 2)))
		{
			float_t diff = (-depthLimit + this->puck->getCollisionRadius()) - puckPosition.getY();
			if (diff > depthLimit) diff -= depthLimit;
			puckPosition = Types::Point2D(puckPosition.getX(), depthLimit - diff);
			this->puck->reverseDirectionY();
		}
		else if (puckPosition.getY() > depthLimit - this->puck->getCollisionRadius() &&
			puckPosition.getX() > (widthLimit - (goalSize / 2)))
		{
			float_t diff = puckPosition.getY() - (depthLimit - this->puck->getCollisionRadius());
			if (diff > depthLimit) diff -= depthLimit;
			puckPosition = Types::Point2D(puckPosition.getX(), depthLimit - diff);
			this->puck->reverseDirectionY();
		}
		else { }
		this->puck->setPosition2D(puckPosition);
		noColision = true;
	}
}

void GameScene::resolveCollision(PuckObject* puck, MalletObject* mallet)
{
	Types::Vector2D malletPosition = Types::Vector2D(mallet->getPosition2D());
	Types::Vector2D puckPosition = Types::Vector2D(puck->getPosition2D());

	float_t collisionDistance = mallet->getCollisionRadius() + puck->getCollisionRadius();

	// Vector de colisión
	Types::Vector2D delta = puckPosition - malletPosition;

	// Distancia entre los objetos
	float_t distance = collisionDistance;

	// Para evitar divisiones por 0
	if (distance == 0.0) {
		delta = Types::Vector2D(collisionDistance, 0.0);
		distance = collisionDistance;
	}

	// Si la distancia no es suficiente para la colisión, no se hace nada
	if (distance > collisionDistance)
	{
		return;
	}
	else {
		Types::Vector2D mtd = delta * ((collisionDistance - distance) / distance);
		puckPosition = puckPosition + (mtd * (0.5 / 0.5 + 1));
		puck->setPosition2D(puckPosition.getPoint());


		/*
		std::cout << "collission d " << distance << std::endl;
		std::cout << "collission pvel " << puckPosition.getX() << " - " << puckPosition.getY() << std::endl;
		std::cout << "collission mvel " << malletPosition.getX() << " - " << malletPosition.getY() << std::endl;
		std::cout << "collission vel " << collision.getPoint().getX() << " - " << collision.getPoint().getY() << std::endl;
		// Get the components of the velocity vectors which are parallel to the collision.
		// The perpendicular component remains the same for both fish
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