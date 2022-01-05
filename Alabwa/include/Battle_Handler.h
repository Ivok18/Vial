#ifndef BATTLE_HANDLER
#define BATTLE_HANDLER

#include "Player.h"
#include "Monster.h"
//#include <conio.h>

class Battle_Actor;

class Battle_Handler
{
protected:
	std::string name;
	Player* player;
	Monster* monster;
	Battle_Actor* active_battle_actor;
	sf::Event event;
	//enum class Battle_Handler_State { Waiting_For_Player, Busy };	
	//Battle_Handler_State state;
	

public:
	Battle_Handler();
	Battle_Handler(Player* player_, Monster* monster_, Battle_Actor* active_battle_actor_);
	~Battle_Handler();
	void Set_Active_Battle_Actor(Battle_Actor* active_actor_);
	void Start_Battle();
	Battle_Actor* Get_Pointer_To_Active_Battle_Actor();
	Player* Get_Pointer_To_Player();
	Monster* Get_Pointer_To_Monster();
	bool Process_Events(sf::RenderWindow& window);
	sf::Event Get_Event();
	
};

#endif