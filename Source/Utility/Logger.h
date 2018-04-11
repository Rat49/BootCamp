#pragma once
#include  <iostream>
#include <stdarg.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
enum LogLevel {
	DEBUG, INFO, WARNING, ERROR, FATAL
};

class OutputTarget {
protected:
	LogLevel _severity;
	std::vector<std::string> _channels;

public:
	void SetSeverity(LogLevel severity) {
		_severity = severity;
	}
	std::vector<std::string> _channels;
	void includeChannel(std::string channel) {
		_channels.insert(_channels.begin(), channel);

	}
	void excludeChannel(std::string channel) {
		for (auto it = std::cbegin(_channels); it != std::cend(_channels); ++it)
			if (it->compare(channel) == 0)
			{
				_channels.erase(it);
				break;
			}
	}
	int severity() {
		return static_cast<int>(_severity);
	}
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
public:
	void write(char *buffer) {
		std::cout << buffer << std::endl;
	}
};

class Logger final {
private:
	std::ostringstream _os;
	std::vector<OutputTarget*> _outputTargets;
	char *buffer = new char[256];
	std::ostringstream& GetStaringInfo(LogLevel level)
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		_os << "[" << std::to_string(level) << "]";
		_os << "[" << newtime.tm_hour << ":" << newtime.tm_min << ":" << newtime.tm_sec<< "]";
		return _os;
	}
	void formatMessage(va_list args, const char* msg) {

		std::size_t constexpr max_buffer_size = 256;
		::strncpy_s(buffer, max_buffer_size, _os.str().c_str(), max_buffer_size);
		std::size_t const prefix_len = std::strlen(buffer);
		::vsnprintf(buffer + prefix_len, max_buffer_size - prefix_len, msg, args);
		_os.str("");
	}
	void notifyTargets(LogLevel level) {
		for (auto target : _outputTargets)
			if (target->severity() <= static_cast<int>(level))
				target->write(buffer);
	}

public:
	
	FileTarget* AddFileTarget(std::string path) {
		FileTarget *ft = new FileTarget(path);
		_outputTargets.insert(_outputTargets.begin(), ft);
		return ft;
	}

	CmdTarget* AddCmdTarget() {
		CmdTarget *cmdTarget = new CmdTarget();
		_outputTargets.insert(_outputTargets.begin(), cmdTarget);
		return cmdTarget;
	}
	
	void Fatal(const char* msg, ...) {

		GetStaringInfo(LogLevel::FATAL);

		::va_list args;
		va_start(args, msg);
		formatMessage(args, msg);
		notifyTargets(LogLevel::FATAL);
		va_end(args);
	}
	void Error(const char* msg, ...) {

		GetStaringInfo(LogLevel::ERROR);

		::va_list args;
		va_start(args, msg);
		formatMessage(args, msg);
		notifyTargets(LogLevel::ERROR);
		va_end(args);
	}
	void Warning(const char* msg, ...) {

		GetStaringInfo(LogLevel::WARNING);

		::va_list args;
		va_start(args, msg);
		formatMessage(args, msg);
		notifyTargets(LogLevel::WARNING);
		va_end(args);
	}
	void Info(const char* msg, ...) {

		GetStaringInfo(LogLevel::INFO);

		::va_list args;
		va_start(args, msg);
		formatMessage(args, msg);
		notifyTargets(LogLevel::INFO);
		va_end(args);
	}
	void Debug(const char* msg, ...) {

		GetStaringInfo(LogLevel::DEBUG);

		::va_list args;
		va_start(args, msg);
		formatMessage(args, msg);
		notifyTargets(LogLevel::DEBUG);
		va_end(args);
	}
};