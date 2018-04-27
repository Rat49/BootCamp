#include "ConfigManager.h"
#include "DebugCommandManager.h"
#include "DrawableManager.h"
#include "Spaceship.h"
#include "BulletManager.h"
#include "ResourceManager.h"

int main()
{
	ConfigManager* cm1 = ConfigManager::Create("Config.INI");

	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;

	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").GetParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").GetParams()));
	resourceConfig.insert(std::make_pair("TextureResource", cm1->GetCategory("TextureResource").GetParams()));

	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").GetParams();

	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));

	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first, cm1->GetCategory("ImageSequenceResource." + i.first).GetParams()));
	}

	ResourceManager *rm = new ResourceManager(resourceConfig);

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceship");
	ImageSequenceResource* flickeringImgseq = rm->GetResource<ImageSequenceResource>("spaceshipFlickering");
	TextureResource* bulletTexture = rm->GetResource<TextureResource>("bullet");
	TextureResource* rocketTexture = rm->GetResource<TextureResource>("rocket");

	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	WindowResolution::SetResolution(window);

	std::multimap<int, ButtonKey_t> actions;
	LogCategory category = cm1->GetCategory("Input");
	std::multimap<const std::string, const std::string> inputCategory = category.GetParams();
	for (auto i : inputCategory)
	{
		int a = atoi(i.first.c_str());
		int b = atoi(i.second.c_str());
		actions.insert(std::pair<int, int>(a, b));
	}
	InputManager input(actions);

	std::multimap<const std::string, const std::string> spaceshipConfig = cm1->GetCategory("SpaceshipConfig").GetParams();
	Spaceship* spaceship = new Spaceship(spaceshipConfig, input, *spaceshipImgseq, *flickeringImgseq);
	spaceship->AddToDrawableManager();
	BulletManager bulletManager(*bulletTexture, *rocketTexture);
	DrawableManager& drawableManager = DrawableManager::getInstance();

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	sf::Event event;
	bool exit = false;
	while (window.isOpen())
	{
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