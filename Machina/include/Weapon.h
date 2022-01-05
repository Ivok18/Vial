#ifndef WEAPON
#define WEAPON

#include "Item.h"
class Weapon : public Item
{
protected:
	std::string nameOfKingdom;
	std::string type;
	int atk;

	sf::Sprite _sprite;
	sf::Texture _lootTexture;
	sf::Texture _inInventoryTexture;
	sf::Texture _onPlayerTexture;

public:
	Weapon();
	Weapon(std::string nameOfKingdom_, std::string type_, int atk_ );
	~Weapon();

	std::string getNameOfKingdom() = 0;
	virtual void setNameOfKingdom(std::string newNameOfKingdom) = 0;
	virtual void printNameOfKingdom() = 0;

	virtual std::string getType() = 0;
	virtual void setType(std::string newType) = 0;
	virtual void printType() = 0;

	virtual int getAtk() = 0;
	virtual void setAtk(int newAtk) = 0;
	virtual void printAtk() = 0;

	virtual sf::Sprite& getSprite() = 0;
	virtual sf::Texture& getLootTexture() = 0;
	virtual sf::Texture& getInInventoryTexture() = 0;
	virtual sf::Texture& getOnPlayerTexture() = 0;

	virtual void Display(sf::RenderWindow& gameWindow) = 0;


};

#endif // !


