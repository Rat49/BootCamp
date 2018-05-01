#include "AchievementsManager.h"

AchievementsManager::AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture)
	:_achievementPicture(achievementPicture),
	_afterFirstBigAsteroidFrag(sf::seconds(0.0f)),
	_afterFirstMiddleAsteroidFrag(sf::seconds(0.0f)),
	_afterFirstSmallAsteroidFrag(sf::seconds(0.0f))
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
		DestroyTimerCheck(_destroyTimer);
		DestroyAchievementsStatus(currentEvent._asteroid->_type);
	});
	_tokenForCollisionEventBetweenAsteroidAndSpaceship = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndSpaceship& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndSpaceship&>(event);
		_noDamageTimer = sf::seconds(0.0f);
	});
}

AchievementsManager::~AchievementsManager()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndBulletID, _tokenForCollisionEventBetweenAsteroidAndBullet);
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID, _tokenForCollisionEventBetweenAsteroidAndSpaceship);
}

void AchievementsManager::DestroyAchievementsStatus(const AsteroidType& type)
{
	if (type == AsteroidType::Big)
	{
		for (auto& achiev : _achievementsStorage[AchievementsTypes::DestroyAchievements])
		{
			if (achiev.GetIdAchievement() == 4 || achiev.GetIdAchievement() == 5)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				ActiveStatusCheck(achiev);
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
				ActiveStatusCheck(achiev);
			}
		}
	}
	else if (type == AsteroidType::Small)
	{
		for (auto& achiev : _achievementsStorage[AchievementsTypes::DestroyAndTimeAchievements])
		{
			if (achiev.GetIdAchievement() == 8)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				ActiveStatusCheck(achiev);
			}
		}
	}
}

void AchievementsManager::DestroyTimerCheck(const sf::Time& destroyTimer)
{
	if (_afterFirstBigAsteroidFrag == sf::seconds(0.0f) && _afterFirstMiddleAsteroidFrag == sf::seconds(0.0f) && _afterFirstSmallAsteroidFrag == sf::seconds(0.0f))
	{
		_afterFirstBigAsteroidFrag = destroyTimer;
		_afterFirstMiddleAsteroidFrag = destroyTimer;
		_afterFirstSmallAsteroidFrag = destroyTimer;
	}
	else if (std::abs((_afterFirstSmallAsteroidFrag.asSeconds() - destroyTimer.asSeconds())) >= 2.0f)
	{
		for (auto& achiev : _achievementsStorage[AchievementsTypes::DestroyAndTimeAchievements])
		{
			if (achiev.GetIdAchievement() == 8)
			{
				achiev.SetProgressState(0);
				_afterFirstSmallAsteroidFrag = destroyTimer;
			}
		}
	}
}

void AchievementsManager::ActiveStatusCheck(Achievement& achiev)
{
	if (!(((achiev.GetProgressState() - achiev.GetProgressFinishState())) < 1.0f && (achiev.GetProgressState() - achiev.GetProgressFinishState()) >= 0.0f))
	{
		return;
	}
	
	achiev.SetAchievedActive(true);
		
	char dateBuffer[32];
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	strftime(dateBuffer, 32, "%d.%m.%Y %H:%M:%S", &newtime);
	achiev.SetDateCompleteAchievements(dateBuffer);
}

void AchievementsManager::Update(const sf::Time& deltaTime,UI& achievUI)
{
	_noDamageTimer += deltaTime;
	_destroyTimer += deltaTime;
	
	std::cout << _afterFirstSmallAsteroidFrag.asSeconds() << std::endl; //delete

	for (auto& achiev : _achievementsStorage[AchievementsTypes::TimeAchievements])
	{
		if (achiev.GetIdAchievement() == 1 || achiev.GetIdAchievement() == 2 || achiev.GetIdAchievement() == 3)
		{
			achiev.SetProgressState(_noDamageTimer.asSeconds());
			ActiveStatusCheck(achiev);
		}
	}
	
	for (auto& achiev : _achievementsStorage)
	{
		for (auto it = achiev.second.begin(); it != achiev.second.end();)
		{
			if (it->GetAchievedActive())
			{
				achievUI.OnAchive(it->GetDisplayName(), it->GetDisplayDescriptionName(), _achievementPicture);
				it = achiev.second.erase(it);
			}
			else
			{
				++it;
			}
		}	
	}
}
