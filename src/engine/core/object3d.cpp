#include "object3d.h"
#include <typeinfo>
#include "../io/tga_image.h"
#include "../materials/tga_material.h"

namespace Engine {
	namespace Core {
		Object3D::Object3D(Mesh geom, Material* mat) : geometry(geom)
		{
			if (mat == nullptr) this->material = new Materials::ColorMaterial(1.0, 1.0, 1.0);
			this->openglPtr = glGenLists(1);
		}

		Object3D::~Object3D()
		{
		}

		void Object3D::internalDraw(bool inhibit_draw) {
			SceneObject::internalDraw(true);

			if (this->recompile) {
				glNewList(this->openglPtr, GL_COMPILE_AND_EXECUTE);
				glPushMatrix();

				Types::Point3D rot = this->getNormalizedRotation();
				Types::Point3D pos = this->getNormalizedPosition();
				Types::Point3D parentPos = this->getHeadParentPosition();

				glScalef(this->scaleFactor, this->scaleFactor, this->scaleFactor);

				// Traslado a la posicion del padre o a 0,0,0 por defecto
				glTranslatef(parentPos.getX(), parentPos.getY(), parentPos.getZ());

				// Rotando el modelo
				if (rot.getX() != 0.0) glRotatef(rot.getX(), 1, 0, 0);
				if (rot.getY() != 0.0) glRotatef(rot.getY(), 0, 1, 0);
				if (rot.getZ() != 0.0) glRotatef(rot.getZ(), 0, 0, 1);

				// Traslado a la posicion del objeto
				glTranslatef(pos.getX(), pos.getY(), pos.getZ());

				glPushMatrix();
				this->draw();
				glPopMatrix();

				glPopMatrix();
				glEndList();

				this->recompile = false;
			}
			else
			{
				glCallList(this->openglPtr);
			}
		}

		/**
		 * \brief Ejecuta el dibujado del objeto 3D
		 * Método de dibujado por defecto para objetos 3D en el que solo se pintan las caras.
		 */
		void Object3D::draw() {
			this->material->preDraw();

			glBegin(GL_TRIANGLES);
			for (std::vector<Types::Face3P>::iterator it = this->geometry.faces.begin(); it != this->geometry.faces.end(); ++it) {
				glVertex3f((*it).getPointA().getX(), (*it).getPointA().getY(), (*it).getPointA().getZ());
				glVertex3f((*it).getPointB().getX(), (*it).getPointB().getY(), (*it).getPointB().getZ());
				glVertex3f((*it).getPointC().getX(), (*it).getPointC().getY(), (*it).getPointC().getZ());
			}
			glEnd();

			this->material->postDraw();
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
