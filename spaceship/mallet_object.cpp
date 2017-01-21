#include "mallet_object.h"
#include "engine/utils/obj_loader.h"

MalletObject::MalletObject() : Object3D(Utils::OBJLoader::Load(".\\mallet_model.obj"))
{
	this->scale(0.1);
}


MalletObject::~MalletObject()
{
}
