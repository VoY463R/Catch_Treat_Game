#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Background
{
public:
	Background();
	void draw(sf::RenderWindow& window);
	sf::Sound background_music;
private:
	sf::Texture background_tex;
	sf::Sprite background;
	sf::SoundBuffer background_buf;

};

