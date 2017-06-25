#include "mallet_object.h"
#include "engine/utils/obj_loader.h"

MalletObject::MalletObject() : Object3D(Utils::OBJLoader::Load(".\\resources\\models\\mallet_model.obj"), nullptr)
{
	this->scale(0.1);
	this->setCollisionRadius(0.65);
	this->setPosition(Types::Point3D(0, -2, 0));
}


MalletObject::~MalletObject()
{
}
