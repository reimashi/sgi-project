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
	MalletObject* two = new MalletObject();
	two->translate(0.5, 0.5, 0);
	this->mallet->addChild(two);
	this->mallet->translate(0.2, 0.2, 0.2);
	this->addObject(this->mallet);

	this->camera->setPosition(Types::Point3D(0, 1, -3));
}

void GameScene::loop()
{
	if (this->controls->isKeyPressed(IO::ControlKey::LEFT))
	{
		this->mallet->rotate(0, -5, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::RIGHT))
	{
		this->mallet->rotate(0, 5, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::UP))
	{
		this->mallet->rotate(5, 0, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::DOWN))
	{
		this->mallet->rotate(-5, 0, 0);
		this->camera->translate(0, 0, -0.2);
	}
}
