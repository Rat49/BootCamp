#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Particles.h"
#include "Drawable.h"

class Rocket {
public:
	ParticleSystem particles;

	Rocket(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		particles.SetNormalDistrParams(0, 3);
		particles.AddColor(0.3, sf::Color::Cyan);
		particles.AddColor(0.7, sf::Color::Green);
		particles.SetParticlesLifetime(2000);
	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
		particles.AddCircleForceBehind(3, 20, 0.5);
		particles.AddCircleForceBehind(6, 40, -0.3);
		particles.AddCircleForceBehind(9, 40, 0.5);
		particles.AddCircleForceBehind(12, 40, 0.2);

	}

	void Stop() {
		particles.SetRate(0);
	}

	void Update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};

class Explosion {
public:
	ParticleSystem particles;
	sf::Time reccomendedLifeTime = sf::seconds(0.2);

	Explosion(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		particles.SetRate(150);
		particles.SetNormalDistrParams(0, 160);
		particles.SetParticlesLifetime(500);
		particles.SetStandartColors();

	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void Stop() {
		particles.SetRate(0);
	}

	void Update(sf::Time deltaTime) {
		reccomendedLifeTime -= deltaTime;
		if (reccomendedLifeTime <= sf::Time::Zero)
		{
			particles.SetRate(0);
			particles.fading = true;
		}
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};

class Spaceship{
public:
	ParticleSystem particles;

	Spaceship(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		particles.SetParticlesLifetime(500);
	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
		particles.AddCircleForceBehind(3, 40, -0.5);
		particles.AddCircleForceBehind(6, 40, 0.5);
		particles.AddCircleForceBehind(9, 40, -0.5);
		particles.AddCircleForceBehind(12, 40, 0.5);
	}

	void Stop() {
		particles.fading = true;
		particles.SetRate(0);
	}
	void Play() {
		particles.fading = false;
		particles.InitializeParticles();
		particles.SetRate(10);
	}

	void Update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};

int main()
{
	sf::VideoMode videoMode(800, 800);
	sf::RenderWindow window(
		sf::VideoMode(videoMode),
		"Particle");
	window.setVerticalSyncEnabled(true);

	DrawableManager& dm = DrawableManager::getInstance();

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	int count = 0;
	sf::Vector2f LastMousePos(0, 0);
	Rocket rocket(1000, window.getSize());
	rocket.SetPosition(sf::Vector2f(600, 233));
	rocket.SetVelocity(sf::Vector2f(-20, 5));

	Explosion* explosion = new Explosion(1000, window.getSize());
	explosion->SetPosition(sf::Vector2f(500, 500));

	Spaceship spaceship(1000, window.getSize());
	spaceship.SetPosition(sf::Vector2f(300, 500));
	
	sf::Event event;
	
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized) {
				Dispatcher & dispatcher = Dispatcher::getInstance();
				sf::Vector2u windowsize = window.getSize();
				ResizeWindowEvent resizeEvent(windowsize);
				dispatcher.Send(resizeEvent, EventTypes::resizeWindowEventId);
			}
		}

		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		rocket.Update(deltaTime * 1.f);
		explosion->Update(deltaTime * 1.f);
		spaceship.Update(deltaTime * 1.f);

		window.clear(sf::Color::Black);
		
		dm.DrawScene(window);
		//~~~~~~~~~~~~~~just for testing~~~~~~~~~~~~~~~~~
		if (count % 47 == 0) {
			spaceship.Stop();
			spaceship.SetVelocity(sf::Vector2f(std::rand() % 40 - 20, std::rand() % 40 - 20));
		}
		if (count % 97 == 0) {
			spaceship.Play();
		}
		if (explosion->IsEnd()) {
			explosion = new Explosion(1000, window.getSize());
			explosion->SetPosition(sf::Vector2f(std::rand() % 50 + 500, std::rand() % 50 + 500));
		}
		window.display();
		count++;
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	return 0;
}