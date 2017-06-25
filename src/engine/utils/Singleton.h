#pragma once

namespace Engine {
	namespace Utils {
		/**
		* \brief Clase auxiliar para crear clases con el patrón Singleton
		*/
		template <class T>
		class Singleton
		{
		public:
			static T& getInstance()
			{
				static T instance;
				return instance;
			}
		};
	}
}