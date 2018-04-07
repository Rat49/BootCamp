#include "Dispatcher.h"

Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
}

Dispatcher& Dispatcher::getInstance()
{
	static Dispatcher instance;

	return instance;
}

int Dispatcher::Connect(const EventID_t eventID, const EventHandler_t& func)
{
	std::vector <EventHandler_t>& functions = _listeners[eventID];

	Token_t tokenForCurrentListener = _listeners[eventID].size();

	_listeners[eventID].push_back(func);

	return tokenForCurrentListener;
}

void Dispatcher::Send(const Event& event)
{
	EventID_t id = event.ID;

	std::map<EventID_t, std::vector<EventHandler_t>>::iterator listenersForCurrentEvent = _listeners.find(id);

	if (listenersForCurrentEvent == _listeners.end())
	{
		return;
	}

	auto& listenersForEvents = listenersForCurrentEvent->second;

	for (auto& listener : listenersForEvents)
	{
		listener(event);
	}

}

void Dispatcher::Disconnect(const EventID_t eventID, const Token_t token)
{
	if (_listeners.empty())
	{
		return;
	}

	std::vector <EventHandler_t>& listenersForCurrentEvent = _listeners.find(eventID)->second;

	if (token >= 0 && token < listenersForCurrentEvent.size())
	{
		std::vector<EventHandler_t>::iterator listenerPosition = listenersForCurrentEvent.begin() + token;

		listenersForCurrentEvent.erase(listenerPosition);
	}
}

