#ifndef BRICK_HPP
#define BRICK_HPP
#include "Includes.hpp"

class Brick
{
public:

	Brick(sf::Texture* texture);

	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif // !BRICK_HPP



