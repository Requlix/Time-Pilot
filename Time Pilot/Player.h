#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void move();
	static int tick;
	static double rotation;
private:
	double rotateSpeed = 2;
};

