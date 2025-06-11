#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Player.h"
class Boost
{
public:
	Boost();
	std::vector<sf::Sprite> boosts;
	void boost_dropping(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void boost_collected(Player& player);
	void boost_moving();

private:
	sf::Texture boost_tex;
	sf::Sprite boost;
	sf::SoundBuffer power_up_buf;
	sf::Sound power_up_sound;
	int spawn_boost_timer = 0;
	int how_often_spawn_boost = 700;

};

