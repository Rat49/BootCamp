#include "Asteroid.h"
#include "Mathematics.h"

Asteroid::Asteroid()
{
	_sprite = sf::Sprite(sf::Texture::Texture());
	_borders = sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(0,0));
	_velocity = sf::Vector2f(0,0);
	_speed = 0;
	_velocity.x *= _speed;
	_velocity.y *= _speed;
	_rotation = 0;
	int startScale = 1;
	_scale = sf::Vector2f(startScale, startScale);
	_radius = 0;
	_rotationSpeed =0;
}

void Asteroid::Reset()
{
	_sprite.setTexture(sf::Texture::Texture(), true);
	_sprite.setScale(1, 1);
	_sprite.setOrigin(0,0);
	_sprite.setPosition(0,0);
	_sprite.setRotation(0);
	_velocity = sf::Vector2f(0, 0);
	_speed = 0;
	_velocity.x *= _speed;
	_velocity.y *= _speed;
	_rotation = 0;
	int startScale = 1;
	_scale = sf::Vector2f(startScale, startScale);
	_radius = 0;
	_rotationSpeed = 0;
}

void Asteroid::Init(sf::Sprite & sprite)
{	
	_sprite = sprite;
	_velocity = sf::Vector2f(GetRandomValue(0, window->getSize().x), GetRandomValue(0, window->getSize().y));
	_speed = GetRandomValue(-1, 1);
	_velocity.x *= _speed;
	_velocity.y *= _speed;
	_rotation = GetRandomValue(-15,15);
	int startScale = GetRandomValue(1, 3);
	_scale = sf::Vector2f(startScale, startScale);
	_sprite.setScale(_scale);
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	_sprite.setPosition(GetRandomValue(0, window->getSize().x), GetRandomValue(0, window->getSize().y));
	_sprite.setRotation(_rotation);
	_rotationSpeed = GetRandomValue(1,80);
}

void Asteroid::Update(float time) 
{
	_rotation = _rotation + time * _rotationSpeed;
	sf::Vector2f nextPosition = _sprite.getPosition() + _velocity * time;

	float halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;

	if ((nextPosition.y + halfLenght > window->getSize().y) && (nextPosition.x > window->getSize().x / 2))
	{
		nextPosition.y = nextPosition.y - window->getSize().y - halfLenght * 2;
		nextPosition.x = window->getSize().x - nextPosition.x;
	}

	if ((nextPosition.x + halfLenght > window->getSize().x) && (nextPosition.y > window->getSize().y / 2))
	{
		nextPosition.x = nextPosition.x - window->getSize().x - halfLenght * 2;
		nextPosition.y = window->getSize().y - nextPosition.y;
	}

	if ((nextPosition.x + halfLenght > window->getSize().x) && (nextPosition.y < window->getSize().y / 2))
	{
		nextPosition.x = nextPosition.x - window->getSize().x - halfLenght * 2;
		nextPosition.y = nextPosition.y + (window->getSize().y / 2 - nextPosition.y) * 2;
	}

	if ((nextPosition.y + halfLenght < 0) && (nextPosition.x > window->getSize().x / 2))
	{
		nextPosition.y = nextPosition.y + window->getSize().y + halfLenght * 2;
		nextPosition.x = window->getSize().x - nextPosition.x;
	}

	if ((nextPosition.y + halfLenght < 0) && (nextPosition.x < window->getSize().x / 2))
	{
		nextPosition.y = nextPosition.y + window->getSize().y + halfLenght * 2;
		nextPosition.x = nextPosition.x + (window->getSize().x / 2 - nextPosition.x) * 2;
	}

	if ((nextPosition.x + halfLenght < 0) && (nextPosition.y < window->getSize().y / 2))
	{
		nextPosition.x = nextPosition.x + window->getSize().x + halfLenght * 2;
		nextPosition.y = nextPosition.y + ((window->getSize().y / 2) - nextPosition.y) * 2;
	}

	if ((nextPosition.x + halfLenght < 0) && (nextPosition.y > window->getSize().y / 2))
	{
		nextPosition.x = nextPosition.x + window->getSize().x + halfLenght * 2;
		nextPosition.y = nextPosition.y - ((window->getSize().y / 2) - (window->getSize().y - nextPosition.y)) * 2;
	}

	if ((nextPosition.y - halfLenght > window->getSize().y) && (nextPosition.x < window->getSize().x / 2))
	{
		nextPosition.y = nextPosition.y - window->getSize().y - halfLenght * 2;
		nextPosition.x = nextPosition.x + (window->getSize().x / 2 - nextPosition.x) * 2;
	}
	
	_sprite.setPosition(nextPosition);
	_sprite.setRotation(_rotation);
}

void Asteroid::Draw()
{
	window->draw(_sprite);
}







