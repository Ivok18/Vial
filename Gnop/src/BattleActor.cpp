#include "BattleActor.h"

BattleActor::BattleActor()
{
	_manaPtr = &_mana;
	_magicAtk = 10;
}

BattleActor::BattleActor(float magicAtk)
{
	_manaPtr = &_mana;
	_magicAtk = magicAtk;
}
