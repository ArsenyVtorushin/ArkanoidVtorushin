#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "PauseMenu.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window);

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:

	int selectedItemIndex;
	sf::Font* font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RenderWindow* window;
};

#endif // !MAINMENU_HPP



