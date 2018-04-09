#include "Dispatcher.h"
#include "DispatcherErrorMessagesStore.h"

#include  <algorithm>

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
	std::map<Token_t, EventHandler_t>& handlersForCurrentEvent = _listeners[eventID];
	Token_t tokenForCurrentListener = 0;
	if (handlersForCurrentEvent.empty())
	{
		handlersForCurrentEvent.insert(std::pair<Token_t, EventHandler_t> (tokenForCurrentListener, handler));
		return tokenForCurrentListener;
	}
	Token_t lastValidTokenForCurrentEvent = handlersForCurrentEvent.rbegin()->first;
	tokenForCurrentListener = lastValidTokenForCurrentEvent + 1;
	handlersForCurrentEvent.insert(std::pair<Token_t, EventHandler_t>(tokenForCurrentListener, handler));

	return tokenForCurrentListener;
}

void Dispatcher::Send(const Event& event, EventID_t eventID)
{
	std::map<EventID_t, std::map<Token_t, EventHandler_t>>::iterator listenersForCurrentEvent = _listeners.find(eventID);

	if (listenersForCurrentEvent == _listeners.end())
	{
		return;
	}

	auto& listenersForEvent = listenersForCurrentEvent->second;

	for (auto& listener : listenersForEvent)
	{
		listener.second(event);
	}
}

void Dispatcher::Disconnect(const EventID_t eventID, const Token_t token)
{
	if (_listeners.empty())
	{
		std::cout << DispatcherErrorMessagesStore::disconectFailedNoListenersToDisconect << std::endl;
		return;
	}

	std::map <Token_t, EventHandler_t>& listenersForCurrentEvent = _listeners.find(eventID)->second;
	auto positionOfRequiredListener = listenersForCurrentEvent.find(token);

	if (positionOfRequiredListener == listenersForCurrentEvent.cend())
	{
		std::cout << DispatcherErrorMessagesStore::disconectFailedWrongToken << std::endl;
		return;
	}
	else
	{
		listenersForCurrentEvent.erase(positionOfRequiredListener);
		return;
	}

}

