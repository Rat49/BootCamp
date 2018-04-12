#include "UI.h"

int main()
{
	UI mui(sf::VideoMode(800,600),"Space");	
	mui.Add(new SfmlButton(sf::Vector2f(100, 50), sf::Vector2f(200, 200),"start"), "start");
	mui.Add(new SfmlButton(sf::Vector2f(20, 30), sf::Vector2f(300, 300),"test"), "test");
	//mui.addLabel("helllowworld", sf::Vector2f(0, 0), "label");
	
	while (mui._space.isOpen())
	{
		sf::Event curEvent;
		while (mui._space.pollEvent(curEvent))
		{
			switch(curEvent.type)
			{
				case sf::Event::MouseButtonPressed:
					if (mui.Get<SfmlButton>("start")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
					{
						mui.SetPostion("start", (rand() % 1000)/10, (rand() % 1000)/10);
						mui.Get<SfmlButton>("start")->SetColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
					}
					if (mui.Get<SfmlButton>("test")->IsClicked(sf::Vector2i(curEvent.mouseButton.x, curEvent.mouseButton.y)))
					{
						mui.Get<SfmlButton>("start")->SetColor(sf::Color::White);
					}
					break;
				case sf::Event::Resized:
						//mui._space.setSize(sf::Vector2u(1200,600));
						mui.onResized();
					break;
				default:
					break;
			}		
		}
		mui.Render();
	}

}