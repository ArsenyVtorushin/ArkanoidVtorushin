#include "Ball.hpp"

Ball::Ball(sf::Texture* texture, sf::RenderWindow* window, Paddle* paddle, unsigned int* levelNumberText_cooldown)
{
	this->window = window;
	this->paddle = paddle;
	this->texture = texture;

	this->sprite.setTexture(*texture);
	this->sprite.setScale(1.2f, 1.2f);
	this->sprite.setOrigin(this->sprite.getTexture()->getSize().x * 0.5f, this->sprite.getTexture()->getSize().y * 0.5f);

	this->sprite.setPosition((*this->paddle).x(), (*this->paddle).top() - this->radius - 5);
	this->radius = this->sprite.getTexture()->getSize().x * 0.5f;
	this->speed = 9.f;
	this->velocity = { -(this->speed), -(this->speed) };

	this->levelNumberText_cooldown = levelNumberText_cooldown;
}

void Ball::update()
{
	if (*this->levelNumberText_cooldown > 0)
	{
		this->sprite.setPosition((*this->paddle).x(), (*this->paddle).top() - this->radius - 5);
	}
	else
	{
		this->sprite.move(this->velocity);
	}
}

//Getters / Setters

void Ball::setSpeed(float speed)
{
	this->speed = speed;
}
float Ball::getSpeed()
{
	return this->speed;
}

void Ball::setVelocityX(float speed)
{
	this->velocity.x = speed;
}
float Ball::getVelocityX()
{
	return this->velocity.x;
}

void Ball::setVelocityY(float speed)
{
	this->velocity.y = speed;
}
float Ball::getVelocityY()
{
	return this->velocity.y;
}

//Additional functions

float Ball::x()
{
	return this->sprite.getPosition().x;
}
float Ball::y()
{
	return this->sprite.getPosition().y;
}
float Ball::left()
{
	return this->sprite.getPosition().x - this->sprite.getTexture()->getSize().x * 0.5;
}
float Ball::right()
{
	return this->sprite.getPosition().x + this->sprite.getTexture()->getSize().x * 0.5;
}
float Ball::top()
{
	return this->sprite.getPosition().y - this->sprite.getTexture()->getSize().y * 0.5;
}
float Ball::bottom()
{
	return this->sprite.getPosition().y + this->sprite.getTexture()->getSize().y * 0.5;
}




