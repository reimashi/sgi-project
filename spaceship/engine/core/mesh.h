#pragma once

#include <vector>

#include "../types/point3d.h"
#include "../../opengl/glig.h"

namespace Engine {
	namespace Core {
		/// <summary>
		/// Representación geometrica de un objeto
		/// </summary>
		class Mesh
		{
			friend class Object3D;

		protected:
			static uint64_t idIndex;

			uint64_t id;
			std::vector <Types::Point3D> vertices;
			//std::list <std::list <Types::Point3D*>> *faces;

		public:
			Mesh();
			~Mesh();

			uint64_t getId() const;

			void addVertex(Types::Point3D vertex);

			static Mesh getCube(float_t size);
		};

	}
}