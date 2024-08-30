#include "Game.hpp"

//public

// Constructor/Destructor

Game::Game()
{
	init();
}

Game::~Game()
{
	this->music.stop();
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

// Functions

void Game::run()
{
	this->music.play();

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

		this->updateMainMenu();
		this->updatePauseMenu();
		this->updateGameOverMenu();
		this->updateWinMenu();
	}

	this->Leveling();
}
void Game::render()
{
	this->window->clear();

	this->mainMenu->render();
	this->pauseMenu->render();
	this->gameOverMenu->render();
	this->winMenu->render();
	this->howToPlay->render();
	this->levelOne->render();
	this->levelTwo->render();
	this->finalRound->render();

	this->window->display();
}

void Game::updateMainMenu()
{
	this->mainMenu->update();

	if (this->mainMenu->getStartLevelOneFlag())
	{
		(*this->levelOne).setStartLevelBool(true);
		(*this->mainMenu).setStartLevelOneFlag(false);
	}

	this->howToPlay->update();
	if (this->exitMainMenuBool)
	{
		(*this->window).close();
	}
}
void Game::updatePauseMenu()
{
	if (this->startGameBool)
	{
		if (this->sfEvent.type == sf::Event::KeyReleased && this->sfEvent.key.code == sf::Keyboard::Space)
		{
			this->startGameBool = false;
			this->pauseMenu->setPauseMenuBool(true);
		}
	}

	this->pauseMenu->update();

	if (this->pauseMenu->getContinueBool())
	{
		this->startGameBool = true;
		this->pauseMenu->setContinueBool(false);
	}

	if (this->pauseMenu->getExitBool())
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->mainMenuBool = true;
		this->pauseMenu->setExitBool(false);
	}
	
}
void Game::updateGameOverMenu()
{
	this->gameOverMenu->update();

	if (this->tryAgainBool)
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->startGameBool = true;
		this->levelOne->setStartLevelBool(true);

		this->tryAgainBool = false;
	}

	if (this->exitGameOverMenuBool)
	{
		delete this->levelOne;
		delete this->levelTwo;
		delete this->finalRound;

		this->initLevels();

		this->exitGameOverMenuBool = false;
		this->mainMenuBool = true;
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

		this->mainMenuBool = true;
		this->winMenu->setPlayAgainBool(false);
	}
	
	if (this->winMenu->getExitBool())
	{
		this->window->close();
	}
}

void Game::Leveling()
{
	if (this->startGameBool)
	{
		this->levelOne->update();

		if (this->levelOne->getWin())
		{
			this->levelOne->setWin(false);
			this->levelTwo->setStartLevelBool(true);
		}

		this->levelTwo->update();

		if (this->levelTwo->getWin())
		{
			this->levelTwo->setWin(false);
			this->finalRound->setStartLevelBool(true);
		}

		this->finalRound->update();

		if (this->finalRound->getWin())
		{
			this->startGameBool = false;
			this->winMenu->setWinMenuBool(true);
			this->finalRound->setWin(false);
		}
	}
}

//private

void Game::init()
{
	this->initBooleans();
	this->initWindow();
	this->initText();
	this->initMusic();
	this->initMenus();
	this->initInstructions();
	this->initLevels();
}

void Game::initBooleans()
{
	this->mainMenuBool = true;

	this->startGameBool = false;
	this->howToPlayBool = false;
	this->exitMainMenuBool = false;

	this->gameOverMenuBool = false;
	this->tryAgainBool = false;
	this->exitGameOverMenuBool = false;
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
	if (!this->music.openFromFile("C:/Users/Admin/source/repos/ArkanoidVtorushin/Assets/Boiler.ogg"))
	{
		std::cout << "Error when opening music\n";
	}

	this->music.setLoop(true);
	this->music.setVolume(90);
}
void Game::initMenus()
{
	this->mainMenu = new MainMenu(this->font, this->window, &this->sfEvent, &this->mainMenuBool, &this->startGameBool, &this->howToPlayBool, &this->exitMainMenuBool);
	this->pauseMenu = new PauseMenu(this->font, this->window, &this->sfEvent);
	this->gameOverMenu = new GameOverMenu(this->font, this->window, &this->sfEvent, &this->gameOverMenuBool, &this->tryAgainBool, &this->exitGameOverMenuBool);
	this->winMenu = new WinMenu(this->font, this->window, &this->sfEvent);
}
void Game::initInstructions()
{
	this->howToPlay = new HowToPlay(this->font, this->window, &this->sfEvent, &this->mainMenuBool, &this->howToPlayBool);
}
void Game::initLevels()
{
	this->levelOne = new Level(this->window, 3, 10, &this->startGameBool, &this->gameOverMenuBool, &this->levelOneText, 12.f);
	this->levelTwo = new Level(this->window, 5, 10, &this->startGameBool, &this->gameOverMenuBool, &this->levelTwoText, 13.f);
	this->finalRound = new Level(this->window, 10, 2, &this->startGameBool, &this->gameOverMenuBool, &this->finalRoundText, 14.f);
}

