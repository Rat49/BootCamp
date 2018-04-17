#pragma once
#include "SFML/Graphics.hpp"

class Object
{
public:
	virtual void Draw(sf::RenderWindow *window) {

	}

	virtual void Update(float time) {

	}
	virtual ~Object() {

	}
};