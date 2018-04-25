#include "UI.h"
#include "SFML\Graphics.hpp"


int main()
{
	sf::Image * img = new sf::Image();
	img->loadFromFile("img/asteroid.png");
	sf::Texture texture;
	sf::Texture empty;
	texture.loadFromImage(*img);
	sf::Sprite spr;
	//spr.setTextureRect(sf::IntRect(200,200, 100, 100));
	spr.setTexture(texture, true);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space");
	UI mui(window);
	mui.CreateButton(sf::Vector2f(100,100), PercentXY(20,30),"start");
	mui.CreateButton(sf::Vector2f(20, 30), PercentXY(21, 15), "test");
	mui.CreateScrollBar(100, PercentXY(46, 30), "scroll");	
	sf::Font font;
	font.loadFromFile("font/arial.ttf");
	mui.CreateLabel("hello",font, PercentXY(1,1),"label");
	mui.CreateAchivementShower(font, PercentXY(80, 80));
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
						mui.SetPostion("start", PercentXY((rand() % 1000)/10, (rand() % 1000)/10));
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
				case sf::Event::KeyPressed:
					if (curEvent.key.code == sf::Keyboard::E)
					{
						sf::Image * img = new sf::Image();
						img->loadFromFile("img/asteroid.png");//Get Image From ResourceManager
						mui.OnAchive("SomeAchive", img);
					}
					break;
				default:
					break;
			}		
		}
		mui.Render();
	}
}