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
	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
		particles.AddCircleForceForRocket();
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
		particles.AddCircleForceForRocket();
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

	ParticleSystem particles(1000, window.getSize());
	particles.SetEmitterPosition(sf::Vector2f(500, 500));
	particles.SetEmitterVelocity(sf::Vector2f(2, 2));
	particles.distribution = Distribution::Normal;
	particles.SetRate(130);

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	int count = 0;
	sf::Vector2f LastMousePos(0, 0);
	Rocket rocket(1000, window.getSize());
	rocket.SetPosition(sf::Vector2f(200, 233));
	rocket.SetVelocity(sf::Vector2f(-20, 5));

	Explosion* explosion = new Explosion(1000, window.getSize());
	explosion->SetPosition(sf::Vector2f(500, 500));

	Spaceship spaceship(1000, window.getSize());
	spaceship.SetPosition(sf::Vector2f(300, 500));

	while (window.isOpen())
	{

		sf::Vector2f mousePos =
			static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (mousePos.x > 0
			|| mousePos.y > 0
			|| mousePos.x < window.getSize().x
			|| mousePos.y < window.getSize().y)
			particles.SetEmitterPosition(mousePos);

		if (LastMousePos.x != 0 && LastMousePos.y != 0)
			particles.SetEmitterVelocity(mousePos - LastMousePos);

		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		rocket.Update(deltaTime * 1.f);
		explosion->Update(deltaTime * 1.f);
		spaceship.Update(deltaTime * 1.f);
		particles.Update(deltaTime * 1.f);

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
		LastMousePos = mousePos;
		count++;
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	return 0;
}