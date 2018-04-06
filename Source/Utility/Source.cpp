#include "Logger.h"
#include <iostream>


int main()
{
	Logger& log = Logger::getInstance();
	auto cmdTarget = log.AddCmdTarget();
	auto fileTarget = log.AddFileTarget("../Events/Event.log");
	fileTarget->includeChannel("Event");
	cmdTarget->SetSeverity(LogLevel::WARNING);
	fileTarget->SetSeverity(LogLevel::INFO);
	cmdTarget->includeChannel("All");
	log("Audio").Debug("%s %s!", "Hello", "world");
	log("Event").Info("%s %s!", "Hello", "world");
	cmdTarget->excludeChannel("All");
	cmdTarget->includeChannel("Audio");
	log("Audio").Error("%s %s!", "Hello", "world");
	log("Event").Warning("%s %s!", "Hello", "world");
	system("pause");
	return 0;
}