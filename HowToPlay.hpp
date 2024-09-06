#ifndef HOWTOPLAY_HPP
#define HOWTOPLAY_HPP
#include "PauseMenu.hpp"

class HowToPlay
{
public:

	HowToPlay(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent);

	// Main functions

	void update();
	void render();

	// Getters / Setters

	void setBackBool(bool backBool);
	bool getBackBool();

	void setHowToPlayBool(bool howToPlayBool);
	bool getHowToPlayBool();

private:

	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool backBool;
	bool howToPlayBool;

	sf::Text text;
	sf::Text back;
	sf::Text pressSpace;

	void initText();
};

#endif // !HOWTOPLAY_HPP



