#ifndef HOWTOPLAY_HPP
#define HOWTOPLAY_HPP
#include "PauseMenu.hpp"

class HowToPlay
{
public:

	HowToPlay(sf::Font* font, sf::RenderWindow* window);

	void update(sf::Event& sfEvent, bool& howToPlay, bool& mainMenuBool);
	void render(sf::RenderWindow* window, bool& howToPlay, bool& mainMenuBool);

private:

	sf::Text text;
	sf::Text back;
	sf::Text pressSpace;
	sf::Font* font;
	sf::RenderWindow* window;
};

#endif // !HOWTOPLAY_HPP



