#include "Sword_.h"

Sword_::Sword_()
{
	this->nameOfKingdom = "lumina";
	this->type = "sword";
	this->atk = 10;

	_lootTexture.loadFromFile("data/swordLootState.png");
	_inInventoryTexture.loadFromFile("data/swordInInventoryState.png");
	_onPlayerTexture.loadFromFile("data/swordOnPlayerState.png");

}

Sword_::Sword_(std::string nameOfKingdom_, std::string type_, int atk_)
{
	nameOfKingdom = nameOfKingdom_;
	type = type_;
	atk = atk_;
}

Sword_::~Sword_() = default;


std::string Sword_::getNameOfKingdom()
{
	return nameOfKingdom;
}

void Sword_::setNameOfKingdom(std::string newNameOfKingdom)
{
	nameOfKingdom = newNameOfKingdom;
}

void Sword_::printNameOfKingdom()
{
	

	std::cout << atk << std::endl;
}

std::string Sword_::getType()
{
	return type;
}

void Sword_::setType(std::string newType)
{
	type = newType;
}

void Sword_::printType()
{
	std::cout << type << std::endl;
}

int Sword_::getAtk()
{
	return atk;
}

void Sword_::setAtk(int newAtk)
{
	atk = newAtk;
}

void Sword_::printAtk()
{
	std::cout << atk << std::endl;
}

sf::Texture& Sword_::getLootTexture()
{
	return _lootTexture;
}

sf::Texture& Sword_::getInInventoryTexture()
{
	return _inInventoryTexture;
}

sf::Texture& Sword_::getOnPlayerTexture()
{
	return _onPlayerTexture;
}

Item* Sword_::getItemPtr()
{
	return this;
}



sf::Sprite& Sword_::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

void Sword_::Display(sf::RenderWindow& _gameWindow)
{
	_gameWindow.draw(_sprite);
}
