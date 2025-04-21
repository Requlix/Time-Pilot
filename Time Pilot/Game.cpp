#include "Game.h"
#include <iostream>
Game::Game()
{
    window.create(sf::VideoMode(winSizeX, winSizeY),
        "Time Pilot");
    srand(time(NULL));
    txt1918.loadFromFile("background1918.png");
    
}

Game::~Game()
{
}

void Game::run()
{
    window.setFramerateLimit(60);
    int points = 1;
    Player player;
    Boss boss(1940, { -100,-100 });
    sf::Text text;
    sf::Font font;
    font.loadFromFile("konami.ttf");
    text.setFont(font);
    int shoot = 0;
    int lives =3;
    int gruntsKilled = 0;
    int threshhold = 10001;
    bool shootable = true;
    bool bossSpawned = false;
    std::vector<Bullet> bullets;
    std::vector<Bullet> ebullets;
    std::vector<Grunt> grunts;
    Cloud cloud[4] = { 0,1,2,3 };
    background.setTexture(txt1918);
    background.setPosition(0, 128);
    while (window.isOpen())
    {
        while (lives > 0)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            bool playerLiving = true;
            while (playerLiving)
            {
                //moves
                player.move();
                if (points % threshhold == 0)
                {
                    lives++;
                    threshhold +=50000;
                }
                text.setString("YOUR SCORE: " + std::to_string(points - 1) + "  YOUR LIVES " + std::to_string(lives));
                //boss
                if (gruntsKilled >= 2&&!bossSpawned)
                {
                    int l = rand() % 60 - 30;
                    sf::Vector2f tempVec(448, 512);
                    tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    tempVec.y += -448 * sin(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    boss.getAnimation().setPosition(tempVec);
                    bossSpawned = true;
                    std::cout << "boss spawned";
                }
                //Grunts
                for (int i = 0; i < grunts.size(); i++)
                {


                    if (grunts[i].collision(player))
                    {
                        grunts.erase(grunts.begin() + i);
                        i--;
                        lives--;
                        playerLiving = false;
                        shoot = 0;
                    }

                }

                if (player.tick >= 210 && grunts.size() < 7 && player.tick % 90 == 0 && rand() % 2 == 0)
                {
                    int l = rand() % 60 - 30;
                    sf::Vector2f tempVec(448, 512);
                    tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    tempVec.y += -448 * sin(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    Grunt tempGrunt(1940, tempVec);
                    grunts.push_back(tempGrunt);
                }


                //shoots bullets
                if (shoot != 0 && player.tick % 6 == 0)
                {
                    Bullet tempBullet(sf::Vector2f(448, 864/2+128), Player::rotation, "p");
                    bullets.push_back(tempBullet);
                    shoot--;

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    if (shootable == true)
                        shoot = 3;
                    shootable = false;
                }
                else if (shoot <= 1)
                    shootable = true;

                //draws
                draw(bullets, grunts, cloud, player, lives, playerLiving, points, ebullets, gruntsKilled,shoot);
                if (bossSpawned) {
                    boss.move();
                    window.draw(boss.getAnimation().getSprite());
                }
                window.draw(player.getAnimation().getSprite());
                window.draw(text);
                window.display();
                window.clear();

            }
            int pause = player.tick;
            while (player.tick - pause < 200)
            {
                int tempLives = lives;
                window.draw(text);
                draw(bullets, grunts, cloud, player, lives, playerLiving, points, ebullets, gruntsKilled,shoot);
                window.display();
                window.clear();
                player.tick += 1;
                lives = tempLives;
            }
            grunts.clear();
            player.rotation = 0;
            player.tick = 1;
        }
        window.clear();
        window.draw(player.getAnimation().getSprite()); 
        text.setString(" YOUR SCORE:" + std::to_string(points - 1) + "\n  You Lose!!!!");
        text.setCharacterSize(100);
        window.draw(text);
        window.display();
    }
}

void Game::draw(std::vector<Bullet>& bullets, std::vector<Grunt>& grunts, Cloud cloud[], Player& player, int& lives, bool& playerLiving, int& points, std::vector<Bullet>& ebullets, int& gruntsKilled, int& shoot)
{
    window.draw(background);
    //Grunts
    for (int i = 0; i < grunts.size(); i++)
    {
        if (grunts[i].move())
        {
            Bullet tempBullet(grunts[i].getPosition(), -grunts[i].getRotation(), "e");
            ebullets.push_back(tempBullet);
        }
        if (grunts.size() > 0 && i >= 0)
        {
            grunts[i].outOfBounds();
            window.draw(grunts[i].getAnimation().getSprite());
        }
    }
    //clouds yay
    for (int i = 0; i < 4; i++)
    {
        cloud[i].setOffset();
        cloud[i].move();
        cloud[i].outOfBounds();
        window.draw(cloud[i].getAnimation().getSprite());
    }

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
            if (i >= 0)
                if (grunts[z].collision(bullets[i]))
                {
                    bullets.erase(bullets.begin() + i);
                    i--;
                    grunts.erase(grunts.begin() + z);
                    z--;
                    points += 100;
                    gruntsKilled++;
                    std::cout << points-1 << std::endl;
                }
    }
    //Enemy projectiles
    for (int i = 0; i < ebullets.size(); i++)
    {
        ebullets[i].move();
        window.draw(ebullets[i].getAnimation().getSprite());
        if (!ebullets[i].inBounds())
        {
            ebullets.erase(ebullets.begin() + i);
            i--;
        }
        if (i >= 0)
        {
            if (ebullets[i].collision(player))
            {
                lives--;
                playerLiving = false;
                shoot = 0;
                ebullets.erase(ebullets.begin() + i);
                i--;
            }
        }
    }
}