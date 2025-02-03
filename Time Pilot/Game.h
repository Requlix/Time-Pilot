#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow window;

	int sizeMult = 4;
	int winSizeX = 224 * sizeMult, winSizeY = 256 * sizeMult;

};

