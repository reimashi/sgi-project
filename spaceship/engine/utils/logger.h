#pragma once

#include <map>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

namespace Engine {
	namespace Utils {
		class Logger
		{
		private:
			static std::map<std::string, Logger> loggerInstances;
			static int level;

			std::string name;

			void log(int level, std::string levelName, std::string fn, std::string message);

		public:
			Logger(std::string logName = "");
			~Logger();

			static const int L_ALL = 0;
			static const int L_TRACE = 10;
			static const int L_DEBUG = 20;
			static const int L_INFO = 30;
			static const int L_WARN = 40;
			static const int L_ERROR = 50;
			static const int L_FATAL = 60;
			static const int L_OFF = 100;

			static Logger* getLogger(std::string name);
			static void setLevel(int level);

			void trace(std::string message);
			void debug(std::string message);
			void info(std::string message);
			void warn(std::string message);
			void error(std::string message);
			void fatal(std::string message);

			void trace(std::string fn, std::string message);
			void debug(std::string fn, std::string message);
			void info(std::string fn, std::string message);
			void warn(std::string fn, std::string message);
			void error(std::string fn, std::string message);
			void fatal(std::string fn, std::string message);
		};
	}
}