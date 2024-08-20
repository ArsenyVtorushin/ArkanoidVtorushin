#include "Level.hpp"

Level::Level(sf::RenderWindow* window, int rowBricks, int columnBricks, bool* startGameBool, sf::Text* levelNumberText)
{
	this->window = window;
	this->rowBricks = rowBricks;
	this->columnBricks = columnBricks;
	this->allBricks = rowBricks * columnBricks;
	this->startGameBool = startGameBool;
	this->startLevelBool = false;
	this->win = false;
	this->levelNumberText = levelNumberText;
	this->levelNumberText_cooldown = 120;

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
	if (*this->startGameBool)
	{
		if (this->levelNumberText_cooldown > 0)
		{
			this->levelNumberText_cooldown--;
			
			this->setDarkerColor();
		}
		else
		{
			this->resetDarkerColor();

			this->paddle->update();
			this->ball->update();

			if (this->bricks->empty())
			{
				this->win = true;
			}
		}
	}
}

void Level::render()
{
	if (*this->startGameBool)
	{
		this->window->draw(this->paddle->sprite);
		this->window->draw(this->ball->sprite);
		this->window->draw(this->walls->sprite);
		this->window->draw(this->logo->sprite);

		for (int i = 0; i < this->hearts->size(); i++)
		{
			this->window->draw((*this->hearts)[i].sprite);
		}

		for (int i = 0; i < this->rowBricks; i++)
		{
			for (int j = 0; j < this->columnBricks; j++)
			{
				this->window->draw((*this->bricks)[i][j].sprite);
			}
		}

		if (this->levelNumberText_cooldown > 0)
		{
			this->window->draw(*this->levelNumberText);
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
	this->brickTexture.loadFromFile("Assets/Brick.png");
}
void Level::initSprites()
{
	this->paddle = new Paddle(&this->paddleTexture, this->window);
	this->ball = new Ball(&this->ballTexture, this->window, this->paddle, &this->levelNumberText_cooldown);
	this->walls = new Walls(&this->wallsTexture);
	this->logo = new Logo(&this->logoTexture, this->window);
	this->hearts = new std::vector<Heart>(this->paddle->getHPMax(), &this->heartTexture);
	this->bricks = new std::vector<std::vector<Brick>>(this->rowBricks, std::vector<Brick>(this->columnBricks, { &this->brickTexture }));

	for (int i = 0; i < this->hearts->size(); i++)
	{
		(*this->hearts)[i].sprite.setPosition(X_HEARTS_POS, Y_HEARTS_POS);
	}

	for (int i = 0; i < this->rowBricks; i++)
	{
		for (int j = 0; j < this->columnBricks; j++)
		{
			(*this->bricks)[i][j].sprite.setPosition(X_BRICKS_POS, Y_BRICKS_POS);
		}
	}
}

void Level::setDarkerColor()
{
	this->paddle->sprite.setColor(sf::Color(255, 255, 255, 128));
	this->ball->sprite.setColor(sf::Color(255, 255, 255, 128));
	this->walls->sprite.setColor(sf::Color(255, 255, 255, 128));
	this->logo->sprite.setColor(sf::Color(255, 255, 255, 128));

	for (int i = 0; i < this->hearts->size(); i++)
	{
		(*this->hearts)[i].sprite.setColor(sf::Color(255, 255, 255, 128));
	}

	for (int i = 0; i < this->rowBricks; i++)
	{
		for (int j = 0; j < this->columnBricks; j++)
		{
			(*this->bricks)[i][j].sprite.setColor(sf::Color(255, 255, 255, 128));
		}
	}
}
void Level::resetDarkerColor()
{
	this->paddle->sprite.setColor(sf::Color(255, 255, 255, 255));
	this->ball->sprite.setColor(sf::Color(255, 255, 255, 255));
	this->walls->sprite.setColor(sf::Color(255, 255, 255, 255));
	this->logo->sprite.setColor(sf::Color(255, 255, 255, 255));

	for (int i = 0; i < this->hearts->size(); i++)
	{
		(*this->hearts)[i].sprite.setColor(sf::Color(255, 255, 255, 255));
	}

	for (int i = 0; i < this->rowBricks; i++)
	{
		for (int j = 0; j < this->columnBricks; j++)
		{
			(*this->bricks)[i][j].sprite.setColor(sf::Color(255, 255, 255, 255));
		}
	}
}

bool Level::getWin()
{
	return this->win;
}
