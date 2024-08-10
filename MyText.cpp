#include "MyText.hpp"

MyText::MyText(sf::Font* font, std::string string, sf::RenderWindow* window)
{
	this->window = window;
	this->font = *font;
	this->text.setFont(*font);
	this->text.setString(string);
	this->text.setScale(1.5f, 1.5f);
}
