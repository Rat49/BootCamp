#include "AchievementsManager.h"

AchievementsManager::AchievementsManager(ConfigManager* achievementCM, sf::Image* achievementPicture)
	:_achievementPicture(achievementPicture),
	_afterFirstBigAsteroidFrag(sf::seconds(0.0f)),
	_afterFirstMiddleAsteroidFrag(sf::seconds(0.0f)),
	_afterFirstSmallAsteroidFrag(sf::seconds(0.0f))
{
	auto achievementsList = achievementCM->GetCategory("AchievementsList").GetParams();
	for (const auto& achiev : achievementsList)
	{
		std::multimap<const std::string, const std::string> achievementsConfig = achievementCM->GetCategory("AchievementsList." + achiev.first).GetParams();
		Achievement achievement(achievementsConfig);
		_achievementsStorage.push_back(achievement);
	}

	Dispatcher& dispatcher = Dispatcher::getInstance();
	tokenForCollisionEventBetweenAsteroidAndBullet = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndBulletID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndBullet& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndBullet&>(event);
		DestroyTimerCheck(_destroyTimer, currentEvent._asteroid->_type);
		DestroyAchievementsStatus(currentEvent._asteroid->_type);
	});
	tokenForCollisionEventBetweenAsteroidAndRocket = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndRocketID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndRocket& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndRocket&>(event);
		DestroyTimerCheck(_destroyTimer, currentEvent._asteroid->_type);
		DestroyAchievementsStatus(currentEvent._asteroid->_type);
	});
	tokenForCollisionEventBetweenAsteroidAndSpaceship = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndSpaceship& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndSpaceship&>(event);
		_noDamageTimer = sf::seconds(0.0f);
	});
}

AchievementsManager::~AchievementsManager()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndBulletID, tokenForCollisionEventBetweenAsteroidAndBullet);
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndRocketID, tokenForCollisionEventBetweenAsteroidAndRocket);
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID, tokenForCollisionEventBetweenAsteroidAndSpaceship);
}

void AchievementsManager::DestroyAchievementsStatus(const AsteroidType& type)
{
	if (type == AsteroidType::Big)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 4 || achiev.GetIdAchievement() == 5 || achiev.GetIdAchievement() == 10)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				ActiveStatusCheck(achiev);
			}
		}
	}
	else if (type == AsteroidType::Middle)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 6 || achiev.GetIdAchievement() == 7 || achiev.GetIdAchievement() == 9)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				ActiveStatusCheck(achiev);
			}
		}
	}
	else if (type == AsteroidType::Small)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 8)
			{
				achiev.SetProgressState(achiev.GetProgressState() + 1);
				ActiveStatusCheck(achiev);
			}
		}
	}
}

void AchievementsManager::DestroyTimerCheck(const sf::Time& destroyTimer, const AsteroidType& type)
{
	if (_afterFirstBigAsteroidFrag == sf::seconds(0.0f) && type == AsteroidType::Big)
	{
		_afterFirstBigAsteroidFrag = destroyTimer;
	}
	else if (_afterFirstMiddleAsteroidFrag == sf::seconds(0.0f) && type == AsteroidType::Middle)
	{
		_afterFirstMiddleAsteroidFrag = destroyTimer;
	}
	else if (_afterFirstSmallAsteroidFrag == sf::seconds(0.0f) && type == AsteroidType::Small)
	{
		_afterFirstSmallAsteroidFrag = destroyTimer;
	}	
	
	if (std::abs((_afterFirstSmallAsteroidFrag.asSeconds() - destroyTimer.asSeconds())) >= 10.0f)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 8)
			{
				achiev.SetProgressState(0);
				_afterFirstSmallAsteroidFrag = destroyTimer;
			}
		}
	}
	else if (std::abs((_afterFirstMiddleAsteroidFrag.asSeconds() - destroyTimer.asSeconds())) >= 20.0f)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 9)
			{
				achiev.SetProgressState(0);
				_afterFirstMiddleAsteroidFrag = destroyTimer;
			}
		}
	}
	else if (std::abs((_afterFirstBigAsteroidFrag.asSeconds() - destroyTimer.asSeconds())) >= 30.0f)
	{
		for (auto& achiev : _achievementsStorage)
		{
			if (achiev.GetIdAchievement() == 10)
			{
				achiev.SetProgressState(0);
				_afterFirstBigAsteroidFrag = destroyTimer;
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

void AchievementsManager::Update(const sf::Time& deltaTime,UI& achievUI,AudioResource &audio)
{
	_noDamageTimer += deltaTime;
	_destroyTimer += deltaTime;

	for (auto& achiev : _achievementsStorage)
	{
		if (achiev.GetIdAchievement() == 1 || achiev.GetIdAchievement() == 2 || achiev.GetIdAchievement() == 3)
		{
			achiev.SetProgressState(_noDamageTimer.asSeconds());
			ActiveStatusCheck(achiev);
		}
	}

	for (auto it = _achievementsStorage.begin(); it != _achievementsStorage.end();)
	{
		if (it->GetAchievedActive())
		{
			achievUI.OnAchive(it->GetDisplayName(), it->GetDisplayDescriptionName(), _achievementPicture);
			audio.Get().play();
			it = _achievementsStorage.erase(it);
		}
		else
		{
			++it;
		}
	}	
}
