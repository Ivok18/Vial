#include "Bow.h"

Bow::Bow()
{
	this->nameOfKingdom = "extasia";
	this->type = "bow";
	this->atk = 10;

	_lootTexture.loadFromFile("data/bowLootState.png");
	_inInventoryTexture.loadFromFile("data/bowInInventoryState.png");
	_onPlayerTexture.loadFromFile("data/bowOnPlayerState.png");


}

Bow::Bow(std::string nameOfKingdom_, std::string type_, int atk_)
{
	nameOfKingdom = nameOfKingdom_;
	type = type_;
	atk = atk_;
}

Bow::~Bow() = default;


std::string Bow::getNameOfKingdom()
{
	return nameOfKingdom;
}

void Bow::setNameOfKingdom(std::string newNameOfKingdom)
{
	nameOfKingdom = newNameOfKingdom;
}

void Bow::printNameOfKingdom()
{
	std::cout << atk << std::endl;
}

std::string Bow::getType()
{
	return type;
}

void Bow::setType(std::string newType)
{
	type = newType;
}

void Bow::printType()
{
	std::cout << type << std::endl;
}

int Bow::getAtk()
{
	return atk;
}

void Bow::setAtk(int newAtk)
{
	atk = newAtk;
}

void Bow::printAtk()
{
	std::cout << atk << std::endl;
}

sf::Sprite& Bow::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

sf::Texture& Bow::getLootTexture()
{
	// TODO: insérer une instruction return ici
	return _lootTexture;
}

sf::Texture& Bow::getInInventoryTexture()
{
	// TODO: insérer une instruction return ici
	return _inInventoryTexture;
}

sf::Texture& Bow::getOnPlayerTexture()
{
	// TODO: insérer une instruction return ici
	return _onPlayerTexture;
}

void Bow::Display(sf::RenderWindow& gameWindow)
{
	
	std::cout << type << std::endl;
	std::cout << "origin kingdom:" << nameOfKingdom << std::endl;
	std::cout << "it gives " << atk << " atk to whoever using it " << std::endl;
}
