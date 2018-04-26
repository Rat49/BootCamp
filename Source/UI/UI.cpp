#include "UI.h"
#include "SfmlButton.h"
#include "Label.h"
#include "ScrollBar.h"
#include "AchievementShower.h"
#include <cassert>


UI::UI(sf::RenderWindow & window) : _window(window)	
{
}

UI::~UI()
{
	for (auto it : _widgets)
	{
		delete it.second;
	}
	_widgets.clear();
}

void UI::OnResize()
{
	auto newSize = sf::Vector2i(_window.getSize().x, _window.getSize().y);
	auto oldSize = _window.getView().getSize();
	for (auto it : _widgets)
	{
		it.second->SetScale(sf::Vector2f(newSize.x / oldSize.x, newSize.y / oldSize.y));
		it.second->Resize();
	}
	_window.setView(sf::View(sf::FloatRect(sf::Vector2f(), static_cast<sf::Vector2f>(newSize))));
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

void UI::OnAchive(const std::string& text, sf::Image* picture)
{
	Get<AchievementShower>("achivementShower")->ImplementAchivement(text, picture, 100);
}

void UI::SetPostion(const std::string& key, const PercentXY relCoord)
{	
	_widgets[key]->SetPosition(RelativeCordToAbs(relCoord));
}

const sf::Vector2f UI::RelativeCordToAbs(const PercentXY relCoord) const 
{
	return sf::Vector2f(_window.getSize().x / 100 * relCoord._x, _window.getSize().y / 100 * relCoord._y);
}

sf::Vector2f UI::GetPosition(const std::string& key)
{
	return _widgets[key]->GetPosition();
}

Widget* UI::CreateButton(const sf::Vector2f size, const PercentXY relPos, const std::string& name)
{	
	Widget* w = new SfmlButton(size, RelativeCordToAbs(relPos), name, _window);
	_widgets[name] = w;
	return w;
}

Widget* UI::CreateLabel(const std::string& content, const sf::Font& font, const PercentXY relPos, const std::string& name)
{
	Widget* w = new Label(content, font, RelativeCordToAbs(relPos), name, _window);
	_widgets[name] = w;
	return w;
}

Widget* UI::CreateScrollBar(const float length, const PercentXY relPos, const std::string& name)
{
	Widget* w = new ScrollBar(length, RelativeCordToAbs(relPos), name, _window);
	_widgets[name] = w;
	return w;
}

Widget* UI::CreateAchivementShower(const sf::Font& font, const PercentXY relPos)
{
	Widget* w = new AchievementShower(font, RelativeCordToAbs(relPos), "achivementShower", _window);
	_widgets["achivementShower"] = w;
	return w;
}

void UI::RemoveWidget(const std::string& key)
{
	delete _widgets[key];
	_widgets.erase(key);
}

Widget* UI::GetWidget(const std::string&key)
{
	auto iter = _widgets.find(key);

	assert(iter != _widgets.end() && "Widget not found");

	return iter->second;
}
