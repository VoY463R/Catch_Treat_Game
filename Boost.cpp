#include "Boost.h"

Boost::Boost()
{
	boost_tex.loadFromFile("lightning.png");
	boost.setTexture(boost_tex);
	boost.setScale(0.05f, 0.05f);
	power_up_buf.loadFromFile("power_up_sound.wav");
	power_up_sound.setBuffer(power_up_buf);
	std::srand(std::time(nullptr));
}

void Boost::boost_dropping(sf::RenderWindow& window) {
	spawn_boost_timer++;
	if (spawn_boost_timer == how_often_spawn_boost) {
		boost.setPosition(std::rand() % static_cast<int>((window.getSize().x - boost.getGlobalBounds().width)), 0.f - boost.getGlobalBounds().height);
		boosts.push_back(sf::Sprite(boost));
		spawn_boost_timer = 0;
	}
}

void Boost::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < boosts.size(); i++)
	{
		window.draw(boosts[i]);
	}
}

void Boost::boost_collected(Player &player) {
	for (size_t i = 0; i < boosts.size(); i++)
	{
		if (player.getBounds().intersects(boosts[i].getGlobalBounds())) {
			boosts.erase(boosts.begin() + i);
			if (player.player_speed < 10.f)
				player.player_speed += 0.5f;
			power_up_sound.play();
		}
	}
}

void Boost::boost_moving() {
	for (size_t i = 0; i < boosts.size(); i++)
	{
		boosts[i].move(0.f, 2.f);
		if ((boosts[i].getPosition().y + boosts[i].getGlobalBounds().height) >= 500) { // If treat touch ground, remove from vector
			boosts.erase(boosts.begin() + i);
		}

	}
}