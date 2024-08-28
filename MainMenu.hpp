#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "HowToPlay.hpp"
#define MAX_NUMBER_OF_ITEMS_MAIN 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent, bool* mainMenuBool, bool* startGameBool, bool* howToPlayBool, bool* exitMainMenuBool);

	void update();
	void render();

	void MoveUp();
	void MoveDown();

	void setStartLevelOneFlag(bool startLevelOneFlag);
	bool getStartLevelOneFlag();
	
	int getSelectedItemIndex();

private:

	int selectedItemIndex;
	
	sf::Font* font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_MAIN];
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool* mainMenuBool;
	bool* startGameBool, * howToPlayBool, * exitMainMenuBool;
	bool startLevelOneFlag;
};

#endif // !MAINMENU_HPP



