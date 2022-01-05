#ifndef SWORD
#define SWORD
#include "Weapon.h"

class Sword : public Weapon
{
protected:


public:
	Sword();
	Sword(std::string nameOfKingdom_, std::string type_, int atk);
	~Sword();

};


#endif


