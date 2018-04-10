#pragma once
#include <map>
#include <SFML\Window.hpp>

using Action_t = int;
using ButtonKey_t = int;

enum class ButtonsState {
	JustPressed,
	Pressed,
	JustReleased,
	Released
};

class InputManager final
{
private:
	struct localButtonsConfig {
		Action_t action;
		ButtonsState state;
		ButtonKey_t primary;
		ButtonKey_t alternatively;
	};

	std::vector<localButtonsConfig> buttonsState;
	ButtonsState ChangeStateWhenReleased(ButtonsState);
	ButtonsState ChangeStateWhenPressed(ButtonsState);

public:
	bool GetState(const Action_t searchAction, ButtonsState & result) const;
	void Update();
	InputManager(const std::multimap<Action_t, ButtonKey_t>& arr);
};