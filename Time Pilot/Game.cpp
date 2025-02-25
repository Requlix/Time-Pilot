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
    int counter = 0;
    int cloudCount = 4;
    double rotation = 0;
    double rotateSpeed = 2;
    double speed = 2.5;
    double cloudspeed = 2;
    double cloudrotation = 0;
    double cloudrotatespeed = 45;
    
    window.setFramerateLimit(60);
    srand(time(NULL));
    sf::CircleShape middle(30);
    middle.setOrigin(15, 15);
    middle.setPosition(winSizeX/2, winSizeY/2);
    sf::Vector2f direction(-speed, 0);
    sf::RectangleShape clouds[4];
    for (int i = 0; i < cloudCount; i++)
    {
        clouds[i].setSize({ 60,60 });
        clouds[i].setOrigin({ 30,30 });
        int l = rand() % (winSizeX-100) + 50;
        int w = rand() % (winSizeY-100) + 50;

        sf::Vector2f place(l, w);
        clouds[i].setPosition(place);
    }
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (rotation != 180)
                {
                    if (rotation > 0)
                        rotation += rotateSpeed;
                    else
                        rotation -= rotateSpeed;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (rotation != 0)
                {
                    if (rotation > 0)
                        rotation -= rotateSpeed;
                    else
                        rotation += rotateSpeed;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (rotation != 90)
                {
                    if (rotation > -90 && rotation < 90)
                        rotation += rotateSpeed;
                    else
                        rotation -= rotateSpeed;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (rotation != -90)
                {
                    if (rotation > -90 && rotation < 90)
                        rotation -= rotateSpeed;
                    else
                        rotation += rotateSpeed;
                }
            }
            if (rotation > 180)
                rotation -= 360;
            if (rotation < -179)
                rotation += 360;
            direction.x = speed * cos(rotation * 6.28 / 360.);
            direction.y = speed * sin(rotation * 6.28 / 360.);
            for (int i = 0; i < cloudCount; i++)
            {
                //Enemy AI
                /*
                sf::Vector2f goal(0, 0);
                goal.x = winSizeX/2. - clouds[i].getPosition().x;
                goal.y = winSizeY/2. - clouds[i].getPosition().y;
                int q = atan2(goal.y, goal.x) * 360. / 6.28;
                if (q < 0)
                    q += 360;

                if (counter % 20 == 0)
                {
                    if (cloudrotation != q && q > 180)
                    {
                        if (cloudrotation > (q + 180) % 360 && cloudrotation < q)
                        {
                            cloudrotation += cloudrotatespeed;
                        }
                        else
                        {
                            cloudrotation -= cloudrotatespeed;
                        }
                    }
                    if (cloudrotation != q && q <= 180)
                    {
                        if (cloudrotation < (q + 180) % 360 && cloudrotation > q)
                        {
                            cloudrotation -= cloudrotatespeed;
                        }
                        else
                        {
                            cloudrotation += cloudrotatespeed;
                        }
                    }
                }
                counter++;

                if (cloudrotation > 360)
                    cloudrotation -= 360;
                if (cloudrotation < 0)
                    cloudrotation += 360;

                clouds[i].move(cloudspeed * cos(cloudrotation * 6.28 / 360.), cloudspeed * sin(cloudrotation * 6.28 / 360.));
                */
                //move the world
                clouds[i].move(-direction);
                if (clouds[i].getPosition().x < -50)
                    clouds[i].setPosition(clouds[i].getPosition().x + winSizeX+100, clouds[i].getPosition().y);
                if (clouds[i].getPosition().x > winSizeX+50)
                    clouds[i].setPosition(clouds[i].getPosition().x - winSizeX-100, clouds[i].getPosition().y);
                if (clouds[i].getPosition().y < -50)
                    clouds[i].setPosition(clouds[i].getPosition().x, clouds[i].getPosition().y + winSizeY+100);
                if (clouds[i].getPosition().y > winSizeY+50)
                    clouds[i].setPosition(clouds[i].getPosition().x, clouds[i].getPosition().y - winSizeY-100);
                window.draw(clouds[i]);
            }

            window.draw(middle);
            window.display();
            window.clear();
        }
    }
}