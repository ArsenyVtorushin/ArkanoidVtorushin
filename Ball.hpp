#ifndef BALL_HPP
#define BALL_HPP
#include "Walls.hpp"

class Ball
{
public:

	Ball(sf::Texture& texture);

	void update(sf::Sprite& paddle);

	void setSpeed(float speed);
	float getSpeed();

	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();

	float left();
	float right();
	float top();
	float bottom();

	sf::Texture texture;
	sf::Sprite sprite;

private:

	float speed;
	sf::Vector2f velocity;
};

#endif // !BALL_HPP



