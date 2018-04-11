#include "UI.h"



UI::UI(sf::VideoMode screen,const std::string &name):
	_space(screen,name,sf::Style::Default)
{
}

void UI::Render()
{
	_space.clear(sf::Color::Black);
	for (auto it : _widgets)
	{
		it.second->Draw();
	}
	
	_space.display();
}

void UI::SetPostion(const std::string & key, float x, float y)
{
	_widgets[key]->SetPosition(_space.getSize().x/100*x, _space.getSize().y / 100 * y);
}

void UI::addButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string &name)
{
	_widgets[name] = new SfmlButton(size, pos, name, _space);
}

Widget* UI::GetWidget(const std::string &key)
{
	auto iter = _widgets.find(key);

	assert(iter != _widgets.end() && "Widget not found");

	Widget* wid = iter->second;

	return wid;
}


UI::~UI()
{
}
