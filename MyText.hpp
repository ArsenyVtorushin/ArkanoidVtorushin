#ifndef MYTEXT_HPP
#define MYTEXT_HPP
#include "Includes.hpp"

class MyText
{
public:

	MyText(sf::Font* font, std::string string, sf::RenderWindow* window);

	sf::Font font;
	sf::Text text;
};

#endif // !MYTEXT_HPP



