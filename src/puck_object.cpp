#include "puck_object.h"
#include "engine/utils/obj_loader.h"

PuckObject::PuckObject() : TableItem(Utils::OBJLoader::Load(".\\resources\\models\\puck_model.obj"))
{
	this->material = new Materials::ColorMaterial(0.5, 0.2, 0.2);
	this->scale(0.1);
	this->velocity = Types::Vector2D(10, 0.5);
	this->collisionRadius = 0.5;
	this->setPosition2D(Types::Point2D(0, -2));
}


PuckObject::~PuckObject()
{
}