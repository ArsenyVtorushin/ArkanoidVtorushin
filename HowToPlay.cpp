#include "HowToPlay.hpp"

HowToPlay::HowToPlay(sf::Font* font, sf::RenderWindow* window)
{
	this->font = font;
	this->window = window;

	this->text.setFont(*font);
	this->text.setString("You have to destroy all of the bricks\nby bouncing off the Ball\nUse the mouse to move the Paddle\nUse the 'space' button to pause the game");
	this->text.setOrigin(this->text.getLocalBounds().width * 0.5, this->text.getLocalBounds().height * 0.5);
	this->text.setScale(1.f, 1.f);

	this->back.setFont(*font);
	this->back.setString("Back");
	this->back.setOrigin(this->back.getLocalBounds().width * 0.5, this->back.getLocalBounds().height * 0.5);
	this->back.setPosition((*window).getSize().x * 0.5, (*window).getSize().y - 200.f);
	this->back.setScale(1.5f, 1.5f);
	this->back.setOutlineThickness(1.f);
	this->back.setOutlineColor(sf::Color::Blue);
}

void HowToPlay::update(sf::Event& sfEvent, bool& howToPlay, bool& mainMenuBool)
{
	if (howToPlay)
	{
		if (sfEvent.type == sf::Event::KeyReleased && sfEvent.key.code == sf::Keyboard::Return)
		{
			howToPlay = false;
			mainMenuBool = true;
		}
	}
}

// why isnt it working? maybe its that the KeyReleased/Return thing in MainMenu
// is the same as the KeyReleased/Return thing in here (update)

void HowToPlay::render(sf::RenderWindow* window, bool& howToPlay, bool& mainMenuBool)
{
	if (howToPlay)
	{
		(*window).draw(this->text);
		(*window).draw(this->back);
	}
}

sf::Text HowToPlay::getText()
{
	return this->text;
}
