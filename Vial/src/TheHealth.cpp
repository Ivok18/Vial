#include "TheHealth.h"

TheHealth::TheHealth()
{

}

TheHealth::TheHealth(float hp)
{
	_hp = hp;
}

float TheHealth::getMaxHp()
{
	return _maxHp;
}

void TheHealth::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

float TheHealth::getHp()
{
	return _hp;
}

void TheHealth::setHp(float hp)
{
	_hp = hp;
}