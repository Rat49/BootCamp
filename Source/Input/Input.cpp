#include "Input.h"
#include <cassert>
#include <iostream>
#include <algorithm>

InputManager::InputManager(const std::multimap<Action_t, ButtonKey_t>& buttonsKeyFromConfig)
{
	for (auto actionIt = std::cbegin(buttonsKeyFromConfig); actionIt != std::cend(buttonsKeyFromConfig); ++actionIt)
	{
		std::vector<localButtonsConfig>::iterator it = std::find_if(
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

bool InputManager::GetState(const Action_t searchAction, ButtonsState & result) const {
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

ButtonsState InputManager::ChangeStateWhenPressed(ButtonsState currentState) {
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

ButtonsState InputManager::ChangeStateWhenReleased(ButtonsState currentState) {
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

void InputManager::Update() {
	for (auto &action : buttonsState)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(action.primary)) ||
			sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(action.alternatively)))
		{
			action.state = ChangeStateWhenPressed(action.state);
		}
		else
		{
			action.state = ChangeStateWhenReleased(action.state);
		}
	}

}