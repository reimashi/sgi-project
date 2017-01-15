#pragma once

#include "engine\engine.h"
#include "mallet_object.h"

using namespace Engine;

class GameScene : public Core::Scene
{
private:
	MalletObject* mallet;

public:
	GameScene();
	~GameScene();

	void init();
	void loop();
};

