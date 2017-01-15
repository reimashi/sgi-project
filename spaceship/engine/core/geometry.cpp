#include "geometry.h"

namespace Engine {
	namespace Core {
		uint64_t Geometry::idIndex = 0;

		Geometry::Geometry()
		{
			this->id = idIndex++;
		}


		Geometry::~Geometry()
		{
		}

		uint64_t Geometry::getId() const {
			return this->id;
		}

		void Geometry::addVertex(Types::Point3D point) {
			this->vertices.push_back(point);
		}

		Geometry Geometry::getCube(float_t size) {
			Geometry cube;
			cube.vertices = vertexCuboSize(size); // FIXME: Comprobar bien
			return cube;
		}
	}
}