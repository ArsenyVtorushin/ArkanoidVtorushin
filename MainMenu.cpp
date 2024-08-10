#include "MainMenu.hpp"

MainMenu::MainMenu(sf::Font* font, sf::RenderWindow* window)
{
	this->window = window;
	this->font = font;
	
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

}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(this->menu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (true)
	{

	}
}

void MainMenu::MoveDown()
{

}
