#include "SfmlButton.h"

#include <SFML\Graphics.hpp>
#include <cassert>
#include <memory>

struct cmpByStringLength
{
	bool operator()(const std::string& a, const std::string& b) const
	{
		return a < b;
	}
};

class UI
{
public:
	UI(sf::VideoMode screen,const std::string & name);

	template<typename T>
	T* Get(const std::string& key)
	{
		Widget* wid = GetWidget(key);
		T* specificWidget = dynamic_cast<T*>(wid);
		return specificWidget;
	}

	void Render();

	sf::RenderWindow _space;
	void addButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string &name);
	
	~UI();
private:
	Widget* GetWidget(const std::string &key);
	std::map<std::string, Widget*, cmpByStringLength> _widgets;
	
};


