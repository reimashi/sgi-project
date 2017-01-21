#include "table_item.h"

TableItem::TableItem(Engine::Core::Mesh geom, Engine::Core::Material* mat) : Object3D(geom, mat), velocity(0, 0)
{
}


TableItem::~TableItem()
{
}

Engine::Types::Point2D TableItem::getPosition2D() const
{
	return Engine::Types::Point2D(this->getPosition().getX(), this->getPosition().getZ());
}

void TableItem::setPosition2D(Engine::Types::Point2D pos)
{
	this->setPosition(Engine::Types::Point3D(pos.getX(), this->position.getY(), pos.getY()));
}

Engine::Types::Vector2D TableItem::getVelocity() const
{
	return this->velocity.clone();
}

void TableItem::setVelocity(Engine::Types::Vector2D vel)
{
	this->velocity = vel;
}

void TableItem::reverseDirectionX()
{
	this->velocity = Engine::Types::Vector2D(-this->velocity.getPoint().getX(), this->velocity.getPoint().getY());
}

void TableItem::reverseDirectionY()
{
	this->velocity = Engine::Types::Vector2D(this->velocity.getPoint().getX(), +this->velocity.getPoint().getY());
}

void TableItem::updatePosition(long ms)
{
	this->translate(this->velocity.getPoint().getX(), 0, this->velocity.getPoint().getY());
	this->velocity = this->velocity * 0.98;
}

float_t TableItem::getCollisionRadius() const { return this->collisionRadius; }