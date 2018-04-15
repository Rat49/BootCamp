#pragma once
using EventID_t = int;

enum EventTypes : EventID_t
{
	debugCommandManagerEventID = 1,
	debugConsoleKeyEventID
};