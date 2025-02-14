#include "MainMenu.hpp"

MainMenu::MainMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent)
{	
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->mainMenuBool = mainMenuBool;
	this->startGameBool = startGameBool;
	this->howToPlayBool = howToPlayBool;
	this->exitBool = exitBool;

	this->startLevelOneFlag = false;

	this->initLogo();
	this->initText();

	this->selectedItemIndex = 0;
}

// Main functions

void MainMenu::update()
{
	if (this->mainMenuBool)
	{
		if ((*this->sfEvent).type == sf::Event::KeyReleased)
		{
			if ((*this->sfEvent).key.code == sf::Keyboard::Up)
			{
				this->MoveUp();
			}
			else if ((*this->sfEvent).key.code == sf::Keyboard::Down)
			{
				this->MoveDown();
			}
			else if ((*this->sfEvent).key.code == sf::Keyboard::Return)
			{
				if (this->selectedItemIndex == 0)
				{
					this->mainMenuBool = false;
					this->startGameBool = true;
					this->howToPlayBool = false;
					this->exitBool = false;

					this->startLevelOneFlag = true;
				}
				else if (this->selectedItemIndex == 1)
				{
					this->mainMenuBool = false;
					this->startGameBool = false;
					this->howToPlayBool = true;
					this->exitBool = false;
				}
				else
				{
					this->mainMenuBool = false;
					this->startGameBool = false;
					this->howToPlayBool = false;
					this->exitBool = true;
				}
			}
		}
	}
}
void MainMenu::render()
{
	if (this->mainMenuBool)
	{
		this->window->draw(this->logo);

		for (int i = 0; i < MAX_NUMBER_OF_ITEMS_MAIN; i++)
		{
			(*this->window).draw(this->menu[i]);
		}

		this->window->draw(this->upDownEnterText);
	}
}

void MainMenu::MoveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex--;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}
void MainMenu::MoveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_MAIN)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex++;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}

// Getters / Setters

void MainMenu::setMainMenuBool(bool mainMenuBool)
{
	this->mainMenuBool = mainMenuBool;
}
bool MainMenu::getMainMenuBool()
{
	return this->mainMenuBool;
}

void MainMenu::setStartGameBool(bool startGameBool)
{
	this->startGameBool = startGameBool;
}
bool MainMenu::getStartGameBool()
{
	return this->startGameBool;
}

void MainMenu::setHowToPlayBool(bool howToPlayBool)
{
	this->howToPlayBool = howToPlayBool;
}
bool MainMenu::getHowToPlayBool()
{
	return this->howToPlayBool;
}

void MainMenu::setExitBool(bool exitBool)
{
	this->exitBool = exitBool;
}
bool MainMenu::getExitBool()
{
	return this->exitBool;
}

void MainMenu::setStartLevelOneFlag(bool startLevelOneFlag)
{
	this->startLevelOneFlag = startLevelOneFlag;
}
bool MainMenu::getStartLevelOneFlag()
{
	return this->startLevelOneFlag;
}

//Initialization

void MainMenu::initLogo()
{
	if (!this->logoTexture.loadFromFile("Assets/ArkanoidLogo.png"))
	{
		std::cout << "Error when loading logo to menu\n";
	}

	this->logo.setTexture(this->logoTexture);
	this->logo.setScale(6.f, 6.f);
	this->logo.setOrigin(this->logo.getLocalBounds().width * 0.5, this->logo.getLocalBounds().height * 0.5);
	this->logo.setPosition(this->window->getSize().x * 0.5f, this->window->getSize().y * 0.3f);
}
void MainMenu::initText()
{
	this->menu[0].setString("Start");
	this->menu[0].setOutlineColor(sf::Color::Blue);
	this->menu[1].setString("How to Play");
	this->menu[1].setOutlineColor(sf::Color::Black);
	this->menu[2].setString("Exit");
	this->menu[2].setOutlineColor(sf::Color::Black);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_MAIN; i++)
	{
		this->menu[i].setOutlineThickness(1.f);
		this->menu[i].setScale(1.5f, 1.5f);
		this->menu[i].setFont(*this->font);
		this->menu[i].setOrigin(this->menu[i].getLocalBounds().width * 0.5f, this->menu[i].getLocalBounds().height * 0.5f);
		this->menu[i].setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.4f + (*this->window).getSize().y * 0.5f / (MAX_NUMBER_OF_ITEMS_MAIN + 1) * (i + 1.f));
	}

	this->upDownEnterText.setString("(use 'up', 'down', 'Enter' keys)");
	this->upDownEnterText.setFont(*this->font);
	this->upDownEnterText.setScale(0.8f, 0.8f);
	this->upDownEnterText.setOrigin(this->upDownEnterText.getLocalBounds().width * 0.5f, this->upDownEnterText.getLocalBounds().height * 0.5f);
	this->upDownEnterText.setPosition(this->window->getSize().x * 0.5f, this->window->getSize().y - 140.f);
	this->upDownEnterText.setFillColor(sf::Color(100, 200, 150));

}
