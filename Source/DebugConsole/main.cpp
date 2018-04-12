#include "DebugConsole.h"
#include "EventSystem.h"
int main()
{

	sf::RenderWindow window(sf::VideoMode(1280,800), "DebugSystem");
	
	DebugConsole debugConsole(window);
	Dispatcher& dispatcher = Dispatcher::getInstance();
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
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Tab)
			{
				debugConsole.logMessageOutput("A Hello, World! program is a computer program that outputs or displays Hello, World! to a user. Being a very simple program in most programming languages, it is often used to illustrate the basic syntax of a programming language for a working program.[1]");
			}
		}

		debugConsole.Draw(window);

		window.display();
	}

	return 0;
}