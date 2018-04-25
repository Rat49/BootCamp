#pragma once
#include "Star.h"
#include "Mathematics.h"

const float SPEED = 30.0f;

void Star::DefaultInit()
{
	_alfaColor = 100;
	_star.setFillColor(sf::Color(255, 255, 255, _alfaColor));

	_radius = 1;
	_star = sf::CircleShape(_radius);
	_star.setRadius(_radius);

	_star.setPosition(0, 0);
}

void Star::RandomInit()
{
	_radius = GetFloatRandomValue(0.1, 1.0);
	_star.setRadius(_radius);

	if (_radius < 0.5)
		_alfaColor = 100;
	else
		_alfaColor = 255;

	_star.setScale(_radius, _radius);
}

sf::Vector2f Star::GetRandomPosition()
{
	return sf::Vector2f(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y));
}

Star::Star()
{
	DefaultInit();
}

void Star::Reset()
{
	DefaultInit();
}

void Star::Remove()
{
	Object::Remove();
}

void Star::Init(const sf::Vector2u &size)
{
	_sizeSpace = size;

	RandomInit();

	_star.setPosition(GetRandomPosition());

	_zOrder = 6;
	AddToDrawableManager();
}

void Star::Update(float time)
{	
	if (_radius < 4.0)
	{
		_radius += time;

		if (_alfaColor < 255)
			_alfaColor += _radius;
	}
	else if (_radius >= 4.0 && _radius < 6.0)
	{
		_radius += time;

		if (_alfaColor > 10)
			_alfaColor -= 10;
	} 
	else
	{
		RandomInit();

		_star.setPosition(GetRandomPosition());
	}

	_star.setScale(_radius, _radius);

	_star.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	
	sf::Vector2f coordinates = sf::Vector2f(_star.getPosition().x, _star.getPosition().y);
	sf::Vector2f directionFromCenter = sf::Vector2f(coordinates.x - GetSizeWindow().x / 2, coordinates.y - GetSizeWindow().y / 2);
	sf::Vector2f linearVelocity = _radius * SPEED * GetNormalizedVelocity(directionFromCenter);
	sf::Vector2f nextPosition = coordinates + linearVelocity * time;

	if ((nextPosition.x >GetSizeWindow().x) || (nextPosition.x < 0) || (nextPosition.y > GetSizeWindow().y) || (nextPosition.y < 0))
	{
		nextPosition = GetRandomPosition();
		RandomInit();
	}

	_star.setPosition(nextPosition);
}

void Star::Draw(sf::RenderWindow & window)
{
	window.draw(_star);
}
