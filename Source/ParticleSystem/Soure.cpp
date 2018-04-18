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

	ParticleSystem particles(1000, window.getSize());
	particles.setEmitter(sf::Vector2f(500, 500));
	particles.setEmitterVelocity(sf::Vector2f(2, 2));
	particles.AddCircleForce(sf::Vector2f(350, 450), 50, -2);
	particles.AddCircleForce(sf::Vector2f(200, 450), 50, 2);
	particles.setRate(130);


	ParticleSystem particles1(1000, window.getSize());
	particles1.setEmitter(sf::Vector2f(350, 350));
	particles1.setRate(10);
	particles1.setEmitterVelocity(sf::Vector2f(20,5));

	ParticleSystem particles2(100, window.getSize());
	particles2.setEmitter(sf::Vector2f(350, 350));
	particles2.setRate(10);
	particles2.setEmitterVelocity(sf::Vector2f(-10, 20));

	ParticleSystem particles3(100, window.getSize());
	particles3.setEmitter(sf::Vector2f(350, 350));
	particles3.setRate(10);
	particles3.setEmitterVelocity(sf::Vector2f(20, -20));

	ParticleSystem particles4(100, window.getSize());
	particles4.setEmitter(sf::Vector2f(350, 350));
	particles4.setRate(10);
	particles4.setEmitterVelocity(sf::Vector2f(-14, -7));


	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	


	while (window.isOpen())
	{
		
		sf::Vector2f mousePos =
			static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		
		if (mousePos.x > 0
			|| mousePos.y > 0
			|| mousePos.x < window.getSize().x
			|| mousePos.y < window.getSize().y)
			particles.setEmitterPosition(mousePos);

		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		particles.update(deltaTime * 1.f);
		particles1.update(deltaTime * 1.f);
		particles2.update(deltaTime * 1.f);
		particles3.update(deltaTime * 1.f);
		particles4.update(deltaTime * 1.f);
		
		window.clear(sf::Color::Black);
		//window.draw(particles);

		window.draw(particles1);
		//window.draw(particles2);
		//window.draw(particles3);
		//window.draw(particles4);
		window.display();
	}
	system("pause");
	return 0;
}