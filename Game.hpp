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

	sf::Texture paddleTexture;
	sf::Texture ballTexture;
	sf::Texture wallsTexture;
	sf::Texture logoTexture;
	sf::Texture heartTexture;
	sf::Texture brickTexture;

	Paddle* paddle;
	Ball* ball;
	Walls* walls;
	Logo* logo;
	std::vector<Heart>* hearts;
	std::vector<Brick>* bricksLevel1;
	std::vector<Brick>* bricksLevel2;
	std::vector<Brick>* bricksFinalRound;

	sf::Font* font;
	MyText* levelOneText;
	MyText* levelTwoText;
	MyText* finalRoundText;

	MainMenu* mainMenu;
	//PauseMenu* pauseMenu;
	//GameOverMenu* gameOverMenu;

	HowToPlay* instructions;

	bool mainMenuBool;

	bool startBool, howToPlayBool, exitBool;

	//Initialization

	void init();
	void initWindow();
	void initTextures();
	void initSprites();
	void initText();
	void initMenus();
	void initInstructions();
	void initBooleans();

};

#endif // !GAME_H


