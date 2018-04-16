#pragma once
#include "SpaceParticle.h"

class Space
{
public:
	Space(sf::Rect<int> &borders);


	std::vector<SpaceParticle*> GetElements();
	void Update(float time);

	~Space();
private:
	sf::Rect<int> _borders;
	std::vector<Space*> _elements;
	int _nElements;
};
