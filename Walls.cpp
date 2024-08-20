#include "Walls.hpp"

Walls::Walls(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(2.2f, 2.2f);
	this->sprite.setPosition(200.f, 0.f);

	this->leftBorder = 312.f;
	this->rightBorder = 1113.f;
	this->topBorder = 139.f;
}

float Walls::left()
{
	return this->leftBorder;
}
float Walls::right()
{
	return this->rightBorder;
}
float Walls::top()
{
	return this->topBorder;
}




