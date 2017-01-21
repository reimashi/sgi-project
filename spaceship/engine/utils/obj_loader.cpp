#include "obj_loader.h"
#include <fstream>
#include <iostream>
#include <GL/glut.h>
#include <sstream>


namespace Engine {
	namespace Utils {

		OBJLoader::OBJLoader()
		{
		}


		OBJLoader::~OBJLoader()
		{
		}

		// Function extracted from Wikibooks
		Core::Mesh OBJLoader::Load(std::string path)
		{
			Core::Mesh toret;

			std::ifstream inFile(path, std::ios::in | std::ios::binary);

			if (!inFile)
			{
				std::cerr << "Cannot open " << path << std::endl;
			}

			std::string line;
			while (getline(inFile, line))
			{
				// Carga de vertices
				if (line.substr(0, 2) == "v ")
				{
					std::istringstream s(line.substr(2));
					Types::Point3D v;
					GLfloat x, y, z;
					s >> x; s >> y; s >> z;
					toret.vertices.push_back(Types::Point3D(x, y, z));
				}
				// Carga de caras
				else if (line.substr(0, 2) == "f ")
				{
					std::istringstream s(line.substr(2));
					GLushort a, b, c;
					s >> a; s >> b; s >> c;
					a--; b--; c--;
					toret.faces.push_back(Types::Face3P(
						toret.vertices[a],
						toret.vertices[b],
						toret.vertices[c],
						Types::Vector3D()
					));
					elements.push_back(a); elements.push_back(b); elements.push_back(c);
				}
				else if (line[0] == '#')
				{
					/* ignoring this line */
				}
				else
				{
					/* ignoring this line */
				}
			}
		}
	}
}
