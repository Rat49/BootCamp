#pragma once
#include "Event.h"
#include <string>

class DebugCommandManagerEvent : public Event
{
public:
	std::string _consoleCommand;
	DebugCommandManagerEvent(const std::string& consoleCommand);
};