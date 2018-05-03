#pragma once
#include "Achievements.h"
#include "ConfigManager.h"
#include "EventSystem.h"
#include "CollisionEvent.h"
#include "Asteroid.h"
#include "UI.h"
#include "ResourceManager.h"
#include "SFML\Graphics.hpp"
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>

class AchievementsManager
{
private:
	std::vector<Achievement> _achievementsStorage;
	sf::Image* _achievementPicture;
	sf::Time _noDamageTimer;
	sf::Time _destroyTimer;
	sf::Time _afterFirstBigAsteroidFrag;
	sf::Time _afterFirstMiddleAsteroidFrag;
	sf::Time _afterFirstSmallAsteroidFrag;
public:
	Token_t tokenForCollisionEventBetweenAsteroidAndBullet;
	Token_t tokenForCollisionEventBetweenAsteroidAndRocket;
	Token_t tokenForCollisionEventBetweenAsteroidAndSpaceship;
	
	AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture);
	~AchievementsManager();

	void DestroyAchievementsStatus(const AsteroidType& type);
	void DestroyTimerCheck(const sf::Time& destroyTimer, const AsteroidType& type);
	void ActiveStatusCheck(Achievement& achiev);
	void Update(const sf::Time& deltaTime,UI& achievUI);
	void Reset();
};