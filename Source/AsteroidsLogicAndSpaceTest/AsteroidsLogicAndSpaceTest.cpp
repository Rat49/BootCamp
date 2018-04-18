#include "Asteroid.h"
#include "ParticleSpace.h"
#include "ResourceManager.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

std::vector<Object *> objects;

void Init(sf::RenderWindow *window, const sf::Texture &asteroidTexture)
{
	std::srand(std::time(nullptr));

	/*Pool<Asteroid*> _poolAsteroid;
	Pool<ParticleSpace*> _poolParticle;*/

	sf::Sprite sprite;
	sprite.setTexture(asteroidTexture);

	int _nParticleSpace = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50);
	int _nAsteroids = (WINDOW_WIDTH / 200) * (WINDOW_HEIGHT / 200);
	for (int i = 0; i < _nParticleSpace; ++i)
	{
		ParticleSpace* particle = new ParticleSpace();
		particle->_window = window;
		particle->Init();

		objects.push_back(particle);
	}
	for (int i = 1; i <= _nAsteroids; ++i)
	{
		Asteroid* asteroid = new Asteroid();
		asteroid->_window = window;
		asteroid->Init(sprite);

		objects.push_back(asteroid);
	}

}

int main()
{

	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");

	std::srand(std::time(nullptr));

	/*Pool<Asteroid*> _poolAsteroid;
	Pool<ParticleSpace*> _poolParticle;*/

	ResourceManager *rm = new ResourceManager();

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroid");
	sf::Texture asteroidTexture = asteroid->Get();

	Init(&window, asteroidTexture);

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
			object->Draw();
		}

		window.display();
	}

	return 0;
}