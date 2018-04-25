#pragma once
#include <fstream>
#include <vector>
#include <string>

enum LogLevel : unsigned int
{
	Debug = 0,
	Info,
	Warning,
	Error,
	Fatal
};

class OutputTarget
{
public:
	LogLevel Severity() const;
	void SetSeverity(LogLevel severity);
	void IncludeChannel(const std::string& channel);
	bool ContainsChannel(const std::string& channel);
	void ExcludeChannel(const std::string& channel);

	virtual void Write(char* buffer) = 0;

protected:
	LogLevel _severity;
	std::vector<std::string> _channels;
};

class FileTarget : public OutputTarget
{
public:
	FileTarget(const std::string& path);
	void Write(char* buffer) override;

private:
	std::ofstream _stream;
};

class CmdTarget : public OutputTarget
{
public:
	void Write(char* buffer) override;
};

class DebugConsoleTarget : public OutputTarget
{
public:
	void Write(char *buffer) override;
};

class Logger final
{
public:
	static Logger& GetInstance();

	Logger();
	~Logger();
	Logger(const Logger&) = delete;

	FileTarget* AddFileTarget(const std::string& path);
	CmdTarget* AddCmdTarget();
	DebugConsoleTarget* AddDebugTarget();

	void SetFrame(__int64 frame);
	Logger& operator() (const std::string& channel);

	void Fatal(const char* msg, ...);
	void Error(const char* msg, ...);
	void Warning(const char* msg, ...);
	void Info(const char* msg, ...);
	void Debug(const char* msg, ...);
};
