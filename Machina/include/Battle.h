#ifndef BATTLE

//Generic includes
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

//Game specific includes
#include "Player.h"
#include "Monster.h"


class Battle
{
protected:
	Player _player;
	Monster _monster;

public:
	Battle();
	Battle(Player& player, Monster monster);
	~Battle();

	void start();

	Player& getPlayer();
	void setPlayer(Player& player);
	

};


#endif // 



