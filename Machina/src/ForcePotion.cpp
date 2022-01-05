#include "ForcePotion.h"

ForcePotion::ForcePotion()
{
	nameOfKingdom = "dalala";
	type = "force potion";
	atkToGive = 10;
	_lootTexture.loadFromFile("data/forcePotionLootState.png");
}

ForcePotion::ForcePotion(std::string type_, int atkToGive_)
{
	nameOfKingdom = "dalala";
	type = type_;
	atkToGive = atkToGive_;
}

ForcePotion::~ForcePotion()
{
}

std::string ForcePotion::getNameOfKingdom()
{
	return nameOfKingdom;
}

void ForcePotion::setNameOfKingdom(std::string newNameOfKingdom)
{
	nameOfKingdom = newNameOfKingdom;
}

void ForcePotion::printNameOfKingdom()
{
	std::cout << nameOfKingdom << std::endl;
}

std::string ForcePotion::getType()
{
	return type;
}

void ForcePotion::setType(std::string newType)
{
	type = newType;
}

void ForcePotion::printType()
{
	std::cout << type << std::endl;
}

int ForcePotion::getAtkToGive()
{
	return atkToGive;
}

void ForcePotion::setAtkToGive(int newAtkToGive)
{
	atkToGive = newAtkToGive;
}

void ForcePotion::printAtkToGive()
{
	std::cout << atkToGive << std::endl;
}

sf::Sprite& ForcePotion::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

sf::Texture& ForcePotion::getLootTexture()
{
	// TODO: insérer une instruction return ici
	return _lootTexture;
	
}

void ForcePotion::Display(sf::RenderWindow& gameWindow)
{
	

	std::cout << type << std::endl;
	std::cout << "origin kingdom:" << nameOfKingdom << std::endl;
	std::cout << "this potion gives " << atkToGive << " atk to player" << std::endl;
}
