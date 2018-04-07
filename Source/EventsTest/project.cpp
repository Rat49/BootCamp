#include "FirstEvent.h"
#include "SecondEvent.h"

#include <iostream>
#include <cassert>

struct Asteroid
{
	std::map<int, int> tokens;
	int countOfHandlerResponce = 0;
	void registerHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInstance();
		std::function<void(const Event&)> handler = [&](const Event &e)
		{
			countOfHandlerResponce++;
		};
		int token = dispatcher.Connect(eventID, handler);
		tokens.insert(std::pair<int, int>(eventID, token));
	}
	void unregisterHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInstance();
		dispatcher.Disconnect(eventID, tokens.at(eventID));
		tokens.erase(tokens.find(eventID));
	}
};

struct Analytic
{
	std::map<int, int> tokens;
	int countOfHandlerResponce = 0;
	void registerHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInstance();
		std::function<void(const Event&)> handler = [&](const Event &e)
		{
			countOfHandlerResponce++;
		};
		int token = dispatcher.Connect(eventID, handler);
		tokens.insert(std::pair<int, int>(eventID, token));
	}
	void unregisterHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInstance();
		dispatcher.Disconnect(eventID, tokens.at(eventID));
		tokens.erase(tokens.find(eventID));
	}
};

int main()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();

	Asteroid asteroid;

	Analytic analytic;

	FirstEvent firstEvent;

	SecondEvent secondEvent;

	assert(firstEvent.getID() != secondEvent.getID());

	std::cout << "Different ID for different Event classes - Done!" << std::endl;

	int beforeRegistrationTokensCount = asteroid.tokens.size();

	asteroid.registerHandler(firstEvent.getID());

	int afterRegistrationTokensCount = asteroid.tokens.size();

	assert(beforeRegistrationTokensCount + 1 == afterRegistrationTokensCount);

	std::cout << "Adding new listener to certain event notification - Done!" << std::endl;
	
	asteroid.unregisterHandler(firstEvent.getID());

	int afterUnregistrationTokensCount = asteroid.tokens.size();

	assert(afterRegistrationTokensCount - 1 == afterUnregistrationTokensCount);

	std::cout << "Removing listener from certain event notification - Done!" << std::endl;

	asteroid.registerHandler(firstEvent.getID());

	dispatcher.Send(firstEvent);

	assert(asteroid.countOfHandlerResponce == 1);
	
	analytic.registerHandler(firstEvent.getID());

	dispatcher.Send(firstEvent);

	assert(asteroid.countOfHandlerResponce == 2 && analytic.countOfHandlerResponce == 1);

	std::cout << "Dispatcher sends events and listeners handle them  - Done!" << std::endl;

}