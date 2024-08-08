#ifndef LOGO_HPP
#define LOGO_HPP
#include "Heart.hpp"

class Logo
{
public:

	Logo(sf::Texture* texture, sf::RenderWindow* window);

	sf::Texture* texture;
	sf::Sprite sprite;
};

#endif // !LOGO_HPP



