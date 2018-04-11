#include "DebugCommandManager.h"

int main()
{
	DebugCommandManager manager;
	manager.addConsoleCommand({ "help", [](const std::vector<std::string>& args)
	{
		std::cout << "help" << std::endl;
		return 0;
	} });
	manager.addConsoleCommand({ "help", [](const std::vector<std::string>& args)
	{
		std::cout << "Help" << std::endl;
		return 0;
	} });
	manager.Run();
	return 0;
}