#include "Level.hpp"

Level::Level(sf::RenderWindow* window, int amountBricksX, int amountBricksY, bool* startBool, bool* levelBool)
{
	this->window = window;
	this->xBricks = amountBricksX;
	this->yBricks = amountBricksY;
	this->allBricks = amountBricksY * amountBricksY;
	this->startBool = startBool;
	this->levelBool = levelBool;
	this->win = false;

	this->init();
}

Level::~Level()
{
	delete this->paddle;
	delete this->ball;
	delete this->walls;
	delete this->logo;
	delete this->hearts;
	delete this->bricks;
}

void Level::update()
{
	if (this->startBool)
	{
		this->paddle->update();
		this->ball->update();

		if (this->bricks->empty())
		{
			this->win = true;
		}
	}
}

void Level::render()
{
	if (this->startBool)
	{
		this->window->draw(this->paddle->sprite);
		this->window->draw(this->ball->sprite);
		this->window->draw(this->walls->sprite);
		this->window->draw(this->logo->sprite);

		for (int i = 0; i < this->hearts->size(); i++)
		{
			this->window->draw((*this->hearts)[i].sprite);
		}
	}
}

void Level::init()
{
	this->initTextures();
	this->initSprites();
}

void Level::initTextures()
{
	this->paddleTexture.loadFromFile("Assets/Paddle3.png");
	this->ballTexture.loadFromFile("Assets/Ball2.png");
	this->wallsTexture.loadFromFile("Assets/Walls.png");
	this->logoTexture.loadFromFile("Assets/ArkanoidLogo.png");
	this->heartTexture.loadFromFile("Assets/Heart.png");
	this->brickTexture.loadFromFile("Assets/Block.png");
}
void Level::initSprites()
{
	this->paddle = new Paddle(&this->paddleTexture, this->window);
	this->ball = new Ball(&this->ballTexture, this->window, this->paddle);
	this->walls = new Walls(&this->wallsTexture);
	this->logo = new Logo(&this->logoTexture, this->window);
	this->hearts = new std::vector<Heart>(3, &this->heartTexture);

	for (int i = 0; i < this->hearts->size(); i++)
	{
		(*this->hearts)[i].sprite.setPosition(this->window->getSize().x - 700 + i * (*this->hearts)[i].sprite.getGlobalBounds().width, 500);
	}

	this->bricks = new std::vector<Brick>(this->allBricks, { &this->brickTexture, this->window });

	/*for (int i = 0; i < this->xBricks; i++)
	{
		for (int j = 0; j < this->yBricks; j++)
		{
			(*this->bricks)[i].sprite.setPosition()
		}
	}*/
}

bool Level::getWin()
{
	return this->win;
}
