#pragma once
#include "Achievements.h"
#include "ConfigManager.h"
#include "SFML\Graphics.hpp"
#include <vector>
#include <map>

class AchievementsManager
{
private:
	std::vector<Achievement> _achievementsStorage;
	std::multimap<const std::string, const std::string> _achievementsList;
public:
	AchievementsManager(ConfigManager* achievementCM);
	~AchievementsManager(); //???
	
	void Update(sf::Time deltaTime);
	//void ShowAchievement();
};

