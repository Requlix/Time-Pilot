#include "Game.h"
#include <iostream>
Game::Game()
{
	window.create(sf::VideoMode(winSizeX, winSizeY),
		"Time Pilot");
    srand(time(NULL));
}

Game::~Game()
{
}

void Game::run()
{
    window.setFramerateLimit(90);
    Player player;
    int shoot = 0;
    bool shootable = true;
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
                
                if (grunts[i].collision(player))
                {
                    grunts.erase(grunts.begin() + i);
                    i--;
                }
                if (grunts.size() > 0 && i>=0)
                {
                    grunts[i].outOfBounds();
                    window.draw(grunts[i].getAnimation().getSprite());
                }
            }

            if (player.tick >= 450 && grunts.size() < 7 && player.tick % 90 == 0&& rand() % 2 == 0)
            {
                int l = rand() % 60 - 30;
                sf::Vector2f tempVec(448,512);
                tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360+l) * (3.14 / 180.0));
                tempVec.y += -448 * sin(((int)(player.rotation + 360) % 360+l) * (3.14 / 180.0));
                Grunt tempGrunt(1918, tempVec);
                grunts.push_back(tempGrunt);
                std::cout << "GRUNT COUNT: " << grunts.size() << std::endl;
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
            if (shoot != 0&&player.tick%6==0)
            {
                Bullet tempBullet(sf::Vector2f(448, 512), Player::rotation, "p");
                bullets.push_back(tempBullet);
                shoot--;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if (shootable == true)
                    shoot = 3;
                shootable = false;
            }
            else
                shootable = true;
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
                for (int z = 0; z < grunts.size(); z++)
                    if(i>=0)
                        if (grunts[z].collision(bullets[i]))
                        {
                            bullets.erase(bullets.begin() + i);
                            i--;
                            grunts.erase(grunts.begin() + z);
                            z--;
                        }
            }
            
            //draws
            window.draw(player.getAnimation().getSprite());
            
            window.display();
            window.clear();
        }
    }
}