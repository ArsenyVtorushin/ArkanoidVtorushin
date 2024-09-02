#ifndef GAMEOVERMENU_HPP
#define GAMEOVERMENU_HPP
#include "WinMenu.hpp"
#define MAX_NUMBER_OF_ITEMS_GAMEOVER 2

class GameOverMenu
{
public:

	GameOverMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent);

	void update();
	void render();
	void MoveUp();
	void MoveDown();

	void setGameOverMenuBool(bool gameOverMenuBool);
	bool getGameOverMenuBool();

	void setTryAgainBool(bool tryAgainBool);
	bool getTryAgainBool();

	void setExitBool(bool exitBool);
	bool getExitBool();

private:

	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool gameOverMenuBool;
	bool tryAgainBool, exitBool;

	sf::Text gameOverText;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_GAMEOVER];

	int selectedItemIndex;
};

#endif // !GAMEOVERMENU_HPP



