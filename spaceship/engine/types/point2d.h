#pragma once

namespace Engine {
	namespace Types {
		class Point2D
		{
		protected:
			float x;
			float y;

		public:
			Point2D(float x, float y);
			~Point2D();

			float getX() const;
			void setX(float x);

			float getY() const;
			void setY(float x);
		};
	}
}