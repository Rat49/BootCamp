#include <SFML/Graphics.hpp>
#include "Events.h"
#include "EventSystem.h"
#include "Input.h"


int main()
{
	std::cout << "hello";
	sf::RenderWindow rw(sf::VideoMode::getDesktopMode(), "Asteroids");
	sf::Event sysEvent;
	while (rw.isOpen())
	{
		if (rw.pollEvent(sysEvent))
		{
			if (sysEvent.type == sysEvent.KeyPressed && sysEvent.key.code == sf::Keyboard::Escape)
			{
				rw.close();
			}
			if (sysEvent.type == sysEvent.Resized)
			{
				FirstEvent firstEvent;
				Dispatcher& dispatcher = Dispatcher::getInstance();
				dispatcher.Send(firstEvent, firstEventID);
			}
		}

		//Input update
		//Audio update
		//Logic update
		//...

		rw.clear();
		//Rendering update
		rw.display();
	}

	return 0;
}