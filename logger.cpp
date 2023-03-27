//
// Created by Alexandr on 2/7/2023.
//
#include <sstream>
#include <chrono>
#include <iomanip>

#include "logger.hpp"

std::array<std::string, sizeof(logger::log_level)+1u> logger::level_string = {
		"TRACE", "DEBUG", "INFO", "WARNING", "ERROR"
};

void logger::log(logger::log_level level, const char* source, const std::string& message)
{
	std::stringstream formatted;
	formatted << "[" << level_string[level] << "]";
	std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm tm = *std::gmtime(&tt); //GMT (UTC)
	formatted << " - " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
#ifdef DEBUG
	formatted << " - " << source;
#endif
	formatted << " - " << message;
	std::cout << formatted.str() << std::endl;
}
void logger::log(logger::log_level level, const char* source, const std::wstring& message)
{
	std::wstringstream formatted;
	formatted << L"[" << level_string[level].c_str() << L"]";
	std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm tm = *std::gmtime(&tt); //GMT (UTC)
	formatted << " - " << std::put_time(&tm, L"%Y-%m-%d %H:%M:%S");
#ifdef DEBUG
	formatted << " - " << source;
#endif
	formatted << " - " << message;
	std::wcout << formatted.str() << std::endl;
}
void logger::log(const char* source, const std::string& message)
{
	log(log_level::DEBUG_LEVEL, source, message);
}
void logger::log(const char* source, const std::wstring& message)
{
	log(log_level::DEBUG_LEVEL, source, message);
}
void logger::simple_out(const std::string& message)
{
	std::cout << message << std::endl;
}
