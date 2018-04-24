#include "DrawableManager.h"
#include "Spaceship.h"
#include "BulletManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceshipNormal");
	ImageSequenceResource* flickeringImgseq = rm->GetResource<ImageSequenceResource>("spaceshipFlickering");
	TextureResource* bulletTexture = rm->GetResource<TextureResource>("bullet");
	TextureResource* rocketTexture = rm->GetResource<TextureResource>("rocket");

	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	WindowResolution::SetResolution(window);

	InputManager* input = new InputManager();
	Spaceship* spaceship = new Spaceship(sf::Vector2f(450.0f, 450.0f), sf::Vector2f(0.0f, 15.0f), *input, *spaceshipImgseq, *flickeringImgseq);
	spaceship->Add();
	BulletManager bulletManager(*bulletTexture,*rocketTexture);
	DrawableManager& drawableManager = DrawableManager::getInstance();

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		spaceship->Update(deltaTime);
		bulletManager.Update(deltaTime);

		window.clear();
		drawableManager.DrawScene(window);

		window.display();
	}
}