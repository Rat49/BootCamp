#pragma once

#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>

const int W = 800;
const int H = 800;

class RigidBody {
private:
	sf::Vector2f _coords;
	sf::Vector2f _speed;
	float _radius;
	float _mass;

public:

	RigidBody();
	RigidBody(sf::Vector2f, sf::Vector2f, float, float);
	void Update(float t, bool clampByPhysicSpace = true);
	void SetRadius(float);
	void SetCoordinates(sf::Vector2f);
	void SetX(float);
	void SetY(float);
	void SetSpeed(sf::Vector2f);
	float GetRadius() const;
	float GetX() const;
	float GetY() const;
	sf::Vector2f GetCoordinates() const;
	float GetMass() const;
	float GetSpeedX() const;
	float GetSpeedY() const;
	sf::Vector2f GetSpeed() const;
	void SetSpeedX(float);
	void SetSpeedY(float);
	void SetMass(float);
};

void RandomFill(RigidBody*, int);
bool Collided(RigidBody, RigidBody);
void ResolveCollision(RigidBody &, RigidBody &);

