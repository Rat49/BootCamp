#include "BulletManager.h"

BulletManager::BulletManager(TextureResource& ordinaryBulletTexture, TextureResource& rocketTexture)
	: _totalBulletCount(200)
	, _totalRocketCount(10)
	, _ordinaryBulletStorage(Pool<OrdinaryBullet>(_totalBulletCount))
	, _rocketStorage(Pool<Rocket>(_totalRocketCount))
	, _ordinaryBulletTexture(ordinaryBulletTexture)
	, _rocketTexture(rocketTexture)
	, _bulletDeflection(5.0f)
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	_bulletDeletion = dispatcher.Connect(createBulletEventID, [&](const Event& event)
	{
		CreateBullet(event);
	});
	_rocketDeletion = dispatcher.Connect(createRocketEventID, [&](const Event& event)
	{
		CreateRocket(event);
	});
	_bulletCreation = dispatcher.Connect(deleteBulletEventID, [&](const Event& event)
	{
		DeleteBullet(event);
	});
	_rocketCreation = dispatcher.Connect(deleteRocketEventID, [&](const Event& event)
	{
		DeleteRocket(event);
	});
}

BulletManager::~BulletManager()
{
	for (auto& bullet: bullets)
	{
		if (!(_ordinaryBulletStorage.Count() == _ordinaryBulletStorage.MaxCount()))
		{
			bullet->Reset();
			_ordinaryBulletStorage.Put(bullet);
		}
	}

	for (auto& rocket : rockets)
	{
		if (!(_rocketStorage.Count() == _rocketStorage.MaxCount()))
		{
			rocket->Reset();
			_rocketStorage.Put(rocket);
		}
	}

	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(createBulletEventID, _bulletCreation);
	dispatcher.Disconnect(deleteBulletEventID, _bulletDeletion);
	dispatcher.Disconnect(createRocketEventID, _rocketCreation);
	dispatcher.Disconnect(deleteRocketEventID, _rocketDeletion);
}

void BulletManager::CreateBullet(const Event& event)
{
	const CreateBulletEvent& currentEvent = static_cast<const CreateBulletEvent&>(event);

	OrdinaryBullet* bulletLeft = _ordinaryBulletStorage.Get();
	bulletLeft->Init(currentEvent._position, DeflectBullets(_bulletDeflection, currentEvent._direction), _ordinaryBulletTexture.Get());

	OrdinaryBullet* bulletRight = _ordinaryBulletStorage.Get();
	bulletRight->Init(currentEvent._position, DeflectBullets(-_bulletDeflection, currentEvent._direction), _ordinaryBulletTexture.Get());

	OrdinaryBullet* bulletCentr = _ordinaryBulletStorage.Get();
	bulletCentr->Init(currentEvent._position, currentEvent._direction, _ordinaryBulletTexture.Get());

	bullets.push_back(bulletLeft);
	bullets.push_back(bulletRight);
	bullets.push_back(bulletCentr);
}

void BulletManager::DeleteBullet(const Event& event)
{
	const DeleteBulletEvent& currentEvent = static_cast<const DeleteBulletEvent&>(event);

	OrdinaryBullet* ptrBullet = currentEvent._deletedBullet;

	bullets.erase(std::remove(bullets.begin(), bullets.end(), ptrBullet), bullets.end());
	_ordinaryBulletStorage.Put(ptrBullet);

    DrawableManager::getInstance().RemoveDrawableObject(ptrBullet);
}

void BulletManager::CreateRocket(const Event & event)
{
	const CreateRocketEvent& currentEvent = static_cast<const CreateRocketEvent&>(event);

	Rocket* rocket = _rocketStorage.Get();
	rocket->Init(currentEvent._position, currentEvent._direction, _rocketTexture.Get());

	rockets.push_back(rocket);
}

void BulletManager::DeleteRocket(const Event & event)
{
	const DeleteRocketEvent& currentEvent = static_cast<const DeleteRocketEvent&>(event);

	Rocket* ptrRocket = currentEvent._deletedRocket;

	rockets.erase(std::remove(rockets.begin(), rockets.end(), ptrRocket), rockets.end());
	_rocketStorage.Put(ptrRocket);
    DrawableManager::getInstance().RemoveDrawableObject(ptrRocket);
}

void BulletManager::Update(const sf::Time& deltaTime)
{
	for (auto& bullet : bullets)
	{
		bullet->Update(deltaTime);
	}
	for (auto& rocket : rockets)
	{
		rocket->Update(deltaTime);
	}
}

sf::Vector2f BulletManager::DeflectBullets(float angle,const sf::Vector2f& direction) const
{
	float radianAngle = angle * static_cast<float>(M_PI) / 180.0f;
	return sf::Vector2f(direction.x * std::cos(radianAngle) - direction.y * std::sin(radianAngle),
		direction.x * std::sin(radianAngle) + direction.y * std::cos(radianAngle));
}
