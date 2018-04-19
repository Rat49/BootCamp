#include <SFML/Graphics.hpp>
#include "iostream"
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