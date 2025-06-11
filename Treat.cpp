#include "Treat.h"

Treat::Treat() {
	treat_tex.loadFromFile("dog_treat.png");
	treat.setTexture(treat_tex);
	treat.setScale(0.2f, 0.2f);
	treats_speed = 2.0f;
	collect_buf.loadFromFile("collect_sound.wav");
	collect_sound.setBuffer(collect_buf);
	fail_buf.loadFromFile("fail_sound.wav");
	fail_sound.setBuffer(fail_buf);
	std::srand(std::time(nullptr));
}

void Treat::treat_moving(Hearts &heart, sf::RenderWindow& window) {
	for (size_t i = 0; i < treats.size(); i++)
	{
		treats[i].move(0.f, treats_speed);
		if ((treats[i].getPosition().y + treats[i].getGlobalBounds().height) >= 500) { // If treat touch ground, remove from vector
			treats.erase(treats.begin() + i);
			heart.removing_heart(window);
			fail_sound.play();
		}

	}
}

void Treat::treat_spawn(sf::RenderWindow& window) {
	spawn_treat_timer++;
	if (spawn_treat_timer == how_often_spawn_treat) {
		treat.setPosition(std::rand() % static_cast<int>((window.getSize().x - treat.getGlobalBounds().width)), 0.f - treat.getGlobalBounds().height);
		treats.push_back(sf::Sprite(treat));
		spawn_treat_timer = 0;
	}
}

void Treat::treat_collect(Player player,int &points) {
	for (size_t i = 0; i < treats.size(); i++)
	{
		if (player.getBounds().intersects(treats[i].getGlobalBounds())) {
			treats.erase(treats.begin() + i);
			collect_sound.play();
			points++;
			toSpeedUp++;
		}
	}
}

void Treat::treat_speed_check()
{
	if (toSpeedUp % 5 == 0 && toSpeedUp > 0) {
		treats_speed += 0.2f;
		toSpeedUp = 0;
	}
}

void Treat::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < treats.size(); i++)
	{
		window.draw(treats[i]);
	}
}