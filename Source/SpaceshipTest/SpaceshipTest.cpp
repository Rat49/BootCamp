#include "Input.h"
#include "Spaceship.h"
#include "DrawableManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceshipNormal");
	ImageSequenceResource* bulletImgseq = rm->GetResource<ImageSequenceResource>("fire");

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	window.clear();
	sf::Sprite* spaceshipSprite = new sf::Sprite();
	sf::Sprite* bulletLeft = new sf::Sprite();
	sf::Sprite* bulletReght = new sf::Sprite();

	AnimationPlayer* spaceshipAnimationPlayer = new AnimationPlayer(*spaceshipSprite, *spaceshipImgseq, true);
	AnimationPlayer* bulletLeftAnimationPlayer = new AnimationPlayer(*bulletLeft, *bulletImgseq, true);
	AnimationPlayer* bulletRightAnimationPlayer = new AnimationPlayer(*bulletReght, *bulletImgseq, true);
	InputManager* input = new InputManager();
	
	Spaceship* spaceship = new Spaceship(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(1.0f, 1.0f), sf::Vector2f(2.0f, 2.0f), *input, *spaceshipAnimationPlayer, *bulletLeftAnimationPlayer, *bulletRightAnimationPlayer);

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

		for (auto drawableObject : DrawableManager::_drawableObjects)
		{
			drawableObject->Draw(window);
		}

		window.clear();
		window.draw(*spaceshipSprite);
		window.display();
	}


	return 0;
}