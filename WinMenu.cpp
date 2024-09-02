#include "WinMenu.hpp"

WinMenu::WinMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent)
{
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->winMenuBool = false;
	this->playAgainBool = false;
	this->exitBool = false;

	this->youWinText.setString("You win!");
	this->youWinText.setScale(3.f, 3.f);
	this->youWinText.setFont(*this->font);
	this->youWinText.setOrigin(this->youWinText.getLocalBounds().width * 0.5f, this->youWinText.getLocalBounds().height * 0.5f);
	this->youWinText.setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f - (*this->window).getSize().y * 0.5f * 0.5);

	this->menu[0].setString("Play Again");
	this->menu[0].setOutlineColor(sf::Color::Blue);
	this->menu[1].setString("Exit");
	this->menu[1].setOutlineColor(sf::Color::Black);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_WINMENU; i++)
	{
		this->menu[i].setOutlineThickness(1.f);
		this->menu[i].setScale(1.5f, 1.5f);
		this->menu[i].setFont(*this->font);
		this->menu[i].setOrigin(this->menu[i].getLocalBounds().width * 0.5f, this->menu[i].getLocalBounds().height * 0.5f);
		this->menu[i].setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f + (*this->window).getSize().y * 0.5f / (MAX_NUMBER_OF_ITEMS_WINMENU + 1) * (i + 1.f));
	}

	this->selectedItemIndex = 0;
}

// Functions

void WinMenu::update()
{
	if (this->winMenuBool)
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
					this->winMenuBool = false;
					this->playAgainBool = true;
					this->exitBool = false;
				}
				else
				{
					this->winMenuBool = false;
					this->playAgainBool = false;
					this->exitBool = true;
				}
			}
		}
	}
}
void WinMenu::render()
{
	if (this->winMenuBool)
	{
		(*this->window).draw(this->youWinText);

		for (int i = 0; i < MAX_NUMBER_OF_ITEMS_WINMENU; i++)
		{
			(*this->window).draw(this->menu[i]);
		}
	}
}

void WinMenu::MoveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex--;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}
void WinMenu::MoveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_WINMENU)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex++;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}

// Getters / Setters

void WinMenu::setWinMenuBool(bool winMenuBool)
{
	this->winMenuBool = winMenuBool;
}
bool WinMenu::getWinMenuBool()
{
	return this->winMenuBool;
}

void WinMenu::setPlayAgainBool(bool playAgainBool)
{
	this->playAgainBool = playAgainBool;
}
bool WinMenu::getPlayAgainBool()
{
	return this->playAgainBool;
}

void WinMenu::setExitBool(bool exitBool)
{
	this->exitBool = exitBool;
}
bool WinMenu::getExitBool()
{
	return this->exitBool;
}
