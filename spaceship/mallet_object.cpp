#include "mallet_object.h"
#include "engine/utils/obj_loader.h"

MalletObject::MalletObject() : TableItem(Utils::OBJLoader::Load(".\\resources\\models\\mallet_model.obj"))
{
	this->scale(0.1);
	this->collisionRadius = 0.65;
}


MalletObject::~MalletObject()
{
}
