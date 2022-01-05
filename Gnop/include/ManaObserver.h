#ifndef MANAOBSERVER
#define MANAOBSERVER

#include "BattleActor.h"
#include "Mana.h"


class ManaObserver
{
protected:
	
	BattleActor* _battleActor;
public:
	ManaObserver();
	ManaObserver(BattleActor* battleActor);
	~ManaObserver() = default;

	void update();
};

#endif


