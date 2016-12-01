#pragma once

#include <string>
#include <cstdbool>
#include "../types/dimension2d.h"

namespace Engine {
	namespace Core {
		class Engine
		{
		public:
			Engine(Types::Dimension2D size);
			~Engine();

			bool run();
			void setTitle(std::string title);
		};
	}
}