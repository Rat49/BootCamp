#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particles.h"

int main()
{
	sf::VideoMode videoMode(800, 800);
	sf::RenderWindow window(
		sf::VideoMode(videoMode),
		"Particle");
	window.setVerticalSyncEnabled(true);

	ParticleSystem particles(4000, window.getSize());
	particles.setEmitter(sf::Vector2f(500, 500));
	particles.setForce(sf::Vector2f(-60, 60));
	//particles.fuel();

	ParticleSystem particles1(4000, window.getSize());
	particles1.setEmitter(sf::Vector2f(550, 550));
	particles1.setForce(sf::Vector2f(-60, 60));
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		particles.update(deltaTime * 1.f);
		particles1.update(deltaTime * 1.f);
		
		window.clear(sf::Color::Black);
		window.draw(particles);

		window.draw(particles1);
		window.display();
	}
	system("pause");
	return 0;
}