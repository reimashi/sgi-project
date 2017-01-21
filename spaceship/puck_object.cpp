#include "puck_object.h"
#include "engine/utils/obj_loader.h"

PuckObject::PuckObject() : Object3D(Utils::OBJLoader::Load(".\\punch_model.obj")), direction(0,0)
{
	this->material = new Materials::ColorMaterial(0.5, 0.2, 0.2);
	this->scale(0.1);
}


PuckObject::~PuckObject()
{
}

void PuckObject::reverseDirectionX()
{
	this->direction = Types::Vector2D(-this->direction.getPoint().getX(), this->direction.getPoint().getY());
}

void PuckObject::reverseDirectionY()
{
	this->direction = Types::Vector2D(this->direction.getPoint().getX(), +this->direction.getPoint().getY());
}
