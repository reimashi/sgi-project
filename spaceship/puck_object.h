#pragma once
#include "./engine/core/object3d.h"
#include "engine/types/vector2d.h"

using namespace Engine;

class PuckObject : public Core::Object3D
{
private:
	Types::Vector2D direction;

public:
	PuckObject();
	~PuckObject();

	void reverseDirectionX();
	void reverseDirectionY();
};

