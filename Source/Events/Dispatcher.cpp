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
	Token_t tokenForCurrentListener = 0;

	std::vector <std::pair<Token_t, EventHandler_t>>& handlersForCurrentEvent = _listeners[eventID];

	if (handlersForCurrentEvent.empty())
	{
		handlersForCurrentEvent.push_back(std::pair<Token_t, EventHandler_t> (tokenForCurrentListener, handler));

		return tokenForCurrentListener;
	}

	Token_t lastValidTokenForCurrentEvent = handlersForCurrentEvent.back().first;

	tokenForCurrentListener = lastValidTokenForCurrentEvent + 1;

	handlersForCurrentEvent.push_back(std::pair<Token_t, EventHandler_t>(tokenForCurrentListener, handler));

	return tokenForCurrentListener;
}

void Dispatcher::Send(const Event& event, EventID_t eventID)
{
	std::map<EventID_t, std::vector<std::pair<Token_t, EventHandler_t>>>::iterator listenersForCurrentEvent = _listeners.find(eventID);

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

	std::vector <std::pair<Token_t, EventHandler_t>>& listenersForCurrentEvent = _listeners.find(eventID)->second;

	std::pair<Token_t, EventHandler_t> requiredListener = std::pair<Token_t, EventHandler_t>(token, nullptr);

	auto positionOfRequiredListener = std::equal_range(listenersForCurrentEvent.begin(), 

		listenersForCurrentEvent.end(), 
			
		requiredListener,
			
		[](const auto& lListener, const auto& rListener)
			{
				return lListener.first < rListener.first;
			}
	);

	if (positionOfRequiredListener.first == listenersForCurrentEvent.cend())
	{
		std::cout << DispatcherErrorMessagesStore::disconectFailedWrongToken << std::endl;
	}

	listenersForCurrentEvent.erase(positionOfRequiredListener.first);

	return;
}

