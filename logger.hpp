//
// Created by Alexandr on 2/7/2023.
//

#ifndef GMA2PATCH_LOGGER_HPP
#define GMA2PATCH_LOGGER_HPP

#include <iostream>
#include <array>

class logger {

public:
	enum log_level {
		TRACE_LEVEL,
		DEBUG_LEVEL,
		INFO_LEVEL,
		WARNING_LEVEL,
		ERROR_LEVEL
	};
	static void log(log_level, const char* source, const std::string& message);
	static void log(log_level, const char* source, const std::wstring& message);
	static void log(const char* source, const std::string& message);
	static void log(const char* source, const std::wstring& message);
	static void simple_out(const std::string& message);
private:
	static std::array<std::string, sizeof(log_level)+1u> level_string;
};


#define STR_(x) #x
#define STR(x) STR_(x)
#define LOG_SIMPLE_OUT(message) logger::simple_out(message)
#define LOG_TRACE(message) logger::log(logger::TRACE_LEVEL, __FILE__ ":" STR(__LINE__), message)
#define LOG_INFO(message) logger::log(logger::INFO_LEVEL, __FILE_NAME__ ":" STR(__LINE__), message)
#define LOG_WARNING(message) logger::log(logger::WARNING_LEVEL, __FILE_NAME__ ":" STR(__LINE__), message)
#define LOG_ERROR(message) logger::log(logger::ERROR_LEVEL, __FILE_NAME__ ":" STR(__LINE__), message)

#endif //GMA2PATCH_LOGGER_HPP
