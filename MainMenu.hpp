#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "HowToPlay.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
public:

	MainMenu(sf::Font* font, sf::RenderWindow* window);
	~MainMenu();

	void update(sf::Event& sfEvent);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int getSelectedItemIndex();

	bool getStart();
	bool getHowToPlay();
	bool getExit();


private:

	int selectedItemIndex;
	sf::Font* font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RenderWindow* window;
	HowToPlay* instructions;

	bool start, howToPlay, exit;
};

#endif // !MAINMENU_HPP



