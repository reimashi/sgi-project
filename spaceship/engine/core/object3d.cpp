#include "object3d.h"

namespace Engine {
	namespace Core {
		Object3D::Object3D(Geometry geom) : visible(true), geometry(geom)
		{
		}

		Object3D::~Object3D()
		{
		}

		void Object3D::setVisibility(bool show) {
			this->visible = show;
		}

		bool Object3D::isVisible() {
			return this->visible;
		}

		void Object3D::draw() {

			glPushMatrix();
			
			Types::Point3D rot = this->getNormalizedRotation();
			Types::Point3D pos = this->getNormalizedPosition();
			Types::Point3D parentPos = this->getHeadParentPosition();

			std::cout << "Trasladando " << parentPos.getX() << " - " << parentPos.getY() << " - " << parentPos.getZ() << std::endl;
			glTranslatef(parentPos.getX(), parentPos.getY(), parentPos.getZ());

			std::cout << "Rotando " << rot.getX() << " - " << rot.getY() << " - " << rot.getZ() << std::endl;
			if (rot.getX() != 0.0) glRotatef(rot.getX(), 1, 0, 0);
			if (rot.getY() != 0.0) glRotatef(rot.getY(), 0, 1, 0);
			if (rot.getZ() != 0.0) glRotatef(rot.getZ(), 0, 0, 1);

			std::cout << "Trasladando con " << this->position.getX() << " - " << this->position.getY() << " - " << this->position.getZ() << std::endl;
			glTranslatef(pos.getX(), pos.getY(), pos.getZ());

			glBegin(GL_LINE_STRIP);
			for (std::list<Types::Point3D>::iterator it = this->geometry.vertices.begin(); it != this->geometry.vertices.end(); ++it) {
				glVertex3f((*it).getX(), (*it).getY(), (*it).getZ());
			}
			glEnd();

			glPopMatrix();

		}

		/*void Object3D::compile()
		{
			if (!this->glCompiled) {
				if (this->glListPtr != 0) {
					glDeleteLists(this->glListPtr, 1);
				}

				glNewList(this->glListPtr, GL_COMPILE);
				glPushMatrix();
				
				for (std::vector<Types::Point3D>::iterator it = this->vertex.begin(); it != this->vertex.end(); ++it) {
					glVertex3f(it->getX(), it->getY(), it->getZ());
				}

				glPopMatrix();
				glEndList();
			}
		}*/
	}
}