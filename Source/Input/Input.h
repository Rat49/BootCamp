#pragma once
#include <map>
#include <SFML\Window.hpp>

using Action_t = int;
using ButtonKey_t = std::vector<int>;
using State_t = int;

enum class ButtonsState {
	JustPressed,
	Pressed,
	JustReleased,
	Released
};

class InputManager final
{
private:
	std::map<Action_t, State_t> _buttonsState;
public:
	bool GetState(const Action_t searchAction, ButtonsState & result) const;
	std::map<Action_t, ButtonKey_t> _buttonsKey;
	State_t ChangeStateWhenRelease(State_t);
	State_t ChangeStateWhenPressed(State_t);
	void Update();
	InputManager(const std::map<Action_t, ButtonKey_t>& arr);
};
