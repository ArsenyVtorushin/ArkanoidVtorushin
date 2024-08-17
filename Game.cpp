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
	delete this->instructions;
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
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed || this->event.key.code == sf::Keyboard::Escape)
		{
			(*this->window).close();
		}

		//this->mainMenu->update(this->event, this->mainMenuBool, this->startBool, this->howToPlayBool, this->exitBool);
		//this->instructions->update(this->event, this->howToPlayBool, this->mainMenuBool);

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

	//this->mainMenu->render(this->window, this->mainMenuBool);
	//this->instructions->render(this->window, this->howToPlayBool, this->mainMenuBool);
	this->levelOne->render();
	

	this->window->display();
}

//private

void Game::init()
{
	this->initWindow();
	this->initFont();
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
void Game::initFont()
{
	this->font = new sf::Font;
	this->font->loadFromFile("Assets/font.ttf");

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
void Game::initLevels()
{
	this->levelOne = new Level(this->window, 11, 4, &this->startBool, &this->levelOneBool);
}
void Game::initBooleans()
{
	this->mainMenuBool = true;

	this->startBool = false;
	this->howToPlayBool = false;
	this->exitBool = false;

	this->levelOneBool = false;
	this->levelTwoBool = false;
	this->FinalRoundBool = false;
}
