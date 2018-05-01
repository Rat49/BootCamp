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
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>

class AchievementsManager
{
private:
	std::map<const AchievementsID_t, std::vector<Achievement>> _achievementsStorage;
	sf::Image* _achievementPicture;
	sf::Time _noDamageTimer;
	sf::Time _destroyTimer;
	sf::Time _afterFirstBigAsteroidFrag;
	sf::Time _afterFirstMiddleAsteroidFrag;
	sf::Time _afterFirstSmallAsteroidFrag;

	Token_t _tokenForCollisionEventBetweenAsteroidAndBullet;
	Token_t _tokenForCollisionEventBetweenAsteroidAndSpaceship;
public:
	AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture);
	~AchievementsManager();

	void DestroyAchievementsStatus(const AsteroidType& type);
	void DestroyTimerCheck(const sf::Time& destroyTimer);
	void ActiveStatusCheck(Achievement& achiev);
	void Update(const sf::Time& deltaTime,UI& achievUI);
};