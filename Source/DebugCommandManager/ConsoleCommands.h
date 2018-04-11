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
