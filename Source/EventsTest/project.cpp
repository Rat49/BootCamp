#include "stdafx.h"

struct Asteroid
{
	std::map<int, int> tokens;
	int countOfHandlerResponce = 0;
	void registerHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInctance();
		std::function<void(const Event&)> handler = [&](const Event &e)
		{
			std::cout << "Asteroid handler" << std::endl;
			countOfHandlerResponce++;
		};
		int token = dispatcher.Connect(eventID, handler);
		tokens.insert(std::pair<int, int>(eventID, token));
	}
	void unregisterHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInctance();
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
		Dispatcher& dispatcher = Dispatcher::getInctance();
		std::function<void(const Event&)> handler = [&](const Event &e)
		{
			std::cout << "Analytic handler" << std::endl;
			countOfHandlerResponce++;
		};
		int token = dispatcher.Connect(eventID, handler);
		tokens.insert(std::pair<int, int>(eventID, token));
	}
	void unregisterHandler(const int eventID)
	{
		Dispatcher& dispatcher = Dispatcher::getInctance();
		dispatcher.Disconnect(eventID, tokens.at(eventID));
		tokens.erase(tokens.find(eventID));
	}
};

int main()
{
	Dispatcher& dispatcher = Dispatcher::getInctance();

	Asteroid asteroid;

	Analytic analytic;

	FirstEvent firstEvent;

	SecondEvent secondEvent;

	std::cout << "firstEvent ID: " << firstEvent.getID() << std::endl;

	std::cout << "secondEvent ID: " << secondEvent.getID() << std::endl;

	assert(firstEvent.getID() != secondEvent.getID());

	int beforeRegistrationTokensCount = asteroid.tokens.size();

	asteroid.registerHandler(firstEvent.getID());

	int afterRegistrationTokensCount = asteroid.tokens.size();

	assert(beforeRegistrationTokensCount + 1 == afterRegistrationTokensCount);
	
	asteroid.unregisterHandler(firstEvent.getID());

	int afterUnregistrationTokensCount = asteroid.tokens.size();

	assert(afterRegistrationTokensCount - 1 == afterUnregistrationTokensCount);

	asteroid.registerHandler(firstEvent.getID());

	dispatcher.Send(firstEvent);

	assert(asteroid.countOfHandlerResponce == 1);
	
	analytic.registerHandler(firstEvent.getID());

	dispatcher.Send(firstEvent);

	assert(asteroid.countOfHandlerResponce == 2 && analytic.countOfHandlerResponce == 1);

	std::cin.get();
}