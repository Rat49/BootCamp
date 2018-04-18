#include "Asteroid.h"
#include "Star.h"
#include "ResourceManager.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

std::vector<Object *> objects;


int main()
{
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 20;//GetFromConfig?
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;

	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	Pool<Star> poolstar(totalCountStar);

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) * (WINDOW_HEIGHT / 200);
	//int _nAsteroids = 2;
	for (int i = 0; i < _nStars; ++i)
	{
		Star* star = poolstar.Get();
		star->Init(window);

		objects.push_back(star);
	}
	for (int i = 1; i <= _nAsteroids; ++i)
	{
		Asteroid* asteroid = poolAsteroid.Get();
		asteroid->Init(sprite, window);
		objects.push_back(asteroid);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					if (!poolAsteroid.Empty())
					{
						Asteroid* asteroid = poolAsteroid.Get();
						asteroid->Init(sprite, window);
						objects.push_back(asteroid);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Button::Right)
				{
					if (!(poolAsteroid.Count() == totalCountAsteroids))
					{
						Asteroid* asteroid = dynamic_cast<Asteroid *>(objects.back());
						objects.pop_back();
						poolAsteroid.Put(asteroid);
					}
				}
			}
		}

		window.clear();

		deltaTime = clock.getElapsedTime() - timer;

		for (auto *object : objects)
		{
			object->Update(deltaTime);
			
			if (object->_live > 0)
				object->Draw();
			
		}

		window.display();

		timer = clock.getElapsedTime();
	}

	return 0;
}