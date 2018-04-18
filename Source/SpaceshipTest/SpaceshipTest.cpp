#include "Input.h"
#include "Spaceship.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceshipNormal");

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* spaceshipAnimationPlayer = new AnimationPlayer(*sprite, *spaceshipImgseq, true);
	InputManager* input = new InputManager();
	
	Spaceship* spaceship = new Spaceship(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, 0.0f), *input, *spaceshipAnimationPlayer);

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	spaceshipAnimationPlayer->Start();

	float currentAngle = 0.0f;

	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		spaceship->Update(deltaTime);

		window.clear();
		window.draw(*sprite);
		window.display();
	}


	return 0;
}