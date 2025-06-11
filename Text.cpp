#include "Text.h"

Text::Text(float x, float y)
{
	open_sans.loadFromFile("OpenSans-Bold.ttf");
	points_text.setFont(open_sans);
	points_text.setPosition(x,y);
}

void Text::draw(sf::RenderWindow& window) {
	window.draw(points_text);
}

void Text::update(int& points) {
	std::stringstream points_counter;
	points_counter << "Points: " << points;
	return points_text.setString(points_counter.str());
}
void Text::setString(const std::string& str) {
	points_text.setString(str);
}
