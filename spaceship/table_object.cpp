#include "table_object.h"
#include "engine/materials/tga_material.h"

TableObject::TableObject() : Object3D(Core::Mesh::getRectangle(1.22, 2.44))
{
	this->material = new Materials::ColorMaterial(0.3, 0.3, 0.3);
	//this->material = new Materials::TGAMaterial(IO::TGAImage::Load(".\\table.tga"));
}

TableObject::~TableObject()
{
}

void TableObject::draw() {
	std::cout << "Deberia dibujar un plano" << this->geometry.faces[0].getPointC().getX() << std::endl;
	this->material->preDraw();

	glBegin(GL_TRIANGLES);

	//glTexCoord2d(0, 0);
	glVertex3f(this->geometry.faces[0].getPointA().getX(), this->geometry.faces[0].getPointA().getY(), this->geometry.faces[0].getPointA().getZ());
	//glTexCoord2d(0, 1);
	glVertex3f(this->geometry.faces[0].getPointB().getX(), this->geometry.faces[0].getPointB().getY(), this->geometry.faces[0].getPointB().getZ());
	//glTexCoord2d(1, 0);
	glVertex3f(this->geometry.faces[0].getPointC().getX(), this->geometry.faces[0].getPointC().getY(), this->geometry.faces[0].getPointC().getZ());
	//glTexCoord2d(1, 1);
	glVertex3f(this->geometry.faces[1].getPointC().getX(), this->geometry.faces[1].getPointC().getY(), this->geometry.faces[1].getPointC().getZ());

	glEnd();

	this->material->postDraw();
}