#include "Asteroid.h"
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "EventSystem.h"
#include "ResourceManager.h"
#include "Star.h"
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

std::vector<Asteroid *> asteroids;
std::vector<Star *> stars;

int main()
{
	sf::Clock clock;

	constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
	float           accumulatedFrameTime = 0.f;

	CollisionEvent collisionEvent;
	Dispatcher &   dispatcher = Dispatcher::getInstance();

	DrawableManager& dm = DrawableManager::getInstance();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;

	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	Pool<Star> poolStar(totalCountStar);

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200);

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
		dispatcher.Connect(EventTypes::collisionEventID, Asteroid::OnCollisionHandler);
		
		asteroids.push_back(asteroid);
	}

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
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
		window.clear();

		while (accumulatedFrameTime >= physicsStepTargetFrameTime)
		{
			accumulatedFrameTime -= physicsStepTargetFrameTime;
			for (int i = 0; i < asteroids.size(); ++i)
			{
				for (int j = 0; j < asteroids.size(); ++j)
				{
					if (i != j)
					{
						if (Collided(*asteroids[i], *asteroids[j]))
						{
							//collisionEvent.setObjs(*asteroids[i], *asteroids[j]);
							dispatcher.Send(collisionEvent, collisionEventID);
							ResolveCollision(*asteroids[i], *asteroids[j]);
							asteroids[i]->_health -= 50;
							asteroids[j]->_health -= 50;
						}
					}
				}
			}

			for (auto *star : stars)
			{
				star->Update(physicsStepTargetFrameTime / 1e3);
			}
			for (size_t i = 0; i < asteroids.size(); ++i)
			{
				Asteroid* cAsteroid = asteroids[i];
				cAsteroid->Update(physicsStepTargetFrameTime / 1e3);

				if (cAsteroid->_health <= 0)
				{
					if (cAsteroid->_type == AsteroidType::Small)
					{
						if (!(poolAsteroid.Count() == totalCountAsteroids))
						{
							asteroids.erase(asteroids.cbegin() + i);
							--i;
							poolAsteroid.Put(cAsteroid);
						}
					}
					else
					{
						for (int j = 0; j < 4; ++j)
						{
							if (!poolAsteroid.Empty())
							{
								Asteroid* asteroidNew = poolAsteroid.Get();
								asteroidNew->InitFromCrash(sprite, cAsteroid->GetCoordinates(), cAsteroid->_type, window.getSize());
								asteroids.push_back(asteroidNew);
							}
						}
						if (!(poolAsteroid.Count() == totalCountAsteroids))
						{
							asteroids.erase(asteroids.cbegin() + i);
							--i;
							poolAsteroid.Put(cAsteroid);
						}
					}
				}
			}
		}
		
		dm.DrawScene(window);
		window.display();
	}

	return 0;
}