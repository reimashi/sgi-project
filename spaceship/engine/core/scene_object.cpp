#include "scene_object.h"

namespace Engine {
	namespace Core {
		Utils::Logger* SceneObject::logger = Utils::Logger::getLogger("Engine::Core::SceneObject");

		SceneObject::SceneObject() : visible(true), position(0, 0, 0), rotation(0, 0, 0)
		{
		}


		SceneObject::~SceneObject()
		{
		}

		void SceneObject::internalDraw() {
			if (this->isVisible()) {
				this->draw();

				for (std::list<SceneObject*>::iterator it = this->childs.begin(); it != this->childs.end(); ++it) {
					(*it)->internalDraw();
				}
			}
		}

		void SceneObject::draw() {
			logger->error(__FUNCTION__, "Todas las clases heredadas de SceneObject deben sobreescribir el metodo draw().");
		}

		void SceneObject::setParent(SceneObject* parentPtr) {
			this->parent = parentPtr;
		}

		void SceneObject::rotate(float_t x, float_t y, float_t z) {
			float_t ix = this->rotation.getX() + x;
			float_t iy = this->rotation.getY() + y;
			float_t iz = this->rotation.getZ() + z;

			if (ix > 360) ix -= 360; else if (ix < 0) ix += 360;
			if (iy > 360) iy -= 360; else if (iy < 0) ix += 360;
			if (iz > 360) iz -= 360; else if (iz < 0) ix += 360;

			this->rotation.setX(ix);
			this->rotation.setY(iy);
			this->rotation.setZ(iz);
		}

		void SceneObject::translate(float_t x, float_t y, float_t z) {
			this->position.setX(this->position.getX() + x);
			this->position.setY(this->position.getY() + y);
			this->position.setZ(this->position.getZ() + z);
		}

		void SceneObject::setPosition(Types::Point3D pos)
		{
			this->position.setX(pos.getX());
			this->position.setY(pos.getY());
			this->position.setZ(pos.getZ());
		}

		void SceneObject::addChild(SceneObject* child) {
			if (!(std::find(this->childs.begin(), this->childs.end(), child) != this->childs.end())) {
				this->childs.push_back(child);
				child->setParent(this);
			}
		}

		void SceneObject::removeChild(SceneObject* child) {
			if ((std::find(this->childs.begin(), this->childs.end(), child) != this->childs.end())) {
				this->childs.remove(child);
				child->setParent(NULL);
			}
		}

		SceneObject* SceneObject::getParent() const {
			return this->parent;
		}

		Types::Point3D SceneObject::getNormalizedPosition() const
		{
			Types::Point3D pos = *this->position.clone();

			if (this->parent != nullptr)
			{
				pos.setX(pos.getX() + this->parent->position.getX());
				pos.setY(pos.getY() + this->parent->position.getY());
				pos.setZ(pos.getZ() + this->parent->position.getZ());
			}

			return pos;
		}

		Types::Point3D SceneObject::getNormalizedRotation() const
		{
			float_t ix = this->rotation.getX();
			float_t iy = this->rotation.getY();
			float_t iz = this->rotation.getZ();

			if (this->parent != nullptr)
			{
				ix += this->parent->rotation.getX();
				iy += this->parent->rotation.getY();
				iz += this->parent->rotation.getZ();
			}

			if (ix > 360) ix -= 360; else if (ix < 0) ix += 360;
			if (iy > 360) iy -= 360; else if (iy < 0) ix += 360;
			if (iz > 360) iz -= 360; else if (iz < 0) ix += 360;

			return Types::Point3D(ix, iy, iz);
		}

		Types::Point3D SceneObject::getHeadParentPosition() const
		{
			if (this->parent == nullptr) return *(this->position.clone());
			else return this->parent->getHeadParentPosition();
		}

		void SceneObject::setVisibility(bool show) {
			this->visible = show;
		}

		bool SceneObject::isVisible() {
			return this->visible;
		}
	}
}