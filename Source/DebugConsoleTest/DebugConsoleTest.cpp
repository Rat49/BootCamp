#include "DebugConsole.h"
#include "EventSystem.h"
#include "Input.h"
#include "SFML\Graphics.hpp"

//=================INPUT TEST PART==================
enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot,
	Console
};

std::multimap<int, ButtonKey_t> init() {

	std::multimap<int, ButtonKey_t> customActions = {
		{ static_cast<int>(GameActions::MoveUp), sf::Keyboard::Up },
	{ static_cast<int>(GameActions::MoveUp), sf::Keyboard::W },
	{ static_cast<int>(GameActions::MoveDown), sf::Keyboard::Down },
	{ static_cast<int>(GameActions::MoveDown), sf::Keyboard::S },
	{ static_cast<int>(GameActions::MoveLeft), sf::Keyboard::Left },
	{ static_cast<int>(GameActions::MoveLeft), sf::Keyboard::A },
	{ static_cast<int>(GameActions::MoveRight), sf::Keyboard::Right },
	{ static_cast<int>(GameActions::MoveRight), sf::Keyboard::D },
	{ static_cast<int>(GameActions::Exit), sf::Keyboard::Escape },
	{ static_cast<int>(GameActions::Choose), sf::Keyboard::Return },
	{ static_cast<int>(GameActions::Shoot), sf::Keyboard::Space },
	{ static_cast<int>(GameActions::Console), sf::Keyboard::Tilde }
	};

	return customActions;
}

std::string GetNameForState(ButtonsState bState) {

	switch (bState)
	{
	case ButtonsState::JustPressed:
		return "JustPressed";
	case ButtonsState::Pressed:
		return "Pressed";
	case ButtonsState::JustReleased:
		return "JustReleased";
	case ButtonsState::Released:
		return "Released";
	default:
		return "Undefined";
		break;
	}
}
//==============================================

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), "DebugSystem");

	//=================INPUT TEST PART==================
	std::multimap<int, ButtonKey_t> actions = init();
	if (actions.empty())
	{
		std::cout << "Failed: Actions from Config is empty!" << std::endl;
		return 1;
	}
	ButtonsState previousStateMoveUp = ButtonsState::Released;
	ButtonsState previousStateMoveDown = ButtonsState::Released;
	ButtonsState previousStateMoveLeft = ButtonsState::Released;
	ButtonsState previousStateMoveRight = ButtonsState::Released;
	ButtonsState previousStateExit = ButtonsState::Released;
	ButtonsState previousStateChoose = ButtonsState::Released;
	ButtonsState previousStateShoot = ButtonsState::Released;

	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateExit;
	ButtonsState stateChoose;
	ButtonsState stateShoot;
	InputManager input(actions);
	//==============================================

	//Create DebugConsole
	DebugConsole debugConsole(window);

	std::cout << "Hello!\nTilda: ON/OFF console\nPageUp/PageDown: Scrolling\nEnter: Enter text\nTab: Test Log Message Output" << std::endl;
	std::cout << std::endl;
	std::cout << "Window Width: " << debugConsole._windowWidth << std::endl;
	std::cout << "Console Height: " << debugConsole._consoleHeight << std::endl;
	std::cout << "Character Size: " << debugConsole._characterSize << std::endl;
	std::cout << std::endl;

	sf::Event event;
	while (window.isOpen())
	{
		window.clear(sf::Color::Blue);

		while (window.pollEvent(event))
		{
			if (input.GetMode() == InputMode::Raw)
			{
				std::cout << "Input Text Global Bounds: " << debugConsole._inputText.getGlobalBounds().width << std::endl;
				std::cout << "Input String Size: " << debugConsole._inputString.getSize() << std::endl;
				std::cout << "Current First History Line: " << debugConsole._currentFirstHistoryLine << std::endl;
				input.HandleRawEvent(event);
				debugConsole._activeConsole = true;
			}
			else
			{
				debugConsole._activeConsole = false;
			}
			input.Update();

			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Tab)
			{
				debugConsole.logMessageOutput("A Hello, World! program is a computer program that outputs or displays Hello, World! to a user. Being a very simple program in most programming languages, it is often used to illustrate the basic syntax of a programming language for a working program.[1]");
			}

		}

		if (debugConsole._activeConsole)
		{
			debugConsole.Draw(window);
		}
		
		window.display();
	}
	return 0;
}