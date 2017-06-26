#include "table_object.h"
#include "engine/materials/tga_material.h"

TableObject::TableObject() : Object3D(Core::Mesh::getRectangle(1, 2)), size(Types::Dimension2D(4.6, 9.2))
{
	this->material = new Materials::TGAMaterial(IO::TGAImage::Load(".\\resources\\textures\\table.tga"));
	this->scale(2);
}

TableObject::~TableObject()
{
}

/// TODO: No me ha dado tiempo de crear una capa de abstracción para dibujar objetos complejos con textura, pero se
/// puede solucionar temporalmente sobreescribiendo el metodo draw e implementandolo a mano.
void TableObject::draw() {
	this->material->preDraw();

	glBegin(GL_QUADS);

	glTexCoord2d(1, 1);
	glVertex3f(this->geometry.vertices[0].getX(), this->geometry.vertices[0].getY(), this->geometry.vertices[0].getZ());
	glTexCoord2d(1, 0);
	glVertex3f(this->geometry.vertices[1].getX(), this->geometry.vertices[1].getY(), this->geometry.vertices[1].getZ());
	glTexCoord2d(0, 0);
	glVertex3f(this->geometry.vertices[2].getX(), this->geometry.vertices[2].getY(), this->geometry.vertices[2].getZ());
	glTexCoord2d(0, 1);
	glVertex3f(this->geometry.vertices[3].getX(), this->geometry.vertices[3].getY(), this->geometry.vertices[3].getZ());

	glEnd();

	this->material->postDraw();
}

Types::Dimension2D TableObject::getSize() const {
	return this->size;
}

void TableObject::resolveCollision(Core::MovableObject3D* puck) {
	float_t widthLimit = this->getSize().getWidth();
	float_t depthLimit = this->getSize().getHeight();
	bool colision = true;

	while (colision) {
		float_t width_max_limit = widthLimit - puck->getCollisionRadius();
		float_t width_min_limit = -widthLimit + puck->getCollisionRadius();
		float_t depth_max_limit = depthLimit - puck->getCollisionRadius();
		float_t depth_min_limit = -depthLimit + puck->getCollisionRadius();

		// Si el puck se intenta salir por la derecha.
		if (puck->getPosition().getX() > width_max_limit)
		{
			float_t diff = width_max_limit - (puck->getPosition().getX() - width_max_limit); // Calculamos cuanto se "ha pasado"
			while (diff > widthLimit) diff -= widthLimit;
			puck->setPosition(Types::Point3D(diff, puck->getPosition().getY(), puck->getPosition().getZ()));	// Establecemos la nueva posicion restando lo que se ha pasado
			puck->setVelocity(Types::Vector3D::flipOverX(&puck->getVelocity())); // Cambiamos la dirección del movimiento sobre el eje correspondiente
			colision = true; // Activamos el flag de colision
		}
		// Colision por la izquierda
		else if (puck->getPosition().getX() < width_min_limit)
		{
			float_t diff = width_min_limit - (puck->getPosition().getX() - width_min_limit);
			while (diff < -widthLimit) diff += widthLimit;
			puck->setPosition(Types::Point3D(diff, puck->getPosition().getY(), puck->getPosition().getZ()));
			puck->setVelocity(Types::Vector3D::flipOverX(&puck->getVelocity()));
			colision = true;
		}
		// Colision por el fondo
		else if (puck->getPosition().getZ() > depth_max_limit)
		{
			float_t diff = depth_max_limit - (puck->getPosition().getZ() - depth_max_limit);
			while (diff > depthLimit) diff -= depthLimit;
			puck->setPosition(Types::Point3D(puck->getPosition().getX(), puck->getPosition().getY(), diff));
			puck->setVelocity(Types::Vector3D::flipOverZ(&puck->getVelocity()));
			colision = true;
		}
		// Colision por el frente
		else if (puck->getPosition().getZ() < depth_min_limit)
		{
			float_t diff = depth_min_limit - (puck->getPosition().getZ() - depth_min_limit);
			while (diff < -depthLimit) diff += depthLimit;
			puck->setPosition(Types::Point3D(puck->getPosition().getX(), puck->getPosition().getY(), diff));
			puck->setVelocity(Types::Vector3D::flipOverZ(&puck->getVelocity()));
			colision = true;
		}
		else {
			colision = false;
		}
	}
}