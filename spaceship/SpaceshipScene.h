#pragma once

#include "engine\engine.h"

using namespace Engine;

class SpaceshipScene : public Core::Scene
{
public:
	SpaceshipScene();
	~SpaceshipScene();

	void loop();
};

