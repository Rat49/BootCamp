#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class DebugConsole final
{
public:
	sf::RectangleShape _consoleRectangle;
	sf::Font _consoleFont;
	sf::String _inputString;
	sf::Text _inputText;
	sf::Text _outputText;
	std::vector<sf::Text> _outputLines;
	int _characterSize;

	DebugConsole(sf::RenderWindow& window);
	void consoleInputOutput();
	void Update(sf::Event& event);
	void Draw(sf::RenderWindow& window);
};