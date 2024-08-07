#include "Ball.hpp"

Ball::Ball(sf::Texture& texture, sf::RenderWindow* window, Paddle* paddle)
{
	this->window = window;
	this->paddle = paddle;
	this->texture = texture;
	this->radius = this->sprite.getGlobalBounds().width / 2;
	this->sprite.setTexture(texture);
	this->sprite.setScale(2.1f, 2.1f);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
	this->sprite.setPosition(1000.f, (*this->window).getSize().y - 80);
	this->speed = 8.f;
	this->velocity = { (-this->speed), (-this->speed) };
}

void Ball::update()
{
	this->sprite.setPosition((*this->paddle).x(), (*this->paddle).top() - this->radius);
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

void Ball::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}
sf::Vector2f Ball::getVelocity()
{
	return this->velocity;
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
	return this->sprite.getPosition().x - this->sprite.getGlobalBounds().width / 2;
}
float Ball::right()
{
	return this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
}
float Ball::top()
{
	return this->sprite.getPosition().y - this->sprite.getGlobalBounds().width / 2;
}
float Ball::bottom()
{
	return this->sprite.getPosition().y + this->sprite.getGlobalBounds().width / 2;
}




