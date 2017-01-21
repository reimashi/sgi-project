#include "table_object.h"
#include "engine/materials/tga_material.h"

TableObject::TableObject() : Object3D(Core::Mesh::getRectangle(1.22, 2.44))
{
	//this->material = new Materials::ColorMaterial(0.3, 0.3, 0.3);
	this->material = new Materials::TGAMaterial(IO::TGAImage::Load(".\\resources\\textures\\table.tga"));
	this->scale(1.5);
}

TableObject::~TableObject()
{
}

void TableObject::draw() {
	std::cout << "Deberia dibujar un plano" << this->geometry.faces[0].getPointC().getX() << std::endl;
	this->material->preDraw();

	glBegin(GL_QUADS);

	glTexCoord2d(1, 1);
	glVertex3f(this->geometry.vertices[0].getX(), this->geometry.vertices[0].getY(), this->geometry.vertices[0].getZ());
	glTexCoord2d(1, 0);
	glVertex3f(this->geometry.vertices[1].getX(), this->geometry.vertices[1].getY(), this->geometry.vertices[1].getZ());
	glTexCoord2d(0, 1);
	glVertex3f(this->geometry.vertices[2].getX(), this->geometry.vertices[2].getY(), this->geometry.vertices[2].getZ());
	glTexCoord2d(0, 0);
	glVertex3f(this->geometry.vertices[3].getX(), this->geometry.vertices[3].getY(), this->geometry.vertices[3].getZ());

	glEnd();

	this->material->postDraw();
}