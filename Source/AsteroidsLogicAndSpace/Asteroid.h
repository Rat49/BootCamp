#pragma once
#include "Object.h"

class Asteroid : public Object
{
public:
	Asteroid(sf::Sprite &sprite, sf::Rect<int> &borders, int id);

	void Update(float time) override;
	void Draw(sf::RenderWindow *window) override;

private:
	sf::Sprite _sprite;
	sf::Vector2f _velocity;
	sf::Rect<int> _borders;
	int _radius;
	float _rotation;
	float _rotationSpeed;
	sf::Vector2f _scale;
	float _speed;

};
