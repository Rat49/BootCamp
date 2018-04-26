#include "AnimationPlayer.h"
#include "ResourceManager.h"
#include "ConfigManager.h"

int main()
{
	ConfigManager* cm1 = ConfigManager::Create("Config.INI");
	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").GetParams()));
	resourceConfig.insert(std::make_pair("TextureResource", cm1->GetCategory("TextureResource").GetParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").GetParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").GetParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first, cm1->GetCategory("ImageSequenceResource." + i.first).GetParams()));
	}

	ResourceManager *rm = new ResourceManager(resourceConfig);

	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	ImageSequenceResource* cat = rm->GetResource<ImageSequenceResource>("cat");

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();

	AnimationPlayer* girlAnimationPlayer = new AnimationPlayer(sprite, girl, true);
	AnimationPlayer* catAnimationPlayer = new AnimationPlayer(sprite, cat, true);

	girlAnimationPlayer->Start(sf::milliseconds(500));
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;
	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		sf::Event event;
   		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				girlAnimationPlayer->Stop();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				girlAnimationPlayer->Pause();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RAlt)
			{
				girlAnimationPlayer->SetLooped(true);
				girlAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RControl)
			{
				girlAnimationPlayer->SetLooped(false);
				girlAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LControl)
			{
				girlAnimationPlayer->Reset();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				girlAnimationPlayer->Stop();
				catAnimationPlayer->Start();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
			{
				catAnimationPlayer->Stop();
				girlAnimationPlayer->Start();
			}
		}	

		girlAnimationPlayer->Update(deltaTime);
		catAnimationPlayer->Update(deltaTime);
	
		window.clear();
		window.draw(*sprite);
		window.display();
	}

	return 0;
}