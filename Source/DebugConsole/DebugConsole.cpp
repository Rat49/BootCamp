#include "DebugConsole.h"

DebugConsole::DebugConsole(sf::RenderWindow& window)
{
	this->_consoleRectangle = sf::RectangleShape(sf::Vector2f(window.getSize().x, ((window.getSize().y) / 3)));
	_consoleRectangle.setFillColor(sf::Color::Black);
	this->_consoleFont.loadFromFile("clacon.ttf");
	this->_inputText = sf::Text("]", _consoleFont, 16);
	_inputText.setPosition(1, (_consoleRectangle.getSize().y - 20));
	this->_outputText = sf::Text("", _consoleFont, 16);
	_outputText.setPosition(1, (_consoleRectangle.getSize().y - 40));
}

void DebugConsole::Update(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{

		if (event.text.unicode > 31 && event.text.unicode < 127)
		{

			std::cout << "ASCII character typed: " << event.text.unicode << std::endl;

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
			_outputStrings.push_back(_inputString);

			_inputString.clear();

			_inputText.setString("] " + _inputString);

			_outputText.setString("User: " + _outputStrings[0]);
		}

	}

}

void DebugConsole::Draw(sf::RenderWindow& window)
{
	window.draw(this->_consoleRectangle);
	window.draw(this->_inputText);
	window.draw(this->_outputText);
}