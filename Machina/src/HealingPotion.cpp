#include "HealingPotion.h"

HealingPotion::HealingPotion()
{
	nameOfKingdom = "dicemania";
	type  = "healing Potion";
	hpToGive = 10;
	_lootTexture.loadFromFile("data/healingPotionLootState.png");
}

HealingPotion::HealingPotion(std::string type_, int hpToGive_)
{
	nameOfKingdom = "dicemania";
	type = type_;
	hpToGive = hpToGive_;
}

HealingPotion::~HealingPotion()
{
}

std::string HealingPotion::getNameOfKingdom()
{
	return nameOfKingdom;
}

void HealingPotion::setNameOfKingdom(std::string newNameOfKingdom)
{
	nameOfKingdom = newNameOfKingdom;
}

void HealingPotion::printNameOfKingdom()
{
	std::cout << nameOfKingdom << std::endl;
}

std::string HealingPotion::getType()
{
	return type;
}

void HealingPotion::setType(std::string newType)
{
	type = newType;
}

void HealingPotion::printType()
{
	std::cout << type << std::endl;
}


int HealingPotion::getHpToGive()
{
	return hpToGive;
}

void HealingPotion::setHpToGive(int newHpToGive)
{
	hpToGive = newHpToGive;
}

void HealingPotion::printHpToGive()
{
	std::cout << hpToGive << std::endl;
}

sf::Sprite& HealingPotion::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

sf::Texture& HealingPotion::getLootTexture()
{
	// TODO: insérer une instruction return ici
	return _lootTexture;
}

void HealingPotion::Display(sf::RenderWindow& gameWindow)
{

	//
	

	std::cout << type << std::endl;
	std::cout << "origin kingdom:" << nameOfKingdom << std::endl;
	std::cout << "this potion gives " << hpToGive << "hp to player" << std::endl;
}


