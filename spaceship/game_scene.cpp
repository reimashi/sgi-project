#include "game_scene.h"

GameScene::GameScene() : Core::Scene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	this->mallet = new MalletObject();
	this->addObject(this->mallet);
}

void GameScene::loop()
{
	std::cout << "Vamos a comprobar" << std::endl;
	if (this->controls->isKeyPressed(IO::ControlKey::LEFT))
	{
		std::cout << "Entra izquierda" << std::endl;
		this->mallet->rotate(0, -5, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::RIGHT))
	{
		std::cout << "Entra derecha" << std::endl;
		this->mallet->rotate(0, 5, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::UP))
	{
		std::cout << "Entra derecha" << std::endl;
		this->mallet->rotate(5, 0, 0);
	}
	else if (this->controls->isKeyPressed(IO::ControlKey::DOWN))
	{
		std::cout << "Entra derecha" << std::endl;
		this->mallet->rotate(5, 0, 0);
	}
}
