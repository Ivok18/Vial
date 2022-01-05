#ifndef BATTLE_ACTOR
#define BATTLE_ACTOR

#include "Entity.h"

class Battle_Handler;

class Battle_Actor : public Entity
{
protected:
	Battle_Handler* pointer_to_battle_handler;
	float MAX_HP;
	float MAX_MANA;
	float hp;
	float atk;
	float magic_atk;
	float mana;
	float resistance;
	bool is_alive;
	
	//enum class Battle_Actor_State { Does_Nothing, Active };
	//Battle_Actor_State state;

public:
	Battle_Actor();
	Battle_Actor(Battle_Handler* battle_handler_, std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_);
	~Battle_Actor();

	virtual void Attack_Physically(Battle_Actor* target) = 0;
	virtual void Defend() = 0;
	virtual void Cast_Attack_Spell(Battle_Actor* target) = 0;
	virtual void Cast_Res_Spell() = 0;

	bool operator==(Battle_Actor* other);

	virtual void Set_Pointer_To_Battle_Handler(Battle_Handler* new_pointer_) = 0;

	virtual void Print_Name() = 0;
	virtual std::string Get_Name() = 0;

	virtual void Print_Hp() = 0;
	virtual int Get_Hp() = 0;
	
	virtual void Get_Damage(float damage_) = 0;

	virtual bool Is_Alive() = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;

	virtual void Set_Texture(sf::Texture texture) = 0;
	virtual sf::Texture Get_Texture() = 0;

	virtual sf::Sprite Get_Sprite() = 0;
	virtual bool Is_Punching() = 0;

	virtual void Update() = 0;
	
};

#endif
