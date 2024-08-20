#ifndef WALLS_HPP
#define WALLS_HPP
#include "Logo.hpp"

class Walls
{
public:

	Walls(sf::Texture* texture);

	float left();
	float right();
	float top();

	sf::Texture* texture;
	sf::Sprite sprite;

private:

	float leftBorder, rightBorder, topBorder;
};

#endif // !WALLS_HPP



