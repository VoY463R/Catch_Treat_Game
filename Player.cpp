#include "Player.h"

Player::Player(float x, float y)
{
	corgi_tex.loadFromFile("corgi.png");
	player.setTexture(corgi_tex);
	player.setOrigin(getBounds().width / 2, getBounds().height / 2);
	player.setScale(sf::Vector2f(0.1f, 0.1f));
	player.setPosition(sf::Vector2f(x, y));
	player_speed = 3.0f;
}


sf::FloatRect Player::getBounds() const
{
	return player.getGlobalBounds();
}

void Player::update()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && 
		player.getPosition().x > 0 + player.getGlobalBounds().width / 2) { // Moving player to the left
		player.move(sf::Vector2f(-player_speed, 0.f));
		player.setScale(sf::Vector2f(-0.1f, 0.1f));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&			  
		player.getPosition().x < 800 - player.getGlobalBounds().width / 2) { // Moving player to the right
		player.move(sf::Vector2f(player_speed, 0.f));
		player.setScale(sf::Vector2f(0.1f, 0.1f));
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
}
