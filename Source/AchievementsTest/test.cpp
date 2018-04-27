#pragma once
#include "Achievements.h"
#include "AchievementsManager.h"
#include "SFML\Graphics.hpp"
#include <cstdlib>
#include <map>

//void ConditionAchievement(Achievement* achieves, int num, sf::RenderWindow window)
//{
//	for (int i = 1; i < maxEventID; ++i)
//	{
//		if (achieves[i].GetAchievedActive() == false)
//		{
//			std::map<EventAchievID_t, Token_t> _tokens;
//			int countOfHandlerResponce = achieves[i - 1].GetProgressState();
//			std::map<EventAchievID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(i);
//			std::function<void(const Event&)> handler = [&](const Event &e)
//			{
//				achieves[i - 1].SetProgressState(++countOfHandlerResponce);
//				if (achieves[i].GetProgressFinishState() == achieves[i].GetProgressState())
//				{
//					achieves[i].SetAchievedActive(true);
//					UI mui(window);
//					sf::Font font;
//					font.loadFromFile("font/arial.ttf");
//					mui.CreateAchivementShower(font, PercentXY(80, 80));
//					sf::Image * img = new sf::Image();
//					img->loadFromFile("img/asteroid.png");
//					mui.OnAchive(achieves[num].GetDisplayName(), img);
//				}
//			};
//		}
//	}
//}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), "AchievementTest");
	ConfigManager* achievementCM = ConfigManager::Create("AchievementsConfig.INI");
	UI ui(window);
	sf::Image* image = new sf::Image();
	image->loadFromFile("achievement.png");
	AchievementsManager achievementsManager(achievementCM,image);
	
	sf::Event event;
	while (window.isOpen())
	{
		window.clear();

		while (window.pollEvent(event))
		{
				

		}

		window.display();
	}
		
}
	
	
	

