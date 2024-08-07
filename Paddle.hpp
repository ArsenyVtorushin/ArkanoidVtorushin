#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "Ball.hpp"

class Paddle
{
public:

	Paddle(sf::Texture& texture, sf::RenderWindow* window);
	
	void update();
	void NotCrossWalls(sf::Sprite& wall);

	float left();
	float right();
	float top();
	float bottom();

	sf::Texture texture;
	sf::Sprite sprite;

private:
	sf::RenderWindow* window;

	int HP;
	int HPMax;
	std::vector<float> xPositions;
};

#endif // !PADDLE_HPP


