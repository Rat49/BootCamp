#pragma once
#include "Event.h"
#include <string>

class LoggerMessageEvent : public Event
{
public:
	std::string _loggerMessage;
	LoggerMessageEvent(const std::string& loggerMessage);
};