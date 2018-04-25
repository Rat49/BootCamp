#include "Star.h"
#include "Mathematics.h"

const float SPEED = 30.0f;

void Star::DefaultInit()
{
	_alfaColor = 100;
	_radius = 0.1;
	_star = sf::CircleShape(_radius);
	_star.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	_star.setPosition(0, 0);
}

void Star::RandomInit()
{
	_radius = GetFloatRandomValue(0.1, 1.0);
	_star.setRadius(_radius);
	if (_radius < 1.5)
		_alfaColor = 100;
	else
		_alfaColor = 255;
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

void Star::Init(sf::RenderWindow & window)
{
	SetWindowOneTime(window);
	RandomInit();
	_star.setPosition(GetRandomPosition());
}

void Star::Update(sf::Time time)
{	
	float updateTime = time.asSeconds()*40.f;
	if (_radius < 4.0)
	{
		_radius += updateTime;

		if (_alfaColor < 255)
			_alfaColor += _radius;
	}
	else if (_radius >= 4.0 && _radius < 6.0)
	{
		_radius += updateTime;

		if (_alfaColor > 10)
			_alfaColor -= 10;
	} 
	else
	{
		_radius = 0.1;
		_alfaColor = 0;
	}

	_star.setRadius(_radius);
	_star.setFillColor(sf::Color(255, 255, 255, _alfaColor));
	
	sf::Vector2f coordinates = sf::Vector2f(_star.getPosition().x, _star.getPosition().y);
	sf::Vector2f directionFromCenter = sf::Vector2f(coordinates.x - GetSizeWindow().x / 2, coordinates.y - GetSizeWindow().y / 2);
	sf::Vector2f linearVelocity = _radius * SPEED * GetNormalizedVelocity(directionFromCenter);
	sf::Vector2f nextPosition = coordinates + linearVelocity * updateTime;

	if ((nextPosition.x >GetSizeWindow().x) || (nextPosition.x < 0) || (nextPosition.y > GetSizeWindow().y) || (nextPosition.y < 0))
	{
		nextPosition = GetRandomPosition();
		RandomInit();
	}

	_star.setPosition(nextPosition);
}

void Star::Draw()
{
	DrawInWindow(_star);
}

