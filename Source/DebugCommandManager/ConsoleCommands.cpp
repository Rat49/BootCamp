#include "ConsoleCommands.h"
#include <iostream>

static CommandHandler_t SetGameSpeed = [](const std::vector<std::string>& args)
{
	for (const auto& str : args)
	{
		std::cout << str << std::endl;
	}
};

static CommandHandler_t Pause = [](const std::vector<std::string>& args)
{
	for (const auto& str : args)
	{
		std::cout << str << std::endl;
	}
};

std::vector<ConsoleCommand>	Commands =
{
	{ "setGameSpeed", SetGameSpeed },
	{ "pause", Pause }
};
