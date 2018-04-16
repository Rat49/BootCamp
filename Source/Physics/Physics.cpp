#include "Physics.h"
#include "EventSystem.h"

RigidBody::RigidBody() {

}

RigidBody::RigidBody(sf::Vector2f c, sf::Vector2f s, float r) {
	_coords = c;
	_speed = s;
	_radius = r;
}



void RigidBody::Update(float t) {
	_coords.x += _speed.x * t;
	_coords.y += _speed.y * t;

	if (_coords.x > W) {
		_coords.x = 0;
	}
	if (_coords.x < 0) {
		_coords.x = W;
	}
	if (_coords.y > H) {
		_coords.y = 0;
	}
	if (_coords.y < 0) {
		_coords.y = H;
	}
}

void RigidBody::SetRadius(float r) {
	_radius = r;
}

void RigidBody::SetCoordinates(sf::Vector2f c) {
	_coords = c;
}

void RigidBody::SetX(float arg) {
	_coords.x = arg;
}

void RigidBody::SetY(float arg) {
	_coords.y = arg;
}

void RigidBody::SetSpeed(sf::Vector2f s) {
	_speed = s;
}

float RigidBody::GetRadius() {
	return _radius;
}

float RigidBody::GetX() {
	return _coords.x;
}

float RigidBody::GetY() {
	return _coords.y;
}

void ResolveCollision(RigidBody &go1, RigidBody &go2) {
	float x1 = go1.GetX();
	float x2 = go2.GetX();
	float y1 = go1.GetY();
	float y2 = go2.GetY();

	float dist =  sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

	float overlap = 0.5 * (dist - go1.GetRadius() - go2.GetRadius());

	go1.SetX(x1 - (overlap * (x1 - x2) / dist));
	go1.SetY(y1 - (overlap * (y1 - y2) / dist));

	go2.SetX(x2 + (overlap * (x1 - x2) / dist));
	go2.SetY(y2 + (overlap * (y1 - y2) / dist));
}

bool Collided(RigidBody go1, RigidBody go2) {
	float dx = (go1.GetX() + go1.GetRadius() - go2.GetX() - go2.GetRadius());
	float dy = (go1.GetY() + go1.GetRadius() - go2.GetY() - go2.GetRadius());
	float distance = dx * dx + dy * dy;
	return (distance <= (go1.GetRadius() + go2.GetRadius()) * (go1.GetRadius() + go2.GetRadius()));
}

void RandomFill(RigidBody *RigidBodysFunc, int length) {
	std::srand(std::time(nullptr));

	for (int i = 0; i < length; ++i) {
		RigidBodysFunc[i].SetRadius(10 + std::rand() / ((RAND_MAX + 1u) / 30));
		RigidBodysFunc[i].SetCoordinates({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / W)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / H)) });
		RigidBodysFunc[i].SetSpeed({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)) });
	}
}