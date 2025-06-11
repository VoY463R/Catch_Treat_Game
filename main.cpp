#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include "Player.h"
#include "Background.h"
#include "Text.h"
#include "Hearts.h"
#include "Boost.h"
#include "Treat.h"
#include "Game_Over.h"

int main()
{
    //Creating a window variable responsible for drawing objects in the created window.
    sf::RenderWindow window(sf::VideoMode(800, 600), "CORGI TREATS");

    //Setting Frame Rate to 60 FPS.
    window.setFramerateLimit(60);

    //Creating points counter variable.
    int points = 0;

    //Creating Text type variable operating a points deduction system.
    Text points_text;

    //Background variable drawing the background.
    Background background;

    //Variable player handling movement.
    Player player(window.getSize().x/2, 460.f);

    //The treat variable is responsible for generating items for the player to collect, checking whether the player has touched the treat, and whether the treat has fallen to the ground.
    Treat treat;

    //The boost variable is responsible for generating items for the player to collect, checking whether the player has touched the boost and increasing player speed.
    Boost boost;

    //A variable that displays and calculates the number of lives remaining for the player.
    Hearts heart;

    //Game Over variable responsible for displaying the end screen
    Game_Over gameOverScreen;

    while (window.isOpen())
    {   
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed && gameOverScreen.is_game_over == true) {
                    window.close();

                }
             
            }
            window.clear();

            //Drawing all stuff onto the screen
            background.draw(window); 
            player.draw(window);
            points_text.draw(window);
            heart.draw(window);
            boost.draw(window);
            treat.draw(window);

            if (!gameOverScreen.is_game_over) {

                player.update();
                points_text.update(points);

                // Moving treats from top to bottom
                treat.treat_moving(heart, window);

                boost.boost_moving();

                // Random spawn of treat
                treat.treat_spawn(window);

                boost.boost_dropping(window);

                treat.treat_collect(player, points);

                boost.boost_collected(player);

                treat.treat_speed_check();

            }

            //If the player reach game over, draw game over background
            else {
                gameOverScreen.draw(window);
                background.background_music.setVolume(20);
            }

            window.display();

    }
    return 0;
}
