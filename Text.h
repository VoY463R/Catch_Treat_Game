#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
class Text
{
public:
	Text(float x = 10.f, float y = 10.f);
	void draw(sf::RenderWindow& window);
	void update(int& points);
	void setString(const std::string& str);
private:
	sf::Font open_sans;
	sf::Text points_text;
};

