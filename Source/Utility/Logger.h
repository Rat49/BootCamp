#pragma once
#include <iostream>
#include <stdarg.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <windows.h>

enum LogLevel {
	DEBUG = 0, INFO, WARNING, LogLevelERROR, FATAL
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
	}
	void Write(char *buffer) {
		_stream<< buffer << std::endl;
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
	__int64 _frame =20;
	std::ostringstream _os;
	std::string _currentChannel;
	std::vector<OutputTarget*> _outputTargets;
	char *buffer = new char[256];
	std::ostringstream& GetStaringInfo(LogLevel level);
	void formatMessage(va_list args, const char* msg);
	void NotifyTargets(LogLevel level);
	static Logger* p_instance;
	static LoggerDestroyer _destroyer;
	HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string GetLevelName(LogLevel level);
protected:
	Logger() {};
	Logger(const Logger&) = delete;
	~Logger() {};
	friend class LoggerDestroyer;
public:
	void SetFrame(__int64 frame);
	static Logger& GetInstance();
	FileTarget* AddFileTarget(std::string path);
	CmdTarget* AddCmdTarget();
	void Fatal(const char* msg, ...);
	void Error(const char* msg, ...);
	void Warning(const char* msg, ...);
	void Info(const char* msg, ...);
	void Debug(const char* msg, ...);
	Logger& operator () (std::string channel);
	void Impl(const char * msg, va_list args, LogLevel level);
};
