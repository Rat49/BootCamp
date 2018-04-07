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

int Dispatcher::Connect(const int eventID, const std::function<void(const Event&)>& func)
{
	std::vector <std::function<void(const Event&)>>& functions = m_listeners[eventID];

	int tokenForCurrentListener = m_listeners[eventID].size();

	m_listeners[eventID].push_back(func);

	return tokenForCurrentListener;
}

void Dispatcher::Send(Event& event)
{
	auto id = event.getID();

	std::map<int, std::vector<std::function<void(const Event&)>>>::iterator listenersForCurrentEvent = m_listeners.find(id);

	if (listenersForCurrentEvent == m_listeners.end())
	{
		return;
	}

	auto& listenersForEvents = listenersForCurrentEvent->second;

	for (auto& listener : listenersForEvents)
	{
		listener(event);
	}

}

void Dispatcher::Disconnect(const int eventID, const int token)
{
	if (m_listeners.empty()) return;

	std::vector <std::function<void(const Event&)>>& listenersForCurrentEvent = m_listeners.find(eventID)->second;

	if (token >= 0 && token < listenersForCurrentEvent.size())
	{
		std::vector<std::function<void(const Event&)>>::iterator listenerPosition = listenersForCurrentEvent.begin() + token;

		listenersForCurrentEvent.erase(listenerPosition);
	}
}

