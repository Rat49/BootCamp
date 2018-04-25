#include "Logger.h"
#include "EventSystem.h"
#include "LoggerMessageEvent.h"
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <sstream>
//#include <stdarg.h>


void OutputTarget::SetSeverity(LogLevel severity)
{
	_severity = severity;
}

void OutputTarget::IncludeChannel(const std::string& channel)
{
	_channels.emplace_back(channel);
}

bool OutputTarget::ContainsChannel(const std::string& channel)
{
	return std::find_if(_channels.cbegin(), _channels.cend(), [&](const std::string& ch) { return (ch == channel || ch == "All"); }) != _channels.cend();
}

void OutputTarget::ExcludeChannel(const std::string& channel)
{
	auto it = std::find(_channels.cbegin(), _channels.cend(), channel);
	if (it != _channels.cend())
	{
		_channels.erase(it);
	}
}

LogLevel OutputTarget::Severity() const
{
	return _severity;
}

FileTarget::FileTarget(const std::string& path)
{
	_stream.open(path, std::ofstream::app);
	if (!_stream)
	{
		Logger::GetInstance().Error("Unable to open file %s", path.c_str());
	}
}

void FileTarget::Write(char* buffer)
{
	if (_stream)
	{
		_stream << buffer << std::endl;
	}
}

void CmdTarget::Write(char* buffer)
{
	std::cout << buffer << std::endl;
}

void DebugConsoleTarget::Write(char* buffer)
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	LoggerMessageEvent _loggerMessage(buffer);
	dispatcher.Send(_loggerMessage, EventTypes::loggerMessageEventID);
}

namespace
{
	Logger instance;

	WORD levelColors[] = { 15, 11, 14, 12, 79 };

	__int64 frame = 0;
	std::ostringstream os;
	std::string currentChannel;
	std::vector<OutputTarget*> outputTargets;
	HANDLE hConsole;

	char formatBuffer[256];
	char infoBuffer[32];

	const char* GetLevelName(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Debug:
			return "DEBUG";
		case LogLevel::Info:
			return "INFO";
		case LogLevel::Warning:
			return "WARNING";
		case LogLevel::Error:
			return "ERROR";
		case LogLevel::Fatal:
			return "FATAL";
		default:
			return "UNDEFINED";
		}
	}

	void GetStaringInfo(LogLevel level)
	{
		tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		os << "[" << currentChannel << "]";
		os << "[" << GetLevelName(level) << "]";

		strftime(infoBuffer, 32, "%H:%M:%S", &newtime);
		os << "[" << infoBuffer << "]";
		sprintf_s(infoBuffer, "%llu", frame);
		os << "[" << infoBuffer << "] ";
	}

	void PrepareMessage(va_list args, const char* msg)
	{
		strncpy_s(formatBuffer, 256, os.str().c_str(), 256);
		const size_t prefix_len = strlen(formatBuffer);
		vsnprintf(formatBuffer + prefix_len, 256 - prefix_len, msg, args);
		os.str("");
	}

	void NotifyTargets(LogLevel level)
	{
		for (auto target : outputTargets)
		{
			if (target->Severity() <= level && target->ContainsChannel(currentChannel))
			{
				target->Write(formatBuffer);
			}
		}

		SetConsoleTextAttribute(hConsole, 15);
	}

	void OutputMessageImpl(const char* msg, va_list args, LogLevel level)
	{
		GetStaringInfo(level);
		SetConsoleTextAttribute(hConsole, levelColors[level]);
		PrepareMessage(args, msg);
		NotifyTargets(level);
	}
}

Logger::Logger()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Logger::~Logger()
{
	for (auto ot : outputTargets)
	{
		delete ot;
	}
}

void Logger::SetFrame(__int64 f)
{
	frame = f;
}

Logger& Logger::GetInstance()
{
	return instance;
}

FileTarget* Logger::AddFileTarget(const std::string& path)
{
	FileTarget* ft = new FileTarget(path);
	outputTargets.emplace_back(ft);
	return ft;
}
CmdTarget* Logger::AddCmdTarget()
{
	CmdTarget* ct = new CmdTarget();
	outputTargets.emplace_back(ct);
	return ct;
}

DebugConsoleTarget* Logger::AddDebugTarget()
{
	DebugConsoleTarget* dt = new DebugConsoleTarget();
	outputTargets.emplace_back(dt);
	return dt;
}

Logger& Logger::operator()(const std::string& channel)
{
	currentChannel = channel;
	return (*this);
}

void Logger::Fatal(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	OutputMessageImpl(msg, args, LogLevel::Fatal);
	va_end(args);
}

void Logger::Error(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	OutputMessageImpl(msg, args, LogLevel::Error);
	va_end(args);
}

void Logger::Warning(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	OutputMessageImpl(msg, args, LogLevel::Warning);
	va_end(args);
}

void Logger::Info(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	OutputMessageImpl(msg, args, LogLevel::Info);
	va_start(args, msg);
}

void Logger::Debug(const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	OutputMessageImpl(msg, args, LogLevel::Debug);
	va_end(args);
}
