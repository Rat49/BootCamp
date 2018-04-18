#pragma once
#include "EventSystem.h"
#include "Input.h"
#include "DebugCommandManagerEvent.h"
#include "LoggerMessageEvent.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

class DebugConsole final
{
private:
	sf::RectangleShape _consoleRectangle;
	sf::Font _consoleFont;
	sf::String _inputString;
	sf::Text _inputText;
	sf::Text _outputText;
	std::vector<sf::Text> _outputLines;
	int _windowWidth;
	int _consoleHeight;
	int _characterSize;
	int _currentFirstHistoryLine;
	bool _activeConsole;
	Token_t _tokenForDebugConsoleKeyEvent;
	Token_t _tokenForLoggerMessageEvent;
	std::map<EventID_t, Token_t> _tokens;
public:
	DebugConsole(sf::RenderWindow& window);
	~DebugConsole();
	void Update(const sf::Event& event);
	void Draw(sf::RenderWindow& window);
	void logMessageOutput(const std::string& string);
	bool getActiveConsoleStatus() const;
	void setActiveConsoleStatus(bool activeConsoleStatus);
};