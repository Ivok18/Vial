#include "Damageable.h"

Damageable::Damageable()
{
	_healthPtr = &_health;
	_atk = 10.f;
}

Damageable::Damageable(float atk)
{
	_healthPtr = &_health;
	_atk = atk;
}
