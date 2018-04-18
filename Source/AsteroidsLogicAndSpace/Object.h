#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
class Object :
	public PoolElement
{
public:

	sf::RenderWindow *_window = nullptr;

	virtual void Draw() {

	}

	virtual void Update(float time) {

	}

	virtual void Reset() {

	}

	virtual ~Object() {

	}
};