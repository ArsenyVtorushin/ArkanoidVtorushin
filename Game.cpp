#include "Game.hpp"

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
	delete this->pauseMenu;
	delete this->gameOverMenu;
	delete this->winMenu;
	delete this->howToPlay;
	delete this->levelOne;
	delete this->levelTwo;
	delete this->finalRound;
}

// Main functions

void Game::run()
{
	this->music.play();

	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}

	this->music.stop();
}

void Game::update()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed || this->sfEvent.key.code == sf::Keyboard::Escape)
		{
			(*this->window).close();
		}

		this->updateMenus();
	}

	this->updateLevels();
}
void Game::render()
{
	this->window->clear();

	this->mainMenu->render();
	this->pauseMenu->render();
	this->gameOverMenu->render();
	this->winMenu->render();

	this->howToPlay->render();

	this->renderLevels();

	this->window->display();
}

// Update menus

void Game::updateMenus()
{
	this->updateMainMenu();
	this->updatePauseMenu();
	this->updateGameOverMenu();
	this->updateWinMenu();
}

void Game::updateMainMenu()
{
	this->mainMenu->update();

	if (this->mainMenu->getHowToPlayBool())
	{
		this->howToPlay->setHowToPlayBool(true);
		this->mainMenu->setHowToPlayBool(false);
	}

	this->howToPlay->update();

	if (this->howToPlay->getBackBool())
	{
		this->mainMenu->setMainMenuBool(true);
		this->howToPlay->setBackBool(false);
	}

	if (this->mainMenu->getExitBool())
	{
		this->window->close();
	}

	if (this->mainMenu->getStartLevelOneFlag())
	{
		this->levelOne->setStartLevelBool(true);
		this->mainMenu->setStartLevelOneFlag(false);
	}
}
void Game::updatePauseMenu()
{
	if (this->mainMenu->getStartGameBool())
	{
		if (this->sfEvent.type == sf::Event::KeyReleased && this->sfEvent.key.code == sf::Keyboard::Space)
		{
			this->pauseMenu->setPauseMenuBool(true);
			this->music.pause();
			this->mainMenu->setStartGameBool(false);
		}
	}

	this->pauseMenu->update();

	if (this->pauseMenu->getContinueBool())
	{
		this->mainMenu->setStartGameBool(true);
		this->music.play();
		this->pauseMenu->setContinueBool(false);
	}

	if (this->pauseMenu->getExitBool())
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->mainMenu->setMainMenuBool(true);
		this->music.play();
		this->pauseMenu->setExitBool(false);
	}
	
}
void Game::updateGameOverMenu()
{
	this->gameOverMenu->update();

	if (this->gameOverMenu->getTryAgainBool())
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->mainMenu->setStartGameBool(true);
		this->levelOne->setStartLevelBool(true);
		this->gameOverMenu->setTryAgainBool(false);
	}

	if (this->gameOverMenu->getExitBool())
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->mainMenu->setMainMenuBool(true);
		this->gameOverMenu->setExitBool(false);
	}
}
void Game::updateWinMenu()
{
	this->winMenu->update();

	if (this->winMenu->getPlayAgainBool())
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->mainMenu->setMainMenuBool(true);
		this->winMenu->setPlayAgainBool(false);
	}
	
	if (this->winMenu->getExitBool())
	{
		this->window->close();
	}
}

// Update levels

void Game::updateLevels()
{
	if (this->mainMenu->getStartGameBool())
	{
		this->updateLevelOne();
		this->updateLevelTwo();
		this->updateFinalRound();
	}
}

void Game::updateLevelOne()
{
	this->levelOne->update();

	if (this->levelOne->getGameOverBool())
	{
		this->gameOverMenu->setGameOverMenuBool(true);
		this->mainMenu->setStartGameBool(false);
		this->levelOne->setGameOverBool(false);
	}

	if (this->levelOne->getWin())
	{
		this->levelOne->setWin(false);
		this->levelTwo->setStartLevelBool(true);
	}
}
void Game::updateLevelTwo()
{
	this->levelTwo->update();

	if (this->levelTwo->getGameOverBool())
	{
		this->gameOverMenu->setGameOverMenuBool(true);
		this->mainMenu->setStartGameBool(false);
		this->levelTwo->setGameOverBool(false);
	}

	if (this->levelTwo->getWin())
	{
		this->levelTwo->setWin(false);
		this->finalRound->setStartLevelBool(true);
	}
}
void Game::updateFinalRound()
{
	this->finalRound->update();

	if (this->finalRound->getGameOverBool())
	{
		this->gameOverMenu->setGameOverMenuBool(true);
		this->mainMenu->setStartGameBool(false);
		this->finalRound->setGameOverBool(false);
	}

	if (this->finalRound->getWin())
	{
		this->mainMenu->setStartGameBool(false);
		this->winMenu->setWinMenuBool(true);
		this->finalRound->setWin(false);
	}
}

// Render levels

void Game::renderLevels()
{
	if (this->mainMenu->getStartGameBool())
	{
		this->levelOne->render();
		this->levelTwo->render();
		this->finalRound->render();
	}
}

// Initialization

void Game::init()
{
	this->initWindow();
	this->initText();
	this->initMusic();
	this->initMenus();
	this->initInstructions();
	this->initLevels();
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
void Game::initMusic()
{
	if (!this->music.openFromFile("C:\\Users\\Admin\\source\\repos\\ArkanoidVtorushin\\Assets\\Boiler.ogg"))
	{
		std::cerr << "Error when opening music";
	}

	this->music.setLoop(true);
}
void Game::initMenus()
{
	this->mainMenu = new MainMenu(this->font, this->window, &this->sfEvent);
	this->mainMenu->setMainMenuBool(true);
	this->pauseMenu = new PauseMenu(this->font, this->window, &this->sfEvent);
	this->gameOverMenu = new GameOverMenu(this->font, this->window, &this->sfEvent);
	this->winMenu = new WinMenu(this->font, this->window, &this->sfEvent);
}
void Game::initInstructions()
{
	this->howToPlay = new HowToPlay(this->font, this->window, &this->sfEvent);
}
void Game::initLevels()
{
	this->levelOne = new Level(this->window, 3, 10, &this->levelOneText, 12.f);
	this->levelTwo = new Level(this->window, 5, 10, &this->levelTwoText, 13.f);
	this->finalRound = new Level(this->window, 10, 2, &this->finalRoundText, 14.f);
}

