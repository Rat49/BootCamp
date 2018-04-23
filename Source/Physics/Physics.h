#pragma once

#include "Event.h"
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>

const int W = 1200;
const int H = 800;

class RigidBody {
public:

	sf::Vector2f _coords;
	sf::Vector2f _speed;
	float _radius;
	float _mass;
	RigidBody();
	RigidBody(sf::Vector2f, sf::Vector2f, float, float);
	void Update(float);
};

void RandomFill(RigidBody*, int);
bool Collided(RigidBody, RigidBody);
void ResolveCollision(const Event& event);

