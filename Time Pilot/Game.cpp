#include "Game.h"
#include <iostream>
Game::Game()
{
	window.create(sf::VideoMode(winSizeX, winSizeY),
		"Time Pilot");
}

Game::~Game()
{
}

void Game::run()
{
    window.setFramerateLimit(60);
    Player player;
    Cloud cloud;
    while (window.isOpen())
    {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            player.move();
            cloud.setOffset();
            cloud.move();
            cloud.outOfBounds();
            window.draw(player.getAnimation().getSprite());
            window.draw(cloud.getAnimation().getSprite());
            window.display();
            window.clear();
        }
    }
}