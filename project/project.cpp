// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ResourseManager.h"
int main()
{/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/
	ResourseManager *rm = new ResourseManager();
	ResourseManager::res_type tmp = rm->getTypeByFilename("C:\Project\BootCamp\Debug\tewtetwt.wav");
    return 0;
}

