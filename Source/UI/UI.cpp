#include "UI.h"

UI::UI(sf::RenderWindow & window) :
	_window(window)	
{

}

void UI::OnResize()
{
	
	auto newSize = sf::Vector2f(_window.getSize().x, _window.getSize().y);
	auto oldSize = _window.getView().getSize();
	for (auto it : _widgets)
	{
		it.second->SetScale(sf::Vector2f(newSize.x / oldSize.x, newSize.y / oldSize.y));
		it.second->Resize();
	}
	_window.setView(sf::View(sf::FloatRect(0, 0, newSize.x, newSize.y)));
	Render();
}

void UI::Render()
{
	for (auto it : _widgets)
	{
		it.second->Draw();
	}
	_window.display();
}

void UI::SetPostion(const std::string & key, float x, float y)
{
	if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
	{
		_widgets[key]->SetPosition(_window.getSize().x/100*x, _window.getSize().y / 100 * y);
	}
	else
	{
		assert(false);//This is place for Log
	}
	
}

sf::Vector2f UI::GetPosition(const std::string & key)
{
	return _widgets[key]->GetPosition();
}

void UI::Add(Widget * wid, const std::string &key)
{
	_widgets[key] = wid;
}

Widget * UI::CreateButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name) const
{
	Widget * w = new SfmlButton(size, pos, name, _window);
	return w;
}

Widget * UI::CreateLabel(const std::string & content, const sf::Font & font, const sf::Vector2f position, const std::string & name) const
{
	Widget * w = new Label(content, font, position, name, _window);
	return w;
}

Widget * UI::CreateScrollBar(const float length, const sf::Vector2f pos, const std::string & name) const
{
	Widget * w = new ScrollBar(length, pos, name, _window);
	return w;
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
