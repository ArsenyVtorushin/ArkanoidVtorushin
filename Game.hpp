#ifndef GAME_HPP
#define GAME_HPP
#include "MainMenu.hpp"

class Game
{
public:

	Game();
	~Game();

	void run();

	void update();
	void render();

	void updateMenus();

	void updateMainMenu();
	void updatePauseMenu();
	void updateGameOverMenu();
	void updateWinMenu();

	void updateLevels();

	void updateLevelOne();
	void updateLevelTwo();
	void updateFinalRound();


private:

	//Variables

	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Font* font;

	sf::Music music;

	sf::Text levelOneText, levelTwoText, finalRoundText;

	MainMenu* mainMenu;
	PauseMenu* pauseMenu;
	GameOverMenu* gameOverMenu;
	WinMenu* winMenu;

	HowToPlay* howToPlay;

	Level* levelOne;
	Level* levelTwo;
	Level* finalRound;

	bool mainMenuBool;
	bool startGameBool, howToPlayBool, exitMainMenuBool;

	//Initialization

	void init();

	void initBooleans();
	void initWindow();
	void initText();
	void initMusic();
	void initMenus();
	void initInstructions();
	void initLevels();
};

#endif // !GAME_H


