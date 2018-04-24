#include "Asteroid.h"
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "EventSystem.h"
#include "ResourceManager.h"
#include "Star.h"

#include <thread>
#include <chrono>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main()
{
	sf::Clock clock;

	constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
	float           accumulatedFrameTime = 0.f;

	Dispatcher &   dispatcher = Dispatcher::getInstance();

	DrawableManager& dm = DrawableManager::getInstance();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	std::vector<Asteroid *> asteroids;

	CollisionEvent<Asteroid> collisionEvent(poolAsteroid, asteroids);
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Pool<Star> poolStar(totalCountStar);
	std::vector<Star *> stars;

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200);
	//int _nAsteroids = 2;

	for (int i = 0; i < _nStars; ++i)
	{
		Star* star = poolStar.Get();
		star->Init(window.getSize());
		stars.push_back(star);
	}
	for (int i = 1; i <= _nAsteroids; ++i)
	{
		Asteroid* asteroid = poolAsteroid.Get();
		asteroid->Init(sprite,window.getSize());
		asteroids.push_back(asteroid);
	}

	bool exit = false;
	while (window.isOpen())
	{
		const float delta = clock.restart().asMicroseconds() / 1e3;
		accumulatedFrameTime += delta;

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				exit = true;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					exit = true;
				}
			}
			if (exit)
			{
				
				window.close();
			}
		}
		window.clear();
		while (accumulatedFrameTime >= physicsStepTargetFrameTime)
		{
			accumulatedFrameTime -= physicsStepTargetFrameTime;

			size_t n = asteroids.size() - 1;
		    size_t m = asteroids.size();
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = i + 1; j < m; ++j)
				{
					if (Collided(*asteroids[i], *asteroids[j]))
					{
						collisionEvent._obj1 = asteroids[i];
						collisionEvent._obj2 = asteroids[j];
						ResolveCollision(*asteroids[i], *asteroids[j]);
						dispatcher.Send(collisionEvent, collisionEventID, asteroids[i]->_token);
						dispatcher.Send(collisionEvent, collisionEventID, asteroids[j]->_token);
					}
				}
			}

			for (size_t i = 0; i < asteroids.size(); ++i)
			{
				if (asteroids[i]->_life == false)
				{
					if (!(poolAsteroid.Count() == poolAsteroid.MaxCount()))
					{
						asteroids[i]->Remove();
						poolAsteroid.Put(asteroids[i]);
						asteroids.erase(std::find(asteroids.begin(), asteroids.end(), asteroids[i]));
						--i;
					}
				}
			}

			for (auto *asteroid : asteroids)
			{
				asteroid->Update(physicsStepTargetFrameTime / 1e3);
			}
			for (auto *star : stars)
			{
				star->Update(physicsStepTargetFrameTime / 1e3);
			}
		}

		dm.DrawScene(window);
		window.display();
	}

	for (auto &asteroid : asteroids)
	{
		if (!(poolAsteroid.Count() == poolAsteroid.MaxCount()))
		{
			asteroid->Remove();
			poolAsteroid.Put(asteroid);
		}
	}

	for (auto &star : stars)
	{
		if (!(poolStar.Count() == poolStar.MaxCount()))
		{
			star->Remove();
			poolStar.Put(star);
		}
	}
	return 0;
}