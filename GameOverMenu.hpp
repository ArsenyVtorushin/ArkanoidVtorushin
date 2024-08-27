#ifndef GAMEOVERMENU_HPP
#define GAMEOVERMENU_HPP
#include "Level.hpp"
#define MAX_NUMBER_OF_ITEMS 2

class GameOverMenu
{
public:

	GameOverMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent, bool* gameOverMenuBool, bool* tryAgainBool, bool* exitGameOverMenuBool);

	void update();
	void render();
	void MoveUp();
	void MoveDown();

	int getSelectedItemIndex();

private:

	int selectedItemIndex;

	sf::Font* font;
	sf::Text gameOverText;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool* gameOverMenuBool;
	bool* tryAgainBool, * exitGameOverMenuBool;
};

#endif // !GAMEOVERMENU_HPP



