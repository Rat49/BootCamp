#include "AnimationPlayer.h"
#include "ResourceManager.h"

int main()
{
	std::vector<float> _settingsForFrame = { 110, 151, 27, 28, 150, 2, 2 };
	ResourceManager *rm = new ResourceManager(_settingsForFrame);
	int counterPicture = 0;
	int counterImageSequence = 0;

	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	counterImageSequence = girl->GetRefCounter();
	std::vector<sf::Texture> _texturesGirl = girl->Get();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* animationPlayer = new AnimationPlayer(sprite, _texturesGirl, true);

	animationPlayer->Start(sf::seconds(28.0));
	while (window.isOpen())
	{
		animationPlayer->Update();
	
		window.clear();
		window.draw(*sprite);
		window.display();
	}

	//sprite->setTexture(_texturesGirl[1]);
	//window.draw(*sprite);
	//window.display();

	return 0;
}