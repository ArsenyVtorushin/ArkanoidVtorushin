#include "Brick.hpp"

Brick::Brick(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(1.6f, 1.5f);
}

float Brick::x()
{
	return this->sprite.getPosition().x;
}
float Brick::y()
{
	return this->sprite.getPosition().y;
}

float Brick::left()
{
	return this->x() - this->sprite.getTexture()->getSize().x * 0.5;
}
float Brick::right()
{
	return this->x() + this->sprite.getTexture()->getSize().x * 0.5;
}
float Brick::top()
{
	return this->y() - this->sprite.getTexture()->getSize().y * 0.5;
}
float Brick::bottom()
{
	return this->y() + this->sprite.getTexture()->getSize().y * 0.5;
}