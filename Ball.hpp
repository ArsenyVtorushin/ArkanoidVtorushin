#ifndef BALL_HPP
#define BALL_HPP
#include "Paddle.hpp"

class Ball
{
public:

	Ball(sf::Texture* texture, sf::RenderWindow* window, Paddle* paddle, unsigned int* levelNumberText_cooldown);

	void update();

	void setSpeed(float speed);
	float getSpeed();

	void setVelocityX(float speed);
	float getVelocityX();

	void setVelocityY(float speed);
	float getVelocityY();

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

	float speed;
	sf::Vector2f velocity;
	float radius;

	unsigned int* levelNumberText_cooldown;
};

#endif // !BALL_HPP



