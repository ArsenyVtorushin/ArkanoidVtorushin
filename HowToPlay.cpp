#include "HowToPlay.hpp"

HowToPlay::HowToPlay(sf::Font* font, sf::RenderWindow* window, sf::Event* sfEvent)
{
	this->font = font;
	this->window = window;
	this->sfEvent = sfEvent;

	this->backBool = false;
	this->howToPlayBool = false;

	this->initText();
}

// Main functions

void HowToPlay::update()
{
	if (this->howToPlayBool)
	{
		if ((*this->sfEvent).type == sf::Event::KeyReleased && (*this->sfEvent).key.code == sf::Keyboard::Space)
		{
			this->backBool = true;
			this->howToPlayBool = false;
		}
	}
}
void HowToPlay::render()
{
	if (this->howToPlayBool)
	{
		(*this->window).draw(this->text);
		(*this->window).draw(this->back);
		(*this->window).draw(this->pressSpace);
	}
}

// Getters / Setters

void HowToPlay::setBackBool(bool backBool)
{
	this->backBool = backBool;
}
bool HowToPlay::getBackBool()
{
	return this->backBool;
}

void HowToPlay::setHowToPlayBool(bool howToPlayBool)
{
	this->howToPlayBool = howToPlayBool;
}
bool HowToPlay::getHowToPlayBool()
{
	return this->howToPlayBool;
}

void HowToPlay::initText()
{
	this->text.setFont(*font);
	this->text.setString("You have to destroy all of the bricks\nby bouncing off the Ball.\n\nUse the mouse to move the Paddle.\n\nUse the 'space' button to pause the game");
	this->text.setOrigin(this->text.getLocalBounds().width * 0.5, this->text.getLocalBounds().height * 0.5);
	this->text.setPosition(window->getSize().x * 0.5, window->getSize().y * 0.5);
	this->text.setScale(1.5f, 1.5f);

	this->back.setFont(*font);
	this->back.setString("Back");
	this->back.setOrigin(this->back.getLocalBounds().width * 0.5, this->back.getLocalBounds().height * 0.5);
	this->back.setPosition((*window).getSize().x * 0.5, (*window).getSize().y - 200.f);
	this->back.setScale(1.6f, 1.6f);
	this->back.setOutlineThickness(1.f);
	this->back.setOutlineColor(sf::Color::Blue);

	this->pressSpace.setFont(*font);
	this->pressSpace.setString("(press 'space')");
	this->pressSpace.setOrigin(this->pressSpace.getLocalBounds().width * 0.5, this->pressSpace.getLocalBounds().height * 0.5);
	this->pressSpace.setPosition((*window).getSize().x * 0.5, (*window).getSize().y - 140.f);
	this->pressSpace.setScale(0.8f, 0.8f);
	this->pressSpace.setFillColor(sf::Color(100, 200, 150));
}

