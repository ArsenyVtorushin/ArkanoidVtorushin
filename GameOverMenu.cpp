#include "GameOverMenu.hpp"

GameOverMenu::GameOverMenu(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent, bool* gameOverMenuBool, bool* tryAgainBool, bool* exitGameOverMenuBool)
{
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->gameOverMenuBool = gameOverMenuBool;
	this->tryAgainBool = tryAgainBool;
	this->exitGameOverMenuBool = exitGameOverMenuBool;

	this->gameOverText.setString("Game Over");
	this->gameOverText.setScale(3.f, 3.f);
	this->gameOverText.setFont(*this->font);
	this->gameOverText.setOrigin(this->gameOverText.getLocalBounds().width * 0.5f, this->gameOverText.getLocalBounds().height * 0.5f);
	this->gameOverText.setPosition((*this->window).getSize().x * 0.5f, (*this->window).getSize().y * 0.5f - (*this->window).getSize().y * 0.5f * 0.5);

	this->menu[0].setString("Try Again");
	this->menu[0].setOutlineColor(sf::Color::Blue);
	this->menu[1].setString("Exit");
	this->menu[1].setOutlineColor(sf::Color::Black);

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

void GameOverMenu::update()
{
	if (*this->gameOverMenuBool)
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
					*this->gameOverMenuBool = false;
					*this->tryAgainBool = true;
					*this->exitGameOverMenuBool = false;

				}
				else
				{
					*this->gameOverMenuBool = false;
					*this->tryAgainBool = false;
					*this->exitGameOverMenuBool = true;
				}
			}
		}
	}
}
void GameOverMenu::render()
{
	if (*this->gameOverMenuBool)
	{
		(*this->window).draw(this->gameOverText);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			(*this->window).draw(this->menu[i]);
		}
	}
}

void GameOverMenu::MoveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex--;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}
void GameOverMenu::MoveDown()
{
	if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Black);
		this->selectedItemIndex++;
		this->menu[selectedItemIndex].setOutlineColor(sf::Color::Blue);
	}
}

int GameOverMenu::getSelectedItemIndex()
{
	return this->selectedItemIndex;
}
