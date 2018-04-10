#pragma once
#include <functional> 
#include <iostream>
#include <vector>
#include <string>

using CommandHandler_t = std::function<void(std::vector<std::string>&)>;

using consoleCommand_t = struct {
	const char* commandName;
	CommandHandler_t handler;
};

static CommandHandler_t SetGameSpeed = [](const std::vector<std::string>& args)
{
	for (std::string str : args)
	{
		std::cout << str << std::endl;
	}
	return 0;
};
static CommandHandler_t Pause = [](const std::vector<std::string>& args)
{
	for (std::string str : args)
	{
		std::cout << str << std::endl;
	}
	return 0;
};

extern std::vector<consoleCommand_t> commands;
