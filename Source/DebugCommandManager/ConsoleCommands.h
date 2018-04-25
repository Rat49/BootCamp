#pragma once
#include <functional> 
#include <vector>
#include <string>

using CommandHandler_t = std::function<void(const std::vector<std::string>&)>;

struct ConsoleCommand
{
	const char* commandName;
	CommandHandler_t handler;
};
