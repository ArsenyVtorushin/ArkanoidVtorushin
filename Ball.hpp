#ifndef BALL_HPP
#define BALL_HPP
#include "Paddle.hpp"

class Ball
{
public:

	Ball(sf::Texture* texture, sf::RenderWindow* window, Paddle* paddle, unsigned int* levelNumberText_cooldown);

	void update();

	void setXSpeed(float speed);
	float getXSpeed();

	void setYSpeed(float speed);
	float getYSpeed();

	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

	sf::Texture* texture;
	sf::Sprite sprite;

private:

	sf::RenderWindow* window;
	Paddle* paddle;

	float xSpeed, ySpeed;
	sf::Vector2f velocity;
	float radius;

	unsigned int* levelNumberText_cooldown;
};

#endif // !BALL_HPP



