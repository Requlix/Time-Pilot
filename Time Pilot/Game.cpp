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
    std::vector<Grunt> grunts;
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

            //Grunts
            for (int i = 0; i < grunts.size(); i++)
            {
                grunts[i].move();
                /*
                if (grunts[i].collision(player))
                    std::cout << "COLLISION" << std::endl;
                */

                grunts[i].outOfBounds();
                window.draw(grunts[i].getAnimation().getSprite());
            }

            if (player.tick >= 450 && grunts.size() < 8 && player.tick % 45 == 0)
            {
                sf::Vector2f tempVec(448,512);
                tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360) * (3.14 / 180.0));
                tempVec.y += -448 * sin(((int)(player.rotation + 360) % 360) * (3.14 / 180.0));
                Grunt tempGrunt(1918, tempVec);
                grunts.push_back(tempGrunt);
            }
            
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
                    i--;
                }
                else
                {
                    for (int z = 0; z < grunts.size(); z++)
                    {
                        if (grunts[z].collision(bullets[i]))
                        {
                            bullets.erase(bullets.begin() + i);
                            i--;
                        }
                    }
                }
            }
            
            //draws
            window.draw(player.getAnimation().getSprite());
            
            window.display();
            window.clear();
        }
    }
}