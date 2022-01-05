#ifndef BOW
#define BOW

#include "Weapon.h"
class Bow : public Weapon
{
protected:

public:
	Bow();
	Bow(std::string nameOfKingdom_, std::string type_, int atk_);
	~Bow();

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


