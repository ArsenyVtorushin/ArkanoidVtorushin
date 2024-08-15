#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "HowToPlay.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window);

	void update(sf::Event& sfEvent, bool& mainMenuBool, bool& startBool, bool& howToPlayBool, bool& exitBool);
	void render(sf::RenderWindow* window, bool& mainMenuBool);
	void MoveUp();
	void MoveDown();

	int getSelectedItemIndex();

private:

	int selectedItemIndex;
	sf::Font* font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RenderWindow* window;
};

#endif // !MAINMENU_HPP



