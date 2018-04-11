#include "ConsoleCommands.h"

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

std::vector<consoleCommand_t>	Commands =
{
	{ "setGameSpeed", SetGameSpeed },
	{ "pause", Pause }
};