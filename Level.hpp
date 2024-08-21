#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Ball.hpp"

#define X_HEARTS_POS this->window->getSize().x - 700 + (i + 1) * (*this->hearts)[i].sprite.getGlobalBounds().width
#define Y_HEARTS_POS 500

#define X_BRICKS_POS (this->walls->left() + 20) + (((*this->bricks)[i][j].sprite.getGlobalBounds().width + 13) * j)
#define Y_BRICKS_POS (this->walls->top() + 20) + (((*this->bricks)[i][j].sprite.getGlobalBounds().height + 13) * i) 

class Level
{
public:

	Level(sf::RenderWindow* window, int amountBricksX, int amountBricksY, bool* startGameBool, sf::Text* levelNumberText);
	~Level();

	void update();
	void render();

	void testCollision();

	void testWallsCollision();
	void testPaddleCollision();
	void testBrickCollision();

	bool isIntersecting(sf::Sprite first, sf::Sprite second);

	void setDarkerColor();
	void resetDarkerColor();

	bool getWin();

private:

	int rowBricks, columnBricks;
	int allBricks;

	bool* startGameBool, startLevelBool;
	bool win;

	sf::RenderWindow* window;
	sf::Event* event;

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
};

#endif // !LEVEL_HPP

