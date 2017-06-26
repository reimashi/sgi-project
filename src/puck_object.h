#pragma once
#include "engine/engine.h"

using namespace Engine;

/**
* \brief Clase que representa el puck, la ficha con la que se juega
*/
class PuckObject : public Core::MovableObject3D
{
public:
	PuckObject();
	~PuckObject();
};

