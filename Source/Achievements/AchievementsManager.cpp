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

	Dispatcher& dispatcher = Dispatcher::getInstance();
	_tokenForCollisionEventBetweenAsteroidAndBullet = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndBulletID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndBullet& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndBullet&>(event);
		for (auto& achiev : _achievementsStorage)
		{
			if (currentEvent._asteroid->_type == AsteroidType::Big && achiev.GetIdAchievement() == 4 && achiev.GetIdAchievement() == 5)
			{
				achiev.SetProgressState(achiev.GetProgressState()+1);
			}
			if (currentEvent._asteroid->_type == AsteroidType::Small && achiev.GetIdAchievement() == 6)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
			}
		}
	});
}

AchievementsManager::~AchievementsManager()
{
	//???
}

void AchievementsManager::Update(sf::Time deltaTime)
{
	for (auto& achiev : _achievementsStorage)
	{
		if (achiev.GetProgressState() != achiev.GetProgressFinishState())
		{
			return;
		}

		ShowAchievement(achiev);
	}
}

void AchievementsManager::ShowAchievement(const Achievement& achiement)
{
	std::cout << "Achive!" << std::endl;
}
