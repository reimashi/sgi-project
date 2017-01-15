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

			std::cout << "Rotando " << this->rotation.getX() << " - " << this->rotation.getY() << " - " << this->rotation.getZ() << std::endl;
			if (this->rotation.getX() != 0.0) glRotated(this->rotation.getX(), 1, 0, 0);
			if (this->rotation.getY() != 0.0) glRotated(this->rotation.getY(), 0, 1, 0);
			if (this->rotation.getZ() != 0.0) glRotated(this->rotation.getZ(), 0, 0, 1);

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