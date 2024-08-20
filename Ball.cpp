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
	this->xSpeed = -9.f;
	this->ySpeed = -9.f;
	this->velocity = { this->xSpeed, -this->ySpeed };

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
		if (this->left() <= 312)
		{
			this->setXSpeed(-(this->getXSpeed()));
		}
		
		if (this->top() <= 139)
		{
			this->setYSpeed(-(this->getYSpeed()));
		}

		if (this->right() >= 1113)
		{
			this->setXSpeed(-(this->getXSpeed()));
		}

		if (this->bottom() >= this->paddle->top())
		{
			this->setYSpeed(-(this->getYSpeed()));
		}
		
		this->setVelocity({ this->xSpeed, this->ySpeed });
		this->sprite.move(this->velocity);
	}
}

//Getters / Setters

void Ball::setXSpeed(float speed)
{
	this->xSpeed = speed;
}
float Ball::getXSpeed()
{
	return this->xSpeed;
}

void Ball::setYSpeed(float speed)
{
	this->ySpeed = speed;
}
float Ball::getYSpeed()
{
	return this->ySpeed;
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




