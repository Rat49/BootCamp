#pragma once
#include  <iostream>
#include <stdarg.h>
#include <fstream>
#include <sstream>
#include <ctime>
enum LogLevel {
	FATAL, ERROR, WARNING, INFO, DEBUG
};
class OutputTarget {
	virtual void write(char *buffer) = 0;
};

class FileTarget : public OutputTarget {
private:
	std::ofstream _stream;
public:
	FileTarget(std::string path) {
		_stream.open(path, std::ofstream::app);
	}
	void write(char *buffer) {
		std::cout << buffer << std::endl;
	}
};

class CmdTarget : public OutputTarget {
private:
	std::ofstream _stream;
public:
	void write(char *buffer) {
		_stream << buffer << std::endl;
	}
};

class Logger final {
private:
	std::ostringstream _os;
	std::ostringstream& GetStaringInfo(LogLevel level)
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		_os << "- " << newtime.tm_hour << ":" << newtime.tm_min << ":" << newtime.tm_sec;
		_os << " " << std::to_string(level) << ": ";
		return _os;
	}
public:
	void warning(const char* msg, ...) {

		GetStaringInfo(LogLevel::logWARNING) << msg << std::endl;
		std::cout << os.str();
			const char *s;
		::va_list args;
		va_start(args, msg);
		std::size_t constexpr max_buffer_size = 256;
		char buffer[max_buffer_size];
		//::strncpy(buffer, fatal_error_prefix, max_buffer_size);
		std::size_t const prefix_len = std::strlen(buffer);
		vsnprintf(buffer, max_buffer_size, msg, args);
		va_end(args);
		//throw std::runtime_error(buffer);
//		printf("nSize: %d, buff: %ls\n", 8, buffer);
		std::cout << buffer << std::endl;
		os << std::endl;

		FileTarget *ft = new FileTarget("application.log");
		ft->write(buffer);
		CmdTarget *cmdT = new CmdTarget();
		cmdT->write(buffer);
		
		//std::ofstream fout("application.log");
//		fout.write((char *)buffer, sizeof(buffer));
	}
};