#include "Input.h"
#include <cassert>
#include <iostream>

InputManager::InputManager(const std::map<Action_t, State_t>& buttonsKeyFromConfig)
{
	for (auto actionIt = std::cbegin(buttonsKeyFromConfig); actionIt != std::cend(buttonsKeyFromConfig); ++actionIt)
	{
		buttonsState[actionIt->first] = static_cast<State_t>(ButtonsState::Released);
	}
	buttonsKey.insert(std::cbegin(buttonsKeyFromConfig), std::cend(buttonsKeyFromConfig));
}

bool InputManager::GetState(const Action_t searchAction, ButtonsState & result) const {
	bool success = false;
	for (auto actionIt = std::cbegin(buttonsState); actionIt != std::cend(buttonsState); ++actionIt)
	{
		if (actionIt->first == searchAction) {
			result = static_cast<ButtonsState>(actionIt->second);
		success = true;
		}
	}
	return success;
}

State_t InputManager::ChangeStateWhenPressed(State_t currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<State_t>(ButtonsState::Pressed);
	case ButtonsState::Pressed:
		return static_cast<State_t>(ButtonsState::Pressed);
	case ButtonsState::JustReleased:
		return static_cast<State_t>(ButtonsState::JustPressed);
	case ButtonsState::Released:
		return static_cast<State_t>(ButtonsState::JustPressed);
	default:
		return static_cast<State_t>(ButtonsState::Pressed);
	}
	
};

State_t InputManager::ChangeStateWhenRelease(State_t currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<State_t>(ButtonsState::JustReleased);
	case ButtonsState::Pressed:
		return static_cast<State_t>(ButtonsState::JustReleased);
	case ButtonsState::JustReleased:
		return static_cast<State_t>(ButtonsState::Released);
	case ButtonsState::Released:
		return static_cast<State_t>(ButtonsState::Released);
	default:
		return static_cast<State_t>(ButtonsState::Released);
	}

};

void InputManager::Update() {
	for (auto &key : buttonsKey) 
	{
		std::map<Action_t, State_t>::iterator buttonState = buttonsState.find(key.first);

		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key.second))) {
			assert(buttonState != std::cend(buttonsState));
			buttonState->second = ChangeStateWhenPressed(buttonState->second);
		}
		else {
			assert(buttonState != std::cend(buttonsState));
			buttonState->second = ChangeStateWhenRelease(buttonState->second);
		}
	}

}
