#include "Asteroid.h"
#include "Mathematics.h"

Pool<Asteroid> *Asteroid::poolAsteroid = nullptr;
std::vector<RigidBody *> Asteroid::rigidBodies;

void Asteroid::DefaultInit()
{
	_angularVelocity = 0;
	_rotationSpeed = 0;
	_sprite.setRotation(_angularVelocity);

	_linearVelocity = sf::Vector2f(0, 0);
	SetSpeed(_linearVelocity);

	_sprite.setPosition(sf::Vector2f(0, 0));
	SetCoordinates(sf::Vector2f(0, 0));

	_radius = 1;
	SetRadius(_radius);

	_type = AsteroidType::Small;
	SetParametersFromType(_type);

	_sprite.setScale(_startScale, _startScale);
	_sprite.setOrigin(0, 0);

	SetMass(0.005f);
}

void Asteroid::RandomInit()
{
	_angularVelocity = GetRandomValue(-15, 15);
	_rotationSpeed = GetRandomValue(1, 80);
	_sprite.setRotation(_angularVelocity);
		
	_linearVelocity = sf::Vector2f(GetRandomValue(-300, 300), GetRandomValue(-300, 300));
	SetSpeed(_linearVelocity);

	_sprite.setPosition(sf::Vector2f(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y)));
	SetCoordinates(sf::Vector2f(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y)));
}

void Asteroid::SetParametersFromType(AsteroidType type)
{
	switch (type)
	{
	case AsteroidType::Big:
		_startScale = 1.5;
		_health = 400.0;
		_damage = 60;
		_defense = 20;
		SetMass(0.015f);
		break;
	case AsteroidType::Middle:
		_startScale = 1.0;
		_health = 300.0;
		_damage = 40;
		_defense = 10;
		SetMass(0.01f);
		break;
	case AsteroidType::Small:
	default:
		_startScale = 0.5;
		_health = 200.0;
		_damage = 20;
		_defense = 5;
		SetMass(0.005f);
		break;
	}
}

void Asteroid::InitFromCrash(const sf::Sprite &sprite, const sf::Vector2f &position, const AsteroidType type, const sf::Vector2u &size)
{
	_sprite = sprite;
	_sizeSpace = size;

	switch (type)
	{
	case AsteroidType::Big:
		_type = AsteroidType::Middle;
		break;
	case AsteroidType::Middle:
	default:
		_type = AsteroidType::Small;
		break;
	}

	SetParametersFromType(_type);
	
	RandomInit();

	_radius = _sprite.getLocalBounds().width / 2 * _startScale;
	SetRadius(_radius);

	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().width / 2);
	_sprite.setScale(sf::Vector2f(_startScale, _startScale));

	_sprite.setPosition(sf::Vector2f(GetRandomValue(position.x - 50.0, position.x + 50.0), GetRandomValue(position.y - 50.0, position.y + 50.0)));
	SetCoordinates(sf::Vector2f(GetRandomValue(position.x - 50.0, position.x + 50.0), GetRandomValue(position.y - 50.0, position.y + 50.0)));

	_halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;
	
	Add();
}

Asteroid::Asteroid()
{
	_sprite = sf::Sprite(sf::Texture::Texture());
	DefaultInit();
}

void Asteroid::Reset()
{
	_sprite.setTexture(sf::Texture::Texture(), true);
	DefaultInit();
}

void Asteroid::OnCollisionHandler(const Event& cEvent)
{
	const CollisionEvent &collisionEvent = dynamic_cast<const CollisionEvent&>(cEvent);
	Asteroid *obj = dynamic_cast<Asteroid *>(collisionEvent._obj2);
	
	this->_health -= obj->_damage - _defense;
	if (this->IsDead())
	{
		if (poolAsteroid != nullptr && !(poolAsteroid->Count() == poolAsteroid->MaxCount()))
		{
			Remove();
			poolAsteroid->Put(this);
		}
	}
	std::cout << "Collision!";
}

void Asteroid::Init(const sf::Sprite &sprite, const sf::Vector2u &size)
{		
	_sprite = sprite;
	_sizeSpace = size;

	_type = static_cast<AsteroidType>(std::rand() % static_cast<uint8_t>(AsteroidType::Count));

	SetParametersFromType(_type);
	
	_sprite.setScale(sf::Vector2f(_startScale, _startScale));

	_radius = _sprite.getLocalBounds().width / 2 * _startScale;
	SetRadius(_radius);
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().width / 2);

	RandomInit();

	_halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;

	Add();
}

void Asteroid::Add()
{
	Object::Add();

	_token = Dispatcher::getInstance().Connect(EventTypes::collisionEventID, std::bind(&Asteroid::OnCollisionHandler, this, std::placeholders::_1));
}

void Asteroid::Remove()
{
	Object::Remove();

	Dispatcher::getInstance().Disconnect(EventTypes::collisionEventID, _token);
}

void Asteroid::Update(float time)
{
	RigidBody::Update(time);

	_angularVelocity = _angularVelocity + time * _rotationSpeed;
	sf::Vector2f nextPosition = GetCoordinates() + GetSpeed() * time;

	if (nextPosition.y + _halfLenght > GetSizeWindow().y)
	{
		nextPosition.y -= GetSizeWindow().y + _halfLenght * 2;
		SetCoordinates(nextPosition);
	}
	if (nextPosition.x + _halfLenght > GetSizeWindow().x)
	{
		nextPosition.x -= GetSizeWindow().x + _halfLenght * 2;
		SetCoordinates(nextPosition);
	}
	if (nextPosition.y + _halfLenght < 0)
	{
		nextPosition.y += GetSizeWindow().y + _halfLenght * 2;
		SetCoordinates(nextPosition);
	}
	if (nextPosition.x + _halfLenght < 0)
	{
		nextPosition.x += GetSizeWindow().x + _halfLenght * 2;
		SetCoordinates(nextPosition);
	}

	_sprite.setPosition(GetCoordinates());
	_sprite.setRotation(_angularVelocity);
}

void Asteroid::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
	
	sf::CircleShape physicsShape(GetRadius());
	physicsShape.setPosition(GetCoordinates()); 
	physicsShape.setOrigin(sf::Vector2f{ GetRadius(), GetRadius() });
	
	float color;

	switch (_type)
	{
	case AsteroidType::Small:
		color = _health / 200.0 * 255.0;
		break;
	case AsteroidType::Middle:
		color = _health / 300.0 * 255.0;
		break;
	case AsteroidType::Big:
	default:
		color = _health / 400.0 * 255.0;
		break;
	}

	physicsShape.setOutlineColor(sf::Color(255, color, color, 255));
	physicsShape.setFillColor(sf::Color::Transparent);
	physicsShape.setOutlineThickness(1);

	window.draw(physicsShape);
}

bool Asteroid::IsDead()
{
	if (_health <= 0)
	{
		if (_type == AsteroidType::Small)
			return true;
		else
		{
			for (int j = 0; j < 4; ++j)
			{
				if (poolAsteroid != nullptr && !poolAsteroid->Empty())
				{
					Asteroid* asteroidNew = poolAsteroid->Get();
					asteroidNew->InitFromCrash(_sprite, GetCoordinates(), _type, _sizeSpace);
					rigidBodies.push_back(asteroidNew);
				}
			}
			return true;
		}
	}
	else
		return false;
}

