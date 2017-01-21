#pragma once

#include "engine\engine.h"
#include "mallet_object.h"
#include "table_object.h"
#include "puck_object.h"

using namespace Engine;

class GameScene : public Core::Scene
{
private:
	TableObject* table;
	PuckObject* puck;
	MalletObject* mallet;

public:
	GameScene();
	~GameScene();

	void init() override;
	void loop() override;

	static void resolveCollision(PuckObject* puck, MalletObject* mallet);
};

