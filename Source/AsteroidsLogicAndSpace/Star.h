#pragma once
#include "Object.h"

class Star : public Object
{
public:
	Star();
	void Init(sf::RenderWindow & window);
	void Update(sf::Time time) override;
	void Draw(sf::RenderWindow &window) override;
	void Reset() override;
private:
	sf::CircleShape _star;
	int _alfaColor;
	float _radius;
	sf::Vector2f GetRandomPosition();
	void DefaultInit();
	void RandomInit();
};
