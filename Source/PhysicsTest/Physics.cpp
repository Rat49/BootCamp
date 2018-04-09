#include "stdafx.h"
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>

float DEGTORAD = 0.017453f;

const int W = 1200;
const int H = 800;

class GameObject {
private:
	std::vector<float> coords;
	std::vector<float> speed;
	float radius;
	float angle;

public:
	GameObject() {

	}

	GameObject(std::vector<float> c, std::vector<float> s, float r, float a) {
		coords = c;
		speed = s;
		radius = r;
	}

	void update(float t) {
		coords.at(0) += speed.at(0) * t;
		coords.at(1) += speed.at(1) * t;

		if (coords.at(0) > W) {
			coords.at(0) = 0;
		}
		if (coords.at(0) < 0) {
			coords.at(0) = W;
		}
		if (coords.at(1) > H) {
			coords.at(1) = 0;
		}
		if (coords.at(1) < 0) {
			coords.at(1) = H;
		}
	}

	void print() {
		std::cout << "Coords:";
		for (std::vector<float>::iterator it = coords.begin(); it != coords.end(); ++it) {
			std::cout << ' ' << *it;
		}
		std::cout << std::endl;

		std::cout << "Speed:";
		for (std::vector<float>::iterator it = speed.begin(); it != speed.end(); ++it) {
			std::cout << ' ' << *it;
		}
		std::cout << std::endl;

		std::cout << "Radius: " << radius << std::endl;
	}

	void reset() {

	}

	void setRadius(float r) {
		radius = r;
	}

	void setCoords(std::vector<float> c) {
		coords = c;
	}

	void setSpeed(std::vector<float> s) {
		speed = s;
	}

	float getRadius() {
		return radius;
	}

	float getX() {
		return coords.at(0);
	}

	float getY() {
		return coords.at(1);
	}
};

void draw(GameObject);
void draw(GameObject*, int);
void randomFill(GameObject*, int);
bool isCollide(GameObject, GameObject);
void resolveCollision(GameObject, GameObject);
void test(int);

int main()
{
	test(2);

	getchar();
    return 0;
}

void draw(GameObject gameObjectFunc) {
	sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");
	sf::CircleShape circle;
	sf::Clock clock;
	sf::Time deltaTime;

	circle.setRadius(gameObjectFunc.getRadius());
	circle.setPosition(gameObjectFunc.getX(), gameObjectFunc.getY());

	while (app.isOpen()) {
		deltaTime = clock.restart();
		float deltaSeconds = deltaTime.asSeconds();

		sf::Event event;

		while (app.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				app.close();
			}
		}

		gameObjectFunc.update(deltaSeconds);
		circle.setPosition(gameObjectFunc.getX(), gameObjectFunc.getY());

		app.clear();
		app.draw(circle);
		app.display();
	}
}

void draw(GameObject *gameObjectsFunc, int length) {
	sf::Clock clock;
	sf::Time deltaTime;

	sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");

	sf::CircleShape* circles = new sf::CircleShape[length];

	for (int i = 0; i < length; ++i) {
		circles[i].setRadius(gameObjectsFunc[i].getRadius());
		circles[i].setPosition(gameObjectsFunc[i].getX(), gameObjectsFunc[i].getY());
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
					if (isCollide(gameObjectsFunc[i], gameObjectsFunc[j])) {
						std::cout << "Collision!" << std::endl;
					}
				}
			}
		}

		for (int i = 0; i < length; ++i) {
			gameObjectsFunc[i].update(deltaSeconds);
			circles[i].setPosition(gameObjectsFunc[i].getX(), gameObjectsFunc[i].getY());
		}

		app.clear();
		for (int i = 0; i < length; ++i) {
			app.draw(circles[i]);
		}
		app.display();
	}

	delete[] circles;
}

void randomFill(GameObject *gameObjectsFunc, int length) {
	std::srand(std::time(nullptr));

	for (int i = 0; i < length; ++i) {
		gameObjectsFunc[i].setRadius(10 + std::rand() / ((RAND_MAX + 1u) / 30));
		gameObjectsFunc[i].setCoords({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / W)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / H)) });
		gameObjectsFunc[i].setSpeed({ static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)), static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)) });
		gameObjectsFunc[i].print();
	}
}

bool isCollide(GameObject go1, GameObject go2) {
	float distance = sqrt((go1.getX() - go2.getX())*(go1.getX() - go2.getX()) + (go1.getY() - go2.getY())*(go1.getY() - go2.getY()));

	if (distance < go1.getRadius() + go2.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

void resolveCollision(GameObject go1, GameObject go2) {
	float dist = sqrt((go1.getX() - go2.getX())*(go1.getX() - go2.getX()) + (go1.getY() - go2.getY())*(go1.getY() - go2.getY()));
	float overlap = 0.5 * (dist - go1.getRadius() - go2.getRadius());

	go1.setCoords({ go1.getX() -  (overlap * (go1.getX() - go2.getX()) / dist), go1.getY() - (overlap * (go1.getY() - go2.getY()) / dist)});
	go2.setCoords({ go1.getX() + (overlap * (go1.getX() - go2.getX()) / dist), go1.getY() + (overlap * (go1.getY() - go2.getY()) / dist) });
}

void test(int numOfObjects) {
	GameObject* gameObjects = new GameObject[numOfObjects];
	//randomFill(gameObjects, numOfObjects);
	gameObjects[0].setRadius(25);
	gameObjects[0].setCoords({500, 500});
	gameObjects[0].setSpeed({1, 0});

	gameObjects[1].setRadius(25);
	gameObjects[1].setCoords({ 551, 500 });
	gameObjects[1].setSpeed({ -1, 0 });
	draw(gameObjects, numOfObjects);
	delete[] gameObjects;
}