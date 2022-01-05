#include "Weapon.h"

Weapon::Weapon()
{
	this->nameOfKingdom = "deikmos";
	this->type = "weapon";
	this->atk = 10;
}

Weapon::Weapon(std::string nameOfKingdom_, std::string type_, int atk_)
{
	nameOfKingdom = nameOfKingdom_;
	type = type_;
	atk = atk_;
}

Weapon::~Weapon()
{
}

