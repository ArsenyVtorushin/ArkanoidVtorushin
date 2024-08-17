#include "MainMenu.hpp"

MainMenu::MainMenu(sf::Font* font, sf::RenderWindow* window)
{	
	this->font = font;
	this->window = window;
	
	this->menu[0].setString("Start");
	this->menu[0].setOutlineColor(sf::Color::Blue);
	this->menu[1].setString("How to Play");
	this->menu[1].setOutlineColor(sf::Color::Black);
	this->menu[2].setString("Exit");
	this->menu[2].setOutlineColor(sf::Color::Black);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		this->menu[i].setOutlineThickness(1.f);
		this->menu[i].setScale(1.5f, 1.5f);
		this->menu[i].setFont(*this->font);
		this->menu[i].setOrigin(this->menu[i].getLocalBounds().width * 0.5f, this->menu[i].getLocalBounds().height * 0.5f);
		this->menu[i].setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f + (*this->window).getSize().y * 0.5f / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1.f));
	}

	this->selectedItemIndex = 0;
}

void MainMenu::update(sf::Event& sfEvent, bool& mainMenuBool, bool& startBool, bool& howToPlayBool, bool& exitBool)
{
	if (mainMenuBool)
	{
		if (sfEvent.type == sf::Event::KeyReleased)
		{
			if (sfEvent.key.code == sf::Keyboard::Up)
			{
				this->MoveUp();
			}
			else if (sfEvent.key.code == sf::Keyboard::Down)
			{
				this->MoveDown();
			}
			else if (sfEvent.key.code == sf::Keyboard::Return)
			{
				if (this->getSelectedItemIndex() == 0)
				{
					mainMenuBool = false;
					startBool = true; 
					howToPlayBool = false;
					exitBool = false;
				}
				else if (this->getSelectedItemIndex() == 1)
				{
					mainMenuBool = false;
					startBool = false;
					howToPlayBool = true;
					exitBool = false;
				}
				else
				{
					mainMenuBool = false;
					startBool = false;
					howToPlayBool = false;
					exitBool = true;
				}
			}
		}
	}
}

void MainMenu::render(sf::RenderWindow* window, bool& mainMenuBool)
{
	if (mainMenuBool)
	{
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			(*window).draw(this->menu[i]);
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
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex++;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}

int MainMenu::getSelectedItemIndex()
{
	return this->selectedItemIndex;
}