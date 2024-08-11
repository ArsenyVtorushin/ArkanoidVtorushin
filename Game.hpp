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
	sf::Texture heartTexture;
	sf::Texture logoTexture;

	Paddle* paddle;
	Ball* ball;
	Walls* walls;
	Logo* logo;
	std::vector<Heart>* hearts;

	sf::Font* font;
	MyText* levelOneText;
	MyText* levelTwoText;
	MyText* finalRoundText;
	//MyText* pressStartText;

	MainMenu* mainMenu;
	//PauseMenu* pauseMenu;
	//GameOverMenu* gameOverMenu;

	//Initialization

	void init();
	void initWindow();
	void initTextures();
	void initSprites();
	void initText();
	void initMenus();

};

#endif // !GAME_H


