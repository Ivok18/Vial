#ifndef EPIC
#define  EPIC

#include "Weapon.h"
class Epic : public Weapon
{
protected:

public:
	Epic();
	Epic(std::string nameOfKingdom_, std::string type_, int atk_);
	~Epic();

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

	void Display(sf::RenderWindow& gameWindow) override;

};

#endif


