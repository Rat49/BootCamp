#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particles.h"
//
class Rocket : public sf::Drawable {
public:
	ParticleSystem particles;

	Rocket(unsigned int quantity, sf::Vector2u window):
		particles(1000, window) {
		particles.setNormalDistrParams(0, 3);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(particles);
	}

	void setPosition(sf::Vector2f position) {
		particles.setEmitterPosition(position);
	}

	void setVelocity(sf::Vector2f velocity) {
		particles.setEmitterVelocity(velocity);
		particles.AddCircleForceForRocket();
	}

	void stop() {
		particles.setRate(0);
	}

	void update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool end() {
		return particles.end;
	}
};

class Explosion : public sf::Drawable {
public:
	ParticleSystem particles;
	sf::Time reccomendedLifeTime = sf::seconds(0.3);

	Explosion(unsigned int quantity, sf::Vector2u window) :
		particles(7000, window) {
		particles.setRate(150);
		particles.setNormalDistrParams(0, 160);
		particles._lifetime = 500;
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(particles);
	}

	void setPosition(sf::Vector2f position) {
		particles.setEmitterPosition(position);
	}

	void stop() {
		particles.setRate(0);
	}

	void update(sf::Time deltaTime) {
		reccomendedLifeTime -= deltaTime;
		if (reccomendedLifeTime <= sf::Time::Zero)
		{
			particles.setRate(0);
			particles.fading = true;
		}
		particles.Update(deltaTime);
	}

	bool end() {
		return particles.end;
	}
};

class Spaceship : public sf::Drawable {
public:
	ParticleSystem particles;

	Spaceship(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		particles._lifetime = 500;
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(particles);
	}

	void setPosition(sf::Vector2f position) {
		particles.setEmitterPosition(position);
	}

	void setVelocity(sf::Vector2f velocity) {
		particles.setEmitterVelocity(velocity);
		particles.AddCircleForceForRocket();
	}

	void stop() {
		particles.fading = true;
		particles.setRate(0);
	}
	void play() {
		particles.fading = false;
		particles.InitializeParticles();
		particles.setRate(10);
	}

	void update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool end() {
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

	ParticleSystem particles(1000, window.getSize());
	particles.SetEmitter(sf::Vector2f(500, 500));
	particles.setEmitterVelocity(sf::Vector2f(2, 2));
	particles.distribution = Distribution::Normal;
	particles.setRate(130);

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	
	int count=0;
	sf::Vector2f LastMousePos(0,0);
	Rocket rocket(1000, window.getSize());
	rocket.setPosition(sf::Vector2f(200, 233));
	rocket.setVelocity(sf::Vector2f(-20, 5));

	Explosion explosion(1000, window.getSize());
	explosion.setPosition(sf::Vector2f(500, 500));

	Spaceship spaceship(1000, window.getSize());
	spaceship.setPosition(sf::Vector2f(300, 500));
	
	while (window.isOpen())
	{

		sf::Vector2f mousePos =
			static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (mousePos.x > 0
			|| mousePos.y > 0
			|| mousePos.x < window.getSize().x
			|| mousePos.y < window.getSize().y)
					particles.setEmitterPosition(mousePos);
		
		if (LastMousePos.x != 0 && LastMousePos.y != 0)
			particles.setEmitterVelocity(mousePos - LastMousePos);

		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		rocket.update(deltaTime * 1.f);
		explosion.update(deltaTime * 1.f);
		spaceship.update(deltaTime * 1.f);
		particles.Update(deltaTime * 1.f);
		
		window.clear(sf::Color::Black);
		window.draw(particles);
		window.draw(rocket);
		window.draw(explosion);
		window.draw(spaceship);

		if (count%47==0) {
			spaceship.stop();
			spaceship.setVelocity(sf::Vector2f(std::rand() % 40 - 20, std::rand() % 40 - 20));
			std::cout << "stop" << std::endl;
		}
		if (count% 97==0) {
			spaceship.play();
			std::cout << "play" << std::endl;
		}
		
		window.display();
		LastMousePos = mousePos;
		count++;
	}
	system("pause");
	return 0;
}