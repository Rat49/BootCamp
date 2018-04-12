#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

class DebugConsole final
{
public:
	sf::RectangleShape _consoleRectangle;
	sf::Font _consoleFont;
	sf::String _inputString;
	sf::Text _inputText;
	sf::Text _outputText;
	std::vector<sf::Text> _outputLines;
	int _windowWidth;
	int _windowHeight;
	int _characterSize;
	static int _currentFirstHistoryLine;
	
	DebugConsole(sf::RenderWindow& window);
	void Update(sf::Event& event);
	void Draw(sf::RenderWindow& window);
	void logMessageOutput(const std::string&);
};