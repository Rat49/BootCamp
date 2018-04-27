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
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").GetParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").GetParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").GetParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first,
			cm1->GetCategory("ImageSequenceResource." + i.first).GetParams()));
	}
	resourceConfig.insert(std::make_pair("TextureResource", cm1->GetCategory("TextureResource").GetParams()));


	constexpr float physicsStepTargetFrameTime = 1000.0f / 60.f;
	float           accumulatedFrameTime = 0.f;

	Dispatcher &   dispatcher = Dispatcher::getInstance();

	DrawableManager& dm = DrawableManager::getInstance();

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");
	
	ResourceManager *rm = new ResourceManager(resourceConfig);

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroidTexture");
	sf::Texture asteroidTexture = asteroid->Get();
	sf::Sprite spriteAsteroid(asteroidTexture);

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Space space(totalCountAsteroids, totalCountStar, window.getSize());

	CollisionEventBetweenAsteroids collisionEvent;


	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	//int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200) + 20;
	int _nAsteroids = 4;
	space.AddSomeStars(_nStars);
	space.AddSomeAsteroids(_nAsteroids, spriteAsteroid);

	bool exit = false;
	while (window.isOpen())
	{
		const float delta = clock.restart().asMicroseconds() / 1000.0f;
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

			size_t n = space.asteroids.size() - 1;
		    size_t m = space.asteroids.size();
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = i + 1; j < m; ++j)
				{
					if (Collided(*space.asteroids[i], *space.asteroids[j]))
					{
						collisionEvent._asteroid1 = space.asteroids[i];
						collisionEvent._asteroid2 = space.asteroids[j];
						ResolveCollision(*space.asteroids[i], *space.asteroids[j]);
						dispatcher.Send(collisionEvent, collisionEventID, space.asteroids[i]->_token);
						dispatcher.Send(collisionEvent, collisionEventID, space.asteroids[j]->_token);
					}
				}
			}
			space.Update(physicsStepTargetFrameTime/1000.0f);
		}

		dm.DrawScene(window);
		window.display();
	}

	return 0;
}