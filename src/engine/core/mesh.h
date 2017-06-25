#pragma once

#include <vector>

#include "../types/point3d.h"
#include "../types/face3p.h"

namespace Engine {
	namespace Core {
		/**
		* \brief Representación geometrica de un objeto
		*/
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

			/**
			* \brief Lista de vertices del objeto geometrico.
			*/
			std::vector <Types::Point3D> vertices;
			
			/**
			* \brief Lista de caras del objeto geometrico.
			*/
			std::vector <Types::Face3P> faces;


			/**
			* \brief Obtiene el ID del mesh.
			* \return ID unico del mesh.
			*/
			uint64_t getId() const;

			/**
			* \brief Genera una forma geometrica con forma de cubo.
			* \param size Tamaño de lado
			* \return Representación geometrica.
			*/
			static Mesh getCube(float_t size);

			/**
			* \brief Genera una forma geometrica con forma de rectangulo.
			* \param width Tamaño del lado a lo ancho.
			* \param height Tamaño del lado a lo alto.
			* \return Representación geometrica.
			*/
			static Mesh Mesh::getRectangle(float_t width, float_t height);
		};

	}
}
