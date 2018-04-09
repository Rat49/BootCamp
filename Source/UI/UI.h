#include "myButton.h"

#include <SFML\Graphics.hpp>
class UI
{
public:
	UI();
	sf::RenderWindow _space;
	std::vector<myButton> _buttons;
	std::vector<std::string> _labels;
	~UI();
};

