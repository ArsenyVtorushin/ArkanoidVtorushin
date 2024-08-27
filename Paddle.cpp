#include "Paddle.hpp"

Paddle::Paddle(sf::Texture* texture, sf::RenderWindow* window)
{
	this->window = window;
	this->HPMax = 3;
	this->HP = this->HPMax;
	this->texture = texture;
	this->sprite.setTexture(*texture);
	this->sprite.setOrigin(this->sprite.getTexture()->getSize().x * 0.5, this->sprite.getTexture()->getSize().y * 0.5);
	this->sprite.setPosition(1000.f, (*this->window).getSize().y - 80.f);
	this->sprite.setScale(3.f, 7.f);
}

void Paddle::update()
{
	this->sprite.setPosition(sf::Mouse::getPosition(*this->window).x, (*this->window).getSize().y - 50.f);

	if (this->left() <= 312.f)
	{
		this->sprite.setPosition(312.f + this->sprite.getGlobalBounds().width * 0.5, this->sprite.getPosition().y);
	}

	if (this->right() >= 1113.f)
	{
		this->sprite.setPosition(1113.f - this->sprite.getGlobalBounds().width * 0.5, this->sprite.getPosition().y);
	}
}

int Paddle::getHPMax()
{
	return this->HPMax;
}
int Paddle::getHP()
{
	return this->HP;
}
void Paddle::decreaseHP()
{
	this->HP--;
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
