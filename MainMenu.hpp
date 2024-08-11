#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "PauseMenu.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window);

	void update(sf::Event& sfEvent);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getSelectedItemIndex();

	bool getStart

private:

	int selectedItemIndex;
	sf::Font* font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RenderWindow* window;

	bool start, howToPlay, exit;
};

#endif // !MAINMENU_HPP



