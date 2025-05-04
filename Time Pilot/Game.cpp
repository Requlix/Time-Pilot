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
    sf::Texture livesText;
	livesText.loadFromFile("player8.png");
	sf::Sprite livesSprite;
	livesSprite.setTexture(livesText);

    sf::RectangleShape topBorder;
    topBorder.setSize({ 896,128 });
	topBorder.setFillColor(sf::Color::Black);

    sf::RectangleShape bottomBorder;
    bottomBorder.setSize({ 896,32 });
    bottomBorder.setFillColor(sf::Color::Black);
	bottomBorder.setPosition(0, 992);

    sf::RectangleShape killCover;
    killCover.setSize({ 448,32 });
    killCover.setFillColor(sf::Color::Black);
    killCover.setPosition(464, 992);

    sf::Texture killBoardTxt;
    killBoardTxt.loadFromFile(killBoardStr[level % 6]);
	sf::Sprite killBoard;
    killBoard.setTexture(killBoardTxt);
    
	
    window.setFramerateLimit(60);
    int points = 1;
    Player player;
    Boss boss(1940, { -100,-100 });
    sf::Text text;
    sf::Font font;
    font.loadFromFile("konami.ttf");
    text.setFont(font);

    sf::Text up1("1-UP", font, 50);
    up1.setPosition(80, -20);
	up1.setFillColor(sf::Color::Red);

    sf::Text score1;
	score1.setCharacterSize(50);
	score1.setFont(font);
	score1.setPosition(165, 10);

    sf::Text score2;
    score2.setCharacterSize(50);
    score2.setFont(font);
    score2.setPosition(400, 10);
    
    sf::Text highScore("HI-SCORE", font, 50);
    highScore.setPosition(336, -20);
    highScore.setFillColor(sf::Color::Red);

    int bossBullet = 0;
    int nextSpawn = 0;
    int shoot = 0;
    int lives = 2;
    int gruntsKilled = 0;
    int threshhold = 10001;
    bool shootable = true;
    bool bossSpawned = false;
    bool bossDead = false;
    std::vector<Bullet> bullets;
    std::vector<Bullet> ebullets;
    std::vector<Grunt> grunts;
    std::vector<Bomb> bombs;
	std::vector<Missile> missiles;
    std::vector<Airman> airmen;
    std::vector<Boss> tGrunts;
    Cloud cloud[8] = { 0,1,2,3 ,4,5,6,7};
    Bomb temp({ 100,100 });
    bombs.push_back(temp);

    bool airmanSpawn = true;

    sf::Text player1;
	player1.setFont(font);
	player1.setString("PLAYER 1");
	player1.setCharacterSize(50);
    player1.setPosition(320, 448);

    sf::Text date;
    date.setFont(font);
    date.setCharacterSize(50);
    date.setPosition(320, 586);

    sf::Text stage;
    stage.setFont(font);
    stage.setCharacterSize(50);
    stage.setPosition(320, 724);

    txt1918.loadFromFile("background" + std::to_string(levels[level % 6]) + ".png");
    background.setTexture(txt1918);
    background.setPosition(0, 128);

    int colors = 0;
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
                score1.setString(std::to_string(points-1));
                score2.setString(std::to_string(points-1));
                //moves
                player.move();
                if (points % threshhold == 0)
                {
                    lives++;
                    threshhold +=50000;
                }

                if (gruntsKilled == 27 && airmen.size() == 0 && airmanSpawn && levels[level%6]!=2000)
                {
                    Airman tempMan;
                    airmen.push_back(tempMan);
                    airmanSpawn = false;
                }
                    

                if (gruntsKilled > nextSpawn && gruntsKilled < 54 && levels[level % 6] == 1940 && gruntsKilled % 7 == 0)
                {
                    //std::cout<<"spawn tgrunt"
                    sf::Vector2f tempVec(448, 512);
                    tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360) * (3.14 / 180.0));
                    tempVec.y += -432 * sin(((int)(player.rotation + 360) % 360) * (3.14 / 180.0));
                    Boss tempDude(1941, tempVec);
                    tGrunts.push_back(tempDude);
                    //std::cout << "HEY I SHOULD BE SPAWNING NOW" << std::endl;
                }

                if (gruntsKilled > 0 && gruntsKilled % 7 == 0)
                    nextSpawn = gruntsKilled;


                //text.setString("YOUR SCORE: " + std::to_string(points - 1) + "  YOUR LIVES " + std::to_string(lives));
                
                //boss
                if (gruntsKilled >= 54 &&!bossSpawned)
                {
                    boss.setYear(levels[level % 6]);
                    bossSpawned = true;
                    boss.outOfBounds();
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

                //boss collision
                for(int i = 0 ; i < bullets.size(); i++)
                    if (bullets[i].collision(boss))
                    {
                        bullets.erase(bullets.begin() + i);
                        i--;
                        if (boss.hit())
                        {
                            bossDead = true;
                        }
                    }
                
                if(boss.collision(player))
				{
					boss.getAnimation().setPosition({ -100, -100 });
                    bossDead = true;
					lives--;
                    playerLiving = false;
					shoot = 0;
				}
                
                if (player.tick >= 180 && grunts.size() < 1 && player.tick % 60 == 0 && rand() % 2 == 0)
                {
                    int l = rand() % 60 - 30;
                    sf::Vector2f tempVec(448, 512);
                    tempVec.x += 448 * cos(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    tempVec.y += -432 * sin(((int)(player.rotation + 360) % 360 + l) * (3.14 / 180.0));
                    Grunt tempGrunt(levels[level%6], tempVec);
                    grunts.push_back(tempGrunt);
                }

                if (grunts.size() > 0 && missiles.size() < 2 && player.tick % 300 == 0 && levels[level % 6] >= 1970)
                {
                    int ranGrunt = rand() % grunts.size();
                    int tempLevel;
                    if (levels[level] < 2000)
                        tempLevel = 1970;
                    else
						tempLevel = 2000;
                    Missile tempMissile(tempLevel, grunts[ranGrunt].getPosition());
                    missiles.push_back(tempMissile);
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
                

				killCover.setPosition(464-4*gruntsKilled, 992);
                //draws
                draw(bullets, grunts, cloud, player, lives, playerLiving, points, ebullets, gruntsKilled,shoot,bombs, missiles);
                if (airmen.size() > 0)
                {
                    airmen[0].move();
                    window.draw(airmen[0].getAnimation().getSprite());
                    if (!airmen[0].inBounds())
                        airmen.erase(airmen.begin());
                    else if (airmen[0].collision(player))
                    {
                        airmen.erase(airmen.begin());
                        points += 1000 * (rand() % 2 + 1);
                    }
                }
                for (int i = 0; i < tGrunts.size(); i++)
                {
                    tGrunts[i].move();
                    window.draw(tGrunts[i].getAnimation().getSprite());
                    if (!tGrunts[i].inBounds())
                    {
                        tGrunts.erase(tGrunts.begin() + i);
                        i--;
                    }
                    else if (tGrunts[i].collision(player))
                    {
                        tGrunts.erase(tGrunts.begin() + i);
                        i--;
                        playerLiving = false;
                        lives--;
                    }
                    else
                    {
                        for(int z = 0; z < bullets.size() && tGrunts.size() > 0; z++)
                            if (tGrunts[i].collision(bullets[z]))
                            {
                                bullets.erase(bullets.begin() + z);
                                z--;
                                if(tGrunts[i].hit())
                                {
                                    tGrunts.erase(tGrunts.begin() + i);
                                    i--;
                                }
                                
                                points += 100;
                                gruntsKilled++;
                            }
                    }

                    if (tGrunts.size() > 0)
                    {
                        if (player.tick % 45 == 0)
                        {
                            sf::Vector2f posVec = tGrunts[i].getPosition();
                            double velvetCake = 45;
                            if (tGrunts[i].getPosition().x > 446)
                                posVec.x -= 42;
                            else
                                posVec.x += 42;

                            if (tGrunts[i].getPosition().y > 560)
                                posVec.y -= 10;
                            else
                                posVec.y += 10;

                            if (tGrunts[i].getPosition().x >= 446 && tGrunts[i].getPosition().y >= 560)
                                velvetCake = 135;
                            else if (tGrunts[i].getPosition().x <= 446 && tGrunts[i].getPosition().y >= 560)
                                velvetCake = 45;
                            else if (tGrunts[i].getPosition().x >= 446 && tGrunts[i].getPosition().y <= 560)
                                velvetCake = 225;
                            if (tGrunts[i].getPosition().x <= 446 && tGrunts[i].getPosition().y <= 560)
                                velvetCake = 315;

                            
                            Bullet daBullet(posVec, velvetCake, "e");
                            ebullets.push_back(daBullet);
                        }
                    }
                }
				window.draw(topBorder);
				window.draw(bottomBorder);
                window.draw(up1);
                window.draw(highScore);
				window.draw(score1);
				window.draw(score2);
                for (int i = 0; i < 7; i++)
                {
                    killBoard.setPosition(16 + 64 * i, 980);
                    window.draw(killBoard);
                }
				window.draw(killCover);
                for(int i = 0; i < lives; i++)
                {
                    livesSprite.setPosition(i * 64 + 16, 64);
                    window.draw(livesSprite);
                }
                if (bossSpawned && !bossDead) {
                    boss.move();
                    boss.outOfBounds();
                    if (player.tick < 180)
                        boss.getAnimation().setPosition({ -100,-100 });

                    window.draw(boss.getAnimation().getSprite());
                }

                if (player.tick % 45 == 0 && bossSpawned)
                {
                    sf::Vector2f posVec = boss.getPosition();
                    double velvetCake = 45;
                    if (boss.getPosition().x > 446)
                        posVec.x -= 42;
                    else
                        posVec.x += 42;

                    if (boss.getPosition().y > 560)
                        posVec.y -= 10;
                    else
                        posVec.y += 10;

                    if (boss.getPosition().x >= 446 && boss.getPosition().y >= 446)
                        velvetCake = 135;
                    else if (boss.getPosition().x <= 446 && boss.getPosition().y >= 446)
                        velvetCake = 45;
                    else if (boss.getPosition().x >= 446 && boss.getPosition().y <= 446)
                        velvetCake = 225;
                    if (boss.getPosition().x <= 446 && boss.getPosition().y <= 446)
                        velvetCake = 315;

                    sf::String temp = "e";
                    if (levels[level % 6] == 2000)
                        temp = "s";
                    Bullet daBullet(posVec, velvetCake, temp);
                    ebullets.push_back(daBullet);
                }
                
                window.draw(player.getAnimation().getSprite());
                //window.draw(text);

                if (player.tick == 2)
                {
                    date.setString("A.D. " + std::to_string(levels[level % 6]));
                    stage.setString("STAGE " + std::to_string(level + 1));

                    for (int i = 0; i < 8; i++)
						cloud[i].setYear(levels[level % 6]);
                }
                if (player.tick <= 180)
                {
					if (player.tick % 20 == 0)
						colors++;
                    if(colors % 3 == 0)
                        date.setFillColor(sf::Color::Blue);
					else if (colors % 3 == 1)
                        date.setFillColor(sf::Color::White);
                    else
                        date.setFillColor(sf::Color::Red);
                    window.draw(date);
                    window.draw(stage);
                    window.draw(player1);
                }
                window.display();
                window.clear();

                if (bossDead)
                {
					level++;
                    bossDead = false;
					playerLiving = false;
                    boss.getAnimation().setPosition({ -100, -100 });
					bossSpawned = false;
                    gruntsKilled = 0;
					boss.setSpeed(0);
                    grunts.clear();
                    missiles.clear();
                    airmanSpawn = true;
                    nextSpawn = 0;
                    killBoardTxt.loadFromFile(killBoardStr[level % 6]);
                    killBoard.setTexture(killBoardTxt);
                }

            }

            for (int i = 0; i < lives; i++)
            {
                livesSprite.setPosition(i * 64 + 16, 64);
                window.draw(livesSprite);
            }
            window.draw(up1);
            window.draw(highScore);
            window.draw(score1);
            window.draw(score2);
            for (int i = 0; i < 7; i++)
            {
                killBoard.setPosition(16 + 64 * i, 980);
                window.draw(killBoard);
            }
            window.draw(killCover);

            int pause = player.tick;
            std::cout << level << std::endl;
            while (player.tick - pause < 200)
            {
                int tempLives = lives;
                window.draw(text);
                draw(bullets, grunts, cloud, player, lives, playerLiving, points, ebullets, gruntsKilled,shoot,bombs,missiles);
                for(int i = 0; i < lives; i++)
				{
					livesSprite.setPosition(i * 64 + 16, 64);
					window.draw(livesSprite);
				}
                window.display();
                window.clear();
                player.tick += 1;
                lives = tempLives;
                txt1918.loadFromFile("background"+ std::to_string(levels[level%6]) + ".png");
				background.setTexture(txt1918);

                for (int i = 0; i < lives; i++)
                {
                    livesSprite.setPosition(i * 64 + 16, 64);
                    window.draw(livesSprite);
                }
                window.draw(up1);
                window.draw(highScore);
                window.draw(score1);
                window.draw(score2);
                for (int i = 0; i < 7; i++)
                {
                    killBoard.setPosition(16 + 64 * i, 980);
                    window.draw(killBoard);
                }
                window.draw(killCover);
                
            }
            boss.getAnimation().setPosition({ -100, -100 });
            grunts.clear();
            player.rotation = 0;
            player.tick = 1;
        }
        window.clear();
		window.draw(background);
        window.draw(text);
        window.draw(player1);
        for (int i = 0; i < lives; i++)
        {
            livesSprite.setPosition(i * 64 + 16, 64);
            window.draw(livesSprite);
        }
        window.draw(up1);
        window.draw(highScore);
        window.draw(score1);
        window.draw(score2);
        for (int i = 0; i < 7; i++)
        {
            killBoard.setPosition(16 + 64 * i, 980);
            window.draw(killBoard);
        }
        window.draw(killCover);
		date.setString("GAME OVER");
        date.setFillColor(sf::Color::Red);
		window.draw(date);
        //window.draw(text);
        window.display();
    }
}

