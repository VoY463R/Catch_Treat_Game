#include "Game_Over.h"

Game_Over::Game_Over() {
	overlay.setSize(sf::Vector2f(800.f, 600.f));
	overlay.setFillColor(sf::Color(0,0, 0, 130));
	open_sans.loadFromFile("OpenSans-Bold.ttf");
	game_over_text = create_text(50, "Game Over", 400.f, 200.f);
	press_key_text = create_text(20, "Press Key to Close the Game", 400.f, 300.f);

}

void Game_Over::draw(sf::RenderWindow& window) {
	window.draw(overlay);
	window.draw(game_over_text);
	window.draw(press_key_text);
}

sf::Text Game_Over::create_text(int size, std::string text_string, float x, float y) const
{
	sf::Text text;
	text.setFont(open_sans);
	text.setString(text_string);
	text.setCharacterSize(size);
	sf::FloatRect bounds_text = text.getLocalBounds();
	text.setOrigin(bounds_text.left + bounds_text.width / 2.f, bounds_text.top + bounds_text.height / 2.f);
	text.setPosition(x, y);

	return text;
}

bool Game_Over::is_game_over = false;