#pragma once
#include "ParticleSpace.h"
#include "SFML\Graphics.hpp"

class Space
{
public:
	Space(sf::Rect<int> &borders);

	std::vector<ParticleSpace*> GetElements();

	~Space();
private:
	sf::Rect<int> _borders;
	std::vector<ParticleSpace*> _elements;
	int _nElements;
};
