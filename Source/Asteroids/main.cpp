#include <SFML/Graphics.hpp>

#include "ConfigManager.h"
#include "Events.h"
#include "EventSystem.h"
#include "Input.h"
#include "ResourceManager.h"

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot
};


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
	ConfigManager* cm1 = ConfigManager::Create("GameConfig.INI");
	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").getParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").getParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").getParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());
	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first, cm1->GetCategory("ImageSequenceResource." + i.first).getParams()));
	}
	ResourceManager *rm = new ResourceManager(resourceConfig);

	std::multimap<int, ButtonKey_t> actions;
	LogCategory category = cm1->GetCategory("Input");
	std::multimap<const std::string, const std::string> inputCategory = category.getParams();
	for (auto i : inputCategory)
	{
		int a = atoi(i.first.c_str());
		int b = atoi(i.second.c_str());
		actions.insert(std::pair<int, int>(a, b));
	}
	InputManager input(actions);

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