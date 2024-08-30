#include "Heart.hpp"

Heart::Heart(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(4.f, 4.f);
}
