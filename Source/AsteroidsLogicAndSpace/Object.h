#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
class Object :
	public PoolElement
{
public:

	int GetRandomValue(int start, int end)
	{
		return start + rand() % end;
	}

	float GetLenght(const sf::Vector2f &vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	float GetFloatRandomValue(int start, int end)
	{
		float result = start / 10.0f + rand() % (10 * end) / 100.0f;
		return result;
	}

	virtual void Draw(sf::RenderWindow *window) {

	}

	virtual void Update(float time) {

	}

	virtual ~Object() {

	}
};