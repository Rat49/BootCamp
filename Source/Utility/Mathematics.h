#pragma once
#define _USE_MATH_DEFINES

#include "SFML\Graphics.hpp"
#include <math.h>

inline int GetRandomValue(int start, int end)
{
	if (start != end)
	{
		return start + rand() % (end - start);
	}
	else
	{
		return start;
	}
}

inline float GetSquareLength(sf::Vector2f vector)
{
	return vector.x * vector.x + vector.y * vector.y;
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

inline float RadiansToDegrees(float radianAngle)
{
	return radianAngle * 180.0f / M_PI;
}
inline float DegreesToRadians(float degreeAngle)
{
	return degreeAngle * M_PI / 180.0f;
}
sf::Vector2f RotateVector(sf::Vector2f vector, float degreeAngle)
{
	float radianAngle = DegreesToRadians(degreeAngle);

	return sf::Vector2f(vector.x * std::cos(radianAngle) - vector.y * std::sin(radianAngle),
		vector.x * std::sin(radianAngle) + vector.y * std::cos(radianAngle));
}

