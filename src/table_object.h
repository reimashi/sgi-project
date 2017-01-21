#pragma once
#include "engine/core/object3d.h"

using namespace Engine;

class TableObject : public Core::Object3D
{
protected:
	void draw() override;
public:
	TableObject();
	~TableObject();
};

