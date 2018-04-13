#include <sstream>
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
	ParticleSystem particleSystem(window.getSize());
	particleSystem.SetParticleNumber(100);
	particleSystem.SetPosition(20, 20);
	while (window.isOpen())
	{
		particleSystem.Update();
		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(particleSystem);
		window.display();
	}
	system("pause");
	return 0;
}