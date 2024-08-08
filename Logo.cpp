#include "Logo.hpp"

Logo::Logo(sf::Texture* texture, sf::RenderWindow* window)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(4.f, 4.f);
	this->sprite.setPosition((*window).getSize().x / 2 + 330, 0);
}
