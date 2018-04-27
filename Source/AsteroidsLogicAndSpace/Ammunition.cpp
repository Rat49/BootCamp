#include "Ammunition.h"
#include "Mathematics.h"

void Ammunition::Update(float time)
{
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

	_sprite.setPosition(GetCoordinates());
	_sprite.setRotation(_angularVelocity);
}



void Ammunition::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
}

void Ammunition::Init()
{
	_angularVelocity = GetFloatRandomValue(-15.0, 15.0);
	_rotationSpeed = GetFloatRandomValue(1, 80);
	_sprite.setRotation(_angularVelocity);

	_linearVelocity = sf::Vector2f(GetFloatRandomValue(-300, 300), GetFloatRandomValue(-300, 300));
	SetSpeed(_linearVelocity);

	float positionBoundX = GetFloatRandomValue(-_spawnBoundWidth, _spawnBoundWidth);
	float positionBoundY = GetFloatRandomValue(-_spawnBoundHeight, _spawnBoundHeight);
	float positionX = positionBoundX > 0 ? WindowResolution::_W + positionBoundX : positionBoundX;
	float positionY = positionBoundY > 0 ? WindowResolution::_H + positionBoundY : positionBoundY;

	_sprite.setPosition(sf::Vector2f(positionX, positionY));
	SetCoordinates(sf::Vector2f(positionX, positionY));
}

Ammunition::Ammunition(sf::Sprite sprite)
{
	_sprite = sprite;
}


void Ammunition::OnSpaceshipCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndSpaceship &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndSpaceship&>(cEvent);

	//collisionEvent.
}


void Ammunition::OnRocketCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndRocket &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndRocket&>(cEvent);

	
}


void Ammunition::OnBulletCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndBullet &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndBullet&>(cEvent);

	
}

void Ammunition::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);

	_tokens[collisionEventBetweenAmmunitionAndBulletId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndBulletId,
		[&](const Event& event)
	{
		OnSpaceshipCollisionHandler(event);
	});

	_tokens[collisionEventBetweenAmmunitionAndRocketId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndRocketId,
		[&](const Event& event)
	{
		OnBulletCollisionHandler(event);
	});

	_tokens[collisionEventBetweenAmmunitionAndSpaceshipId] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndSpaceshipId,
		[&](const Event& event)
	{
		OnRocketCollisionHandler(event);
	});
}

int Ammunition::GetZOrder() const
{
	return 2;
}

Ammunition::~Ammunition()
{
}
