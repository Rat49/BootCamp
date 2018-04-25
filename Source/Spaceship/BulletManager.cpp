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

	_bullets.push_back(bulletLeft);
	_bullets.push_back(bulletRight);
	_bullets.push_back(bulletCentr);
}

void BulletManager::DeleteBullet(const Event& event)
{
	const DeleteBulletEvent& currentEvent = static_cast<const DeleteBulletEvent&>(event);

	OrdinaryBullet* ptrBullet = currentEvent._deletedBullet;

	_bullets.erase(std::remove(_bullets.begin(), _bullets.end(), ptrBullet), _bullets.end());
	_ordinaryBulletStorage.Put(ptrBullet);
	DrawableManager::getInstance()._drawableObjects.erase
	(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrBullet)),
			DrawableManager::getInstance()._drawableObjects.end());
}

void BulletManager::CreateRocket(const Event & event)
{
	const CreateRocketEvent& currentEvent = static_cast<const CreateRocketEvent&>(event);

	Rocket* rocket = _rocketStorage.Get();
	rocket->Init(currentEvent._position, currentEvent._direction, _rocketTexture.Get());

	_rockets.push_back(rocket);
}

void BulletManager::DeleteRocket(const Event & event)
{
	const DeleteRocketEvent& currentEvent = static_cast<const DeleteRocketEvent&>(event);

	Rocket* ptrRocket = currentEvent._deletedRocket;

	_rockets.erase(std::remove(_rockets.begin(), _rockets.end(), ptrRocket), _rockets.end());
	_rocketStorage.Put(ptrRocket);
	DrawableManager::getInstance()._drawableObjects.erase
	(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrRocket)),
		DrawableManager::getInstance()._drawableObjects.end());
}

void BulletManager::Update(const sf::Time& deltaTime)
{
	for (auto& bullet : _bullets)
	{
		bullet->Update(deltaTime);
	}
	for (auto& rocket : _rockets)
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
