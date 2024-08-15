#include "Game.hpp"

//public

// Constructor/Destructor

Game::Game()
{
	init();
}

Game::~Game()
{
	delete this->window;
	delete this->paddle;
	delete this->ball;
	delete this->walls;
	delete this->hearts;
	delete this->logo;
	delete this->font;
	delete this->levelOneText;
	delete this->levelTwoText;
	delete this->finalRoundText;
	//delete this->pressStartText;
	delete this->mainMenu;
	//delete this->pauseMenu;
	//delete this->gameOverMenu;
	delete this->instructions;
}

// Functions

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed || this->event.key.code == sf::Keyboard::Escape)
		{
			(*this->window).close();
		}

		this->mainMenu->update(this->event, this->mainMenuBool, this->startBool, this->howToPlayBool, this->exitBool);
		this->instructions->update(this->event, this->howToPlayBool, this->mainMenuBool);

		if (this->exitBool)
		{
			(*this->window).close();
		}
	}

	this->paddle->update();
	this->ball->update();
}

void Game::render()
{
	this->window->clear();

	this->mainMenu->render(this->window, this->mainMenuBool);
	this->instructions->render(this->window, this->howToPlayBool, this->mainMenuBool);
	
	/*this->window->draw(this->paddle->sprite);
	this->window->draw(this->ball->sprite);
	this->window->draw(this->walls->sprite);
	this->window->draw(this->logo->sprite);

	for (int i = 0; i < this->hearts->size(); i++)
	{
		this->window->draw((*this->hearts)[i].sprite);
	}

	this->window->draw(this->levelOneText->text);*/

	this->window->display();
}

//private

void Game::init()
{
	this->initWindow();
	this->initTextures();
	this->initSprites();
	this->initText();
	this->initMenus();
	this->initInstructions();
	this->initBooleans();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Arkanoid", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setMouseCursorVisible(false);
}
void Game::initTextures()
{
	this->paddleTexture.loadFromFile("Assets/Paddle3.png");
	this->ballTexture.loadFromFile("Assets/Ball2.png");
	this->wallsTexture.loadFromFile("Assets/Walls.png");
	this->logoTexture.loadFromFile("Assets/ArkanoidLogo.png");
	this->heartTexture.loadFromFile("Assets/Heart.png");
}
void Game::initSprites()
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
}
void Game::initText()
{
	this->font = new sf::Font;
	this->font->loadFromFile("Assets/font.ttf");

	this->levelOneText = new MyText(this->font, "Level 1", this->window);
	this->levelOneText->text.setPosition((*this->window).getSize().x - 700, 400);

	this->levelTwoText = new MyText(this->font, "Level 2", this->window);
	this->levelTwoText->text.setPosition((*this->window).getSize().x - 700, 400);

	this->finalRoundText = new MyText(this->font, "Final Round", this->window);
	this->finalRoundText->text.setPosition((*this->window).getSize().x - 700, 400);

	/*this->pressStartText = new MyText(this->font, "- Press 'space' to start -", this->window);
	this->pressStartText->text.setOrigin(this->pressStartText->text.getGlobalBounds().width / 2, this->pressStartText->text.getGlobalBounds().height / 2);
	this->pressStartText->text.setPosition((*this->window).getSize().x / 2, (*this->window).getSize().y / 2);*/
}
void Game::initMenus()
{
	this->mainMenu = new MainMenu(this->font, this->window);
	//this->pauseMenu = new PauseMenu();
	//this->gameOverMenu = new GameOverMenu();
}
void Game::initInstructions()
{
	this->instructions = new HowToPlay(this->font, this->window);
}
void Game::initBooleans()
{
	this->mainMenuBool = true;

	this->startBool = false;
	this->howToPlayBool = false;
	this->exitBool = false;
}
