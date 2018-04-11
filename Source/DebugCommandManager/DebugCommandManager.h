#pragma once
#include "ConsoleCommands.h"
#include "Parser.h"
#include <functional> 

class DebugCommandManager
{
	Parser _parser;

public:

	void handleConsoleCommand(std::string ConsoleCommand);
	void addConsoleCommand(const consoleCommand_t& command);
	void Run();
};

