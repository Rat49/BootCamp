#include "DebugConsole.h"

int DebugConsole::_currentFirstHistoryLine = 0;

DebugConsole::DebugConsole(sf::RenderWindow& window)
{
	_windowWidth = window.getSize().x;
	_windowHeight = ((window.getSize().y) / 3);
	_characterSize = _windowHeight / 10;

	_consoleRectangle = sf::RectangleShape(sf::Vector2f(_windowWidth, _windowHeight));
	_consoleRectangle.setFillColor(sf::Color::Black);

	_consoleFont.loadFromFile("DroidSansMono.ttf");
	
	_inputText = sf::Text("]", _consoleFont, _characterSize);
	_inputText.setPosition(1, (_consoleRectangle.getSize().y - _characterSize) - 5);

	_outputText = sf::Text("", _consoleFont, _characterSize);
}

void DebugConsole::Update(sf::Event& event)
{
	if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::PageDown)
	{
		if (_currentFirstHistoryLine > 0)
		{
			--_currentFirstHistoryLine;
		}
	}

	if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::PageUp)
	{
		++_currentFirstHistoryLine;
	}
	
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode > 31 && event.text.unicode < 127)
		{
			if (!(_inputText.getGlobalBounds().width > (_windowWidth - _characterSize)))
			{
				_inputString += event.text.unicode;
				_inputText.setString("] " + _inputString);

			}
		}

		if (event.text.unicode == 8)
		{
			_inputString.clear();
			_inputText.setString("] " + _inputString);
		}

		if (event.text.unicode == 13)
		{
			_outputText.setString("> " + _inputString);
			_outputLines.insert(_outputLines.begin(), _outputText);

			_inputString.clear();
			_inputText.setString("] " + _inputString);

		}
		
	}

}

void DebugConsole::Draw(sf::RenderWindow& window)
{
	window.draw(_consoleRectangle);
	window.draw(_inputText);
	
	std::size_t start = _currentFirstHistoryLine;
	std::size_t end = _currentFirstHistoryLine + 9;
	std::vector<sf::Text>::iterator firstLine = _outputLines.begin();
	std::vector<sf::Text>::iterator lastLine = _outputLines.begin();
	std::advance(firstLine, std::min(start, _outputLines.size()));
	std::advance(lastLine, std::min(end, _outputLines.size()));

	int positionStep = 1;
	for (; firstLine != lastLine; ++firstLine)
	{
		firstLine->setPosition(1, ((_consoleRectangle.getSize().y - _characterSize) - 5) - _characterSize * positionStep);
		++positionStep;

		window.draw(*firstLine);
	}
	
}

void DebugConsole::logMessageOutput(const std::string& logMessage)
{
	std::string oneLineLogMessage;

	if (logMessage.empty())
	{
		return;
	}

	for (int character = 0; character < logMessage.size(); ++character)
	{
		oneLineLogMessage.push_back(logMessage.at(character));
		_outputText.setString("> " + oneLineLogMessage);

		if (_outputText.getGlobalBounds().width > (_windowWidth-_characterSize))
		{
			_outputLines.insert(_outputLines.begin(), _outputText);
			oneLineLogMessage.clear();
			_outputText.setString("> " + oneLineLogMessage);
		}
		
	}
	_outputLines.insert(_outputLines.begin(), _outputText);
}
