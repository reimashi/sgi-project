#pragma once
#include <windows.h>

namespace Engine {
	namespace Time {
		/**
		* \brief Contador de tiempo.
		*/
		class Counter
		{
		private:
			double frequency = 0.0;
			__int64 startFlag = 0;

		public:
			Counter();
			~Counter();

			/**
			* \brief Reinicia el contador de tiempo.
			*/
			void reset();

			/**
			* \brief Obtiene el tiempo transcurrido desde la inicializacion o el ultimo reset.
			* \return Tiempo en milisegundos.
			*/
			long int get() const;
		};
	}
}