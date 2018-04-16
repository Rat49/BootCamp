#include "Asteroid.h"

int GetRandomValue (int start, int end)
{
	return start + rand() % end;
}

float GetLenght(const sf::Vector2f &vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Dot(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}

Asteroid::Asteroid(sf::Sprite &sprite, sf::Rect<int> &borders, int id)
	:_sprite(sprite)
	, _borders(borders)
{
//	srand(id);
	_velocity = sf::Vector2f(GetRandomValue(0,_borders.width), GetRandomValue(0,_borders.height));
	_speed = GetRandomValue(-1, 1);
	//_speed = -1;
	//_velocity = sf::Vector2f(50,50);
	_velocity.x *= _speed;
	_velocity.y *= _speed;
	_rotation = GetRandomValue(-15,15);
	int startScale = GetRandomValue(1, 3);
	_scale = sf::Vector2f(startScale, startScale);
	_sprite.setScale(_scale);
	_radius = _sprite.getLocalBounds().width / 2;
	_sprite.setOrigin(_radius, _radius);
	//_sprite.setPosition(200, 300);
	_sprite.setPosition(GetRandomValue(0, _borders.width), GetRandomValue(0, _borders.height));
	_sprite.setRotation(_rotation);
	_rotationSpeed = GetRandomValue(1,80);
	
}

sf::Sprite Asteroid::GetSprite()
{
	return _sprite;
}

void Asteroid::Update(float time)
{
	_rotation = _rotation + time * _rotationSpeed;
	sf::Vector2f nextPosition = _sprite.getPosition() + _velocity * time;

	float halfLenght = GetLenght(sf::Vector2f(_sprite.getLocalBounds().width, _sprite.getLocalBounds().height)) / 2;

	if ((nextPosition.y + halfLenght > _borders.height) && (nextPosition.x > _borders.width / 2))
	{
		nextPosition.y = nextPosition.y - _borders.height - halfLenght * 2;
		nextPosition.x = _borders.width - nextPosition.x;
	}

	if ((nextPosition.x + halfLenght > _borders.width) && (nextPosition.y > _borders.height / 2))
	{
		nextPosition.x = nextPosition.x - _borders.width - halfLenght * 2;
		nextPosition.y = _borders.height - nextPosition.y;
	}

	if ((nextPosition.x + halfLenght > _borders.width) && (nextPosition.y < _borders.height / 2))
	{
		nextPosition.x = nextPosition.x - _borders.width - halfLenght * 2;
		nextPosition.y = nextPosition.y + (_borders.height / 2 - nextPosition.y) * 2;
	}

	if ((nextPosition.y + halfLenght < 0) && (nextPosition.x > _borders.width / 2))
	{
		nextPosition.y = nextPosition.y + _borders.height + halfLenght * 2;
		nextPosition.x = _borders.width - nextPosition.x;
	}

	if ((nextPosition.y + halfLenght < 0) && (nextPosition.x < _borders.width / 2))
	{
		nextPosition.y = nextPosition.y + _borders.height + halfLenght * 2;
		nextPosition.x = nextPosition.x + (_borders.width / 2 - nextPosition.x) * 2;
	}

	if ((nextPosition.x + halfLenght < 0) && (nextPosition.y < _borders.height / 2))
	{
		nextPosition.x = nextPosition.x + _borders.width + halfLenght * 2;
		nextPosition.y = nextPosition.y + ((_borders.height / 2) - nextPosition.y) * 2;
	}

	if ((nextPosition.x + halfLenght < 0) && (nextPosition.y > _borders.height / 2))
	{
		nextPosition.x = nextPosition.x + _borders.width + halfLenght * 2;
		nextPosition.y = nextPosition.y - ((_borders.height / 2) - (_borders.height - nextPosition.y)) * 2;
	}

	if ((nextPosition.y - halfLenght > _borders.height) && (nextPosition.x < _borders.width / 2))
	{
		nextPosition.y = nextPosition.y - _borders.height - halfLenght * 2;
		nextPosition.x = nextPosition.x + (_borders.width / 2 - nextPosition.x) * 2;
	}
	
	_sprite.setPosition(nextPosition);
	_sprite.setRotation(_rotation);
}

Asteroid::~Asteroid()
{

}


