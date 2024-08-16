#include "HowToPlay.hpp"

HowToPlay::HowToPlay(sf::Font* font, sf::RenderWindow* window)
{
	this->font = font;
	this->window = window;

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
	this->pressSpace.setScale(1.f, 1.f);
}

void HowToPlay::update(sf::Event& sfEvent, bool& howToPlay, bool& mainMenuBool)
{
	if (howToPlay)
	{
		if (sfEvent.type == sf::Event::KeyReleased && sfEvent.key.code == sf::Keyboard::Space)
		{
			howToPlay = false;
			mainMenuBool = true;
		}
	}
}

// why isnt it working? maybe its that the KeyReleased/Return thing in MainMenu
// is the same as the KeyReleased/Return thing in here (update) 
// upd: YES

void HowToPlay::render(sf::RenderWindow* window, bool& howToPlay, bool& mainMenuBool)
{
	if (howToPlay)
	{
		(*window).draw(this->text);
		(*window).draw(this->back);
		(*window).draw(this->pressSpace);
	}
}

