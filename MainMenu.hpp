#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "PauseMenu.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
public:

	MainMenu(float width, float height, sf::Font& font);

private:

	int maxNumberOfItems = 3;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[maxNumberOfItems];
};

#endif // !MAINMENU_HPP



