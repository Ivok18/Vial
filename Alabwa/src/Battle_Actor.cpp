#include "Battle_Actor.h"

bool Battle_Actor::operator==(Battle_Actor* other)
{
	return (other->name == other->name);
	
	
}

Battle_Actor::Battle_Actor()
{
	pointer_to_battle_handler = nullptr;
	MAX_HP = 100;
	MAX_MANA = 100;
	hp = 100;
	atk = 30;
	magic_atk = 10;
	mana = 10;
	resistance = 0.1;
	is_alive = true;
	//state = Battle_Actor_State::Does_Nothing;
}

Battle_Actor::Battle_Actor(Battle_Handler* battle_handler_,std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_)
{
	pointer_to_battle_handler = battle_handler_;
	MAX_HP = 100;
	MAX_MANA = 100;
	hp = hp_;
	atk = atk_;
	magic_atk = magic_atk_;
	mana = mana_;
	resistance = resistance_;
	is_alive = true;
	//state = Battle_Actor_State::Does_Nothing;
}

Battle_Actor::~Battle_Actor()
{
}


