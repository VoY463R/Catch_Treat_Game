#pragma once
#include <SFML/Graphics.hpp>
class Game_Over
{
public:
	Game_Over();
	static bool is_game_over;
	void draw(sf::RenderWindow& window);
	sf::Text create_text(int size,std::string text_string, float x, float y) const;
private:
	sf::RectangleShape overlay;
	sf::Font open_sans;
	sf::Text game_over_text;
	sf::Text press_key_text;

};

