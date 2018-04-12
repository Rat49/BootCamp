#include "AnimationPlayer.h"
#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterPicture = 0;
	int counterImageSequence = 0;

	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	counterImageSequence = girl->GetRefCounter();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* animationPlayer = new AnimationPlayer(sprite, girl, true);

	animationPlayer->Start(sf::milliseconds(10.0f));
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				animationPlayer->Reset();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				animationPlayer->Pause();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RAlt)
			{
				animationPlayer->SetLooped(true);
				animationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RControl)
			{
				animationPlayer->SetLooped(false);
				animationPlayer->Start();
			}
		}

		animationPlayer->Update(clock.getElapsedTime());
	
		window.clear();
		window.draw(*sprite);
		window.display();
		clock.restart();
	}

	return 0;
}