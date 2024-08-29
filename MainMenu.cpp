#include "MainMenu.hpp"

MainMenu::MainMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent, bool* mainMenuBool, bool* startGameBool, bool* howToPlayBool, bool* exitMainMenuBool)
{	
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->mainMenuBool = mainMenuBool;
	this->startGameBool = startGameBool;
	this->howToPlayBool = howToPlayBool;
	this->exitMainMenuBool = exitMainMenuBool;

	this->startLevelOneFlag = false;
	
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
		this->menu[i].setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f + (*this->window).getSize().y * 0.5f / (MAX_NUMBER_OF_ITEMS_MAIN + 1) * (i + 1.f));
	}

	this->selectedItemIndex = 0;
}

//Functions

void MainMenu::update()
{
	if (*this->mainMenuBool)
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
				if (this->getSelectedItemIndex() == 0)
				{
					*this->mainMenuBool = false;
					*this->startGameBool = true;
					this->startLevelOneFlag = true;
					*this->howToPlayBool = false;
					*this->exitMainMenuBool = false;
				}
				else if (this->getSelectedItemIndex() == 1)
				{
					*this->mainMenuBool = false;
					*this->startGameBool = false;
					*this->howToPlayBool = true;
					*this->exitMainMenuBool = false;
				}
				else
				{
					*this->mainMenuBool = false;
					*this->startGameBool = false;
					*this->howToPlayBool = false;
					*this->exitMainMenuBool = true;
				}
			}
		}
	}
}
void MainMenu::render()
{
	if (*this->mainMenuBool)
	{
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS_MAIN; i++)
		{
			(*this->window).draw(this->menu[i]);
		}
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

void MainMenu::setStartLevelOneFlag(bool startLevelOneFlag)
{
	this->startLevelOneFlag = startLevelOneFlag;
}
bool MainMenu::getStartLevelOneFlag()
{
	return this->startLevelOneFlag;
}

int MainMenu::getSelectedItemIndex()
{
	return this->selectedItemIndex;
}