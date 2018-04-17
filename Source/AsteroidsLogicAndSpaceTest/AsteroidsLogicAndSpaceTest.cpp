#include "Asteroid.h"
#include "Space.h"
#include "ResourceManager.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main()
{
	srand(time(0));

	sf::Rect<int> border;
	border.top = 0;
	border.left = 0;
	border.width = WINDOW_WIDTH;
	border.height = WINDOW_HEIGHT;

	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	PictureResource* asteroid = rm->GetResource<PictureResource>("asteroid");
	sf::Image image(*asteroid->Get());
	image.createMaskFromColor(sf::Color(0, 35, 57, 255), 0);

	sf::Sprite sprite;
	sf::Texture asteroidTexture;
	asteroidTexture.loadFromImage(image, sf::IntRect(300,90,85,85));
	sprite.setTexture(asteroidTexture);

	std::vector<Object *> objects;
	
	Space* space = new Space(border);
	std::vector<ParticleSpace*> elements = space->GetElements();
	for (auto element : elements)
	{
		objects.push_back(element);
	}

	int nAsteroids = 10;
	for (int currentAsteroid = 1; currentAsteroid <= nAsteroids; ++currentAsteroid)
	{
		Asteroid *asteroid = new Asteroid(sprite, border, currentAsteroid);
		objects.push_back(asteroid);
	}
	
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
			{
				window.close();
			}
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		window.clear();

		for (auto *object : objects)
		{
			object->Update(time);
			object->Draw(&window);
		}

		window.display();
	}

	return 0;
}