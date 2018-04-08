#include "Dispatcher.h"
#include "DispatcherErrorMessagesStore.h"

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

int Dispatcher::Connect(const EventID_t eventID, const EventHandler_t& handler)
{
	std::vector <EventHandler_t>& handlersForCurrentEvent = _listeners[eventID];

	Token_t tokenForCurrentListener = handlersForCurrentEvent.size();

	handlersForCurrentEvent.push_back(handler);

	return tokenForCurrentListener;
}

void Dispatcher::Send(const Event& event, EventID_t eventID)
{

	std::map<EventID_t, std::vector<EventHandler_t>>::iterator listenersForCurrentEvent = _listeners.find(eventID);

	if (listenersForCurrentEvent == _listeners.end())
	{
		return;
	}

	auto& listenersForEvent = listenersForCurrentEvent->second;

	for (auto& listener : listenersForEvent)
	{
		listener(event);
	}

}

void Dispatcher::Disconnect(const EventID_t eventID, const Token_t token)
{
	if (_listeners.empty())
	{
		std::cout << DispatcherErrorMessagesStore::disconectFailedNoListenersToDisconect << std::endl;

		return;
	}

	std::vector <EventHandler_t>& listenersForCurrentEvent = _listeners.find(eventID)->second;

	if (token >= 0 && token < listenersForCurrentEvent.size())
	{
		std::vector<EventHandler_t>::iterator listenerPosition = listenersForCurrentEvent.begin() + token;

		listenersForCurrentEvent.erase(listenerPosition);

		return;
	}

	std::cout << DispatcherErrorMessagesStore::disconectFailedWrongToken << std::endl;
}

