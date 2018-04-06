#pragma once
#include "stdafx.h"

class Dispatcher
{
private:
	std::map <int, std::vector<std::function<void(const Event&)>>> m_listeners;

	Dispatcher(Dispatcher const&) = delete;

	Dispatcher& operator= (Dispatcher const&) = delete;

	Dispatcher();

	~Dispatcher();

public:

	static Dispatcher& getInctance();

	int Connect(const int eventID, const std::function<void(const Event&)>& func);

	void Send(Event& event);

	void Disconnect(const int eventID, const int token);
};