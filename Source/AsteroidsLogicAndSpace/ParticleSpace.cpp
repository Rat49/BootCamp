#include "ParticleSpace.h"
#include "Mathematics.h"
#include <iostream>

sf::Vector2f ParticleSpace::GetRandomPosition()
{
	return sf::Vector2f(GetRandomValue(0, GetSizeWindow().x), GetRandomValue(0, GetSizeWindow().y));
}

ParticleSpace::ParticleSpace()
{
	_alfaColor = 100;
	_radius = 0.1;
	_particle = sf::CircleShape(_radius);
	_particle.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	_particle.setPosition(0,0);
	_depth = 1;
}

void ParticleSpace::Reset()
{
	_alfaColor = 100;
	_radius = 0.1;
	_particle = sf::CircleShape(_radius);
	_particle.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	_particle.setPosition(0, 0);
	_depth = 1;
}

void ParticleSpace::Init(sf::RenderWindow & window)
{
	SetWindowOneTime(window);
	//_radius = GetFloatRandomValue(0.1, 2.0);
	_radius = 0.5;
	_particle.setRadius(_radius);
	_depth = GetFloatRandomValue(3.0, 5.0);
	if (_radius < 1.5)
		_alfaColor = 150;
	else 
		_alfaColor = 255;
	_particle.setPosition(GetRandomPosition());	
}

void ParticleSpace::Update(sf::Time time)
{	
	float updateTime = time.asMilliseconds()/3600.0f;
	if (_radius < 4.0)
	{
		_radius += updateTime;
		_depth += updateTime;

		if (_alfaColor < 255)
			_alfaColor += _depth;
	}
	else if (_radius >= 4.0 && _radius < 5.0)
	{
		_radius += updateTime;
		_depth += updateTime;

		if (_alfaColor > 30)
			_alfaColor -= 30;
	} 
	else
	{
		_radius = 0.1;
		_alfaColor = 0;
	}

	_particle.setRadius(_radius);
	_particle.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	
	sf::Vector2f coordinates = sf::Vector2f(_particle.getPosition().x, _particle.getPosition().y);
	sf::Vector2f directionFromCenter = sf::Vector2f(coordinates.x - GetSizeWindow().x / 2, coordinates.y - GetSizeWindow().y / 2);
	sf::Vector2f linearVelocity = _depth * 10.0f * GetNormalizedVelocity(directionFromCenter);
	sf::Vector2f nextPosition = coordinates + linearVelocity * updateTime;
	std::cout << nextPosition.x << ", " << nextPosition.y << std::endl;

	if ((nextPosition.x >GetSizeWindow().x) || (nextPosition.x < 0) || (nextPosition.y > GetSizeWindow().y) || (nextPosition.y < 0))
	{
		nextPosition = GetRandomPosition();
		_depth = GetFloatRandomValue(3.0, 5.0);
		_radius = GetFloatRandomValue(0.1, 2.0);

		if (_radius < 1.5)
			_alfaColor = 150;
		else
			_alfaColor = 255;

		_particle.setFillColor(sf::Color(255, 255, 255, _alfaColor));
		_particle.setRadius(_radius);
	}

	_particle.setPosition(nextPosition);
}

void ParticleSpace::Draw()
{
	DrawInWindow(_particle);
}

