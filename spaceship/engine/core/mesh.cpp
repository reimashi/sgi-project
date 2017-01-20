#include "mesh.h"
#include "../types/vector3d.h"
#include "../../opengl/glig.h"

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

		void Mesh::addFace(Types::Face3P face) {
			this->faces.push_back(face);
		}

		Mesh Mesh::getCube(float_t size) {
			Mesh pl;
			float_t csize = size / 2;

			Types::Point3D coords[] = {
				// Cubierta superior
				Types::Point3D(-csize, csize, -csize),
				Types::Point3D(csize, csize, -csize),
				Types::Point3D(csize, csize, csize),
				Types::Point3D(-csize, csize, csize),
				// Cubierta inferior
				Types::Point3D(-csize, -csize, -csize),
				Types::Point3D(csize, -csize, -csize),
				Types::Point3D(csize, -csize, csize),
				Types::Point3D(-csize, -csize, csize)
			};

			for (int i = 0; i < sizeof(coords); ++i)
			{
				pl.addVertex(coords[i]);
			}

			// Cubierta superior
			pl.addFace(Types::Face3P(coords[0], coords[1], coords[2], Types::Vector3D::yAxis()));
			pl.addFace(Types::Face3P(coords[0], coords[2], coords[3], Types::Vector3D::yAxis()));
			// Cubierta inferior
			pl.addFace(Types::Face3P(coords[7], coords[6], coords[5], -Types::Vector3D::zAxis()));
			pl.addFace(Types::Face3P(coords[4], coords[7], coords[5], -Types::Vector3D::zAxis()));
			// Cubierta trasera
			pl.addFace(Types::Face3P(coords[2], coords[1], coords[6], -Types::Vector3D::zAxis()));
			pl.addFace(Types::Face3P(coords[1], coords[5], coords[6], -Types::Vector3D::zAxis()));
			// Cubierta frontal
			pl.addFace(Types::Face3P(coords[0], coords[3], coords[4], Types::Vector3D::zAxis()));
			pl.addFace(Types::Face3P(coords[3], coords[7], coords[4], Types::Vector3D::zAxis()));
			// Cubierta izquierda
			pl.addFace(Types::Face3P(coords[1], coords[0], coords[5], -Types::Vector3D::xAxis()));
			pl.addFace(Types::Face3P(coords[0], coords[4], coords[5], -Types::Vector3D::xAxis()));
			// Cubierta derecha
			pl.addFace(Types::Face3P(coords[3], coords[2], coords[6], Types::Vector3D::xAxis()));
			pl.addFace(Types::Face3P(coords[3], coords[6], coords[7], Types::Vector3D::xAxis()));

			return pl;
		}

		Mesh Mesh::getRectangle(float_t width, float_t height) {
			Mesh pl;

			Types::Point3D coords[] = {
				Types::Point3D(-(width/2), 0, -(height/2)),
				Types::Point3D((width / 2), 0, -(height / 2)),
				Types::Point3D((width / 2), 0, (height / 2)),
				Types::Point3D(-(width / 2), 0, (height / 2))
			};

			for (int i = 0; i < sizeof(coords); ++i)
			{
				pl.addVertex(coords[i]);
			}

			pl.addFace(Types::Face3P(coords[0], coords[1], coords[2], Types::Vector3D::yAxis()));
			pl.addFace(Types::Face3P(coords[0], coords[2], coords[3], Types::Vector3D::yAxis()));

			return pl;
		}
	}
}