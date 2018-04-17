#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
class Object :
	public PoolElement
{
public:
	virtual void Draw(sf::RenderWindow *window) {

	}

	virtual void Update(float time) {

	}
	virtual ~Object() {

	}
};