#pragma once
#define _USE_MATH_DEFINES

#include <SFML\System\Vector2.hpp>
#include <math.h>

inline int GetRandomValue(int start, int end)
{
	if (start != end)
	{
		start += rand() % (end - start);
	}
	return start;
}

inline float GetSquaredLength(sf::Vector2f vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

inline float GetLength(sf::Vector2f vector)
{
	return std::sqrt(GetSquaredLength(vector));
}

inline float GetFloatRandomValue(float start, float end)
{
	return (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * (end - start) + start;
}

inline sf::Vector2f GetNormalizedVelocity(sf::Vector2f vector)
{
	float length = GetLength(vector);
	return sf::Vector2f(vector.x / length, vector.y / length);
}

inline float RadiansToDegrees(float radianAngle)
{
	return static_cast<float>(radianAngle * 180.0f / M_PI);
}

inline float DegreesToRadians(float degreeAngle)
{
	return static_cast<float>(degreeAngle * M_PI / 180.0f);
}

inline sf::Vector2f RotateVector(sf::Vector2f vector, float degreeAngle)
{
	float radianAngle = DegreesToRadians(degreeAngle);
	return sf::Vector2f(vector.x * std::cos(radianAngle) - vector.y * std::sin(radianAngle),
		vector.x * std::sin(radianAngle) + vector.y * std::cos(radianAngle));
}

