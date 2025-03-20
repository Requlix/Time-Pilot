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
    window.setFramerateLimit(240);
    Player player;
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
            player.move();
            
            for (int i = 0; i < 4; i++)
            {
                cloud[i].setOffset();
                cloud[i].move();
                cloud[i].outOfBounds();
                window.draw(cloud[i].getAnimation().getSprite());
            }
            
            grunt.move();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Bullet tempBullet(sf::Vector2f(448, 512),Player::rotation, "e");
                bullets.push_back(tempBullet);
            }
            
            for (int i = 0; i < bullets.size(); i++)
            {
                bullets[i].move();
                window.draw(bullets[i].getAnimation().getSprite());
                if(!bullets[i].inBounds())
                   bullets.erase(bullets.begin()+i);

                if (grunt.collision(bullets[i]))
                    bullets.erase(bullets.begin() + i);
            }
            
            if (grunt.collision(player))
                std::cout << "COLLISION" << std::endl;
                
            
            
            
            window.draw(player.getAnimation().getSprite());
            window.draw(grunt.getAnimation().getSprite());
            
            window.display();
            window.clear();
        }
    }
}