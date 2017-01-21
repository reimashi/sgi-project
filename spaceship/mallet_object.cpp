#include "mallet_object.h"
#include "engine/utils/obj_loader.h"

MalletObject::MalletObject() : Object3D(Utils::OBJLoader::Load(".\\punch_model.obj"))
{
}


MalletObject::~MalletObject()
{
}
