#include "ConsoleCommands.h"
#include "DebugCommandManager.h"
#include "DebugCommandManagerEvent.h"
#include "EventSystem.h"

extern std::vector<ConsoleCommand> Commands;

DebugCommandManager::DebugCommandManager()
{
	Dispatcher & dispatcher = Dispatcher::getInstance();
	_token = dispatcher.Connect(debugCommandManagerEventID, 
		[&](const Event& event)
		{
			const DebugCommandManagerEvent& debugCommandManagerEvent = static_cast<const DebugCommandManagerEvent&>(event);
			std::string incomingCommand = debugCommandManagerEvent._consoleCommand;
			handleConsoleCommand(incomingCommand);
	});
};

DebugCommandManager::~DebugCommandManager()
{
	Dispatcher & dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(debugCommandManagerEventID, _token);
};

void DebugCommandManager::handleConsoleCommand(std::string& incomingConsoleCommand)
{
	std::string consoleCommand = incomingConsoleCommand;
	const std::string delimiter = " ";

	_parser.Trim(consoleCommand);

	std::vector<std::string> args = _parser.Split(consoleCommand, delimiter);

	ConsoleCommand requiredCommand;
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


void DebugCommandManager::addConsoleCommand(const ConsoleCommand& newConsoleCommand)
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