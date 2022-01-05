#include "Health.h"
#include "HealthObserver.h"


Health::Health()
{
	_hp = 0;
	_maxHp = 0;
	_baseMaxHp = 0;
}

Health::Health(float hp)
{
	_hp = hp;
	_maxHp = 100.f;
}

float Health::getHp()
{
	return _hp;
}

void Health::setHp(float hp)
{
	_hp = hp;
}

float Health::getMaxHp()
{
	return _maxHp;
}

void Health::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

float Health::getBaseMaxHp()
{
	return _baseMaxHp;
}

void Health::setBaseMaxHp(float base)
{
	_baseMaxHp = base;
}

