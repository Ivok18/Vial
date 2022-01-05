#ifndef ITEM
#define ITEM
#include <iostream>
#include <SFML/Graphics.hpp>

class Item
{
protected:
	std::string nameOfKingdom;
	std::string type;

	sf::Sprite _sprite;

	

public:
	Item();
	Item(std::string type_);
	~Item();

	virtual std::string getNameOfKingdom() = 0;
	virtual void setNameOfKingdom(std::string newNameOfKingdom) = 0;
	virtual void printNameOfKingdom() = 0;

	virtual std::string getType() = 0;
	virtual void setType(std::string newType) = 0;
	virtual void printType() = 0;

	virtual sf::Sprite& getSprite() = 0;

	virtual void Display(sf::RenderWindow& gameWindow) = 0;
	
};

#endif