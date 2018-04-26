#include "AchievementsManager.h"

AchievementsManager::AchievementsManager(ConfigManager* achievementCM)
{
	_achievementsList = achievementCM->GetCategory("AchievementsList").GetParams();

	for (const auto& achiev : _achievementsList)
	{
		std::multimap<const std::string, const std::string> achievementsConfig = achievementCM->GetCategory("AchievementsList." + achiev.first).GetParams();
		Achievement achievement(achievementsConfig);
		_achievementsStorage.push_back(achievement);
	}
}

AchievementsManager::~AchievementsManager()
{
	//???
}

void AchievementsManager::Update(sf::Time deltaTime)
{

}
