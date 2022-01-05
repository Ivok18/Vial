#include "ManaObserver.h"



ManaObserver::ManaObserver()
{
	_battleActor = nullptr;
}

ManaObserver::ManaObserver(BattleActor* battleActor)
{
	_battleActor = battleActor;
}


void ManaObserver::update()
{
}
