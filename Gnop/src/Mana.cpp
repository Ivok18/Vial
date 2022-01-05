#include "Mana.h"

Mana::Mana()
{
	_mana = 100.f;
	_maxMana = 100.f;
}

Mana::Mana(float mana)
{
	_mana = mana;
	_maxMana = 100.f;
}

float Mana::getMana()
{
	return _mana;
}

void Mana::setMana(float mana)
{
	_mana = mana;
}

float Mana::getMaxMana()
{
	return 0.0f;
}

void Mana::setMaxMana()
{
	//TODO
}
