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

	_sprite.setOrigin(_radius * 2, _radius * 2);
	_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
		//SetCoordinates(sf::Vector2f(200,200));
	auto rt = GetCoordinates();
	_sprite.setPosition(sf::Vector2f(rt.x + _radius, rt.y + _radius));
	_sprite.setRotation(_angularVelocity);
}



void Ammunition::Draw(sf::RenderWindow &window)
{
	sf::CircleShape physicsShape(GetRadius());
	physicsShape.setPosition(GetCoordinates());
		//physicsShape.setOrigin(sf::Vector2f{ GetRadius(), GetRadius() });
	physicsShape.setOutlineColor(sf::Color(255, 255, 255, 255));
	physicsShape.setFillColor(sf::Color::Transparent);
	physicsShape.setOutlineThickness(1);
	
	window.draw(physicsShape);
	sf::CircleShape circleCenter(1);
	circleCenter.setPosition(GetX() + GetRadius(),
	+GetY() + GetRadius());
	circleCenter.setRadius(1.f);
	circleCenter.setFillColor(sf::Color::Green);
	window.draw(circleCenter);
	window.draw(_sprite);
}

void Ammunition::Init()
{

	uint8_t ammunitionNumber = std::rand() % 6;
	
	_sprite = _sprites[ammunitionNumber];
	
	_radius = _sprite.getLocalBounds().width / 4;
	SetRadius(_radius);
	_sprite.setOrigin(_radius, _radius);
	
	SetMass(0.015f);
	
	AddToDrawableManager();
	
	_ammunitionType = static_cast<AmmunitionType>(ammunitionNumber / 3);
	_ammunitionSize = static_cast<AmmunitionSize>(ammunitionNumber % 3);


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

Ammunition::Ammunition(ResourceManager *rm)
{
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("bulletSmall")->Get()));
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("bulletMedium")->Get()));
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("bulletBig")->Get()));
	
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("rocketSmall")->Get()));
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("rocketMedium")->Get()));
	_sprites.push_back(sf::Sprite(rm->GetResource<TextureResource>("rocketBig")->Get()));
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
