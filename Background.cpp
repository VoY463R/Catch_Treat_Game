#include "Background.h"

Background::Background()
{
	background_tex.loadFromFile("background.png");
	background.setTexture(background_tex);
	background_buf.loadFromFile("background_music.ogg");
	background_music.setBuffer(background_buf);
	background_music.setVolume(70);
	background_music.play();
}

void Background::draw(sf::RenderWindow& window) {
	window.draw(background);
}	