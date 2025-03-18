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
    Cloud cloud[4] = { 0,1,2,3 };
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
            for (int i = 0; i < 4; i++)
            {
                cloud[i].setOffset();
                cloud[i].move();
                cloud[i].outOfBounds();
                window.draw(cloud[i].getAnimation().getSprite());
            }
            
            
            window.draw(player.getAnimation().getSprite());
            
            window.display();
            window.clear();
        }
    }
}