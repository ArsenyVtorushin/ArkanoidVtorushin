#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP
#include "GameOverMenu.hpp"
#define MAX_NUMBER_OF_ITEMS_PAUSE 2

class PauseMenu
{
public:

	PauseMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent);

	void update();
	void render();

	void MoveUp();
	void MoveDown();

	void setPauseMenuBool(bool pauseMenuBool);
	bool getPauseMenuBool();

	void setContinueBool(bool continueBool);
	bool getContinueBool();

	void setExitBool(bool exitBool);
	bool getExitBool();

	int getSelectedItemIndex();

private:

	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool pauseMenuBool;
	bool continueBool, exitBool;

	sf::Text pauseText;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_PAUSE];

	int selectedItemIndex;

};

#endif // !PAUSEMENU_HPP



