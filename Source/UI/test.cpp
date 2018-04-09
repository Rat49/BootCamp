#include "UI.h"

int main()
{
	sf::RectangleShape rect;

	UI mui;
	myButton but(100,100,200,200,mui._space);
	mui._space.draw(but._body);
	mui._space.display();

	while (mui._space.isOpen())
	{
		but.isClicked();
	}

}