#include "logger.h"

namespace Engine {
	namespace Utils {
		int Logger::level = Logger::L_WARN;
		std::map<std::string, Logger> Logger::loggerInstances;

		Logger::Logger(std::string logName)
		{
			this->name = logName;
		}

		Logger::~Logger()
		{
		}

		Logger* Logger::getLogger(std::string name) {
			std::map<std::string, Logger>::iterator it = Logger::loggerInstances.find(name);

			if (it == Logger::loggerInstances.end())
			{
				Logger nlog = Logger(name);
				Logger::loggerInstances[name] = nlog;
				return &Logger::loggerInstances[name];
			}
			else {
				return &it->second;
			}
		}

		void Logger::log(int level, std::string levelName, std::string fn, std::string message) {
			if (Logger::level <= level) {
				if (fn.length() == 0) { fn = this->name; }
				time_t t = time(0);
				struct tm now;
				localtime_s(&now, &t);
				std::cout <<
					std::setfill('0') << std::setw(2) << now.tm_mday << '-' << std::setfill('0') << std::setw(2) << (now.tm_mon + 1) << '-' << (now.tm_year + 1900) << " " <<
					std::setfill('0') << std::setw(2) << now.tm_hour << ':' << std::setfill('0') << std::setw(2) << now.tm_min << ':' << std::setfill('0') << std::setw(2) << now.tm_sec << " " <<
					levelName << " " << fn << " - " << message << std::endl;
			}
		}

		void Logger::setLevel(int level) {
			Logger::level = level;
		}

		void Logger::trace(std::string message) { this->trace("", message); }
		void Logger::debug(std::string message) { this->debug("", message); }
		void Logger::info(std::string message) { this->info("", message); }
		void Logger::warn(std::string message) { this->warn("", message); }
		void Logger::error(std::string message) { this->error("", message); }
		void Logger::fatal(std::string message) { this->fatal("", message); }

		void Logger::trace(std::string fn, std::string message) { this->log(Logger::L_TRACE, "TRACE", fn, message); }
		void Logger::debug(std::string fn, std::string message) { this->log(Logger::L_DEBUG, "DEBUG", fn, message); }
		void Logger::info(std::string fn, std::string message) { this->log(Logger::L_INFO, "INFO ", fn, message); }
		void Logger::warn(std::string fn, std::string message) { this->log(Logger::L_WARN, "WARN ", fn, message); }
		void Logger::error(std::string fn, std::string message) { this->log(Logger::L_ERROR, "ERROR", fn, message); }
		void Logger::fatal(std::string fn, std::string message) { this->log(Logger::L_FATAL, "FATAL", fn, message); }
	}
}