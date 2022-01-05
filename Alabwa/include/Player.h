#ifndef PLAYER
#define PLAYER

#include "Battle_Actor.h"


class Player : public Battle_Actor
{
protected:
	//player sprite
	sf::Texture player_texture;
	sf::Texture* p_player_texture;
	sf::Sprite player_sprite;

	//health sprite
	sf::Texture health_bar_background_texture;
	sf::Texture* p_health_bar_background_texture;
	sf::Sprite health_bar_background_sprite;

	sf::Texture health_bar_texture;
	sf::Texture* p_health_bar_texture;
	sf::Sprite health_bar_sprite;

	bool display_hover_of_hp_lost;
	//bool display_hover_of_hp_gain;

	//mana sprite
	sf::Texture mana_bar_background_texture;
	sf::Texture* p_mana_bar_background_texture;
	sf::Sprite mana_bar_background_sprite;

	sf::Texture mana_bar_texture;
	sf::Texture* p_mana_bar_texture;
	sf::Sprite mana_bar_sprite;

	//sprite of hover of mana cost
	sf::Texture texture_of_hover_of_mana_cost;
	sf::Texture* p_texture_of_hover_of_mana_cost;
	sf::Sprite sprite_of_hover_of_mana_cost;

	//sprite of hover of hp lost
	sf::Texture texture_of_hover_of_hp_lost;
	sf::Texture* p_texture_of_hover_of_hp_lost;
	sf::Sprite sprite_of_hover_of_hp_lost;

	//sprite of hover of hp gain
	//sf::Texture texture_of_hover_of_hp_gain;
	//sf::Texture* p_texture_of_hover_of_hp_gain;
	//sf::Sprite sprite_of_hover_of_hp_gain;

	//res sprite
	sf::Texture texture_of_background_of_resistance_bar;
	sf::Texture* p_texture_of_background_of_resistance_bar;
	sf::Sprite sprite_of_background_of_resistance_bar;

	sf::Texture texture_of_resistance_bar;
	sf::Texture* p_texture_of_resistance_bar;;
	sf::Sprite sprite_of_resistance_bar;

	//sprite of hover of res gain
	sf::Texture texture_of_hover_of_res_gain;
	sf::Texture* p_texture_of_hover_of_res_gain;
	sf::Sprite sprite_of_hover_of_res_gain;
	
	bool display_hover_of_res_gain_with_res_spell;
	bool display_hover_of_res_gain_with_healing_spell;

	//user action
	bool mouse_has_entered_attack_spell_button;
	bool mouse_has_entered_resistance_spell_button;
	bool mouse_has_entered_healing_spell_button;


	//actions
	bool is_punching;
	bool is_tightening_abs;
	bool is_meditating;
	bool is_casting_beam;
	bool is_casting_res_spell;
	bool has_used_too_much_mana;
	bool is_victorious;
	bool is_standing;

public:
	Player();
	Player(Battle_Handler* battle_handler_, std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_);
	~Player();
	void Update();
		void Update_Res_Sprite();
		void Update_Hover_Of_Res_Gain_Sprite();
		void Update_Health_Sprite();
		void Update_Mana_Sprite();
		void Update_Hover_Of_Hp_Lost_Sprite();
		void Update_Hover_Of_Mana_Cost_Sprite();
		void Update_Action_Sprite();
		
	void Attack_Physically(Battle_Actor* target);
		void Punch(Battle_Actor* target);

	void Defend();
		void Tighten_Abs();

	void Cast_Attack_Spell(Battle_Actor* target);
		void Cast_Beam(Battle_Actor* target);

	void Cast_Res_Spell();
		void Cast_Bubble_Armor();

	void Heal();
		void Meditate();

	void Set_Pointer_To_Battle_Handler(Battle_Handler* new_pointer_);

	void Print_Name();

	void Get_Damage(float damage_);
	
	std::string Get_Name();

	bool Is_Alive();

	bool Is_Victorious();

	bool Is_Punching();

	bool Is_Casting_Beam();

	

	void Print_Hp();

	int Get_Hp();

	int Get_Mana();
	float Get_MAX_MANA();

	float Get_Resistance();

	sf::Texture Get_Texture();

	sf::Texture Get_Mana_Bar_Background_Texture();

	sf::Sprite Get_Sprite();

	sf::Sprite Get_Mana_Bar_Background_Sprite();

	sf::Sprite Get_Sprite_Of_Hover_Of_Mana_Cost();

	void Set_Texture(sf::Texture texture);

	void Draw(sf::RenderWindow& window);
	

	void Set_Visible_Hover_Of_Mana_Cost_Of_Attack_Spell(bool boolean);

	void Set_Visible_Hover_Of_Mana_Cost_Of_Resistance_Spell(bool boolean);

	void Set_Visible_Hover_Of_Mana_Cost_Of_Healing_Spell(bool boolean);

	void Set_Visible_Hover_Of_Hp_Lost_Sprite(bool boolean);

	void Set_Visible_Hover_Of_Res_Gain_Of_Res_Spell(bool boolean);

	void Set_Visible_Hover_Of_Res_Gain_Of_Healing_Spell(bool boolean);

	//void Set_Visible_Hover_Of_Hp_Gain_Of_Healing_Spell(bool boolean);

	void Set_Victory(bool boolean);

	void Set_Is_Alive(bool boolean);

	void Set_Resistance(float res);
	
	void Set_Hp(float hp_);

	void Set_Mana(float mana_);

	void Set_Default_Action(bool boolean);
	




};
#endif 

