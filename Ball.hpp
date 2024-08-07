#ifndef BALL_HPP
#define BALL_HPP
#include "Walls.hpp"

class Ball
{
public:

	Ball(sf::Texture& texture, sf::RenderWindow* window, Paddle* paddle);

	void update();

	void setSpeed(float speed);
	float getSpeed();

	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

	sf::Texture texture;
	sf::Sprite sprite;

private:

	sf::RenderWindow* window;
	Paddle* paddle;

	float speed;
	sf::Vector2f velocity;
	float radius;
};

#endif // !BALL_HPP



