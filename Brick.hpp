#ifndef BRICK_HPP
#define BRICK_HPP
#include "Includes.hpp"

class Brick
{
public:

	Brick(sf::Texture* texture, sf::RenderWindow* window);

	sf::Texture* texture;
	sf::Sprite sprite;

private:

	sf::RenderWindow* window;
};

#endif // !BRICK_HPP