void Game::draw(std::vector<Bullet>& bullets, std::vector<Grunt>& grunts, Cloud cloud[], Player& player, int& lives, bool& playerLiving, int& points, std::vector<Bullet>& ebullets, int& gruntsKilled, int& shoot,std::vector<Bomb>& bombs, std::vector<Missile>& missiles)
{
    int bomb = 0;
    window.draw(background);
    //Grunts
    for (int i = 0; i < grunts.size(); i++)
    {
        if (grunts[i].move())
        {
            std::string temp = "e";
            if (levels[level] == 2000)
                temp = "s";
            Bullet tempBullet(grunts[i].getPosition(), -grunts[i].getRotation(), temp);
            ebullets.push_back(tempBullet);
        }
        if (grunts.size() > 0 && i >= 0)
        {
            if(!grunts[i].inBounds() && grunts[i].retreating())
            {
                grunts.erase(grunts.begin() + i);
                i--;
                std::cout << "executed coward";
            }
            else
            {
                grunts[i].outOfBounds();
                window.draw(grunts[i].getAnimation().getSprite());
            }
            
        }
        if (grunts.size() > 0 && i >= 0)
            if (grunts[i].getPosition().y < 600 && ((grunts[i].getRotation() <=22.5||grunts[i].getRotation()>=337.5) || (grunts[i].getRotation() <=202.5 && grunts[i].getRotation()>=157.5))&&rand()%40==i&&bomb<3 && levels[level%6] == 0)
            {
                Bomb tempBomb(grunts[i].getPosition());
                bombs.push_back(tempBomb);
                bomb++;
            }
    }
    //clouds yay
    for (int i = 0; i < 8; i++)
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
    for (int i = 0; i < bombs.size(); i++)
    {
        bombs[i].move();
        window.draw(bombs[i].getAnimation().getSprite());
        if (!bombs[i].inBounds())
        {
            bombs.erase(bombs.begin() + i);
            i--;
            bomb--;
        }
        if (i >= 0)
        {
            if (bombs[i].collision(player))
            {
                lives--;
                playerLiving = false;
                shoot = 0;
                bombs.erase(bombs.begin() + i);
                i--;
                bomb = 0;
            }
        }
    }

    for (int i = 0; i < missiles.size(); i++)
    {
        if (missiles.size() > 0 && i >= 0)
        {
            missiles[i].move();
            window.draw(missiles[i].getAnimation().getSprite());
            //missiles[i].outOfBounds();
            if (missiles[i].collision(player))
            {
                lives--;
                playerLiving = false;
                missiles.erase(missiles.begin() + i);
                i--;
            }
            else if (!missiles[i].inBounds())
            {
                missiles.erase(missiles.begin() + i);
                i--;
                //std::cout << "boom" << std::endl;
            }
        }
    }
}
