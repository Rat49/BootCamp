#include "Ammunition.h"
#include "Mathematics.h"

void Ammunition::Update(float time)
{
	if (_cRespawnTime>=_respawnTime && _hp>=0)
	{
		if (GetRadius() == 0)
			Init();
		RigidBody::Update(time);

		_angularVelocity = _angularVelocity + time * _rotationSpeed;
		sf::Vector2f nextPosition = GetCoordinates() + GetSpeed() * time;

		if (nextPosition.y - _halfLenght > WindowResolution::_H)
		{
			nextPosition.y -= WindowResolution::_H + _halfLenght * 2;
			SetCoordinates(nextPosition);
		}
		else if (nextPosition.y + _halfLenght < 0)
		{
			nextPosition.y += WindowResolution::_H + _halfLenght * 2;
			SetCoordinates(nextPosition);
		}

		if (nextPosition.x - _halfLenght > WindowResolution::_W)
		{
			nextPosition.x -= WindowResolution::_W + _halfLenght * 2;
			SetCoordinates(nextPosition);
		}
		else if (nextPosition.x + _halfLenght < 0)
		{
			nextPosition.x += WindowResolution::_W + _halfLenght * 2;
			SetCoordinates(nextPosition);
		}

		_sprite->setOrigin(_radius * 2, _radius * 2);
		_sprite->setScale(sf::Vector2f(0.5f, 0.5f));
		_sprite->setPosition(sf::Vector2f(GetCoordinates().x + _radius, GetCoordinates().y + _radius));
		_sprite->setRotation(_angularVelocity);
		_spaceshipAnimation->Update(sf::milliseconds(time*1000));

		if (_hp == 30 || _lifeTime - _cLifeTime < 5.f) {
			_spaceshipAnimation = _animations[ammunitionNumber].second; 
			_sprite =  _animations[ammunitionNumber].second->GetSprite();
			_spaceshipAnimation->Start();
		}
		if (_hp == 0 || _lifeTime - _cLifeTime < 0.f) {
			SetRadius(0);
			DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(this));
			_cRespawnTime = 0;
		 }
		_cLifeTime += time;
	}
	else 
	{
		_cRespawnTime += time;
	}
}



void Ammunition::Draw(sf::RenderWindow &window)
{
	window.draw(*(_spaceshipAnimation->GetSprite()));
}

void Ammunition::RandomInit() {
	unsigned int randomAmmunition = std::rand() % 36;

	if (randomAmmunition / 6 <=2)
		_ammunitionType = AmmunitionType::Bullet;
	else 
		if (randomAmmunition / 6 == 3 || randomAmmunition / 6 == 4)
			_ammunitionType = AmmunitionType::Rocket;
		else
			_ammunitionType = AmmunitionType::Aid;

	if (randomAmmunition % 6 <= 2)
		_ammunitionSize = AmmunitionSize::Small;
	else
		if (randomAmmunition % 6 == 3 || randomAmmunition % 6 == 4)
			_ammunitionSize = AmmunitionSize::Medium;
		else 
			_ammunitionSize = AmmunitionSize::Big;
}

void Ammunition::Init()
{
	unsigned int randomAmmunition = std::rand() % 18;

	RandomInit();
	
	ammunitionNumber = static_cast<int>(_ammunitionSize) +  static_cast<int>(_ammunitionType) * 3;
	capacity = ammunitionCapacity[ammunitionNumber];

	_sprite = _animations[ammunitionNumber].first->GetSprite();
	_spaceshipAnimation = _animations[ammunitionNumber].first;
	_spaceshipAnimation->Start();
	_hp = 100;
	_cLifeTime = 0.f;

	_radius = _spaceshipAnimation->GetWidth()/4;
	SetRadius(_radius);
	_sprite->setOrigin(_radius, _radius);
	
	SetMass(0.015f);
	
	AddToDrawableManager();

	_angularVelocity = GetFloatRandomValue(-15.0, 15.0);
	_rotationSpeed = GetFloatRandomValue(1, 80);
	_sprite->setRotation(_angularVelocity);

	_linearVelocity = sf::Vector2f(GetFloatRandomValue(-100, 100), GetFloatRandomValue(-100, 100));
	SetSpeed(_linearVelocity);

	float positionBoundX = GetFloatRandomValue(-_spawnBoundWidth, _spawnBoundWidth);
	float positionBoundY = GetFloatRandomValue(-_spawnBoundHeight, _spawnBoundHeight);
	float positionX = positionBoundX > 0 ? WindowResolution::_W + positionBoundX : positionBoundX;
	float positionY = positionBoundY > 0 ? WindowResolution::_H + positionBoundY : positionBoundY;

	_sprite->setPosition(sf::Vector2f(positionX, positionY));
	SetCoordinates(sf::Vector2f(positionX, positionY));
}

Ammunition::Ammunition(ResourceManager *rm)
{
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletSmall"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletSmallFlickering"), true)));
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletMedium"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletMediumFlickering"), true)));
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletBig"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("bulletBigFlickering"), true)));
	
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketSmall"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketSmallFlickering"), true)));  
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketMedium"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketMediumFlickering"), true)));  
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketBig"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("rocketBigFlickering"), true)));

	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("thirdAid"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("thirdAidFlickering"), true)));
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("secondAid"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("secondAidFlickering"), true)));
	_animations.push_back(std::make_pair(new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("firstAid"), true),
		new AnimationPlayer(new sf::Sprite(), rm->GetResource<ImageSequenceResource>("firstAidFlickering"), true)));
}


void Ammunition::OnAsteroidCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndAsteroid &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndAsteroid&>(cEvent);
	_hp -= 10;
}


void Ammunition::OnSpaceshipCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndSpaceship &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndSpaceship&>(cEvent);
	Ammunition* ammunition = collisionEvent.ammunition;
	ammunition->SetRadius(0);
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(ammunition));
	_cRespawnTime = 0;
}


void Ammunition::OnRocketCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndRocket &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndRocket&>(cEvent);
	Ammunition* ammunition = collisionEvent.ammunition;
	ammunition->SetRadius(0);
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(ammunition));
	_cRespawnTime = 0;
	
}


void Ammunition::OnBulletCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndBullet &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndBullet&>(cEvent);
	Ammunition* ammunition = collisionEvent.ammunition;
	ammunition->SetRadius(0);
	DrawableManager::getInstance().RemoveDrawableObject(static_cast<Drawable*>(ammunition));
	_cRespawnTime = 0;
}

void Ammunition::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);

	_tokens[collisionEventBetweenAmmunitionAndBulletId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndBulletId,
		[&](const Event& event)
	{
		OnBulletCollisionHandler(event);
	});

	_tokens[collisionEventBetweenAmmunitionAndAsteroidId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndAsteroidId,
		[&](const Event& event)
	{
		OnAsteroidCollisionHandler(event);
	});

	_tokens[collisionEventBetweenAmmunitionAndRocketId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndRocketId,
		[&](const Event& event)
	{
		OnRocketCollisionHandler(event);
	});

	_tokens[collisionEventBetweenAmmunitionAndSpaceshipId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndSpaceshipId,
		[&](const Event& event)
	{
		OnSpaceshipCollisionHandler(event);
	});
}

int Ammunition::GetZOrder() const
{
	return 2;
}

Ammunition::~Ammunition()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID, collisionEventBetweenAmmunitionAndBulletId);
}