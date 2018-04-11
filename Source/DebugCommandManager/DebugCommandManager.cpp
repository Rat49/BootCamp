#include "ConsoleCommands.h"
#include "DebugCommandManager.h"

extern std::vector<consoleCommand_t> Commands;


void DebugCommandManager::handleConsoleCommand(std::string consoleCommand)
{
	_parser.Trim(consoleCommand);
	std::string delimiter = " ";
	std::vector<std::string> args = _parser.Split(consoleCommand, delimiter);

	if (args.empty())
	{
		return;
	}

	consoleCommand_t requiredCommand;
	requiredCommand.commandName = args[0].c_str();

	auto command = std::find_if(Commands.begin(), 
		Commands.end(),
		[&requiredCommand](const auto& existingCommand)
			{
				return 0 == strcmp(existingCommand.commandName, requiredCommand.commandName);
			});

	if (command != std::end(Commands))
	{
		args.erase(args.begin());
		command->handler(args);
	}
	else
	{
		std::cout << "Command not found!" << std::endl;
	}
}


void  DebugCommandManager::Run()
{
	while (true)
	{
		std::string command;
		std::getline(std::cin, command);
		handleConsoleCommand(command);
	}
}

void DebugCommandManager::addConsoleCommand(const consoleCommand_t& newConsoleCommand)
{
	auto retrievedPositionOfNewConsoleCommand = std::find_if(Commands.begin(),
		Commands.end(),
		[&newConsoleCommand](const auto& existingCommand)
		{
			return 0 == strcmp(existingCommand.commandName, newConsoleCommand.commandName);
		});

	if (retrievedPositionOfNewConsoleCommand == Commands.end())
	{
		Commands.push_back(newConsoleCommand);
	}
	else
	{
		std::cout << "Add command failed! Command already exists." << std::endl;
	}
}