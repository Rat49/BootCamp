#include "Asteroid.h"
#include "ParticleSpace.h"
#include "ResourceManager.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

std::vector<Object *> objects;


int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	std::srand(std::time(nullptr));

	int nAsteroids = (WINDOW_WIDTH / 200) * (WINDOW_HEIGHT / 200);
	int nParticleSpace = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	const int totalCountAsteroids = 20;//GetFronConfig?
	const int totalCountParticleSpace = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	Pool<ParticleSpace> poolParticle(totalCountParticleSpace);

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nParticleSpace = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) * (WINDOW_HEIGHT / 200);
	for (int i = 0; i < _nParticleSpace; ++i)
	{
		ParticleSpace* particle = poolParticle.Get();
		particle->Init(window);

		objects.push_back(particle);
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
					Asteroid* asteroid = poolAsteroid.Get();					
					asteroid->Init(sprite,window);
					objects.push_back(asteroid);
				}
				else if (event.mouseButton.button == sf::Mouse::Button::Right)
				{
					Asteroid* asteroid = dynamic_cast<Asteroid *>(objects.back());
					objects.pop_back();
					poolAsteroid.Put(asteroid);
				}
			}
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		window.clear();

		for (auto *object : objects)
		{
			object->Update(time);
			object->Draw();
		}

		window.display();
	}

	return 0;
}