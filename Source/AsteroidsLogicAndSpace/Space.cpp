#include "Space.h"

Space::Space(sf::Rect<int> &borders)
	:_borders(borders)
{
	_nElements = borders.width / 2 * borders.height * 2;
	for (int currentElement = 0; currentElement < _nElements; ++currentElement)
	{
		SpaceParticle* particle = new SpaceParticle();
		_elements.push_back(particle);
	}
}

std::vector<SpaceParticle*> Space::GetElements()
{
	return _elements;
}

void Space::Update(float time)
{
	for (auto &particle : _elements)
	{
		particle.Update(time);
	}
}

Space::~Space()
{

}