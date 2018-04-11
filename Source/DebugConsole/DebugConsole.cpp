#include "DebugConsole.h"

DebugConsole::DebugConsole(sf::RenderWindow& window)
{
	_consoleRectangle = sf::RectangleShape(sf::Vector2f(window.getSize().x, ((window.getSize().y) / 3)));
	_consoleRectangle.setFillColor(sf::Color::Black);
	
	_consoleFont.loadFromFile("clacon.ttf");

	_characterSize = (((window.getSize().y) / 3) / 10);

	_inputText = sf::Text("]", _consoleFont, _characterSize);
	_inputText.setPosition(1, (_consoleRectangle.getSize().y - _characterSize) - 5);
	
	_outputText = sf::Text("", _consoleFont, _characterSize);
}

void DebugConsole::consoleInputOutput()
{
	int moveCounter = 1;
	for (auto& line : _outputLines)
	{
		line.setPosition(1, ((_consoleRectangle.getSize().y - _characterSize) - 5) - _characterSize*moveCounter);
		moveCounter++;
	}
}

void DebugConsole::Update(sf::Event& event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode > 31 && event.text.unicode < 127)
		{
			_inputString += event.text.unicode;
			_inputText.setString("] " + _inputString);
		}

		if (event.text.unicode == 8)
		{
			_inputString.clear();
			_inputText.setString("] " + _inputString);
		}

		if (event.text.unicode == 13)
		{
			_outputText.setString("User: " + _inputString);
			_outputLines.insert(_outputLines.begin(),_outputText);

			_inputString.clear();
			_inputText.setString("] " + _inputString);

			consoleInputOutput();
		}

	}

}

void DebugConsole::Draw(sf::RenderWindow& window)
{
	window.draw(_consoleRectangle);
	window.draw(_inputText);
	for (auto& line : _outputLines)
	{
		window.draw(line);
	}
}