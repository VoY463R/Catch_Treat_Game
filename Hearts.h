#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Game_Over.h"
class Hearts
{
public:
	Hearts();
	std::vector<sf::Sprite> hearts;
	sf::FloatRect getBounds();
	void draw(sf::RenderWindow& window);
	void removing_heart(sf::RenderWindow& window);
	void closing_window(sf::RenderWindow& window);
private:
	sf::Texture heart_tex;
	sf::Sprite heart;
	sf::Vector2f heart_position = sf::Vector2f(600.f, 10.f);
	int hp = 3;
};

