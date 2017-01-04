#pragma once

#include <list>

#include "../types/point3d.h"
#include "../../opengl/glig.h"

namespace Engine {
	namespace Core {
		/// <summary>
		/// Representación geometrica de un objeto
		/// </summary>
		class Geometry
		{
		private:
			static uint64_t idIndex;

			uint64_t id;
			std::list <Types::Point3D> *vertices;
			//std::list <std::list <Types::Point3D*>> *faces;

		public:
			Geometry();
			~Geometry();

			uint64_t getId() const;

			void addVertex(Types::Point3D vertex);

			static Geometry getCube(float_t size);
		};

	}
}