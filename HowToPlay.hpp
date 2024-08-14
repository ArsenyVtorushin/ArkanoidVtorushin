#ifndef HOWTOPLAY_HPP
#define HOWTOPLAY_HPP
#include "PauseMenu.hpp"

class HowToPlay
{
public:

	HowToPlay(sf::Font* font, sf::RenderWindow* window);

private:

	sf::Text text;
	sf::Font* font;
	sf::RenderWindow* window;
};

#endif // !HOWTOPLAY_HPP



