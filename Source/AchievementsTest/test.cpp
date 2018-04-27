#pragma once
#include "Achievements.h"
#include "AchievementsManager.h"
#include "SFML\Graphics.hpp"
#include <cstdlib>
#include <map>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), "AchievementTest");
	ConfigManager* achievementCM = ConfigManager::Create("AchievementsConfig.INI");
	UI ui(window);
	sf::Font font;
	font.loadFromFile("arial.ttf");
	ui.CreateAchivementShower(font, PercentXY(1, 1));
	sf::Image* image = new sf::Image();
	image->loadFromFile("achievement.png");
	AchievementsManager achievementsManager(achievementCM,image);
	
	Dispatcher& dispatcher = Dispatcher::getInstance();
	Asteroid* asteroid = new Asteroid();
	asteroid->_type = AsteroidType::Middle;
	CollisionEventBetweenAsteroidAndBullet eventAchiev;
	eventAchiev._asteroid = asteroid;
	
	sf::Clock clock;
	sf::Time deltaTime;
	sf::Time fixedTime;
	const sf::Time fixedUpdateTime = sf::milliseconds(2);
	window.setVerticalSyncEnabled(true);
	sf::Event event;
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		fixedTime += deltaTime;
		window.clear();
				
 		while (window.pollEvent(event))
		{
				
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				dispatcher.Send(eventAchiev, EventTypes::collisionEventBetweenAsteroidAndBulletID);
			}
		}
		achievementsManager.Update(deltaTime);
		achievementsManager.ShowAchievement(ui);
		ui.Render();
		//window.display();
	}
		
}
	
	
	

