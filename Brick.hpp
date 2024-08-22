#ifndef BRICK_HPP
#define BRICK_HPP
#include "Includes.hpp"

class Brick
{
public:

	Brick(sf::Texture* texture);

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif // !BRICK_HPP



