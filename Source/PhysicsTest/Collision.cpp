#include "stdafx.h"
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>

class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	float positionX, positionY;
	float speedX, speedY;
	float radius;
};
Asteroid::Asteroid()
{

}

Asteroid::~Asteroid()
{

}
int main()
{
	int time =1;
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
	}
	Asteroid asteroid1;
	Asteroid asteroid2;

	asteroid1.positionX = 100;
	asteroid1.positionY = 100;
	asteroid1.radius = 10;
	asteroid1.speedX = 0.01f;
	asteroid1.speedY = 0;

	asteroid2.positionX = 200;
	asteroid2.positionY = 95;
	asteroid2.radius = 10;
	asteroid2.speedX = -0.01f;
	asteroid2.speedY = 0;

	while (time)
	{
		rw.clear();
		sf::CircleShape asterid_1;
		asterid_1.setRadius(asteroid1.radius);
		asterid_1.setFillColor(sf::Color::Yellow);
		asterid_1.setPosition(asteroid1.positionX, asteroid1.positionY);


		sf::CircleShape asterid_2;
		asterid_2.setRadius(asteroid2.radius);
		asterid_2.setFillColor(sf::Color::Yellow);
		asterid_2.setPosition(asteroid2.positionX, asteroid2.positionY);

		rw.draw(asterid_1);
		rw.draw(asterid_2);

		float distance = sqrt((asteroid1.positionX - asteroid2.positionX)*(asteroid1.positionX - asteroid2.positionX) +
			(asteroid1.positionY - asteroid2.positionY)*(asteroid1.positionY - asteroid2.positionY));
		float overlap = 0.5f * (distance - asteroid1.radius - asteroid2.radius);

		if (distance < asteroid1.radius + asteroid2.radius)
		{
			asteroid1.positionX -= overlap * (asteroid1.positionX - asteroid2.positionX) / distance;
			asteroid1.positionY -= overlap * (asteroid1.positionY - asteroid2.positionY) / distance;

			asteroid2.positionX += overlap * (asteroid1.positionX - asteroid2.positionX) / distance;
			asteroid2.positionY += overlap * (asteroid1.positionY - asteroid2.positionY) / distance;
		}

		asteroid2.positionX += asteroid2.speedX;
		asteroid1.positionX += asteroid1.speedX;
		asteroid2.positionY += asteroid2.speedY;
		asteroid1.positionY += asteroid1.speedY;
		rw.display();
	}

	return 0;
}
