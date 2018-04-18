#include "Asteroid.h"
#include "Mathematics.h"

Asteroid::Asteroid()
{
	_sprite = sf::Sprite(sf::Texture::Texture());
	_linearVelocity = sf::Vector2f(0,0);
	_angularVelocity = 0;
	_radius = 0;
	_rotationSpeed = 0;
}

void Asteroid::Reset()
{
	_sprite.setTexture(sf::Texture::Texture(), true);
	_sprite.setScale(1, 1);
	_sprite.setOrigin(0,0);
	_sprite.setPosition(0,0);
	_sprite.setRotation(0);
	_linearVelocity = sf::Vector2f(0, 0);
	_angularVelocity = 0;
	_radius = 0;
	_rotationSpeed = 0;
}

void Asteroid::Init(sf::Sprite & sprite)
{	
	_sprite = sprite;
	_linearVelocity = sf::Vector2f(GetRandomValue(-500, 500), GetRandomValue(-500, 500));
	_angularVelocity = GetRandomValue(-15,15);
	int startScale = GetRandomValue(1, 3);
	_sprite.setScale(sf::Vector2f(startScale, startScale));
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	_sprite.setPosition(GetRandomValue(0, _window->getSize().x), GetRandomValue(0, _window->getSize().y));
	_sprite.setRotation(_angularVelocity);
	_rotationSpeed = GetRandomValue(1,80);
}

void Asteroid::Update(float time) 
{
	_angularVelocity = _angularVelocity + time * _rotationSpeed;
	sf::Vector2f nextPosition = _sprite.getPosition() + _linearVelocity * time;

	float halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;

	if (nextPosition.y + halfLenght > _window->getSize().y)
	{
		nextPosition.y -= _window->getSize().y + halfLenght * 2;
	}

	if (nextPosition.x + halfLenght > _window->getSize().x)
	{
		nextPosition.x -= _window->getSize().x + halfLenght * 2;
	}

	if (nextPosition.y + halfLenght < 0) 
	{
		nextPosition.y += _window->getSize().y + halfLenght * 2;
	}

	if (nextPosition.x + halfLenght < 0) 
	{
		nextPosition.x += _window->getSize().x + halfLenght * 2;
	}
	
	_sprite.setPosition(nextPosition);
	_sprite.setRotation(_angularVelocity);
}

void Asteroid::Draw()
{
	_window->draw(_sprite);
}







