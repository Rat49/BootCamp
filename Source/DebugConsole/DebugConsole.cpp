#include "DebugConsole.h"

DebugConsole::DebugConsole(sf::RenderWindow& window)
{
	_consoleRectangle = sf::RectangleShape(sf::Vector2f(window.getSize().x, ((window.getSize().y) / 3)));
	_consoleRectangle.setFillColor(sf::Color::Black);

	_consoleFont.loadFromFile("clacon.ttf");
	
	_windowWidth = window.getSize().x;
	_characterSize = (((window.getSize().y) / 3) / 10);

	_inputText = sf::Text("]", _consoleFont, _characterSize);
	_inputText.setPosition(1, (_consoleRectangle.getSize().y - _characterSize) - 5);

	_outputText = sf::Text("", _consoleFont, _characterSize);
}

int DebugConsole::_currentFirstHistoryLine = 0;

//struct RawInputEvent
//{
//	uint32_t _keycode;
//};

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
			//RawInputEvent e;
			//e._keycode = event.text.unicode;
			
			if (!(_inputText.getGlobalBounds().width > (_windowWidth - _characterSize)))
			{
				_inputString += event.text.unicode;
				_inputText.setString("] " + _inputString);

			}
		/*
			std::cout << "StringSize: " << _inputString.getSize() << std::endl;
			std::cout << "getGlobalBounds width: " << _inputText.getGlobalBounds().width << std::endl;
			std::cout << "getGlobalBounds height: " << _inputText.getGlobalBounds().height << std::endl;*/
		}

		if (event.text.unicode == 8)
		{
			_inputString.clear();
			_inputText.setString("] " + _inputString);
		}

		if (event.text.unicode == 13)
		{
			_outputText.setString("User: " + _inputString);
			_outputLines.insert(_outputLines.begin(), _outputText);

			_inputString.clear();
			_inputText.setString("] " + _inputString);

		}
		
	}

}

//if (tilda)
//{
//	active = !active;
//}

void DebugConsole::Draw(sf::RenderWindow& window)
{
	/*if (!active)
		return;*/
	
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