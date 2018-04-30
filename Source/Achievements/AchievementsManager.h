#pragma once
#include "Achievements.h"
#include "ConfigManager.h"
#include "EventSystem.h"
#include "CollisionEvent.h"
#include "Asteroid.h"
#include "UI.h"
#include "ResourceManager.h"
#include "AchievementsTypes.h"
#include "SFML\Graphics.hpp"
#include <vector>
#include <map>

class AchievementsManager
{
private:
	std::map<const AchievementsID_t, std::vector<Achievement>> _achievementsStorage;
	sf::Image* _achievementPicture;

	Token_t _tokenForCollisionEventBetweenAsteroidAndBullet;
public:
	AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture);
	~AchievementsManager();

	void DestroyAchievementsHandler(const AsteroidType& type);
	void TimeAchievementsHandler();
	void DestroyAndTimeAchievementsHandler(const AsteroidType& type);
	void CheckActiveStatus(Achievement& achiev);
	void Update(const sf::Time& deltaTime,UI& achievUI);
};