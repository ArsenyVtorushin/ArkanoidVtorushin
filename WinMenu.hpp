#ifndef WINMENU_HPP
#define WINMENUO_HPP
#include "Level.hpp"
#define MAX_NUMBER_OF_ITEMS_WINMENU 2

class WinMenu
{
public:

	WinMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent);

	void update();
	void render();

	void MoveUp();
	void MoveDown();

	void setWinMenuBool(bool winMenuBool);
	bool getWinMenuBool();

	void setPlayAgainBool(bool playAgainBool);
	bool getPlayAgainBool();

	void setExitBool(bool exitBool);
	bool getExitBool();

private:

	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool winMenuBool;
	bool playAgainBool, exitBool;

	sf::Text youWinText;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_WINMENU];

	int selectedItemIndex;
};

#endif // !WINMENU_HPP



