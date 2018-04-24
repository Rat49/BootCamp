#pragma once
#include "EventTypes.h"
#include "Event.h"

#include <functional>
#include <iostream>
#include <map>
#include <vector>

using EventHandler_t = std::function<void(const Event&)>;
using Token_t = std::size_t;

class Dispatcher final
{
private:
	std::map <EventID_t, std::map<Token_t, EventHandler_t>> _listeners;

	Dispatcher(Dispatcher const&) = delete;

	Dispatcher& operator= (Dispatcher const&) = delete;

	Dispatcher();

	~Dispatcher();

public:

	static Dispatcher& getInstance();

	Token_t Connect(const EventID_t eventID, const EventHandler_t& handler);

	void Send(const Event& event, EventID_t eventID);

	void Send(const Event& event, EventID_t eventID, Token_t token);

	void Disconnect(const EventID_t eventID, const Token_t token);
};