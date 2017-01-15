#include "mesh.h"

namespace Engine {
	namespace Core {
		uint64_t Mesh::idIndex = 0;

		Mesh::Mesh()
		{
			this->id = idIndex++;
		}


		Mesh::~Mesh()
		{
		}

		uint64_t Mesh::getId() const {
			return this->id;
		}

		void Mesh::addVertex(Types::Point3D point) {
			this->vertices.push_back(point);
		}

		Mesh Mesh::getCube(float_t size) {
			return geoCuboSize(size);
		}
	}
}