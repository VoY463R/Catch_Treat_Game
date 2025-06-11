#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float x, float y);
	void update();
	void draw(sf::RenderWindow &window);
	sf::FloatRect getBounds() const;
	float player_speed;

private:
	sf::Texture corgi_tex;
	sf::Sprite player;

};

