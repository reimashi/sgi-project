#include "table_object.h"
#include "engine/materials/tga_material.h"

TableObject::TableObject() : Object3D(Core::Mesh::getRectangle(1.22, 2.44))
{
	this->material = new Materials::TGAMaterial(IO::TGAImage::Load(".\\resources\\textures\\table.tga"));
	this->scale(1.5);
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