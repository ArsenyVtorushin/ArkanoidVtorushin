#ifndef GAME_H
#define GAME_H
#include "MainMenu.hpp"

class Game
{
public:

	Game();
	~Game();

	void run();
	void update();
	void render();
	
private:

	//Variables

	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Font* font;

	sf::Text levelOneText, levelTwoText, finalRoundText;

	MainMenu* mainMenu;
	//PauseMenu* pauseMenu;
	//GameOverMenu* gameOverMenu;
	HowToPlay* howToPlay;
	Level* levelOne;
	Level* levelTwo;
	Level* finalRound;

	bool mainMenuBool;
	bool startGameBool, howToPlayBool, exitBool;

	//Initialization

	void init();

	void initWindow();
	void initText();
	void initMenus();
	void initInstructions();
	void initLevels();
	void initBooleans();

};

#endif // !GAME_H


