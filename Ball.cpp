#include "Ball.hpp"

Ball::Ball(sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(texture);
	this->sprite.setScale(2.1f, 2.1f);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
	this->speed = 8.f;
	this->velocity = { (-this->speed), (-this->speed) };
}

void Ball::update(sf::Sprite& paddle)
{
	this->sprite.setPosition(paddle.getPosition().x, paddle.getPosition().y + this->sprite.getGlobalBounds().height);
}

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




