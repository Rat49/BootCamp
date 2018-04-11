
#include "stdafx.h"
#include "Physics.h"

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

int main()
{

	Test(20);

	getchar();
	return 0;
}

void Draw(RigidBody *RigidBodysFunc, int length) {
	sf::Clock clock;
	sf::Time deltaTime;

	sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");

	sf::CircleShape* circles = new sf::CircleShape[length];

	for (int i = 0; i < length; ++i) {
		circles[i].setRadius(RigidBodysFunc[i].GetRadius());
		circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
	}

	while (app.isOpen()) {
		deltaTime = clock.restart();
		float deltaSeconds = deltaTime.asSeconds();

		sf::Event event;

		while (app.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				app.close();
			}
		}

		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (i != j) {
					if (Collided(RigidBodysFunc[i], RigidBodysFunc[j])) {
						ResolveCollision(RigidBodysFunc[i], RigidBodysFunc[j]);
						circles[i].setFillColor(sf::Color::Red);
						circles[j].setFillColor(sf::Color::Red);
					}
					else {
						circles[i].setFillColor(sf::Color::White);
						circles[j].setFillColor(sf::Color::White);
					}
				}
			}
		}

		for (int i = 0; i < length; ++i) {
			RigidBodysFunc[i].Update(deltaSeconds);
			circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
		}

		app.clear();
		for (int i = 0; i < length; ++i) {
			app.draw(circles[i]);
		}
		app.display();
	}

	delete[] circles;
}

void RandomFill(RigidBody *RigidBodysFunc, int length) {
	std::srand(std::time(nullptr));

	for (int i = 0; i < length; ++i) {
		RigidBodysFunc[i].SetRadius(10 + std::rand() / ((RAND_MAX + 1u) / 30));
		RigidBodysFunc[i].SetCoordinates({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / W)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / H)) });
		RigidBodysFunc[i].SetSpeed({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)) });
	}
}

bool Collided(RigidBody go1, RigidBody go2) {
	float distance = (go1.GetX() - go2.GetX())*(go1.GetX() - go2.GetX()) + (go1.GetY() - go2.GetY())*(go1.GetY() - go2.GetY());
	return (distance < (go1.GetRadius() + go2.GetRadius()) * (go1.GetRadius() + go2.GetRadius()));
}

void ResolveCollision(RigidBody &go1, RigidBody &go2) {
	float x1 = go1.GetX();
	float x2 = go2.GetX();

	float y1 = go1.GetY();
	float y2 = go2.GetY();

	float dist = sqrt((go1.GetX() - go2.GetX())*(go1.GetX() - go2.GetX()) + (go1.GetY() - go2.GetY())*(go1.GetY() - go2.GetY()));

	float overlap = 0.5 * (dist - go1.GetRadius() - go2.GetRadius());

	go1.SetX(x1 - (overlap * (x1 - x2) / dist));
	go1.SetY(y1 - (overlap * (y1 - y2) / dist));

	go2.SetX(x2 + (overlap * (x1 - x2) / dist));
	go2.SetY(y2 + (overlap * (y1 - y2) / dist));
}

void Test(int numOfObjects) {
	RigidBody* RigidBodys = new RigidBody[numOfObjects];
	RandomFill(RigidBodys, numOfObjects);

	/*
	RigidBodys[0].SetRadius(25);
	RigidBodys[0].SetCoordinates({ 500, 500 });
	RigidBodys[0].SetSpeed({ 10, 0 });

	RigidBodys[1].SetRadius(25);
	RigidBodys[1].SetCoordinates({ 751, 501 });
	RigidBodys[1].SetSpeed({ -10, 0 });
	*/

	Draw(RigidBodys, numOfObjects);
	delete[] RigidBodys;
}