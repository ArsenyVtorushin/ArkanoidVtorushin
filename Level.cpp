#include "Level.hpp"

Level::Level(sf::RenderWindow* window, int rowBricks, int columnBricks, sf::Text* levelNumberText, float ballSpeed)
{
	this->window = window;

	this->rowBricks = rowBricks;
	this->columnBricks = columnBricks;
	this->allBricks = rowBricks * columnBricks;

	this->levelNumberText = levelNumberText;
	this->levelNumberText_cooldown = 120;

	this->ballSpeed = ballSpeed;

	this->startLevelBool = false;
	this->gameOverBool = false;
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

// Main functions

void Level::update()
{
	if (this->startLevelBool)
	{
		if (this->levelNumberText_cooldown > 0)
		{
			this->levelNumberText->setScale(3.f, 3.f);
			this->levelNumberText->setPosition(this->window->getSize().x * 0.5, this->window->getSize().y * 0.5 - 20);
			this->levelNumberText_cooldown--;

			this->setDarkerColor();
		}
		else
		{
			if (this->bricks->empty())
			{
				this->win = true;
				this->startLevelBool = false;
			}
			else
			{
				this->levelNumberText->setScale(2.f, 2.f);
				this->levelNumberText->setPosition(this->window->getSize().x - 550.f, 480.f);

				this->resetDarkerColor();

				this->checkCollision();
				this->checkBallOut();

				this->paddle->update();
				this->ball->update();
			}
		}
	}
}
void Level::render()
{
	if (this->startLevelBool)
	{
		this->window->draw(this->paddle->sprite);
		this->window->draw(this->ball->sprite);
		this->window->draw(this->walls->sprite);
		this->window->draw(this->logo->sprite);

		for (int i = 0; i < this->hearts->size(); i++)
		{
			this->window->draw((*this->hearts)[i].sprite);
		}

		for (int i = 0; i < (*this->bricks).size(); i++)
		{
			for (int j = 0; j < (*this->bricks)[i].size(); j++)
			{
				this->window->draw((*this->bricks)[i][j].sprite);
			}
		}

		this->window->draw(*this->levelNumberText);
	}
}

// Check stuff

void Level::checkCollision()
{
	this->checkWallsCollision();
	this->checkPaddleCollision();
	this->checkBrickCollision();
}

void Level::checkWallsCollision()
{
	if (this->ball->left() <= 312)
	{
		this->ball->setVelocityX(this->ball->getSpeed());
	}

	if (this->ball->top() <= 139)
	{
		this->ball->setVelocityY(this->ball->getSpeed());
	}

	if (this->ball->right() >= 1113)
	{
		this->ball->setVelocityX(-(this->ball->getSpeed()));
	}
}
void Level::checkPaddleCollision()
{
	if (this->isIntersecting(this->ball->sprite, this->paddle->sprite))
	{
		this->ball->setVelocityY(-(rand() % 10 + 7));

		if (this->ball->x() < this->paddle->x())
		{
			this->ball->setVelocityX(-(this->ball->getSpeed()));
		}
		else
		{
			this->ball->setVelocityX(this->ball->getSpeed());
		}
	}
}
void Level::checkBrickCollision()
{
	for (int i = 0; i < (*this->bricks).size(); i++)
	{
		for (int j = 0; j < (*this->bricks)[i].size(); j++)
		{
			if (this->isIntersecting(this->ball->sprite, (*this->bricks)[i][j].sprite))
			{
				this->overlapLeft = (*this->ball).right() - (*this->bricks)[i][j].left();
				this->overlapRight = (*this->bricks)[i][j].right() - (*this->ball).left();
				this->overlapTop = (*this->ball).bottom() - (*this->bricks)[i][j].top();
				this->overlapBottom = (*this->bricks)[i][j].bottom() - (*this->ball).top();

				this->ballFromLeft = this->overlapLeft < this->overlapRight;
				this->ballFromTop = this->overlapTop < this->overlapBottom;

				this->minOverlapX = { this->ballFromLeft ? overlapLeft : overlapRight };
				this->minOverlapY = { this->ballFromTop ? overlapTop : overlapBottom };

				if (this->minOverlapX < this->minOverlapY)
				{
					this->ball->setVelocityX(this->ballFromLeft ? -(this->ball->getSpeed()) : this->ball->getSpeed());
				}
				else
				{
					this->ball->setVelocityY(this->ballFromTop ? -(this->ball->getSpeed()) : this->ball->getSpeed());
				}

				(*this->bricks)[i].erase((*this->bricks)[i].begin() + j);

				if ((*this->bricks)[i].empty())
				{
					this->bricks->erase(this->bricks->begin() + i);
				}

				i = -1;
				j = -1;

				break;
			}
		}
	}
}
void Level::checkBallOut()
{
	if (this->ball->top() > this->window->getSize().y + 100)
	{
		this->hearts->pop_back();

		if (this->hearts->empty())
		{
			this->startLevelBool = false;
			this->gameOverBool = true;

			delete this->hearts;
			this->initHearts();
		}

		delete this->bricks;
		this->initBricks();

		this->levelNumberText_cooldown = 120;
		this->ball->setVelocityY(-(this->ball->getSpeed()));
	}
}

bool Level::isIntersecting(sf::Sprite first, sf::Sprite second)
{
	return first.getGlobalBounds().intersects(second.getGlobalBounds());
}

// Getters / Setters

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

	for (int i = 0; i < (*this->bricks).size(); i++)
	{
		for (int j = 0; j < (*this->bricks)[i].size(); j++)
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

	for (int i = 0; i < (*this->bricks).size(); i++)
	{
		for (int j = 0; j < (*this->bricks)[i].size(); j++)
		{
			(*this->bricks)[i][j].sprite.setColor(sf::Color(255, 255, 255, 255));
		}
	}
}

void Level::setStartLevelBool(bool startLevelBool)
{
	this->startLevelBool = startLevelBool;
}
bool Level::getStartLevelBool()
{
	return this->startLevelBool;
}

void Level::setGameOverBool(bool gameOverBool)
{
	this->gameOverBool = gameOverBool;
}
bool Level::getGameOverBool()
{
	return this->gameOverBool;
}

void Level::setWin(bool win)
{
	this->win = win;
}
bool Level::getWin()
{
	return this->win;
}

//Initialization

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
	this->ball->setSpeed(this->ballSpeed);
	this->walls = new Walls(&this->wallsTexture);
	this->logo = new Logo(&this->logoTexture, this->window);
	this->initHearts();
	this->initBricks();
}
void Level::initHearts()
{
	this->hearts = new std::vector<Heart>(this->paddle->getHPMax(), &this->heartTexture);

	for (int i = 0; i < this->hearts->size(); i++)
	{
		(*this->hearts)[i].sprite.setPosition(X_HEARTS_POS, Y_HEARTS_POS);
	}
}
void Level::initBricks()
{
	this->bricks = new std::vector<std::vector<Brick>>(this->rowBricks, std::vector<Brick>(this->columnBricks, { &this->brickTexture }));

	for (int i = 0; i < (*this->bricks).size(); i++)
	{
		for (int j = 0; j < (*this->bricks)[i].size(); j++)
		{
			(*this->bricks)[i][j].sprite.setPosition(X_BRICKS_POS, Y_BRICKS_POS);
		}
	}
}
