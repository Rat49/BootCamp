#include "Input.h"
#include "Spaceship.h"
#include "DrawableManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceshipNormal");
	//ImageSequenceResource* bulletImgseq = rm->GetResource<ImageSequenceResource>("fire");
	TextureResource* bulletTexture = rm->GetResource<TextureResource>("bullet");
	TextureResource* rocketTexture = rm->GetResource<TextureResource>("rocket");

	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	WindowResolution::SetResolution(window);
	window.clear();

	InputManager* input = new InputManager();
	
	Spaceship* spaceship = new Spaceship(sf::Vector2f(450.0f, 450.0f), sf::Vector2f(0.0f, 15.0f), *input, *spaceshipImgseq, *bulletTexture, *rocketTexture);
	spaceship->Add();
	
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	float currentAngle = 0.0f;

	DrawableManager& drawableManager = DrawableManager::getInstance();

	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		spaceship->Update(deltaTime);

		//std::cout << "_drawableObjects.size(): " << DrawableManager::getInstance()._drawableObjects.size() << std::endl;
		
		window.clear();
		drawableManager.DrawScene(window);

		window.display();
	}


	return 0;
}