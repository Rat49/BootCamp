#include "DebugConsole.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(1280,800), "DebugSystem");
	
	DebugConsole debugConsole(window);

	sf::Event event;
	while (window.isOpen())
	{
		window.clear(sf::Color::Blue);
		
		while (window.pollEvent(event))
		{
			debugConsole.Update(event);

			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		debugConsole.Draw(window);

		window.display();
	}

	return 0;
}