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
		particles.update(deltaTime);
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
	particles.setEmitter(sf::Vector2f(500, 500));
	particles.setEmitterVelocity(sf::Vector2f(2, 2));
	particles.distribution = Distribution::Normal;
	particles.setRate(130);


	ParticleSystem particles1(1000, window.getSize());
	//particles1.setEmitter(sf::Vector2f(350, 350));
	particles1.distribution = Distribution::Uniform;
	//particles1.setRate(10);
	//particles1.setEmitterVelocity(sf::Vector2f(-20,5));
	//particles1.AddCircleForce(particles1.m_emitter - sf::Vector2f(2 * particles1.emitterVelocity.x + 15, 2 * particles1.emitterVelocity.y + 15), 20, -0.4);
	//particles1.AddCircleForce(particles1.m_emitter - sf::Vector2f(4 * particles1.emitterVelocity.x + 15, 4 *  particles1.emitterVelocity.y + 20), 20, -0.4);
	//particles1.AddCircleForce(particles1.m_emitter - sf::Vector2f(6 * particles1.emitterVelocity.x+10, 6 *      particles1.emitterVelocity.y + 10), 20, 0.8);

	//ParticleSystem particles2(1000, window.getSize());
	//particles2.setEmitter(sf::Vector2f(450, 450));
	//particles2.setRate(10);
	//particles2.setEmitterVelocity(sf::Vector2f(-10,0));
	//particles2.distribution = Distribution::Uniform;
	//particles2.setUniformDistrRange(90);

	//ParticleSystem particles3(100, window.getSize());
	//particles3.setEmitter(sf::Vector2f(350, 350));
	//particles3.setRate(10);
	//particles3.setEmitterVelocity(sf::Vector2f(-20, 5));
	//particles3.distribution = Distribution::Uniform;

	//ParticleSystem particles4(100, window.getSize());
	//particles4.setEmitter(sf::Vector2f(350, 350));
	//particles4.setRate(10);
	//particles4.setEmitterVelocity(sf::Vector2f(-14, -7));


	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	
	int count=0;
	sf::Vector2f LastMousePos(0,0);
	Rocket rocket(1000, window.getSize());
	rocket.setPosition(sf::Vector2f(200, 233));
	rocket.setVelocity(sf::Vector2f(-20, 5));
	
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
		if (count == 100)
			rocket.stop();

		//particles.update(deltaTime * 1.f);
		particles1.update(deltaTime * 1.f);
		/*particles2.update(deltaTime * 1.f);
		particles3.update(deltaTime * 1.f);
		particles4.update(deltaTime * 1.f);
		*/
		window.clear(sf::Color::Black);
		//window.draw(particles);
		window.draw(rocket);
		//window.draw(particles1);
		/*window.draw(particles2);*/
		//window.draw(particles3);
		//window.draw(particles4);
		window.display();
		LastMousePos = mousePos;
		count++;
	}
	system("pause");
	return 0;
}