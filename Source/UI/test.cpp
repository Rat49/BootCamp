#include "UI.h"

int main()
{
	UI mui(sf::VideoMode(800,600),"Space");	
	mui.addButton(sf::Vector2f(100, 50), sf::Vector2f(200, 200), "start");
	
	mui._space.display();
	while (mui._space.isOpen())
	{
		sf::Event curEvent;
		while (mui._space.pollEvent(curEvent))
		{
			if (curEvent.type == sf::Event::MouseButtonPressed)
			{
				mui.Get<SfmlButton>("start")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y));
			}
		}
	}

}