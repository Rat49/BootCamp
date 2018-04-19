#include "Asteroid.h"
#include "Mathematics.h"
#include "iostream"

void Asteroid::DefaultInit()
{
	_linearVelocity = sf::Vector2f(0, 0);
	_angularVelocity = 0;
	_radius = 0;
	_rotationSpeed = 0;
	_sprite.setScale(1, 1);
	_sprite.setOrigin(0, 0);
	_sprite.setPosition(0, 0);
	_sprite.setRotation(0);
}

void Asteroid::RandomInit()
{
	_linearVelocity = sf::Vector2f(GetRandomValue(-500, 500), GetRandomValue(-500, 500));
	_angularVelocity = GetRandomValue(-15, 15);
	int startScale = GetRandomValue(1, 3);
	_sprite.setScale(sf::Vector2f(startScale, startScale));
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	_sprite.setPosition(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y));
	_sprite.setRotation(_angularVelocity);
	_rotationSpeed = GetRandomValue(1, 80);
	_live = GetFloatRandomValue(20.0, 50.0);
}

void Asteroid::InitFromCrash()
{

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

void Asteroid::Init(sf::Sprite & sprite, sf::RenderWindow & window)
{	
	SetWindowOneTime(window);
	_sprite = sprite;
	RandomInit();
	_halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;
}

void Asteroid::Update(sf::Time time)
{
	float updateTime = time.asSeconds() * 40.f;

	if (_live >= 0)
		_live -= updateTime;
	else
	{
		std::cout << "Crash must be now!" << std::endl;
	}

	_angularVelocity = _angularVelocity + updateTime * _rotationSpeed;
	sf::Vector2f nextPosition = _sprite.getPosition() + _linearVelocity * updateTime;

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
	
	_sprite.setPosition(nextPosition);
	_sprite.setRotation(_angularVelocity);
}

void Asteroid::Draw()
{
	DrawInWindow(_sprite);
}







