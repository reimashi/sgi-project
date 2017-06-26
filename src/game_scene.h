#pragma once

#include "engine\engine.h"
#include "mallet_object.h"
#include "table_object.h"
#include "puck_object.h"

using namespace Engine;

/**
* \brief Escena principal del juego
*/
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

	/**
	* \brief Clase que maneja las colisiones entre el mazo de juego y la ficha
	* \param puck Ficha del juego
	* \brief mallet Maza del jugador
	*/
	static void resolveCollision(PuckObject* puck, MalletObject* mallet);
};

