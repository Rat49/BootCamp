#pragma once
#include "SFML/System/Vector2.hpp"
#include <math.h>

inline int GetRandomValue(int start, int end)
{
	return start + rand() % (end - start);
}

inline float GetLenght(const sf::Vector2f &vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

inline float GetFloatRandomValue(float start, float end)
{
	return (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * (end - start) + start;
}

inline sf::Vector2f GetNormalizedVelocity(const sf::Vector2f &vector)
{
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	return sf::Vector2f(vector.x / length, vector.y / length);
}
