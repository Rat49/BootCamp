#pragma once
using EventID_t = int;

enum EventTypes : EventID_t
{
	firstEventID = 1,
	secondEventID,
	debugCommandManagerEventID,
	debugConsoleKeyEventID
};
