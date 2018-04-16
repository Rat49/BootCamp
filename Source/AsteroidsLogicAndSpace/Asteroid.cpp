#include "Asteroid.h"

int GetRandomValue (int start, int end)
{
	return start + rand() % end;
}

float GetLenght(const sf::Vector2f &vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

Asteroid::Asteroid(sf::Sprite &sprite, sf::Rect<int> &borders, int id)
	:_sprite(sprite)
	, _borders(borders)
{
//	srand(id);
	//_velocity = sf::Vector2f(GetRandomValue(0,_borders.width), GetRandomValue(0,_borders.height));
	_velocity = sf::Vector2f(20,20);
	_rotation = GetRandomValue(-15,15);
	int startScale = GetRandomValue(1, 3);
	_scale = sf::Vector2f(startScale, startScale);
	_sprite.setScale(_scale);
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	_sprite.setPosition(0, 0);
	_sprite.setPosition(GetRandomValue(0, _borders.width), GetRandomValue(0, _borders.height));
	_sprite.setRotation(_rotation);
	
}

sf::Sprite Asteroid::GetSprite()
{
	return _sprite;
}

void Asteroid::Update(float time)
{
	if (!active) return;
	_rotation = _rotation + time * 10;
	sf::Vector2f nextPosition = _sprite.getPosition() + _velocity * time;
	float l = dot(nextPosition, sf::Vector2f(0, 1));

	float halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;
	if (nextPosition.x + halfLenght < 0)
	{
		active = false;
		nextPosition.x += _borders.width - halfLenght * 2;
	}

	if (nextPosition.x - halfLenght > _borders.width)
	{
		active = false;
		nextPosition.x -= _borders.width - halfLenght * 2;
	}
	
	if (nextPosition.y + halfLenght< 0)
	{
		active = false;
		nextPosition.y += _borders.height + halfLenght * 2;
	}

	if (nextPosition.y - halfLenght> _borders.height)
	{
		active = false;
		nextPosition.y -= _borders.height + halfLenght * 2;
	}
	
	_sprite.setPosition(nextPosition);
	_sprite.setRotation(_rotation);
}

float Asteroid::dot(sf::Vector2f v1, sf::Vector2f v2) 
{
	return v1.x * v2.x + v1.y * v2.y;
}

Asteroid::~Asteroid()
{

}


