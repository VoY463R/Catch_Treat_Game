#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Hearts.h"
#include "Player.h"

class Treat
{
public:
	Treat();
	void treat_moving(Hearts &heart, sf::RenderWindow &window);
	void treat_spawn(sf::RenderWindow &window);
	void treat_collect(Player player, int &points);
	void treat_speed_check();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture treat_tex;
	sf::Sprite treat;
	std::vector<sf::Sprite> treats;
	float treats_speed;
	sf::SoundBuffer collect_buf;
	sf::Sound collect_sound;
	sf::SoundBuffer fail_buf;
	sf::Sound fail_sound;
	int spawn_treat_timer = 0;
	int how_often_spawn_treat = 120;
	int toSpeedUp = 0;
};

