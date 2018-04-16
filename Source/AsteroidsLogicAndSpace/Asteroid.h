#pragma once
#include "SFML\Graphics.hpp"

class Asteroid
{
	bool active = true;
public:
	Asteroid(sf::Sprite &sprite, sf::Rect<int> &borders, int id);

	sf::Sprite GetSprite();
	void Update(float time);

	~Asteroid();
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
