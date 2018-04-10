#pragma once
#include "Parser.h"
#include <functional> 

class DebugCommandManager
{
	Parser _parser;
public:
	void HandleConsoleCommand(const std::string ConsoleCommand);
	void Run();
};

