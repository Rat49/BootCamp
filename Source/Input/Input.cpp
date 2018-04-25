#include "Input.h"
#include <cassert>
#include <iostream>
#include <algorithm>

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot,
	SuperShoot
};

InputManager::InputManager()
{

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
	{ static_cast<int>(GameActions::SuperShoot), sf::Keyboard::LAlt }
	};


	for (auto actionIt = std::cbegin(customActions); actionIt != std::cend(customActions); ++actionIt)
	{
		auto it = std::find_if(
			buttonsState.begin(),
			buttonsState.end(),
			[actionIt](const localButtonsConfig & current) -> bool {
			return current.action == actionIt->first;
		});

		if (it != buttonsState.end())
		{
			it->alternatively = actionIt->second;
		}
		else
		{
			localButtonsConfig config = { actionIt->first, ButtonsState::Released, actionIt->second, sf::Keyboard::Unknown };
			buttonsState.insert(buttonsState.begin(), config);
		}
	}
}

InputManager::InputManager(const std::multimap<Action_t, ButtonKey_t>& buttonsKeyFromConfig)
{
	for (auto actionIt = std::cbegin(buttonsKeyFromConfig); actionIt != std::cend(buttonsKeyFromConfig); ++actionIt)
	{
		auto it = std::find_if(
			buttonsState.begin(),
			buttonsState.end(),
			[actionIt](const localButtonsConfig & current) -> bool {
			return current.action == actionIt->first;
		});

		if (it != buttonsState.end())
		{
			it->alternatively = actionIt->second;
		}
		else
		{
			localButtonsConfig config = { actionIt->first, ButtonsState::Released, actionIt->second, sf::Keyboard::Unknown };
			buttonsState.insert(buttonsState.begin(), config);
		}
	}
}

bool InputManager::GetState(const Action_t searchAction, ButtonsState & result) const 
{
	bool success = false;
	for (auto actionIt = std::cbegin(buttonsState); actionIt != std::cend(buttonsState); ++actionIt)
	{
		if (actionIt->action == searchAction) {
			result = actionIt->state;
			success = true;
		}
	}
	return success;
}

ButtonsState InputManager::ChangeStateWhenPressed(ButtonsState currentState) 
{
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return ButtonsState::Pressed;
	case ButtonsState::Pressed:
		return ButtonsState::Pressed;
	case ButtonsState::JustReleased:
		return ButtonsState::JustPressed;
	case ButtonsState::Released:
		return ButtonsState::JustPressed;
	default:
		return ButtonsState::Pressed;
	}
};

ButtonsState InputManager::ChangeStateWhenReleased(ButtonsState currentState) 
{
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return ButtonsState::JustReleased;
	case ButtonsState::Pressed:
		return ButtonsState::JustReleased;
	case ButtonsState::JustReleased:
		return ButtonsState::Released;
	case ButtonsState::Released:
		return ButtonsState::Released;
	default:
		return ButtonsState::Released;
	}
};

InputMode InputManager::GetMode() const
{
	return InputManager::_mode;
}

void InputManager::Update() 
{
	for (auto &action : buttonsState)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(action.primary)) ||
			sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(action.alternatively)))
		{
			action.state = ChangeStateWhenPressed(action.state);
			if (action.primary == sf::Keyboard::Tilde && action.state == ButtonsState::JustPressed)
			{
				ConsoleMode();
				_mode = (GetMode() == InputMode::Raw) ? InputMode::Normal : InputMode::Raw;
			}
		}
		else
		{
			action.state = ChangeStateWhenReleased(action.state);
		}
	}
}

void  InputManager::ConsoleMode() 
{
	for (auto &action : buttonsState)
	{
		if (action.primary != sf::Keyboard::Tilde)
		{
			action.state = (action.state == ButtonsState::Block) ? ButtonsState::Released : ButtonsState::Block;
		}
	}
}

void InputManager::HandleRawEvent(const sf::Event& event)
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	
	_keyEvent = event;
	
	DebugConsoleKeyEvent keyEvent(_keyEvent);
	dispatcher.Send(keyEvent, EventTypes::debugConsoleKeyEventID);
}