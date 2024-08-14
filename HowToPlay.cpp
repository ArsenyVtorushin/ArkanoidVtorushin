#include "HowToPlay.hpp"

HowToPlay::HowToPlay(sf::Font* font, sf::RenderWindow* window)
{
	this->font = font;
	this->window = window;

	this->text.setFont(*font);
	this->text.setString("You have to destroy all of the bricks\nby bouncing off the Ball\nUse the mouse to move the Paddle\nUse the 'space' button to pause the game");
	this->text.setScale(0.3f, 0.3f);
}
