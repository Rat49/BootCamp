#pragma once
#include "Event.h"

#include <map>
#include <functional>
#include <vector>

using EventHandler_t = std::function<void(const Event&)>;
using Token_t = int;

class Dispatcher
{
private:
	std::map <EventID_t, std::vector<EventHandler_t>> _listeners;

	Dispatcher(Dispatcher const&) = delete;

	Dispatcher& operator= (Dispatcher const&) = delete;

	Dispatcher();

	~Dispatcher();

public:

	static Dispatcher& getInstance();

	int Connect(const EventID_t eventID, const EventHandler_t& func);

	void Send(const Event& event);

	void Disconnect(const EventID_t eventID, const Token_t token);
};