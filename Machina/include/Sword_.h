#ifndef SWORD_
#define SWORD_

#include "Weapon.h"

class Sword_ : public Weapon
{
protected:

public:
	Sword_();
	Sword_(std::string nameOfKingdom_, std::string type_, int atk_);
	~Sword_();

	std::string getNameOfKingdom() override;
	void setNameOfKingdom(std::string newNameOfKingdom) override;
	void printNameOfKingdom() override;

	std::string getType() override;
	void setType(std::string newType) override;
	void printType() override;

	int getAtk() override;
	void setAtk(int newAtk) override;
	void printAtk() override;

	sf::Sprite& getSprite();
	sf::Texture& getLootTexture();
	sf::Texture& getInInventoryTexture();
	sf::Texture& getOnPlayerTexture();

	Item* getItemPtr();
	

	void Display(sf::RenderWindow& _gameWindow) override;

};

#endif


