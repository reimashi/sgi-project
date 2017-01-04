#pragma once

#include <list>
#include <gl/glut.h>

#include "./geometry.h"
#include "../types/point3d.h"

namespace Engine {
	namespace Core {
		class Object3D
		{
		public:
			Object3D();
			~Object3D();

			void draw();

			void rotate(float_t x, float_t y, float_t z);
			void translate(float_t x, float_t y, float_t z);
			void setVisibility(bool show);
			bool isVisible();

			void addChild(Object3D* child);
			void removeChild(Object3D* child);

		private:
			Geometry geometry;
			std::list<Object3D*> childs;
			Object3D* parent = NULL;

			GLuint glListPtr = 0;
			bool glCompiled = false;

			void compile();

			Types::Point3D rotation;
			Types::Point3D position;
			bool visible;

			void setParent(Object3D* parent);
		};
	}
}