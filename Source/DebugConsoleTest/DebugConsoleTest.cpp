#include "DebugConsole.h"
#include "EventSystem.h"
#include "Input.h"
#include "Logger.h"
#include "SFML\Graphics.hpp"

//=================INPUT TEST PART==================
enum class GameActions 
{
	Console
};

std::multimap<int, ButtonKey_t> init() 
{
	std::multimap<int, ButtonKey_t> customActions = 
	{
		{ 
			static_cast<int>(GameActions::Console), sf::Keyboard::Tilde 
		}
	};

	return customActions;
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
	InputManager input(actions);
	//==============================================

	DebugConsole debugConsole(window);
	std::cout << "Hello!\nTilda: ON/OFF console\nPageUp/PageDown: Scrolling\nEnter: Enter text\nTab: Test Log Message Output" << std::endl;
	
	Logger& log = Logger::GetInstance();
	log.SetFrame(400);
	auto debug = log.AddDebugTarget();
	debug->IncludeChannel("All");
	debug->SetSeverity(LogLevel::Warning);

	sf::Event event;
	while (window.isOpen())
	{
		window.clear(sf::Color::Blue);

		while (window.pollEvent(event))
		{
			if (input.GetMode() == InputMode::Raw)
			{
				input.HandleRawEvent(event);
				debugConsole.setActiveConsoleStatus(true);
			}
			else
			{
				debugConsole.setActiveConsoleStatus(false);
			}
			input.Update();

			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Tab)
			{
				log("Audio").Debug("%s %s!", "Hello", "world");
				log("Audio").Warning("%s %s!", "Hello", "world");
			}

		}

		if (debugConsole.getActiveConsoleStatus())
		{
			debugConsole.Draw(window);
		}
		
		window.display();
	}
	return 0;
}