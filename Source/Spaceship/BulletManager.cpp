#include "BulletManager.h"

BulletManager::BulletManager(TextureResource& ordinaryBulletTexture, TextureResource& rocketTexture)
	: _totalBulletCount(200)
	, _totalRocketCount(10)
	, _ordinaryBulletStorage(Pool<OrdinaryBullet>(_totalBulletCount))
	, _rocketStorage(Pool<Rocket>(_totalRocketCount))
	, _ordinaryBulletTexture(ordinaryBulletTexture)
	, _rocketTexture(rocketTexture)
	, _bulletDeflection(5.0f)
	, _particleStorage(Pool<RocketParticle>(_totalRocketCount))
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	_bulletCreation = dispatcher.Connect(createBulletEventID, [&](const Event& event)
	{
		CreateBullet(event);
	});
	_rocketCreation = dispatcher.Connect(createRocketEventID, [&](const Event& event)
	{
		CreateRocket(event);
	});

	_bulletDeletion = dispatcher.Connect(deleteBulletEventID, [&](const Event& event)
	{
		DeleteBullet(event);
	});
	_rocketDeletion = dispatcher.Connect(rocketOutOfBoundsEventID, [&](const Event& event)
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
	dispatcher.Disconnect(rocketOutOfBoundsEventID, _rocketDeletion);
}

void BulletManager::CreateBullet(const Event& event)
{
	const CreateBulletEvent& currentEvent = static_cast<const CreateBulletEvent&>(event);

	OrdinaryBullet* bulletLeft = _ordinaryBulletStorage.Get();
	bulletLeft->Init(currentEvent._position, RotateVector(currentEvent._direction,_bulletDeflection), _ordinaryBulletTexture.Get());

	OrdinaryBullet* bulletRight = _ordinaryBulletStorage.Get();
	bulletRight->Init(currentEvent._position, RotateVector(currentEvent._direction, -_bulletDeflection), _ordinaryBulletTexture.Get());

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
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(ptrBullet));

	std::cout << "bullets storage " << _ordinaryBulletStorage.Count() << std::endl;

		/*_drawableObjects.erase
	(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrBullet)),
			DrawableManager::getInstance()._drawableObjects.end());
	*/
}

void BulletManager::CreateRocket(const Event & event)
{
	const CreateRocketEvent& currentEvent = static_cast<const CreateRocketEvent&>(event);

	Rocket* rocket = _rocketStorage.Get();
	RocketParticle * rocketParticle = _particleStorage.Get();

	rocket->Init(currentEvent._position, currentEvent._direction, _rocketTexture.Get(), *rocketParticle);


	rockets.push_back(rocket);
}

void BulletManager::DeleteRocket(const Event & event)
{
	const DeleteRocketEvent& currentEvent = static_cast<const DeleteRocketEvent&>(event);

	Rocket* ptrRocket = currentEvent._deletedRocket;

	rockets.erase(std::remove(rockets.begin(), rockets.end(), ptrRocket), rockets.end());
	_rocketStorage.Put(ptrRocket);
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(ptrRocket));

	std::cout << "rockets storage " << _rocketStorage.Count() << std::endl;	
	
	/*_drawableObjects.erase
	(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrRocket)),
		DrawableManager::getInstance()._drawableObjects.end());*/
}

void BulletManager::Update(const sf::Time& deltaTime)
{
	for (auto& bullet : bullets)
	{
		bullet->Update(deltaTime);
		if (bullet->GetSprite()->getPosition().x < -bullet->GetHalfSpriteLength()
			|| bullet->GetSprite()->getPosition().x > WindowResolution::_W + bullet->GetHalfSpriteLength()
			|| bullet->GetSprite()->getPosition().y > WindowResolution::_H + bullet->GetHalfSpriteLength()
			|| bullet->GetSprite()->getPosition().y < -bullet->GetHalfSpriteLength())
		{
			_deleteBulletEvent._deletedBullet = bullet;
			Dispatcher::getInstance().Send(_deleteBulletEvent, deleteBulletEventID);
		}
	}
	for (auto& rocket : rockets)
	{
		rocket->Update(deltaTime);
		if (rocket->GetSprite()->getPosition().x < -rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().x > WindowResolution::_W + rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().y > WindowResolution::_H + rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().y < -rocket->GetHalfSpriteLength())
		{
			Dispatcher::getInstance().Send(DeleteRocketEvent(rocket), rocketOutOfBoundsEventID);
		}
	}
}