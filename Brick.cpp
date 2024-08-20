#include "Brick.hpp"

Brick::Brick(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(1.6f, 1.5f);
}
