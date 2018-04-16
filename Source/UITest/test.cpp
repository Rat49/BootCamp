#include "UI.h"
#include "SFML\Graphics.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space");
	UI mui(window);
	mui.CreateButton(sf::Vector2f(100,100), sf::Vector2f(55, 43),"start");
	mui.CreateButton(sf::Vector2f(20, 30), sf::Vector2f(21, 15), "test");
	mui.CreateScrollBar(100, sf::Vector2f(46, 30), "scroll");
	sf::Font font;
	font.loadFromFile("arial.ttf");
	mui.CreateLabel("hello",font,sf::Vector2f(1,1),"label");
	mui.Get<ScrollBar>("scroll")->SetFillColor(sf::Color::Green);
	mui.Get<ScrollBar>("scroll")->SetLength(200);
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		window.clear();
		sf::Event curEvent;
		while (window.pollEvent(curEvent))
		{
			switch(curEvent.type)
			{
				case sf::Event::MouseButtonPressed:
					mui.Get<ScrollBar>("scroll")->ChangeStateGrab(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y));
					if (mui.Get<SfmlButton>("start")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
					{
						mui.SetPostion("start", sf::Vector2f((rand() % 1000)/10, (rand() % 1000)/10));
						mui.Get<SfmlButton>("start")->SetFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
					}
					if (mui.Get<SfmlButton>("test")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
					{
						mui.Get<SfmlButton>("start")->SetFillColor(sf::Color::White);
					}
					break;
				case sf::Event::MouseButtonReleased:
					mui.Get<ScrollBar>("scroll")->UnGrab();
					break;
				case sf::Event::Resized:  					
					mui.OnResize();
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}		
		}
		mui.Render();
	}
}