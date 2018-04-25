#include "Asteroid.h"
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "EventSystem.h"
#include "ResourceManager.h"
#include "ConfigManager.h"
#include "Star.h"
#include "Space.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main()
{
	sf::Clock clock;
	ConfigManager* cm1 = ConfigManager::Create("GameConfig.INI");

	/*
	ResourceManager Initialization
	*/

	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").getParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").getParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").getParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first,
			cm1->GetCategory("ImageSequenceResource." + i.first).getParams()));
	}
	resourceConfig.insert(std::make_pair("TextureResource", cm1->GetCategory("TextureResource").getParams()));


	constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
	float           accumulatedFrameTime = 0.f;

	Dispatcher &   dispatcher = Dispatcher::getInstance();

	DrawableManager& dm = DrawableManager::getInstance();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");
	
	ResourceManager *rm = new ResourceManager(resourceConfig);

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroidTexture");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Space space(totalCountAsteroids, totalCountStar, window.getSize());

	CollisionEventBetweenAsteroids collisionEvent;


	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200);
	//int _nAsteroids = 2;
	sf::Sprite spriteAsteroid(asteroidTexture);
	space.AddSomeStars(_nStars);
	space.AddSomeAsteroids(_nAsteroids, spriteAsteroid);

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

			size_t n = space._asteroids.size() - 1;
		    size_t m = space._asteroids.size();
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = i + 1; j < m; ++j)
				{
					if (Collided(*space._asteroids[i], *space._asteroids[j]))
					{
						collisionEvent._asteroid1 = space._asteroids[i];
						collisionEvent._asteroid2 = space._asteroids[j];
						ResolveCollision(*space._asteroids[i], *space._asteroids[j]);
						dispatcher.Send(collisionEvent, collisionEventID, space._asteroids[i]->_token);
						dispatcher.Send(collisionEvent, collisionEventID, space._asteroids[j]->_token);
					}
				}
			}

			for (size_t i = 0; i < space._asteroids.size(); ++i)
			{
				if (space._asteroids[i]->_life == false)
				{
					if (!(space._poolAsteroid.Count() == space._poolAsteroid.MaxCount()))
					{
						space._asteroids[i]->Remove();
						space._poolAsteroid.Put(space._asteroids[i]);
						space._asteroids.erase(std::find(space._asteroids.begin(), space._asteroids.end(), space._asteroids[i]));
						--i;
					}
				}
			}

			for (auto *asteroid : space._asteroids)
			{
				asteroid->Update(physicsStepTargetFrameTime / 1e3);
			}
			for (auto *star : space._stars)
			{
				star->Update(physicsStepTargetFrameTime / 1e3);
			}
		}

		dm.DrawScene(window);
		window.display();
	}

	for (auto &asteroid : space._asteroids)
	{
		if (!(space._poolAsteroid.Count() == space._poolAsteroid.MaxCount()))
		{
			asteroid->Remove();
			space._poolAsteroid.Put(asteroid);
		}
	}

	for (auto &star : space._stars)
	{
		if (!(space._poolStar.Count() == space._poolStar.MaxCount()))
		{
			star->Remove();
			space._poolStar.Put(star);
		}
	}
	return 0;
}