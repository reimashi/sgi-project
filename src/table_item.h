#pragma once
#include "engine/core/object3d.h"
#include "engine/types/vector2d.h"

class TableItem : public Engine::Core::Object3D
{
protected:
	Engine::Types::Vector2D velocity;
	float_t collisionRadius = 0;

public:
	TableItem(Engine::Core::Mesh geom = Engine::Core::Mesh(), Engine::Core::Material* mat = nullptr);
	~TableItem();

	void reverseDirectionX();
	void reverseDirectionY();

	Engine::Types::Point2D getPosition2D() const;
	void setPosition2D(Engine::Types::Point2D);

	Engine::Types::Vector2D getVelocity() const;
	void setVelocity(Engine::Types::Vector2D vel);

	float_t getCollisionRadius() const;

	void updatePosition(long ms);
};

