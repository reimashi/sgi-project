#pragma once

namespace Engine {
	namespace Utils {
		template <class T>
		class Singleton
		{
		public:
			static T& getInstance()
			{
				static T instance;
				return instance;
			}

			// No implementar. Evita copias de instancias singleton.
			/*T(T const&);
			void operator=(T const&);*/
		};
	}
}