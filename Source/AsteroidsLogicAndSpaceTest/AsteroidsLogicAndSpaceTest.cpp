#include "AnimationPlayer.h"
#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* space = rm->GetResource<ImageSequenceResource>("space");

	sf::RenderWindow window(sf::VideoMode(500, 375), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* spaceAnimationPlayer = new AnimationPlayer(*sprite, *space, true);

	spaceAnimationPlayer->Start(sf::milliseconds(10.0f));
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				spaceAnimationPlayer->Stop();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				spaceAnimationPlayer->Pause();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RAlt)
			{
				spaceAnimationPlayer->SetLooped(true);
				spaceAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RControl)
			{
				spaceAnimationPlayer->SetLooped(false);
				spaceAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl)
			{
				spaceAnimationPlayer->Reset();
			}
		}

		deltaTime = clock.getElapsedTime() - timer;

		spaceAnimationPlayer->Update(deltaTime);

		window.clear();
		window.draw(*sprite);
		window.display();

		timer = clock.getElapsedTime();
	}

	return 0;
}