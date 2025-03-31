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
    window.setFramerateLimit(90);
    Player player;
    bool shoot = true;
    std::vector<Bullet> bullets;
    Grunt grunt(1918, sf::Vector2f(400, 300));
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

            //moves
            player.move();
            grunt.move();
            
            //clouds yay
            for (int i = 0; i < 4; i++)
            {
                cloud[i].setOffset();
                cloud[i].move();
                cloud[i].outOfBounds();
                window.draw(cloud[i].getAnimation().getSprite());
            }
            
            //shoots bullets
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if (shoot)
                {
                    Bullet tempBullet(sf::Vector2f(448, 512), Player::rotation, "p");
                    bullets.push_back(tempBullet);
                    
                }
                shoot = false;

            }
            else
                shoot = true;
            
            //checks bullets collision and inbounds
            for (int i = 0; i < bullets.size(); i++)
            {
                bullets[i].move();
                window.draw(bullets[i].getAnimation().getSprite());
                if (!bullets[i].inBounds())
                {
                    bullets.erase(bullets.begin() + i);
                }
                else if (grunt.collision(bullets[i]))
                {
                    bullets.erase(bullets.begin() + i);
                    i--;
                }
                    
            }
            
            //heck grunts collision with player
            if (grunt.collision(player))
                std::cout << "COLLISION" << std::endl;
            grunt.outOfBounds();
            
            //draws
            window.draw(player.getAnimation().getSprite());
            window.draw(grunt.getAnimation().getSprite());
            
            window.display();
            window.clear();
        }
    }
}