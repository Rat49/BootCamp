#include "Space.h"
#include "ParticleSpace.h"

Space::Space(sf::Rect<int> &borders)
	:_borders(borders)
{
	_nElements = (borders.width / 50) * (borders.height / 50);
	//_nElements = 10;
	for (int currentElement = 0; currentElement < _nElements; ++currentElement)
	{
		ParticleSpace* particle = new ParticleSpace(borders);
		_elements.push_back(particle);
	}
}

std::vector<ParticleSpace*> Space::GetElements()
{
	return _elements;
}

Space::~Space()
{

}