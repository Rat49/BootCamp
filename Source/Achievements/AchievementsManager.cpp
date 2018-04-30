#include "AchievementsManager.h"

AchievementsManager::AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture)
	:_achievementPicture(achievementPicture)
{
	auto achievementsListCategory = achievementCM->GetCategory("TimeAchievementsList").GetParams();
	for (const auto& achiev : achievementsListCategory)
	{
		std::multimap<const std::string, const std::string> achievementsConfig = achievementCM->GetCategory("TimeAchievementsList." + achiev.first).GetParams();
		Achievement achievement(achievementsConfig);
		_achievementsStorage[AchievementsTypes::TimeAchievements].push_back(achievement);
	}
	achievementsListCategory = achievementCM->GetCategory("DestroyAchievementsList").GetParams();
	for (const auto& achiev : achievementsListCategory)
	{
		std::multimap<const std::string, const std::string> achievementsConfig = achievementCM->GetCategory("DestroyAchievementsList." + achiev.first).GetParams();
		Achievement achievement(achievementsConfig);
		_achievementsStorage[AchievementsTypes::DestroyAchievements].push_back(achievement);
	}
	achievementsListCategory = achievementCM->GetCategory("DestroyAndTimeAchievementsList").GetParams();
	for (const auto& achiev : achievementsListCategory)
	{
		std::multimap<const std::string, const std::string> achievementsConfig = achievementCM->GetCategory("DestroyAndTimeAchievementsList." + achiev.first).GetParams();
		Achievement achievement(achievementsConfig);
		_achievementsStorage[AchievementsTypes::DestroyAndTimeAchievements].push_back(achievement);
	}

	Dispatcher& dispatcher = Dispatcher::getInstance();
	_tokenForCollisionEventBetweenAsteroidAndBullet = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndBulletID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndBullet& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndBullet&>(event);
		DestroyAchievementsHandler(currentEvent._asteroid->_type);
		//DestroyAndTimeAchievementsHandler(currentEvent._asteroid->_type); TODO
	});
}

AchievementsManager::~AchievementsManager()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndBulletID, _tokenForCollisionEventBetweenAsteroidAndBullet);
}

void AchievementsManager::DestroyAchievementsHandler(const AsteroidType& type)
{
	if (type == AsteroidType::Big)
	{
		for (auto& achiev : _achievementsStorage[AchievementsTypes::DestroyAchievements])
		{
			if (achiev.GetIdAchievement() == 4 || achiev.GetIdAchievement() == 5)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				CheckActiveStatus(achiev);
			}
		}
	}
	else if (type == AsteroidType::Middle)
	{
		for (auto& achiev : _achievementsStorage[AchievementsTypes::DestroyAchievements])
		{
			if (achiev.GetIdAchievement() == 6 || achiev.GetIdAchievement() == 7)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				CheckActiveStatus(achiev);
			}
		}
	}
}

void AchievementsManager::TimeAchievementsHandler()
{
	//TODO
}

void AchievementsManager::DestroyAndTimeAchievementsHandler(const AsteroidType& type)
{
	//TODO
}

void AchievementsManager::CheckActiveStatus(Achievement& achiev)
{
	if (achiev.GetProgressState() == achiev.GetProgressFinishState())
	{
		achiev.SetAchievedActive(true);
		
		char dateBuffer[32];
		tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		strftime(dateBuffer, 32, "%d.%m.%Y %H:%M:%S", &newtime);
		achiev.SetDateCompleteAchievements(dateBuffer);
	}
}

void AchievementsManager::Update(const sf::Time& deltaTime,UI& achievUI)
{
	for (auto& achiev : _achievementsStorage)
	{
		for (auto it = achiev.second.begin(); it != achiev.second.end(); ++it)
		{
			if (it->GetAchievedActive())
			{
				achievUI.OnAchive(it->GetDisplayName(), it->GetDisplayDescriptionName(), _achievementPicture);
				it->SetAchievedActive(false);
			}
		}
	}
}