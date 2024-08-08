#include "Walls.hpp"

Walls::Walls(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(2.2f, 2.2f);
	this->sprite.setPosition(200.f, 0.f);
}
