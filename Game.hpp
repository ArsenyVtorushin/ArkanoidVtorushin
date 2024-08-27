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

	void updateMainMenu();
	void updateGameOverMenu();

	void Leveling();
	void TryAgain();

private:

	//Variables

	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Font* font;

	sf::Text levelOneText, levelTwoText, finalRoundText;

	MainMenu* mainMenu;
	//PauseMenu* pauseMenu;
	GameOverMenu* gameOverMenu;
	HowToPlay* howToPlay;
	Level* levelOne;
	Level* levelTwo;
	Level* finalRound;

	bool mainMenuBool;
	bool startGameBool, howToPlayBool, exitMainMenuBool;
	bool gameOverMenuBool;
	bool tryAgainBool, exitGameOverMenuBool;

	//Initialization

	void init();

	void initBooleans();
	void initWindow();
	void initText();
	void initMenus();
	void initInstructions();
	void initLevels();

};

#endif // !GAME_H


