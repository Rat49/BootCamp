#pragma once
#include "Dispatcher.h"
#include "ConsoleCommands.h"
#include "Parser.h"
#include <functional> 

class DebugCommandManager
{
	Parser _parser;
	Token_t _token;

public:
	DebugCommandManager();
	~DebugCommandManager();
	void handleConsoleCommand(std::string& ConsoleCommand);
	void addConsoleCommand(const ConsoleCommand& command);
};

