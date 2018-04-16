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

void UI::SetPostion(const std::string & key, sf::Vector2f relCoord)
{	
	_widgets[key]->SetPosition(RelativeCordToAbs(relCoord));	
}


sf::Vector2f UI::RelativeCordToAbs(sf::Vector2f relCoord)
{
	auto x = relCoord.x;
	auto y = relCoord.y;
	sf::Vector2f result(0, 0);
	if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
	{
		result = sf::Vector2f(_window.getSize().x / 100 * x, _window.getSize().y / 100 * y);
	}
	else
	{		
		assert(false);//Not Percent
	}
	return result;
}


sf::Vector2f UI::GetPosition(const std::string & key)
{
	return _widgets[key]->GetPosition();
}

Widget * UI::CreateButton(const sf::Vector2f size, const sf::Vector2f relPos, const std::string & name) 
{	

	return _widgets[name] = new SfmlButton(size, RelativeCordToAbs(relPos), name, _window);
}

Widget * UI::CreateLabel(const std::string & content, const sf::Font & font, const sf::Vector2f relPos, const std::string & name)
{
	return _widgets[name] = new Label(content, font, RelativeCordToAbs(relPos), name, _window);
}

Widget * UI::CreateScrollBar(const float length, const sf::Vector2f relPos, const std::string & name) 
{
	return _widgets[name] = new ScrollBar(length, RelativeCordToAbs(relPos), name, _window);
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