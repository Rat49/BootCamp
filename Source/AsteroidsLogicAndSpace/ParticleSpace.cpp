#include "ParticleSpace.h"
#include "Mathematics.h"

sf::Vector2f ParticleSpace::GetRandomPosition()
{
	return sf::Vector2f(GetRandomValue(0, _window->getSize().x), GetRandomValue(0, _window->getSize().y));
}

ParticleSpace::ParticleSpace()
{
	_particle = sf::CircleShape(0);
	_particle.setFillColor(sf::Color(255, 255, 255, 255));
	_particle.setPosition(0,0);
	_depth = 3;
}

void ParticleSpace::Reset()
{
	_particle = sf::CircleShape(0);
	_particle.setFillColor(sf::Color(255, 255, 255, 255));
	_particle.setPosition(0, 0);
	_depth = 3;
}

void ParticleSpace::Init()
{

	_depth = GetFloatRandomValue(3.0, 3.9);
	_particle.setPosition(GetRandomPosition());
	
}

void ParticleSpace::Update(float time)
{	
	_depth += time;
	if (_depth >= 3 && _depth < 4)
	{
		_particle.setRadius(GetFloatRandomValue(0.01, 0.02));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(0, 1)));
	}
	else if (_depth >= 4 && _depth < 5)
	{
		_particle.setRadius(GetFloatRandomValue(0.1, 0.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(200, 255)));
	}
	else if (_depth >= 5 && _depth < 6)
	{
		_particle.setRadius(GetFloatRandomValue(1.0, 1.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(150, 200)));
	}
	else if (_depth >= 6 && _depth < 7)
	{
		_particle.setRadius(GetFloatRandomValue(2.0, 2.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(130, 150)));
	}
	else if (_depth >= 7 && _depth < 8)
	{
		_particle.setRadius(GetFloatRandomValue(3.0, 3.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(100, 130)));
	}
	else if (_depth >= 8 && _depth < 9)
	{
		_particle.setRadius(GetFloatRandomValue(4.0, 4.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(70, 100)));
	}
	else if (_depth >= 5 && _depth < 6)
	{
		_particle.setRadius(GetFloatRandomValue(5.0, 5.9));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(50, 70)));
	}
	else
	{
		_particle.setRadius(GetFloatRandomValue(6.0, 7.0));
		_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(30, 50)));
	}
	sf::Vector2f coordinates = sf::Vector2f(_particle.getPosition().x, _particle.getPosition().y);
	sf::Vector2f directionFromCenter = sf::Vector2f(coordinates.x - _window->getSize().x / 2, coordinates.y - _window->getSize().y / 2);
	sf::Vector2f linearVelocity = _depth * 10.0f * GetNormalizedVelocity(directionFromCenter);
	sf::Vector2f nextPosition = coordinates + linearVelocity * time;
	if ((nextPosition.x > _window->getSize().x) || (nextPosition.x < 0) || (nextPosition.y > _window->getSize().y) || (nextPosition.y < 0))
	{
		nextPosition = GetRandomPosition();
		_depth = GetFloatRandomValue(3, 11);
		if (_depth >= 3 && _depth < 5)
			_particle.setRadius(GetFloatRandomValue(3, 4));
		else if (_depth >= 5 && _depth < 7)
			_particle.setRadius(GetFloatRandomValue(2, 3));
		else if (_depth >= 7 && _depth < 9)
			_particle.setRadius(GetFloatRandomValue(1, 2));
		else
			_particle.setRadius(GetFloatRandomValue(0.1, 1));
	}
	_particle.setPosition(nextPosition);

}

void ParticleSpace::Draw()
{
	_window->draw(_particle);
}

