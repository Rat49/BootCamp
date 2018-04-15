#include "DebugConsole.h"
#include "EventSystem.h"
#include "Input.h"
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
				debugConsole.logMessageOutput("Psychonauts is a platform game developed by Double Fine Productions. The game was initially published by Majesco Entertainment for Microsoft Windows, Xbox and PlayStation 2; Budcat Creations helped in the PlayStation 2 port. In 2011, Double Fine acquired the rights for the title, allowing the company to republish the title with updates for modern gaming systems and ports for OS X and Linux. Psychonauts follows the player - character Raz(voiced by Richard Horvitz), a young boy gifted with psychic abilities who runs away from the circus to try to sneak into a summer camp for those with similar powers to become a Psychonaut, a spy with psychic abilities.He finds that there is a sinister plot occurring at the camp that only he can stop.The game is centered on exploring the strange and imaginative minds of various characters that Raz enters as a Psychonaut - in - training / Psycadet to help them overcome their fears or memories of their past, so as to gain their help and progress in the game.Raz gains use of several psychic abilities during the game that are used for both attacking foes and solving puzzles.");
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