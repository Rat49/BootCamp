#include "AnimationPlayer.h"
#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterPicture = 0;
	int counterImageSequence = 0;

	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	counterImageSequence = girl->GetRefCounter();
	std::vector<sf::Texture> _texturesGirl = girl->Get();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	sf::Time time = girl->GetTime();

	AnimationPlayer* animationPlayer = new AnimationPlayer(sprite, _texturesGirl, time, true);

	animationPlayer->Start(sf::milliseconds(10.0f));
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				animationPlayer->Reset();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
			{
				animationPlayer->Reset();
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