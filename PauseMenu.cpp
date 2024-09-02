#include "PauseMenu.hpp"

PauseMenu::PauseMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent)
{
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->pauseMenuBool = false;
	this->continueBool = false;
	this->exitBool = false;

	this->pauseText.setString("Paused");
	this->pauseText.setScale(3.f, 3.f);
	this->pauseText.setFont(*this->font);
	this->pauseText.setOrigin(this->pauseText.getLocalBounds().width * 0.5f, this->pauseText.getLocalBounds().height * 0.5f);
	this->pauseText.setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f - (*this->window).getSize().y * 0.5f * 0.5);

	this->menu[0].setString("Continue");
	this->menu[0].setOutlineColor(sf::Color::Blue);
	this->menu[1].setString("Exit to Menu");
	this->menu[1].setOutlineColor(sf::Color::Black);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_PAUSE; i++)
	{
		this->menu[i].setOutlineThickness(1.f);
		this->menu[i].setScale(1.5f, 1.5f);
		this->menu[i].setFont(*this->font);
		this->menu[i].setOrigin(this->menu[i].getLocalBounds().width * 0.5f, this->menu[i].getLocalBounds().height * 0.5f);
		this->menu[i].setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f + (*this->window).getSize().y * 0.5f / (MAX_NUMBER_OF_ITEMS_PAUSE + 1) * (i + 1.f));
	}

	this->selectedItemIndex = 0;
}

//Functions

void PauseMenu::update()
{
	if (this->pauseMenuBool)
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
					this->pauseMenuBool = false;
					this->continueBool = true;
					this->exitBool = false;
				}
				else
				{
					this->pauseMenuBool = false;
					this->continueBool = false;
					this->exitBool = true;
				}
			}
		}
	}
}
void PauseMenu::render()
{
	if (this->pauseMenuBool)
	{
		(*this->window).draw(this->pauseText);

		for (int i = 0; i < MAX_NUMBER_OF_ITEMS_PAUSE; i++)
		{
			(*this->window).draw(this->menu[i]);
		}
	}
}

void PauseMenu::MoveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex--;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}
void PauseMenu::MoveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_PAUSE)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex++;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}

//Getters/Setters

void PauseMenu::setPauseMenuBool(bool pauseMenuBool)
{
	this->pauseMenuBool = pauseMenuBool;
}
bool PauseMenu::getPauseMenuBool()
{
	return this->pauseMenuBool;
}

void PauseMenu::setContinueBool(bool continueBool)
{
	this->continueBool = continueBool;
}
bool PauseMenu::getContinueBool()
{
	return this->continueBool;
}

void PauseMenu::setExitBool(bool exitBool)
{
	this->exitBool = exitBool;
}
bool PauseMenu::getExitBool()
{
	return this->exitBool;
}