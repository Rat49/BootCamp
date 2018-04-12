#include "UI.h"



UI::UI(sf::VideoMode screen, const std::string &name) :
	_space(screen, name, sf::Style::Default)
	
{
	_oldSize = _space.getSize();
}

void UI::onResize()
{
	auto newSize = sf::Vector2f(_space.getSize().x, _space.getSize().y);
	for (auto it : _widgets)
	{
		it.second->SetScale(sf::Vector2f(newSize.x/_oldSize.x, newSize.y / _oldSize.y));
		it.second->Update();
	}
	//_space.setView(sf::View(_space.getDefaultView().getCenter(),newSize));
	Render();
	_oldSize = _space.getSize();
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
	if (x > 0 && x < 100 && y > 0 && y < 100)
	{
		_widgets[key]->SetPosition(_space.getSize().x/100*x, _space.getSize().y / 100 * y);
	}
	else
	{
		assert(false);//This is place for Log
	}
	
}

void UI::Add(Widget * wid, const std::string &key)
{
	wid->AddOwner(&_space);
	_widgets[key] = wid;
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
