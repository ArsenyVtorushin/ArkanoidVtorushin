#include "Paddle.hpp"

Paddle::Paddle(sf::Texture& texture, sf::RenderWindow* window)
{
	this->window = window;
	this->HPMax = 3;
	this->HP = this->HPMax;
	this->texture = texture;
	this->sprite.setTexture(texture);
	this->sprite.setScale(2.1f, 2.1f);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
	this->sprite.setPosition(1000.f, (*this->window).getSize().y - 80);
	this->xPositions.push_back(this->sprite.getPosition().x);
}

void Paddle::update()
{
	this->sprite.setPosition(sf::Mouse::getPosition(*this->window).x, (*this->window).getSize().y - 80);
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
	return this->sprite.getPosition().x - this->sprite.getGlobalBounds().width / 2;
}
float Paddle::right()
{
	return this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
}
float Paddle::top()
{
	return this->sprite.getPosition().y - this->sprite.getGlobalBounds().width / 2;
}
float Paddle::bottom()
{
	return this->sprite.getPosition().y + this->sprite.getGlobalBounds().width / 2;
}
