#include "DebugCommandManager.h"
#include "ConsoleCommandsStore.h"

void DebugCommandManager::HandleConsoleCommand(std::string consoleCommand)
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

	auto command = std::find_if(commands.begin(), 
		commands.end(),
		[&requiredCommand](const auto& consoleCommand)
			{
				return 0 == strcmp(consoleCommand.commandName,requiredCommand.commandName);
			});

	if (command != std::end(commands))
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
		HandleConsoleCommand(command);
	}
}
