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
		const CreateBulletEvent& currentEvent = static_cast<const CreateBulletEvent&>(event);

		OrdinaryBullet* bulletLeft = _ordinaryBulletStorage.Get();
		bulletLeft->Init(currentEvent._position, RotateVector(currentEvent._direction, _bulletDeflection), _ordinaryBulletTexture.Get(), currentEvent._isColliderVisible);

		OrdinaryBullet* bulletRight = _ordinaryBulletStorage.Get();
		bulletRight->Init(currentEvent._position, RotateVector(currentEvent._direction, -_bulletDeflection), _ordinaryBulletTexture.Get(), currentEvent._isColliderVisible);

		OrdinaryBullet* bulletCentr = _ordinaryBulletStorage.Get();
		bulletCentr->Init(currentEvent._position, currentEvent._direction, _ordinaryBulletTexture.Get(), currentEvent._isColliderVisible);

		bullets.push_back(bulletLeft);
		bullets.push_back(bulletRight);
		bullets.push_back(bulletCentr);
	});
	_rocketCreation = dispatcher.Connect(createRocketEventID, [&](const Event& event)
	{
		const CreateRocketEvent& currentEvent = static_cast<const CreateRocketEvent&>(event);

		Rocket* rocket = _rocketStorage.Get();
		RocketParticle * rocketParticle = _particleStorage.Get();

		rocket->Init(currentEvent._position, currentEvent._direction, _rocketTexture.Get(), *rocketParticle, currentEvent._isColliderVisible);

		rockets.push_back(rocket);
	});
	_collisionRocketVsAsteroid = dispatcher.Connect(collisionEventBetweenAsteroidAndRocketID, [&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndRocket& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndRocket&>(event);
		Rocket* ptrRocket = currentEvent._rocket;

		DeleteRocket(ptrRocket);
	});
	_collisionBulletVsAsteroid = dispatcher.Connect(collisionEventBetweenAsteroidAndBulletID, [&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndBullet& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndBullet&>(event);
		OrdinaryBullet* ptrBullet = currentEvent._bullet;

		DeleteBullet(ptrBullet);
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
	dispatcher.Disconnect(createRocketEventID, _rocketCreation);
	dispatcher.Disconnect(collisionEventBetweenAsteroidAndRocketID, _collisionRocketVsAsteroid);
	dispatcher.Disconnect(collisionEventBetweenAsteroidAndBulletID, _collisionBulletVsAsteroid);
}

void BulletManager::DeleteBullet(OrdinaryBullet* bullet)
{
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
	_ordinaryBulletStorage.Put(bullet);
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(bullet));

	std::cout << "bullets storage " << _ordinaryBulletStorage.Count() << std::endl;
}

void BulletManager::DeleteRocket(Rocket* rocket)
{
	rocket->SetRadius(0);
	rocket->_rocketParticle->Stop();
	rocket->_rocketParticle->SetVelocity(sf::Vector2f(0, 0));
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(rocket));
	std::cout << "rockets storage " << _rocketStorage.Count() << std::endl;	
}

void BulletManager::RocketOutOfBoundsHandler(const Event & event)
{
	const RocketOutOfBoundsEvent& currentEvent = static_cast<const RocketOutOfBoundsEvent&>(event);
	Rocket* ptrRocket = currentEvent._deletedRocket;

	DeleteRocket(ptrRocket);
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
			DeleteBullet(bullet);
		}
	}
	for (auto& rocket : rockets)
	{
		
		if ((rocket->GetSprite()->getPosition().x < -rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().x > WindowResolution::_W + rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().y > WindowResolution::_H + rocket->GetHalfSpriteLength()
			|| rocket->GetSprite()->getPosition().y < -rocket->GetHalfSpriteLength()) && rocket->isAlive)
		{
			//_rocketOutOfBoundsEvent._deletedRocket = rocket;
			/*Dispatcher::getInstance().Send(RocketOutOfBoundsEvent(_rocketOutOfBoundsEvent), rocketOutOfBoundsEventID);
			*/
			rocket->isAlive = false;
			DeleteRocket(rocket);
		}
		if (!rocket->_rocketParticle->IsEnd())
		{
			rocket->Update(deltaTime);
		}
		else 
		{
			_particleStorage.Put(rocket->_rocketParticle);
			_rocketStorage.Put(rocket);
			rockets.erase(std::remove(rockets.begin(), rockets.end(), rocket), rockets.end());
		}
	}
}