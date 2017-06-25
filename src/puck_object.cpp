#include "puck_object.h"
#include "engine/utils/obj_loader.h"

PuckObject::PuckObject() : MovableObject3D(Utils::OBJLoader::Load(".\\resources\\models\\puck_model.obj"), nullptr)
{
	this->material = new Materials::ColorMaterial(0.5, 0.2, 0.2);
	this->scale(0.1);
	this->setVelocity(Types::Vector3D(6.0, 0, 4));
	this->setFriction(0.95);
	this->setCollisionRadius(0.1);
	this->setPosition2D(Types::Point2D(0, -2));
}


PuckObject::~PuckObject()
{
}