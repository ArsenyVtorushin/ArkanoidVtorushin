#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Ball.hpp"

class Level
{
public:

	Level(sf::RenderWindow* window, int amountBricksX, int amountBricksY, bool* startBool, bool* levelBool);
	~Level();

	void update();
	void render();
	
	void init();
	void initTextures();
	void initSprites();

	bool getWin();

private:

	int xBricks, yBricks;
	int allBricks;

	bool* startBool, levelBool;
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
	std::vector<Brick>* bricks;
};

#endif // !LEVEL_HPP



