#include "SfmlButton.h"
#include "Label.h"
#include "ScrollBar.h"
#include "Widget.h"
#include <SFML\Graphics.hpp>
#include <cassert>

struct cmpByString
{
	bool operator()(const std::string& a, const std::string& b) const
	{
		return a < b;
	}
};
class UI final
{
public:
	UI(sf::RenderWindow & window);
	template<typename T>
	T* Get(const std::string& key)
	{
		Widget* wid = GetWidget(key);
		T* specificWidget = dynamic_cast<T*>(wid);
		return specificWidget;
	}

	void OnResize();
	void Render();

	void SetPostion(const std::string& key, float x, float y);
	sf::Vector2f GetPosition(const std::string& key);

	
	void Add(Widget * wid, const std::string & key);
	Widget * CreateButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name) const;
	Widget * CreateLabel(const std::string & content, const sf::Font & font, const sf::Vector2f position, const std::string & name) const;
	Widget * CreateScrollBar(const float length, const sf::Vector2f pos, const std::string & name) const;

	~UI();
private:	
	sf::RenderWindow & _window;
	Widget* GetWidget(const std::string &key);
	std::map<std::string, Widget*, cmpByString> _widgets;
	
};


