#include "Epic.h"
#include "Bow.h"

Epic::Epic()
{
	this->nameOfKingdom = "epikia";
	this->type = "epik";
	this->atk = 10;

	_lootTexture.loadFromFile("data/epicHammerLootState.png");
	_inInventoryTexture.loadFromFile("data/epicHammerInInventoryState.png");
	_onPlayerTexture.loadFromFile("data/epicHammerOnPlayerState.png");
}

Epic::Epic(std::string nameOfKingdom_, std::string type_, int atk_)
{
	nameOfKingdom = nameOfKingdom_;
	type = type_;
	atk = atk_;
}

Epic::~Epic() = default;


std::string Epic::getNameOfKingdom()
{
	return nameOfKingdom;
}

void Epic::setNameOfKingdom(std::string newNameOfKingdom)
{
	nameOfKingdom = newNameOfKingdom;
}

void Epic::printNameOfKingdom()
{
	std::cout << atk << std::endl;
}

std::string Epic::getType()
{
	return type;
}

void Epic::setType(std::string newType)
{
	type = newType;
}

void Epic::printType()
{
	std::cout << type << std::endl;
}

int Epic::getAtk()
{
	return atk;
}

void Epic::setAtk(int newAtk)
{
	atk = newAtk;
}

void Epic::printAtk()
{
	std::cout << atk << std::endl;
}

sf::Sprite& Epic::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

sf::Texture& Epic::getLootTexture()
{
	// TODO: insérer une instruction return ici
	return _lootTexture;
}

sf::Texture& Epic::getInInventoryTexture()
{
	// TODO: insérer une instruction return ici
	return _inInventoryTexture;
}

sf::Texture& Epic::getOnPlayerTexture()
{
	// TODO: insérer une instruction return ici
	return _onPlayerTexture;
}

void Epic::Display(sf::RenderWindow& gameWindow)
{
	

	std::cout << type << std::endl;
	std::cout << "origin kingdom:" << nameOfKingdom << std::endl;
	std::cout << "it gives " << atk << " atk to whoever using it " << std::endl;
}
