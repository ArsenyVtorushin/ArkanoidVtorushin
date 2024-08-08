#include "Heart.hpp"

Heart::Heart(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(3.5f, 3.5f);
}
