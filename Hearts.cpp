#include "Hearts.h"

Hearts::Hearts()
{
	heart_tex.loadFromFile("heart.png");
	heart.setTexture(heart_tex);
	heart.setScale(0.2f, 0.2f);
	for (size_t i = 0; i < 3; i++)
	{
		hearts.push_back(sf::Sprite(heart));
	}
	for (size_t i = 0; i < hearts.size(); i++)
	{
		hearts[i].setPosition(heart_position);
		heart_position.x += getBounds().width + 10.f;
	}
}

sf::FloatRect Hearts::getBounds()
{
	return heart.getGlobalBounds();
}

void Hearts::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < hearts.size(); i++)
	{
		window.draw(hearts[i]);
	}
}

void Hearts::removing_heart(sf::RenderWindow& window)
{
	hearts.erase(hearts.begin() + hp - hearts.size());
	hp--;
	if (hp == 0)
		Game_Over::is_game_over = true;
}

void Hearts::closing_window(sf::RenderWindow& window) {
	window.close();
}