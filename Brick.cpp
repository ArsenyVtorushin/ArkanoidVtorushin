#include "Brick.hpp"

Brick::Brick(sf::Texture* texture, sf::RenderWindow* window)
{
	this->window = window;

	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(2.f, 2.f);
}
