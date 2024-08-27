#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "Walls.hpp"

class Paddle
{
public:

	Paddle(sf::Texture* texture, sf::RenderWindow* window);
	
	void update();

	int getHPMax();
	int getHP();
	void decreaseHP();

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

	unsigned int HP;
	int HPMax;
};

#endif // !PADDLE_HPP


