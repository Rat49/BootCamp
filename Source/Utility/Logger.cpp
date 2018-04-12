#include "Logger.h"
#include <iostream>

int levelColors[] = { 15,11,14,12,79 };

Logger* Logger::p_instance = 0;
LoggerDestroyer Logger::destroyer;
std::string Logger::GetLevelName(LogLevel level){
	switch (level)
	{
	case DEBUG:
		return "DEBUG";
		break;
	case INFO:
		return "INFO";
		break;
	case WARNING:
		return "WARNING";
		break;
	case LogLevelERROR:
		return "ERROR";
		break;
	case FATAL:
		return "FATAL";
		break;
	default:
		return "UNDEFINED";
		break;
	}
	
}
void Logger::setFrame(__int64 frame) {
	_frame = frame;
}

std::ostringstream& Logger::GetStaringInfo(LogLevel level)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	_os << "[" << _currentChannel << "]";
	_os << "[" << GetLevelName(level) << "]";
	char buff[100];
	strftime(buff, 100, "%H:%M:%S", &newtime);
	_os << "[" << buff << "]";
	char fr[16];
	sprintf_s(fr,"%u", _frame);
	_os << "[" << fr << "] ";
	return _os;
}

void Logger::formatMessage(va_list args, const char* msg) {

	std::size_t max_buffer_size = 256;
	::strncpy_s(buffer, max_buffer_size, _os.str().c_str(), max_buffer_size);
	std::size_t const prefix_len = std::strlen(buffer);
	::vsnprintf(buffer + prefix_len, max_buffer_size - prefix_len, msg, args);
	_os.str("");
}

void Logger::notifyTargets(LogLevel level) {

	for (auto target : _outputTargets){
		if (target->severity() <= static_cast<int>(level) &&  target->containsChannel(_currentChannel))
			target->write(buffer);
	}
	SetConsoleTextAttribute(hConsole, 15);
}

LoggerDestroyer::~LoggerDestroyer(){
	delete p_instance;
};

void LoggerDestroyer::initialize(Logger* p){
	p_instance = p;
};

Logger& Logger::getInstance(){
	if (!p_instance)     {
		p_instance = new Logger();
		destroyer.initialize(p_instance);
	}
	return *p_instance;
};

FileTarget* Logger::AddFileTarget(std::string path) {
	FileTarget *ft = new FileTarget(path);
	_outputTargets.insert(_outputTargets.begin(), ft);
	return ft;
}
CmdTarget* Logger::AddCmdTarget() {
	CmdTarget *cmdTarget = new CmdTarget();
	_outputTargets.insert(_outputTargets.begin(), cmdTarget);
	return cmdTarget;
}
Logger& Logger::operator () (std::string channel)
{
	_currentChannel = channel;
	return (*this);
}
void Logger::impl(const char* msg, va_list args, LogLevel level)
{
	GetStaringInfo(level);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, levelColors[level]);
	formatMessage(args, msg);
	notifyTargets(LogLevel::FATAL);
}

void Logger::Fatal(const char* msg, ...) {

	::va_list args;
	va_start(args, msg);
	impl(msg, args, LogLevel::FATAL);
	va_end(args);
}
void  Logger::Error(const char* msg, ...) {

	::va_list args;
	va_start(args, msg);
	impl(msg, args, LogLevel::LogLevelERROR);
	va_end(args);
}
void  Logger::Warning(const char* msg, ...) {

	::va_list args;
	va_start(args, msg);
	impl(msg, args, LogLevel::WARNING);
	va_end(args);
}
void  Logger::Info(const char* msg, ...) {

	::va_list args;
	va_start(args, msg);
	impl(msg, args, LogLevel::INFO);
	va_start(args, msg);
}
void  Logger::Debug(const char* msg, ...) {

	::va_list args;
	va_start(args, msg);
	impl(msg, args, LogLevel::DEBUG);
	va_end(args);
}


