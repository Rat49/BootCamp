#include <SFML/Graphics.hpp>
#include "Events.h"
#include "EventSystem.h"
#include "Input.h"

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot
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
	{ static_cast<int>(GameActions::Shoot), sf::Keyboard::Space }
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


int main()
{
	//ResourceManager *rm = new ResourceManager();

	sf::RenderWindow rw(sf::VideoMode::getDesktopMode(), "Asteroids");
	sf::Event sysEvent;
	while (rw.isOpen())
	{
		if (rw.pollEvent(sysEvent))
		{
			if (sysEvent.type == sysEvent.KeyPressed && sysEvent.key.code == sf::Keyboard::Escape)
			{
				rw.close();
			}
			if (sysEvent.type == sysEvent.Resized)
			{
				FirstEvent firstEvent;
				Dispatcher& dispatcher = Dispatcher::getInstance();
				dispatcher.Send(firstEvent, firstEventID);
			}
		}

		//Input update
		std::multimap<int, ButtonKey_t> actions = init();
		ButtonsState previousStateMoveUp = ButtonsState::Released;
		ButtonsState stateMoveUp;

		if (actions.empty())
		{
			std::cout << "Failed: Actions from Config is empty!" << std::endl;
			return 1;
		}
		InputManager input(actions);
		input.Update();

		if (input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && previousStateMoveUp != stateMoveUp)
		{
			std::cout << "MoveUp state - " << GetNameForState(stateMoveUp) << std::endl;
			previousStateMoveUp = stateMoveUp;
		}
		//Audio update
		//Logic update
		//...

		rw.clear();
		//Rendering update
		rw.display();
	}

	return 0;
}