#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Ball.hpp"

#define X_HEARTS_POS this->window->getSize().x - 730 + (i + 1) * (*this->hearts)[i].sprite.getGlobalBounds().width
#define Y_HEARTS_POS 580

#define X_BRICKS_POS (this->walls->left() + 20) + (((*this->bricks)[i][j].sprite.getGlobalBounds().width + 13) * j)
#define Y_BRICKS_POS (this->walls->top() + 40) + (((*this->bricks)[i][j].sprite.getGlobalBounds().height + 13) * i)

class Level
{
public:

	Level(sf::RenderWindow* window, int rowBricks, int columnBricks, sf::Text* levelNumberText, float ballSpeed);
	~Level();

	// Main functions

	void update();
	void render();

	// Check stuff

	void checkCollision();
	void checkWallsCollision();
	void checkPaddleCollision();
	void checkBrickCollision();
	void checkBallOut();

	bool isIntersecting(sf::Sprite first, sf::Sprite second);

	// Getters / Setters

	void setDarkerColor();
	void resetDarkerColor();

	void setStartLevelBool(bool startLevelBool);
	bool getStartLevelBool();

	void setGameOverBool(bool gameOverBool);
	bool getGameOverBool();

	void setWin(bool win);
	bool getWin();

private:

	// Variables
	
	int rowBricks, columnBricks;
	int allBricks;

	float overlapLeft, overlapRight, overlapTop, overlapBottom;
	float minOverlapX, minOverlapY;
	float ballSpeed;

	bool ballFromLeft, ballFromTop;
	bool startLevelBool;
	bool gameOverBool;
	bool win;

	sf::RenderWindow* window;

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
	std::vector<std::vector<Brick>>* bricks;

	sf::Text* levelNumberText;

	unsigned int levelNumberText_cooldown;

	//Initialization

	void init();

	void initTextures();
	void initSprites();
	void initHearts();
	void initBricks();
};

#endif // !LEVEL_HPP

