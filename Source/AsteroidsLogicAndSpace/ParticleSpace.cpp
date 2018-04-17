#include "ParticleSpace.h"

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
	_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(10, 255)));
	_particle.setPosition(GetRandomValue(0, borders.width), GetRandomValue(0, borders.height));
	_depth = GetFloatRandomValue(5,9);
}

void ParticleSpace::Update(float time)
{
	
	sf::Vector2f coordinates = sf::Vector2f(_particle.getPosition().x, _particle.getPosition().y);
	sf::Vector2f velocity = 10.0f * GetNormalizedVelocity(coordinates);
	sf::Vector2f nextPosition = coordinates + velocity * time;
	if ((nextPosition.x > _borders.width) || (nextPosition.x < 0) || (nextPosition.y > _borders.height) || (nextPosition.y < 0))
	{
		nextPosition = sf::Vector2f(GetRandomValue(0, _borders.width), GetRandomValue(0, _borders.height));
	}
	_particle.setPosition(nextPosition);

}

void ParticleSpace::Draw(sf::RenderWindow *window)
{
	window->draw(_particle);
}
