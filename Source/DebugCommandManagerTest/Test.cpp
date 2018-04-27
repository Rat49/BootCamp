#include "DebugCommandManager.h"
#include "DebugCommandManagerEvent.h"
#include "EventSystem.h"

int main()
{
	DebugCommandManager manager;
	DebugCommandManagerEvent newEvent("help");

	manager.addConsoleCommand({ "help", [](const std::vector<std::string>& /*args*/)
	{
		std::cout << "help" << std::endl;
		return 0;
	} });

	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Send(newEvent, debugCommandManagerEventID);

	return 0;
}