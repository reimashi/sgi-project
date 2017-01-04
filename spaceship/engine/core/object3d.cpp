#include "object3d.h"

namespace Engine {
	namespace Core {
		Object3D::Object3D() : position(0, 0, 0), rotation(0, 0, 0), visible(true)
		{
		}

		Object3D::~Object3D()
		{
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