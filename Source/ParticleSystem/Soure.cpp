#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particles.h"

int main()
{
	sf::VideoMode videoMode(800, 800);
	sf::RenderWindow window(
		sf::VideoMode(videoMode),
		"Inside the Particle Storm");
	window.setVerticalSyncEnabled(true);

	sf::Text text;
	text.setPosition(
		static_cast<float>(window.getSize().x) * 0.01f,
		static_cast<float>(window.getSize().y) * 0.01f);
	ParticleSystem particles(1000, window.getSize());
	particles.setEmitter(sf::Vector2f(500, 500));
	particles.setForce(sf::Vector2f(50, -50));
	particles.fuel();
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		particles.update(deltaTime * 1.f);

		
		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(particles);
		window.display();
	}
	system("pause");
	return 0;
}