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
	sf::Event event;

	sf::Font* font;

	MainMenu* mainMenu;
	//PauseMenu* pauseMenu;
	//GameOverMenu* gameOverMenu;

	HowToPlay* instructions;

	Level* levelOne;

	bool mainMenuBool;
	bool startBool, howToPlayBool, exitBool;
	bool levelOneBool, levelTwoBool, FinalRoundBool, congratsBool; 

	//Initialization

	void init();

	void initWindow();
	void initFont();
	void initMenus();
	void initInstructions();
	void initLevels();
	void initBooleans();

};

#endif // !GAME_H


