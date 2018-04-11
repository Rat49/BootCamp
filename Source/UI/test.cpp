#include "UI.h"

int main()
{
	UI mui(sf::VideoMode(800,600),"Space");	
	mui.addButton(sf::Vector2f(100, 50), sf::Vector2f(200, 200), "start");
	mui.addButton(sf::Vector2f(20, 30), sf::Vector2f(300, 300), "test");
	
	while (mui._space.isOpen())
	{
		sf::Event curEvent;
		while (mui._space.pollEvent(curEvent))
		{
			if (curEvent.type == sf::Event::MouseButtonPressed)
			{
				if (mui.Get<SfmlButton>("start")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
				{
					mui.SetPostion("start", rand() % (100), rand() % (100));
					mui.Get<SfmlButton>("start")->GetBody().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
				}
				if (mui.Get<SfmlButton>("test")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
				{
					mui.Get<SfmlButton>("start")->GetBody().setFillColor(sf::Color::White);
				}
			}			
		}
		mui.Render();
	}

}