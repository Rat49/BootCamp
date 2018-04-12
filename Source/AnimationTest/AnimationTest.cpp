#include "AnimationPlayer.h"
#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	ImageSequenceResource* cat = rm->GetResource<ImageSequenceResource>("cat");
	ImageSequenceResource* fire = rm->GetResource<ImageSequenceResource>("fire");

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* girlAnimationPlayer = new AnimationPlayer(*sprite, *girl, true);
	AnimationPlayer* catAnimationPlayer = new AnimationPlayer(*sprite, *cat, true);

	girlAnimationPlayer->Start(sf::milliseconds(10.0f));
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
				girlAnimationPlayer->Stop();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				girlAnimationPlayer->Pause();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RAlt)
			{
				girlAnimationPlayer->SetLooped(true);
				girlAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RControl)
			{
				girlAnimationPlayer->SetLooped(false);
				girlAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl)
			{
				girlAnimationPlayer->Reset();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				girlAnimationPlayer->Stop();
				catAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
			{
				catAnimationPlayer->Stop();
				girlAnimationPlayer->Start();
			}
		}

		deltaTime = clock.getElapsedTime() - timer;		

		girlAnimationPlayer->Update(deltaTime);
		catAnimationPlayer->Update(deltaTime);
	
		window.clear();
		window.draw(*sprite);
		window.display();

		timer = clock.getElapsedTime();
	}

	return 0;
}