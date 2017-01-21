#pragma once

#include <vector>

#include "../types/point3d.h"
#include "../types/face3p.h"

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

			void addVertex(Types::Point3D vertex);
			void addFace(Types::Face3P face);

		public:
			Mesh();
			~Mesh();

			std::vector <Types::Point3D> vertices;
			std::vector <Types::Face3P> faces;

			uint64_t getId() const;

			static Mesh getCube(float_t size);
			static Mesh Mesh::getRectangle(float_t width, float_t height);
		};

	}
}
