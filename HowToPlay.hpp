#ifndef HOWTOPLAY_HPP
#define HOWTOPLAY_HPP
#include "PauseMenu.hpp"

class HowToPlay
{
public:

	HowToPlay(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent, bool*mainMenuBool, bool* howToPlayBool);

	void update();
	void render();

private:

	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool* mainMenuBool;
	bool* howToPlayBool;

	sf::Text text;
	sf::Text back;
	sf::Text pressSpace;

	void initText();
};

#endif // !HOWTOPLAY_HPP



