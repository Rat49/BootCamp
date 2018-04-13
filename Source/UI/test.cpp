#include "UI.h"
#include <iostream>


int main()
{
	
	UI mui(sf::VideoMode(800,600),"Space");	

	mui.Add(new SfmlButton(sf::Vector2f(100, 50), sf::Vector2f(200, 200),"start"), "start");
	mui.Add(new SfmlButton(sf::Vector2f(20, 30), sf::Vector2f(300, 300),"test"), "test");

	sf::Font font;
	font.loadFromFile("arial.ttf");
	mui.Add(new Label("helllowworld",font,sf::Vector2f(0, 0), "label"),"label");

	mui.Add(new ScrollBar(100, sf::Vector2f(100, 100), "scroll"), "scroll");

	mui.Get<ScrollBar>("scroll")->SetFillColor(sf::Color::Green);
	mui.Get<ScrollBar>("scroll")->SetLength(200);
	while (mui._space.isOpen())
	{
		sf::Event curEvent;

		while (mui._space.pollEvent(curEvent))
		{
			switch(curEvent.type)
			{
				case sf::Event::MouseButtonPressed:
					mui.Get<ScrollBar>("scroll")->ChangeStateGrab(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y));
					if (mui.Get<SfmlButton>("start")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
					{
						mui.SetPostion("start", (rand() % 1000)/10, (rand() % 1000)/10);
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
					mui.onResize();
					break;
				default:
					break;
			}		
			mui.Render();
		}
	}

}