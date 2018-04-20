#include "Asteroid.h"
#include "Mathematics.h"
#include "iostream"

void Asteroid::DefaultInit()
{
	_angularVelocity = 0;
	_radius = 0;
	_position = sf::Vector2f(0, 0);
	_rotationSpeed = 0;
	_sprite.setScale(1, 1);
	_sprite.setOrigin(0, 0);
	_sprite.setPosition(_position);
	_sprite.setRotation(0);
	
}

void Asteroid::RandomInit()
{
	_angularVelocity = GetRandomValue(-15, 15);
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	_position = sf::Vector2f(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y));
	_sprite.setPosition(_position);
	_sprite.setRotation(_angularVelocity);
	_rotationSpeed = GetRandomValue(1, 80);
	
}

void Asteroid::InitFromCrash(sf::Sprite & sprite,sf::Vector2f position, float preLifeTime)
{
	
	_sprite = sprite;
	_linearVelocity = sf::Vector2f(GetRandomValue(-500, 500), GetRandomValue(-500, 500));

	float startScale = 1.0;
	_liveTime = 30.0;

	if (preLifeTime == 30.0)
	{
		startScale = 0.5;
		_liveTime = 20.0;
	}
	
	_allLiveTime = _liveTime;
	_sprite.setScale(sf::Vector2f(startScale, startScale));

	RandomInit();
	_position = sf::Vector2f(GetRandomValue(position.x - 50.0, position.x + 50.0), GetRandomValue(position.y - 50.0, position.y + 50.0));
	_sprite.setPosition(_position);	
	_halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;
}

Asteroid::Asteroid()
{
	_sprite = sf::Sprite(sf::Texture::Texture());
	_linearVelocity = sf::Vector2f(0, 0);
	DefaultInit();
}

void Asteroid::Reset()
{
	_sprite.setTexture(sf::Texture::Texture(), true);
	_linearVelocity = sf::Vector2f(0, 0);
	DefaultInit();
}

void Asteroid::Init(sf::Sprite & sprite, sf::Vector2u size)
{	
	_sizeSpace = size;
	_sprite = sprite;
	_linearVelocity = sf::Vector2f(GetRandomValue(-300, 300), GetRandomValue(-300, 300));
	//float startScale = GetRandomValue(0.3, 1.5);
	float startScale = 1.5;
	_sprite.setScale(sf::Vector2f(startScale, startScale));

	if (startScale <= 0.5)
		_liveTime = 20.0;
	else if (startScale > 0.5 && startScale <= 1)
		_liveTime = 30.0;
	else
		_liveTime = 40.0;

	_allLiveTime = _liveTime;

	_sprite.setScale(sf::Vector2f(startScale, startScale));
	RandomInit();
	_halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;
}

void Asteroid::Update(sf::Time time)
{
	float updateTime = time.asSeconds() * 40.0f;

	if (_liveTime >= 0)
		_liveTime -= updateTime;

	_angularVelocity = _angularVelocity + updateTime * _rotationSpeed;
	sf::Vector2f nextPosition = _position + _linearVelocity * updateTime;

	if (nextPosition.y + _halfLenght > GetSizeWindow().y)
	{
		nextPosition.y -= GetSizeWindow().y + _halfLenght * 2;
	}

	if (nextPosition.x + _halfLenght > GetSizeWindow().x)
	{
		nextPosition.x -= GetSizeWindow().x + _halfLenght * 2;
	}

	if (nextPosition.y + _halfLenght < 0)
	{
		nextPosition.y += GetSizeWindow().y + _halfLenght * 2;
	}

	if (nextPosition.x + _halfLenght < 0)
	{
		nextPosition.x += GetSizeWindow().x + _halfLenght * 2;
	}
	_position = nextPosition;
	_sprite.setPosition(_position);
	_sprite.setRotation(_angularVelocity);
}

void Asteroid::Draw(sf::RenderWindow & window)
{
	window.draw(_sprite);
}

