#include <SFML/Graphics.hpp>

class Animation : public sf::Sprite
{
public:
	Animation();
	~Animation();
	void setFrame(int);
	void setTexture(std::vector<sf::Texture>);
private:
	std::vector<sf::Texture> textures;
};

