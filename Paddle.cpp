#include "Paddle.hpp"

Paddle::Paddle(sf::Texture* texture, sf::RenderWindow* window)
{
	this->window = window;
	this->HPMax = 3;
	this->HP = this->HPMax;
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setOrigin(this->sprite.getTexture()->getSize().x * 0.5, this->sprite.getTexture()->getSize().y * 0.5);
	this->sprite.setPosition(1000.f, (*this->window).getSize().y - 80.f);
	this->xPositions.push_back(this->sprite.getPosition().x);
}

void Paddle::update()
{
	this->sprite.setPosition(sf::Mouse::getPosition(*this->window).x, (*this->window).getSize().y - 50.f);
}

//cook this frickin function
//                     |
//                     V

void Paddle::NotCrossWalls(sf::Sprite& wall)
{
	this->xPositions.push_back(this->sprite.getPosition().x);

	if (this->sprite.getGlobalBounds().intersects(wall.getGlobalBounds()))
	{
		this->sprite.setPosition(this->xPositions[0], this->sprite.getPosition().y);
	}
	this->xPositions.erase(this->xPositions.begin());
}

float Paddle::x()
{
	return this->sprite.getPosition().x;
}
float Paddle::y()
{
	return this->sprite.getPosition().y;
}

float Paddle::left()
{
	return this->x() - this->sprite.getTexture()->getSize().x * 0.5;
}
float Paddle::right()
{
	return this->x() + this->sprite.getTexture()->getSize().x * 0.5;
}
float Paddle::top()
{
	return this->y() - this->sprite.getTexture()->getSize().y * 0.5;
}
float Paddle::bottom()
{
	return this->y() + this->sprite.getTexture()->getSize().y * 0.5;
}
