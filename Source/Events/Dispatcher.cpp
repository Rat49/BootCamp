#include "stdafx.h"


Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
}

Dispatcher& Dispatcher::getInctance()
{
	static Dispatcher instance;

	return instance;
}

int Dispatcher::Connect(const int eventID, const std::function<void(const Event&)>& func)
{
	m_listeners[eventID].push_back(func);

	int tokenForCurrentListener = m_listeners[eventID].size() - 1;

	return tokenForCurrentListener;
}

void Dispatcher::Send(Event& event)
{
	auto id = event.getID();

	if (m_listeners.find(id) == m_listeners.end())
	{
		return;
	}

	auto& listenersForEvents = m_listeners.at(id);

	for (auto& listeners : listenersForEvents)
	{
		listeners(event);
	}

}

void Dispatcher::Disconnect(const int eventID, const int token)
{
	if (!(m_listeners.empty()))
	{
		std::vector <std::function<void(const Event&)>>& listenersForCurrentEvent = m_listeners.at(eventID);

		if (!listenersForCurrentEvent.empty() && (listenersForCurrentEvent.size() - 1 >= token))
		{
			std::vector <std::function<void(const Event&)>>::iterator listenerPosition = listenersForCurrentEvent.begin() + token;

			listenersForCurrentEvent.erase(listenerPosition);
		}
	}
	return;
}

