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
	delete this->font;
	delete this->mainMenu;
	//delete this->pauseMenu;
	//delete this->gameOverMenu;
	delete this->howToPlay;
	delete this->levelOne;
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
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed || this->sfEvent.key.code == sf::Keyboard::Escape)
		{
			(*this->window).close();
		}

		this->mainMenu->update();
		this->howToPlay->update();

	 	if (this->exitBool)
		{
			(*this->window).close();
		}
	}

	this->levelOne->update();
}

void Game::render()
{
	this->window->clear();

	this->mainMenu->render();
	this->howToPlay->render();
	this->levelOne->render();

	this->window->display();
}

//private

void Game::init()
{
	this->initWindow();
	this->initText();
	this->initMenus();
	this->initInstructions();
	this->initLevels();
	this->initBooleans();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Arkanoid", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setMouseCursorVisible(false);
}
void Game::initText()
{
	this->font = new sf::Font;
	this->font->loadFromFile("Assets/font.ttf");
	
	this->levelOneText.setFont(*this->font);
	this->levelOneText.setString("Level 1");
	this->levelOneText.setScale(3.f, 3.f);
	this->levelOneText.setOrigin(this->levelOneText.getLocalBounds().width * 0.5, this->levelOneText.getLocalBounds().height * 0.5);
	this->levelOneText.setPosition(this->window->getSize().x * 0.5, this->window->getSize().y * 0.5 - 20);

	this->levelTwoText.setFont(*this->font);
	this->levelTwoText.setString("Level 2");
	this->levelTwoText.setScale(3.f, 3.f);
	this->levelTwoText.setOrigin(this->levelTwoText.getLocalBounds().width * 0.5, this->levelTwoText.getLocalBounds().height * 0.5);
	this->levelTwoText.setPosition(this->window->getSize().x * 0.5, this->window->getSize().y * 0.5 - 20);

	this->finalRoundText.setFont(*this->font);
	this->finalRoundText.setString("Final Round");
	this->finalRoundText.setScale(3.f, 3.f);
	this->finalRoundText.setOrigin(this->finalRoundText.getLocalBounds().width * 0.5, this->finalRoundText.getLocalBounds().height * 0.5);
	this->finalRoundText.setPosition(this->window->getSize().x * 0.5, this->window->getSize().y * 0.5 - 20);
}
void Game::initMenus()
{
	this->mainMenu = new MainMenu(this->font, this->window, &this->sfEvent, &this->mainMenuBool, &this->startGameBool, &this->howToPlayBool, &this->exitBool);
	//this->pauseMenu = new PauseMenu();
	//this->gameOverMenu = new GameOverMenu();
}
void Game::initInstructions()
{
	this->howToPlay = new HowToPlay(this->font, this->window, &this->sfEvent, &this->mainMenuBool, &this->howToPlayBool);
}
void Game::initLevels()
{
	this->levelOne = new Level(this->window, 5, 10, &this->startGameBool, &this->levelOneText);
}
void Game::initBooleans()
{
	this->mainMenuBool = true;

	this->startGameBool = false;
	this->howToPlayBool = false;
	this->exitBool = false;
}
