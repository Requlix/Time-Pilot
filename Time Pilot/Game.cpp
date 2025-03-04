#include "Game.h"

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
    Enemy enemy;
    sf::Vector2f playmove;
    
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
            enemy.move(window);
            player.move(window);
            playmove.x = player.speed * cos(player.rotation);
            playmove.y = player.speed * sin(player.rotation);
            enemy.setVelocity(playmove.x, playmove.y);
            enemy.Object::move();
            window.display();
            window.clear();
        }
    }
}