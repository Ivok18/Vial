#ifndef ONEVERSUSMUCH
#define ONEVERSUSMUCH
//Generic includes
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

//Game specific includes
#include "Player.h"
#include "Monster.h"

class OneVersusMuch
{
	protected:
		Player _player;
		std::vector<Monster> _enemies;

	public:
		OneVersusMuch();
		OneVersusMuch(Player& player, std::vector<Monster>& monsters);
		~OneVersusMuch() = default;

		void start();

		Player& getPlayer();
		void setPlayer(Player& player);

		std::vector<Monster>& getEnemies();
		void setEnemies(std::vector<Monster>& enemies);
};

#endif


