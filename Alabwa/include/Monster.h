#ifndef MONSTER
#define MONSTER

#include "Battle_Actor.h"

class Monster : public Battle_Actor
{
protected:
	//monster sprite
	sf::Texture* p_monster_texture;
	sf::Texture monster_texture;
	sf::Sprite monster_sprite;

	//health sprite
	sf::Texture health_bar_background_texture;
	sf::Texture* p_health_bar_background_texture;
	sf::Sprite health_bar_background_sprite;

	sf::Texture health_bar_texture;
	sf::Texture* p_health_bar_texture;
	sf::Sprite health_bar_sprite;

	//states
	bool has_evolved;

	//actions
	bool has_punched;
	bool has_taken_iron_shell;
	bool has_casted_eyesbeam;
	bool has_casted_pentagram_wall;
	bool is_victorious;
	bool is_standing;
	
public:
	Monster();
	Monster(Battle_Handler* battle_handler_, std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_);
	~Monster();
	
	void Update();
		void Update_Health_Sprite();
		void Update_Action_Sprite();
	

	void React_To(Battle_Actor* pointer_to_battle_actor_to_react_to);

	void Attack_Physically(Battle_Actor* target);
		void Punch(Battle_Actor* target);

	void Defend();
		void Get_Iron_Shell();
		
	void Cast_Attack_Spell(Battle_Actor* target);
		void Cast_Eyesbeam(Battle_Actor* target);

	void Cast_Res_Spell();
		void Cast_Pentagram_Wall();

	void Mutate();

	void Set_Pointer_To_Battle_Handler(Battle_Handler* new_pointer_);

	void Print_Name();

	std::string Get_Name();

	void Get_Damage(float damage_);

	bool Is_Alive();

	bool Is_Punching();
	void Print_Hp();

	int Get_Hp();

	float Get_Resistance();

	bool Is_Victorious();

	float Get_Mana();

	void Set_Texture(sf::Texture);

	sf::Texture Get_Texture();

	sf::Sprite Get_Sprite();

	void Draw(sf::RenderWindow& window);

	void Set_Is_Alive(bool boolean);

	void Set_Victory(bool boolean);

	void Set_Resistance(float res_);

	void Set_Hp(float hp_);

	void Set_Mana(float mana_);

	void Set_Default_Action(bool boolean);



	
};

#endif 