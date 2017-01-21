#pragma once
#include "scene_object.h"

namespace Engine {
	namespace Core {
		class Camera : public SceneObject
		{
			static const int32_t ORTHOGONAL = 1;
			static const int32_t PERSPECTIVE = 2;

		private:
			float_t farv = 500.0;
			int32_t mode = PERSPECTIVE;
			bool change = true;
			bool changePosition = true;
			Types::Point3D target;

		public:
			Camera();
			~Camera();

			void setFar(float_t value);
			float_t getFar() const;
			void setMode(int32_t value);
			void setTarget(Types::Point3D target);

			void draw() override;

			void rotate(float_t x, float_t y, float_t z) override;
			void translate(float_t x, float_t y, float_t z) override;
			void setPosition(Types::Point3D pos) override;
		};
	}
}
