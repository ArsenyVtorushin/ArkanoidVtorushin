#ifndef HEARTS_HPP
#define HEARTS_HPP
#include "Brick.hpp"

class Heart
{
public:

	Heart(sf::Texture* texture);

	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif // !HEARTS_HPP



