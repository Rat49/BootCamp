#include "ParticleSpace.h"
#include <iostream>

float GetFloatRandomValue(int start, int end)
{
	float result = start / 10.0f + rand() % (10 * end) / 100.0f;
	return result;
}

int GetRandomValue1(int start, int end)
{
	return start + rand() % end;
}

float GetLenght1(const sf::Vector2f &vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f ParticleSpace::GetNormalizedVelocity(sf::Vector2f vector)
{

	sf::Vector2f razn = sf::Vector2f(vector.x - _borders.width / 2, vector.y - _borders.height / 2);
	float length = std::sqrt(razn.x * razn.x + razn.y * razn.y);
	sf::Vector2f normalizedVelocity = _depth * sf::Vector2f(razn.x / length, razn.y / length);
	return normalizedVelocity;
}

ParticleSpace::ParticleSpace(sf::Rect<int> &borders)
	:_borders(borders)
{
	_particle = sf::CircleShape(GetFloatRandomValue(1, 9));
	_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue1(10, 255)));
	_particle.setPosition(GetRandomValue1(0, borders.width), GetRandomValue1(0, borders.height));
	//_particle.setPosition(500, 500);
	_depth = GetFloatRandomValue(5,9);
}

void ParticleSpace::Update(float time)
{
	if (!active)
		return;
	//std::cout << "_particle.getGlobalBounds() = " << _particle.getPosition().x << ", " << _particle.getPosition().y << std::endl;
	sf::Vector2f coordinates = sf::Vector2f(_particle.getPosition().x, _particle.getPosition().y);
	sf::Vector2f velocity = 10.0f * GetNormalizedVelocity(coordinates);
	sf::Vector2f nextPosition = coordinates + velocity * time;
	//std::cout << "nextPosition = " << nextPosition.x << ", " << nextPosition.y << std::endl;
	if ((nextPosition.x > _borders.width) || (nextPosition.x < 0) || (nextPosition.y > _borders.height) || (nextPosition.y < 0))
	{
		nextPosition = sf::Vector2f(GetRandomValue1(0, _borders.width), GetRandomValue1(0, _borders.height));
	}
	_particle.setPosition(nextPosition);
	//active = false;

}

void ParticleSpace::Draw(sf::RenderWindow *window)
{
	window->draw(_particle);
}
