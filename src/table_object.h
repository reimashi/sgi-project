#pragma once
#include "engine/engine.h"
#include "puck_object.h"

using namespace Engine;

/**
* \brief Clase que representa el tablero de juego.
*/
class TableObject : public Core::Object3D
{
private:
	Types::Dimension2D size;

protected:
	void draw() override;

public:
	TableObject();
	~TableObject();

	/**
	* \brief Obtiene el tamaño del tablero de juego.
	* \return Tamaño del tablero en el plano XZ.
	*/
	Types::Dimension2D getSize() const;

	/**
	* \brief Comprueba las colisiones de un objeto con los limites del tablero de juego.
	* \param p Objeto a comprobar.
	*/
	void resolveCollision(Core::MovableObject3D* p);
};

