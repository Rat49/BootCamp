#include "Physics.h"
#include "EventSystem.h"

RigidBody::RigidBody() {

}

RigidBody::RigidBody(sf::Vector2f c, sf::Vector2f s, float r, float m) {
	_coords = c;
	_speed = s;
	_radius = r;
	_mass = m;
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

float RigidBody::GetMass()
{
	return _mass;
}
float RigidBody::GetSpeedX()
{
	return _speed.x;
}
float RigidBody::GetSpeedY()
{
	return _speed.y;
}

void RigidBody::SetSpeedX(float arg)
{
	_speed.x = arg;
}
void RigidBody::SetSpeedY(float arg)
{
	_speed.y = arg;
}
void RigidBody::SetMass(float arg)
{
	_mass = arg;
}


void ResolveCollision(RigidBody &go1, RigidBody &go2) {

	float dx = (go1.GetX() + go1.GetRadius() - go2.GetX() - go2.GetRadius());
	float dy = (go1.GetY() + go1.GetRadius() - go2.GetY() - go2.GetRadius());
	
	float d1x = go1.GetX() + go1.GetRadius();
	float d1y = go1.GetY() + go1.GetRadius();

	float d2x = go2.GetX() + go2.GetRadius();
	float d2y = go2.GetY() + go2.GetRadius();

	float dist = sqrt(dx * dx + dy * dy);

	float overlap = (dist - go1.GetRadius() - go2.GetRadius());

	go1.SetX(go1.GetX() - (overlap * (go1.GetX() - go2.GetX()) / dist));
	go1.SetY(go1.GetY() - (overlap * (go1.GetY() - go2.GetY()) / dist));

	go2.SetX(go2.GetX() + (overlap * (go1.GetX() - go2.GetX()) / dist));
	go2.SetY(go2.GetY() + (overlap * (go1.GetY() - go2.GetY()) / dist));

	//normal 
	float nx = (d1x - d2x) / dist;
	float ny = (d1y - d2y) / dist;
	//Tanget
	float tx = -ny;
	float ty = nx;
	float dpTan1 = go1.GetSpeedX() * tx + go1.GetSpeedY() * ty;
	float dpTan2 = go2.GetSpeedX() * tx + go2.GetSpeedX() * ty;
	
	float dpNorm1 = go1.GetSpeedX() * nx + go1.GetSpeedY() * ny;
	float dpNorm2 = go2.GetSpeedX() * nx + go2.GetSpeedX() * ny;

	float m1 = (dpNorm1 * (go1.GetMass() - go2.GetMass()) + 2.0f *go2.GetMass() * dpNorm2) / (go1.GetMass() + go2.GetMass());
	float m2 = (dpNorm2 * (go2.GetMass() - go1.GetMass()) + 2.0f * go1.GetMass() * dpNorm1) / (go1.GetMass() + go2.GetMass());

	// Update ball velocities
	go1.SetSpeedX (tx * dpTan1 + nx * m1);
	go1.SetSpeedY (ty * dpTan1 + ny * m1);
	go2.SetSpeedX (tx * dpTan2 + nx * m2);
	go2.SetSpeedY (ty * dpTan2 + ny * m2);
	/*go1.SetSpeedX(((go1.GetMass() - go2.GetMass()) * go1.GetSpeedX() + (2 * go2.GetMass() * go2.GetSpeedX())) / (go1.GetMass() + go2.GetMass()));
	
	go2.SetSpeedX(((go2.GetMass() - go1.GetMass()) * go2.GetSpeedX() + (2 * go1.GetMass() * go1.GetSpeedX())) / (go1.GetMass() + go2.GetMass()));
	
	go1.SetSpeedY(((go1.GetMass() - go2.GetMass()) * go1.GetSpeedY() + (2 * go2.GetMass() * go2.GetSpeedY())) / (go1.GetMass() + go2.GetMass()));
	
	go2.SetSpeedY(((go2.GetMass() - go1.GetMass()) * go2.GetSpeedY() + (2 * go1.GetMass() * go1.GetSpeedY())) / (go1.GetMass() + go2.GetMass()));*/

}

bool Collided(RigidBody go1, RigidBody go2) {
	float dx = (go1.GetX() + go1.GetRadius() - go2.GetX() - go2.GetRadius());
	float dy = (go1.GetY() + go1.GetRadius() - go2.GetY() - go2.GetRadius());
	float distance = dx * dx + dy * dy;
	return (distance < (go1.GetRadius() + go2.GetRadius()) * (go1.GetRadius() + go2.GetRadius()));
}

void RandomFill(RigidBody *RigidBodysFunc, int length) {
	std::srand(std::time(nullptr));

	for (int i = 0; i < length; ++i) {
		RigidBodysFunc[i].SetRadius(10 + std::rand() / ((RAND_MAX + 1u) / 100));
		RigidBodysFunc[i].SetCoordinates({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / W)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / H)) });
		RigidBodysFunc[i].SetSpeed({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 15)) });
		RigidBodysFunc[i].SetMass(10 + std::rand() / ((RAND_MAX + 1u) / 20));
	}
}