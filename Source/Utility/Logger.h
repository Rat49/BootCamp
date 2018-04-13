#pragma once
#include <algorithm>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <vector>
#include <windows.h>

enum LogLevel {
	Debug = 0, Info, Warning, Error, Fatal
};


class OutputTarget {
protected:
	LogLevel _severity;
public:
	void SetSeverity(LogLevel severity) {
		_severity = severity;
	}
	std::vector<std::string> _channels;
	void IncludeChannel(std::string channel) {
		_channels.insert(_channels.begin(), channel);

	}
	bool ContainsChannel(std::string channel) {
		for (auto it = std::cbegin(_channels); it != std::cend(_channels); ++it)
			if (it->compare(channel) == 0 || it->compare("All") == 0)
			{
				return true;
			}
		return false;
	}
	void ExcludeChannel(std::string channel) {
		for (auto it = std::cbegin(_channels); it != std::cend(_channels); ++it)
			if (it->compare(channel) == 0)
			{
				_channels.erase(it);
				break;
			}
	}
	int Severity() {
		return static_cast<int>(_severity);
	}
	virtual void Write(char *buffer) = 0;
};

class FileTarget : public OutputTarget {
private:
	std::ofstream _stream;
public:
	FileTarget(std::string path) {
		_stream.open(path, std::ofstream::app);
		if (!_stream)
		{
			std::cout << "Unable to open file " << path << std::endl;
		}
	}
	void Write(char *buffer) {
		if(_stream)
			_stream << buffer << std::endl;
	}
};

class CmdTarget : public OutputTarget {
private:
public:
	void Write(char *buffer) {
		std::cout << buffer << std::endl;
	}
};

class Logger;

class LoggerDestroyer
{
private:
	Logger* p_instance;
public:
	~LoggerDestroyer();
	void Initialize(Logger* p);
};


class Logger final {
private:
	__int64 _frame = 0;
	std::ostringstream _os;
	std::string _currentChannel;
	std::vector<OutputTarget*> _outputTargets;
	char buffer[256];
	void GetStaringInfo(LogLevel level);
	void formatMessage(va_list args, const char* msg);
	void NotifyTargets(LogLevel level);
	static Logger* p_instance;
	static LoggerDestroyer _destroyer;
	HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string GetLevelName(LogLevel level);
	Logger() {};
	Logger(const Logger&) = delete;
	~Logger() {};
	friend class LoggerDestroyer;
	void OutputMessageImpl(const char * msg, va_list args, LogLevel level);

public:
	void SetFrame(uint64_t frame);
	static Logger& GetInstance();
	FileTarget* AddFileTarget(std::string path);
	CmdTarget* AddCmdTarget();
	void Fatal(const char* msg, ...);
	void Error(const char* msg, ...);
	void Warning(const char* msg, ...);
	void Info(const char* msg, ...);
	void Debug(const char* msg, ...);
	Logger& operator () (std::string channel);
};
