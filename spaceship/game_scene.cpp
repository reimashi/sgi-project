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
	// Obtenemos la posicion de los 3 elementos
	Types::Point3D malletAPosition = this->mallet->getPosition();
	Types::Point3D malletBPosition = this->mallet->getPosition();
	Types::Point3D puckPosition = this->mallet->getPosition();

	float_t widthLimit = 4;
	float_t depthLimit = 8.5;
	float_t malletSize = 0.65;
	float_t goalSize = 2.4;
	float_t puckSize = 0.5;
	float_t collisionDistance = malletSize + puckSize;

	std::cout << "Puck: " << malletAPosition.getX() << " - " << malletAPosition.getZ() << std::endl;

	// Calculamos si se ha salido del tablero, para anotar punto
	// Calculamos si ha chocado con el mazo del usuario o del contrincante
	if (puckPosition.distance(malletAPosition) < collisionDistance || puckPosition.distance(malletBPosition) < collisionDistance)
	{
		std::cout << "salta" << std::endl;
	}
	// Calculamos si ha chocado con el tablero
	else
	{
		// Si choca contra un lateral
		if (puckPosition.getX() < -widthLimit) { this->puck->reverseDirectionX(); }
		if (puckPosition.getX() > widthLimit) { this->puck->reverseDirectionX(); }
		// Si choca contra el fondo y fuera de la porteria
		if (puckPosition.getZ() < -depthLimit && puckPosition.getX() < -(widthLimit - (goalSize / 2))) { this->puck->reverseDirectionY(); }
		if (puckPosition.getZ() > -depthLimit && puckPosition.getX() > (widthLimit - (goalSize / 2))) { this->puck->reverseDirectionY(); }
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
}
