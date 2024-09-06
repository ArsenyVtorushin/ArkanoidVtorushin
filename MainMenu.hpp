#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "HowToPlay.hpp"
#define MAX_NUMBER_OF_ITEMS_MAIN 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent);

	// Main functions

	void update();
	void render();

	void MoveUp();
	void MoveDown();

	// Getters / Setters

	void setMainMenuBool(bool mainMenuBool);
	bool getMainMenuBool();

	void setStartGameBool(bool startGameBool);
	bool getStartGameBool();

	void setHowToPlayBool(bool howToPlayBool);
	bool getHowToPlayBool();

	void setExitBool(bool exitBool);
	bool getExitBool();

	void setStartLevelOneFlag(bool startLevelOneFlag);
	bool getStartLevelOneFlag();

private:

	// Variables
	
	sf::Font* font;
	sf::RenderWindow* window;
	sf::Event* sfEvent;

	bool mainMenuBool;
	bool startGameBool, howToPlayBool, exitBool;
	bool startLevelOneFlag;

	sf::Texture logoTexture;
	sf::Sprite logo;

	sf::Text menu[MAX_NUMBER_OF_ITEMS_MAIN];
	sf::Text upDownEnterText;

	int selectedItemIndex;

	//Initialization

	void initLogo();
	void initText();
};

#endif // !MAINMENU_HPP



