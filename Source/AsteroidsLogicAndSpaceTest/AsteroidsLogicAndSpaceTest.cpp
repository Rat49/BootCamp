#include "Asteroid.h"
#include "Star.h"
#include "ResourceManager.h"
#include <iostream>
#include "drawableManager.h"
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

std::vector<Asteroid *> asteroids;
std::vector<Asteroid *> asteroidsNew;

int main()
{
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	DrawableManager& dm = DrawableManager::getInstance();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;//GetFromConfig?
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;

	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	Pool<Star> poolStar(totalCountStar);

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200);
	//int _nAsteroids = 1;
	for (int i = 0; i < _nStars; ++i)
	{
		Star* star = poolStar.Get();
		star->Init(window);

		dm._drawableObjects.push_back(star);
	}
	for (int i = 1; i <= _nAsteroids; ++i)
	{
		Asteroid* asteroid = poolAsteroid.Get();
		asteroid->Init(sprite,window.getSize());
		asteroids.push_back(asteroid);
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
						asteroid->Init(sprite,window.getSize());
						asteroids.push_back(asteroid);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Button::Right)
				{
					if (!(poolAsteroid.Count() == totalCountAsteroids))
					{
						Asteroid* asteroid = dynamic_cast<Asteroid *>(dm._drawableObjects.back());
						asteroids.pop_back();
						poolAsteroid.Put(asteroid);
					}
				}
			}
		}

		window.clear();

		deltaTime = clock.getElapsedTime() - timer;
		for (auto *cAsteroid : asteroids)
		{
			cAsteroid->Update(deltaTime);
			
			if (cAsteroid->_liveTime > 0)
			{
				//cAsteroid->Draw();
				asteroidsNew.push_back(cAsteroid);
			}
			else if (cAsteroid->_allLiveTime == 20.0)
			{
				if (!(poolAsteroid.Count() == totalCountAsteroids))
				{
					Asteroid* asteroid = asteroids.back();
					asteroids.pop_back();
					poolAsteroid.Put(asteroid);
				}
			}
			else
			{
				for (int i = 0; i < 4; ++i)
				{
					if (!poolAsteroid.Empty())
					{
						Asteroid* asteroidNew = poolAsteroid.Get();
						asteroidNew->InitFromCrash(sprite, cAsteroid->_position, cAsteroid->_allLiveTime);
						asteroidsNew.push_back(asteroidNew);
					}
					if (i == 3)
					{
						if (!(poolAsteroid.Count() == totalCountAsteroids))
						{
							Asteroid* asteroid = asteroids.back();
							asteroids.pop_back();
							poolAsteroid.Put(asteroid);
						}
					}
				}
			}
			dm._drawableObjects.emplace_back(cAsteroid);
		}

		asteroids.clear();
		asteroids = asteroidsNew;
		asteroidsNew.clear();

		dm.DrawScene(window);
		window.display();

		timer = clock.getElapsedTime();
	}

	return 0;
}