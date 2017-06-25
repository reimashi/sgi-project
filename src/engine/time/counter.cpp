#include "counter.h"

namespace Engine {
	namespace Time {
		Counter::Counter()
		{
			this->reset();
		}

		Counter::~Counter()
		{
		}

		void Counter::reset() {
			LARGE_INTEGER li;
			QueryPerformanceFrequency(&li);

			this->frequency = double(li.QuadPart) / 1000.0;

			QueryPerformanceCounter(&li);
			this->startFlag = li.QuadPart;
		}

		long int Counter::get() const {
			LARGE_INTEGER li;
			QueryPerformanceCounter(&li);
			return long(double(li.QuadPart - this->startFlag) / this->frequency);
		}
	}
}