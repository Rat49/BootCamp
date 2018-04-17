#pragma once
#include "Object.h"

class ParticleSpace : public Object
{
public:
	ParticleSpace();
	void Init(sf::Rect<int> &borders);
	void Update(float time) override;
	void Draw(sf::RenderWindow *window) override;
	void Reset() override;
private:
	sf::Rect<int> _borders;
	sf::CircleShape _particle;
	float _depth;
	bool active = true;

	sf::Vector2f GetNormalizedVelocity(sf::Vector2f vector);
};
