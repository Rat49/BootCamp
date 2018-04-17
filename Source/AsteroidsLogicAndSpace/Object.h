#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
class Object :
	public PoolElement
{
public:

	sf::RenderWindow *window = nullptr;

	virtual void Draw() {

	}

	virtual void Update(float time) {

	}

	virtual ~Object() {

	}
};