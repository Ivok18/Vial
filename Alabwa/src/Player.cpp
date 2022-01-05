#include "Player.h"
Player::Player()
{
	name = "Player";
	hp = 100;
	atk = 40;
	magic_atk = 50;
	mana = 100;
	resistance = 0.1;

	
	//health sprite
	health_bar_texture.loadFromFile("data/Images/health_bar.png");
	p_health_bar_texture = &health_bar_texture;
	health_bar_sprite.setTexture(*p_health_bar_texture);
	health_bar_sprite.setPosition(100, 60);

	
	health_bar_background_texture.loadFromFile("data/Images/health_bar_background_player.png");
	p_health_bar_background_texture = &health_bar_background_texture;
	health_bar_background_sprite.setTexture(*p_health_bar_background_texture);
	health_bar_background_sprite.setPosition(100, 60);

	//hover of hp lost sprite
	texture_of_hover_of_hp_lost.loadFromFile("data/Images/hover_of_hp_lost.png");
	p_texture_of_hover_of_hp_lost = &texture_of_hover_of_hp_lost;
	sprite_of_hover_of_hp_lost.setTexture(*p_texture_of_hover_of_hp_lost);
	sprite_of_hover_of_hp_lost.setTextureRect(sf::IntRect(0, 0, 0, 0));

	sprite_of_hover_of_hp_lost.setPosition(100, 60);

	display_hover_of_hp_lost = false;

	//hover of hp gain sprite
	/*texture_of_hover_of_hp_gain.loadFromFile("Assets/Images/hover_of_hp_gain.png");
	p_texture_of_hover_of_hp_gain = &texture_of_hover_of_hp_gain;
	sprite_of_hover_of_hp_gain.setTexture(*p_texture_of_hover_of_hp_gain);
	sprite_of_hover_of_hp_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sprite_of_hover_of_hp_gain.setPosition(100, 60);

	display_hover_of_hp_gain = false;
	*/

	//player sprite
	player_texture.loadFromFile("data/Images/player.png");
	p_player_texture = &player_texture;
	player_sprite.setTexture(*p_player_texture);
	player_sprite.setPosition(100, 100);

	//mana bar sprite
	mana_bar_texture.loadFromFile("data/Images/mana_bar.png");
	p_mana_bar_texture = &mana_bar_texture;
	mana_bar_sprite.setTextureRect(sf::IntRect(0, 0, 64, 87));
	mana_bar_sprite.setTexture(*p_mana_bar_texture);
	mana_bar_sprite.setPosition(80,120);
	
	mana_bar_background_texture.loadFromFile("data/Images/mana_bar_background.png");
	p_mana_bar_background_texture = &mana_bar_background_texture;
	mana_bar_background_sprite.setTexture(*p_mana_bar_background_texture);
	mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	mana_bar_background_sprite.setPosition(80, 120);

	//hover mana cost sprite
	texture_of_hover_of_mana_cost.loadFromFile("data/Images/hover_of_cost_of_mana_bar.png");
	p_texture_of_hover_of_mana_cost = &texture_of_hover_of_mana_cost;
	sprite_of_hover_of_mana_cost.setTexture(*p_texture_of_hover_of_mana_cost);
	sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sprite_of_hover_of_mana_cost.setPosition(80, 120);
	

	//res sprite
	texture_of_background_of_resistance_bar.loadFromFile("data/Images/resistance_bar_full.png");
	p_texture_of_background_of_resistance_bar = &texture_of_background_of_resistance_bar;
	sprite_of_background_of_resistance_bar.setTexture(*p_texture_of_background_of_resistance_bar);
	sprite_of_background_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sprite_of_background_of_resistance_bar.setPosition(100, 20);

	texture_of_resistance_bar.loadFromFile("data/Images/resistance_bar_empty.png");
	p_texture_of_resistance_bar = &texture_of_resistance_bar;
	sprite_of_resistance_bar.setTexture(*p_texture_of_resistance_bar);
	sprite_of_resistance_bar.setPosition(100, 20);

	// hover of res gain sprite
	texture_of_hover_of_res_gain.loadFromFile("data/Images/hover_of_resistance_bar.png");
	p_texture_of_hover_of_res_gain = &texture_of_hover_of_res_gain;
	sprite_of_hover_of_res_gain.setTexture(*p_texture_of_hover_of_res_gain);
	sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
	sprite_of_hover_of_res_gain.setPosition(100, 20);

	display_hover_of_res_gain_with_res_spell = false;
	display_hover_of_res_gain_with_healing_spell = false;
	

	//user actions
	mouse_has_entered_attack_spell_button = false;
	mouse_has_entered_resistance_spell_button = false;
	mouse_has_entered_healing_spell_button = false;

	//actions
	is_punching = false;
	is_tightening_abs = false;
	is_meditating = false;
	is_casting_beam = false;
	is_casting_res_spell = false;
	has_used_too_much_mana = false;
	is_victorious = false;
	is_standing = false;
	
	
}
Player::Player(Battle_Handler* battle_handler_, std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_)
{
	pointer_to_battle_handler = battle_handler_;
	name = name_;
	hp = hp_;
	atk = atk_;
	magic_atk = magic_atk_;
	mana = mana_;
	resistance = resistance_;

	health_bar_texture.loadFromFile("data/Images/health_bar.png");
	p_health_bar_texture = &health_bar_texture;
	health_bar_sprite.setTexture(*p_health_bar_texture);
	health_bar_sprite.setPosition(100, 60);

	player_texture.loadFromFile("data/Images/player.png");
	p_player_texture = &player_texture;
	player_sprite.setTexture(player_texture);
	player_sprite.setPosition(100, 100);

	//user actions
	mouse_has_entered_attack_spell_button = false;
	mouse_has_entered_resistance_spell_button = false;
	mouse_has_entered_healing_spell_button = false;

	//actions
	is_punching = false;
	is_tightening_abs = false;
	is_meditating = false;
	is_casting_beam = false;
	is_casting_res_spell = false;
	
}
Player::~Player()
{
	
}

void Player::Update()
{
	Update_Res_Sprite();
	Update_Hover_Of_Res_Gain_Sprite();
	Update_Health_Sprite();
	Update_Hover_Of_Hp_Lost_Sprite();
	Update_Mana_Sprite();
	Update_Hover_Of_Mana_Cost_Sprite();
	Update_Action_Sprite();
	
}

void Player::Update_Res_Sprite()
{

	if(is_alive)
	{ 
		sprite_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 241, 42));

		if (resistance >= 0.9f)
		{
			p_texture_of_background_of_resistance_bar->loadFromFile("data/Images/resistance_bar_full.png");
			sprite_of_background_of_resistance_bar.setTexture(*p_texture_of_background_of_resistance_bar);
			sprite_of_background_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0.9 * 241, 42));
		}

		else
		{
			
			float res_ = this->resistance;
			float res_sprite_width = sprite_of_resistance_bar.getScale().x * texture_of_resistance_bar.getSize().x;
			float res_sprite_new_width = res_ * res_sprite_width;
			sprite_of_background_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, res_sprite_new_width, 42));
		}
	}

	else
	{
		sprite_of_background_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0, 0));
		sprite_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
	
}

void Player::Update_Hover_Of_Res_Gain_Sprite()
{
	if (is_alive)
	{
		if (display_hover_of_res_gain_with_res_spell)
		{
			if (this->resistance >= 0.9f)
			{
				sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
			}

			else
			{
				float percentage_of_res_before_res_spell = resistance;
				float percentage_of_res_after_res_spell = resistance + 0.5;
				if (percentage_of_res_after_res_spell >= 0.9f)
				{
					percentage_of_res_after_res_spell = 0.9f;
				}

				float percentage_of_res_gained = percentage_of_res_after_res_spell - percentage_of_res_before_res_spell;

				float width_res_bar_before_res_spell = percentage_of_res_before_res_spell * 241;

				sf::FloatRect res_bar_before_res_spell(sprite_of_background_of_resistance_bar.getPosition().x, sprite_of_background_of_resistance_bar.getPosition().y, width_res_bar_before_res_spell, 42);
				//int res_bar__width = res_bar_before_res_spell.width;

				sprite_of_hover_of_res_gain.setPosition(100 + width_res_bar_before_res_spell, 20);

				sprite_of_hover_of_res_gain.setTextureRect
				(
					sf::IntRect
					(
						width_res_bar_before_res_spell,
						0,
						percentage_of_res_gained * 241,
						42
					)
				);
			}
		}

		else if (display_hover_of_res_gain_with_healing_spell)
		{

			if (this->resistance == 0.9f)
			{
				sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
			}

			else
			{
				float percentage_of_res_before_res_spell = resistance;
				float percentage_of_res_after_res_spell = resistance + 0.15;
				float percentage_of_res_gained = percentage_of_res_after_res_spell - percentage_of_res_before_res_spell;

				float width_res_bar_before_res_spell = percentage_of_res_before_res_spell * 241;

				sf::FloatRect res_bar_before_res_spell(sprite_of_background_of_resistance_bar.getPosition().x, sprite_of_background_of_resistance_bar.getPosition().y, width_res_bar_before_res_spell, 42);
				//int res_bar__width = res_bar_before_res_spell.width;

				sprite_of_hover_of_res_gain.setPosition(100 + width_res_bar_before_res_spell, 20);
				sprite_of_hover_of_res_gain.setTextureRect
				(
					sf::IntRect
					(
						width_res_bar_before_res_spell,
						0,
						percentage_of_res_gained * 241,
						42
					)
				);
			}

		}

		else
		{
			sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
		}
	}

	else
	{
		sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
	
}

void Player::Update_Health_Sprite()
{
	if (!is_alive)
	{
		health_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		health_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}

	else
	{
		health_bar_sprite.setTextureRect(sf::IntRect(0, 0, 241, 42));
		float percentage_of_hp_remaining = (hp / MAX_HP) * 100;
		float percentage_of_hp_lost = 100 - (hp / MAX_HP) * 100;
		sf::FloatRect health_bar(health_bar_background_sprite.getPosition().x, health_bar_background_sprite.getPosition().y, 241, 42);
		int health_bar_new_width = health_bar.width - (percentage_of_hp_lost / 100 * health_bar.width);
		health_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, health_bar_new_width, 41));
	}
}

void Player::Update_Mana_Sprite()
{
	//printf("%f \n", mana);
	
	if (is_alive)
	{
		mana_bar_sprite.setTextureRect(sf::IntRect(0, 0, 62, 87));
		mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));

		if (mana <= 0)
		{
			mana_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 62, 87));


		}

		else
		{
			
			float percentage_of_mana_remaining = (mana / MAX_MANA) * 100;
			float percentage_of_mana_lost = 100 - percentage_of_mana_remaining;
			sf::FloatRect mana_bar(mana_bar_sprite.getPosition().x, mana_bar_sprite.getPosition().y, 64, 87);
			sf::FloatRect mana_bar_background(mana_bar_background_sprite.getPosition().x, mana_bar_background_sprite.getPosition().y, 0, 0);
			float mana_bar_background_new_height = mana_bar_background.height + (percentage_of_mana_lost / 100 * mana_bar.height);
			mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 64, mana_bar_background_new_height));
		}

	}

	else
	{
		mana_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
	
	
}

void Player::Update_Hover_Of_Hp_Lost_Sprite()
{
	if (is_alive)
	{
		if (display_hover_of_hp_lost)
		{
			if (hp <= 0)
			{
				sprite_of_hover_of_hp_lost.setTextureRect(sf::IntRect(0, 0, 0, 0));
			}

			else
			{
				float percentage_of_hp_before_loss_of_hp = (hp / MAX_HP) * 100;
				float percentage_of_hp_after_loss_of_hp = (hp - 20) / MAX_HP * 100;
				float percentage_of_hp_lost = percentage_of_hp_before_loss_of_hp - percentage_of_hp_after_loss_of_hp;

				float width_health_bar_before_loss_of_hp = percentage_of_hp_before_loss_of_hp / 100 * 241;

				sf::FloatRect health_bar_before_loss_of_hp(health_bar_background_sprite.getPosition().x, health_bar_background_sprite.getPosition().y, width_health_bar_before_loss_of_hp, 42);
				int health_bar_new_width = health_bar_before_loss_of_hp.width - (percentage_of_hp_lost / 100 * 241);

				sprite_of_hover_of_hp_lost.setPosition(100 + health_bar_new_width, 60);
				sprite_of_hover_of_hp_lost.setTextureRect
				(
					sf::IntRect
					(
						health_bar_new_width,
						0,
						percentage_of_hp_lost / 100 * 241,
						42
					)
				);
			}

		}

		else
		{
			sprite_of_hover_of_hp_lost.setTextureRect(sf::IntRect(0, 0, 0, 0));
		}
	}

	else
	{
		sprite_of_hover_of_hp_lost.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
	
}

void Player::Update_Hover_Of_Mana_Cost_Sprite()
{
	if (is_alive)
	{
		//mouse entered attack spell button
		if (mouse_has_entered_attack_spell_button)
		{
			sf::IntRect sub_rect_of_mana_bar_background_sprite = mana_bar_background_sprite.getTextureRect();

			float mana_before_spell = mana;
			float percentage_of_mana_before_spell = (mana_before_spell / MAX_MANA) * 100;

			float mana_after_spell = mana - 30;
			float percentage_of_mana_remaining_after_spell = (mana_after_spell / MAX_MANA) * 100;

			float percentage_of_mana_lost_during_spell = percentage_of_mana_before_spell - percentage_of_mana_remaining_after_spell;

			float height_of_mana_bar_texture = mana_bar_texture.getSize().y * mana_bar_sprite.getScale().y;

			float height_of_hover_of_mana_cost = (percentage_of_mana_lost_during_spell / 100) * height_of_mana_bar_texture;
			//sub_rect_of_mana_bar_background_sprite.height += height_of_hover_of_mana_cost;

			sprite_of_hover_of_mana_cost.setPosition(80, 120 + sub_rect_of_mana_bar_background_sprite.height);
			sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect
			(0,
				sub_rect_of_mana_bar_background_sprite.height,
				64,
				height_of_hover_of_mana_cost)
			);

			mouse_has_entered_attack_spell_button = false;
		}

		//mouse entered resistance spell button
		else if (mouse_has_entered_resistance_spell_button)
		{
			sf::IntRect sub_rect_of_mana_bar_background_sprite = mana_bar_background_sprite.getTextureRect();

			float mana_before_spell = mana;
			float percentage_of_mana_before_spell = (mana_before_spell / MAX_MANA) * 100;

			float mana_after_spell = mana - 20;
			float percentage_of_mana_remaining_after_spell = (mana_after_spell / MAX_MANA) * 100;

			float percentage_of_mana_lost_during_spell = percentage_of_mana_before_spell - percentage_of_mana_remaining_after_spell;

			float height_of_mana_bar_texture = mana_bar_texture.getSize().y * mana_bar_sprite.getScale().y;

			float height_of_hover_of_mana_cost = (percentage_of_mana_lost_during_spell / 100) * height_of_mana_bar_texture;


			sprite_of_hover_of_mana_cost.setPosition(80, 120 + sub_rect_of_mana_bar_background_sprite.height);
			sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect
			(0,
				sub_rect_of_mana_bar_background_sprite.height,
				64,
				height_of_hover_of_mana_cost)
			);

			mouse_has_entered_resistance_spell_button = false;
		}


		else if (mouse_has_entered_healing_spell_button)
		{
			sf::IntRect sub_rect_of_mana_bar_background_sprite = mana_bar_background_sprite.getTextureRect();

			float mana_before_spell = mana;
			float percentage_of_mana_before_spell = (mana_before_spell / MAX_MANA) * 100;

			float mana_after_spell = mana - 50;
			float percentage_of_mana_remaining_after_spell = (mana_after_spell / MAX_MANA) * 100;

			float percentage_of_mana_lost_during_spell = percentage_of_mana_before_spell - percentage_of_mana_remaining_after_spell;

			float height_of_mana_bar_texture = mana_bar_texture.getSize().y * mana_bar_sprite.getScale().y;

			float height_of_hover_of_mana_cost = (percentage_of_mana_lost_during_spell / 100) * height_of_mana_bar_texture;


			sprite_of_hover_of_mana_cost.setPosition(80, 120 + sub_rect_of_mana_bar_background_sprite.height);
			sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect
			(0,
				sub_rect_of_mana_bar_background_sprite.height,
				64,
				height_of_hover_of_mana_cost)
			);

			mouse_has_entered_healing_spell_button = false;

		}

		else
		{
			sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect(0, 0, 0, 0));
		}
	
	}

	else
	{
		sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
}

void Player::Update_Action_Sprite()
{
	if (is_alive)
	{
		if (is_standing)
		{
			p_player_texture->loadFromFile("data/Images/player.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 130, 381));
			player_sprite.setTexture(*p_player_texture);
			//std::this_thread::sleep_for(std::chrono::seconds{ 2 });
			//p_player_texture->loadFromFile("Assets/Images/player.png");
			is_standing = false;
		}

		if (is_punching)
		{
			//printf("%s \n", "player throws a punch");
			p_player_texture->loadFromFile("data/Images/player_Punch.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 420, 389));
			player_sprite.setTexture(*p_player_texture);
			//std::this_thread::sleep_for(std::chrono::seconds{ 2 });
			//p_player_texture->loadFromFile("Assets/Images/player.png");
			is_punching = false;
		}

		else if (is_tightening_abs)
		{
			//printf("%s \n", "player tighten his abs");
			p_player_texture->loadFromFile("data/Images/player_Tighten_Abs.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 208, 392));
			player_sprite.setTexture(*p_player_texture);
			is_tightening_abs = false;
			//resistance -= 0.1;
		}

		else if (is_meditating)
		{
			//printf("%s \n", "player enters in meditation mode");
			p_player_texture->loadFromFile("data/Images/player_Meditate.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 333, 395));
			player_sprite.setTexture(*p_player_texture);
			do
			{
				is_meditating = false;;
			} while (is_meditating);

		}

		else if (is_casting_beam)
		{
			printf("%s \n", "player cast attack spell");
			p_player_texture->loadFromFile("data/Images/player_Cast_Beam.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 1054, 382));
			player_sprite.setTexture(*p_player_texture);
			do
			{
				is_casting_beam = false;
			} while (is_casting_beam);

		}

		else if (is_casting_res_spell)
		{
			//printf("%s \n", "player cast res spell");
			p_player_texture->loadFromFile("data/Images/player_Cast_Bubble_Armor.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 171, 400));
			player_sprite.setTexture(*p_player_texture);
			do
			{
				is_casting_res_spell = false;
			} while (is_casting_res_spell);

		}

		else if (has_used_too_much_mana)
		{
			p_player_texture->loadFromFile("data/Images/player_used_too_much_mana.png");
			player_sprite.setPosition(60, 260);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 318, 161));
			player_sprite.setTexture(*p_player_texture);
			has_used_too_much_mana = false;
		}

		else if (is_victorious)
		{
			p_player_texture->loadFromFile("data/Images/player_Win.png");
			player_sprite.setPosition(100, 100);
			player_sprite.setTextureRect(sf::IntRect(0, 0, 196, 387));
			player_sprite.setTexture(*p_player_texture);

			//set UI invisible
			sprite_of_background_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0, 0));
			sprite_of_resistance_bar.setTextureRect(sf::IntRect(0, 0, 0, 0));
			sprite_of_hover_of_res_gain.setTextureRect(sf::IntRect(0, 0, 0, 0));
			health_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			health_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			mana_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			mana_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			sprite_of_hover_of_hp_lost.setTextureRect(sf::IntRect(0, 0, 0, 0));
			sprite_of_hover_of_mana_cost.setTextureRect(sf::IntRect(0, 0, 0, 0));

		}
	}

	else if (!is_alive)
	{
		p_player_texture->loadFromFile("data/Images/player_Dead.png");
		player_sprite.setPosition(100, 100);
		player_sprite.setTextureRect(sf::IntRect(0, 0, 375, 375));
		player_sprite.setTexture(*p_player_texture);

	}
	
}

void Player::Attack_Physically(Battle_Actor* target)
{
	Punch(target);
}
	void Player::Punch(Battle_Actor* target)
{
		//std::cout << termcolor::bright_green << name << " throws a Punch on " << target->Get_Name() <<  std::endl << std::endl;
		is_punching = true;
		target->Get_Damage(atk);
}


void Player::Defend()
{
	if (resistance >= 0.9f)
	{
		resistance = 0.9f;
		//std::cout << termcolor::bright_grey << name << " can no longer tighten abs " << std::endl << std::endl;
	}

	else 
	{
		Tighten_Abs();
	}
	
}
	void Player::Tighten_Abs()
{
			//std::cout << termcolor::bright_green << name << " Tighten Abs" << std::endl;
			//std::cout << termcolor::bright_grey << "resistance:" << (resistance >= 0.9 ? 0.9 : resistance) << "->" << (resistance >=0.8 ? 0.9 : resistance + 0.1) << std::endl << std::endl;
			is_tightening_abs = true;
			resistance += 0.05; if (resistance >= 0.9f) { resistance = 0.9f; }
}


void Player::Cast_Attack_Spell(Battle_Actor* target)
{
	if(mana >= 30)
	{
		Cast_Beam(target);
	}

	else
	{
		has_used_too_much_mana = true;
		//printf("%s\n", "player hurts himself for trying to overcome too soon his known limits"); 
		if (hp > 10)
		{
			//std::cout << "hp:" << hp << "->" << hp - 10 << std::endl << std::endl;
			
			hp -= 10;
			
		}

		else
		{
			hp = 0;
			is_alive = false;
			//printf("%s\n", "player died from his injuries");
		}
	}
	
}
	void Player::Cast_Beam(Battle_Actor* target)
{
	//std::cout << termcolor::bright_green << name << " cast Beam on " << target->Get_Name() << std::endl;
	//std::cout << termcolor::bright_grey << "mana:" << mana << "->" << mana-30 << std::endl << std::endl;
	is_casting_beam = true;
	mana -= 30;
	target->Get_Damage(magic_atk);
}


void Player::Cast_Res_Spell()
{
	if (mana >= 20)
	{
		Cast_Bubble_Armor();
	}

	else
	{
		has_used_too_much_mana = true;
		//printf("%s\n", "player hurts himself for trying to overcome too soon his known limits");
		if (hp > 10)
		{
			//std::cout << "hp:" << hp << "->" << hp - 10 << std::endl << std::endl;
			
			hp -= 10;
		}

		else
		{
			hp = 0;
			is_alive = false;
			//printf("%s\n", "player died from his injuries");
		}
	}
	
}
	void Player::Cast_Bubble_Armor()
{
	//std::cout << termcolor::bright_green << name << " cast Bubble Armor" << std::endl; 
	//std::cout << termcolor::bright_grey << "resistance:" <<( resistance >= 0.9 ? 0.9 : resistance) << "->" << (resistance >= 0.4 ? 0.9 : resistance + 0.5) << std::endl;
	//std::cout << "mana:" << mana << "->" << mana - 20 << std::endl << std::endl;
	is_casting_res_spell = true;
	mana -= 20;  
	resistance += 0.5f;  if(resistance >= 0.9f) { resistance = 0.9f; }
}


void Player::Heal()
{
	if (mana >= 50)
	{
		if (hp <= 85 || mana <= 85 || resistance <= 0.75)
		{
			Meditate();
		}
	}


	//printf("%s\n", "player hurts himself for trying to overcome too soon his known limits");
	

	else
	{
		has_used_too_much_mana = true;
		if (hp > 10)
		{
			//std::cout << "hp:" << hp << "->" << hp - 10 << std::endl << std::endl;
			hp -= 10;
		}

		else
		{
			hp = 0;
			is_alive = false;
			//printf("%s\n", "player died from his injuries");
		}

		
	}
	
}
	void Player::Meditate()
{
		//std::cout << termcolor::bright_green << name << " enters in Meditation Mode" << std::endl;
		//std::cout << termcolor::bright_grey;
		//HP
		is_meditating = true;
		mana -= 50;
		if (hp == MAX_HP || hp > 40)
		{
			//std::cout << "hp:" << hp << "->" << MAX_HP << std::endl;	
			hp = MAX_HP;
		}

		else if(hp <= 40)
		{
			//std::cout << "hp:" << hp << "->" << hp + 15 << std::endl;
			hp += 60;
		}
		
		//MANA
		//if (mana == 100 || mana > 85)
		//{
			//std::cout << "mana:" << mana << "->" << "100" << std::endl;
			//mana = 100;
		//}

		//else if (mana <= 85)
		//{
			//std::cout << "mana:" << mana << "->" << mana + 15 << std::endl;
			//mana += 15;
		//}
		
		//RESISTANCE
		if (resistance == 0.9f || resistance > 0.75f)
		{
			//std::cout << "resistance:" << resistance << "->" << "0.9" << std::endl << std::endl;
			resistance = 0.9f;
		}
		
		else if (resistance <= 0.75f)
		{	
			//std::cout << "resistance:" << resistance << "->" << resistance+0.15 << std::endl << std::endl;
			resistance += 0.15f;
		}

		
}






	void Player::Set_Pointer_To_Battle_Handler(Battle_Handler* new_pointer_to_battle_handler_)
	{
		pointer_to_battle_handler = new_pointer_to_battle_handler_;
	}
	void Player::Print_Name()
	{
		//std::cout << name;
	}
	void Player::Get_Damage(float damage_)
	{
		
		hp = hp - (damage_ - (damage_ * resistance));
		if (hp <= 0)
		{
			is_alive = false;
		}
		
	}
	std::string Player::Get_Name()
	{
		return name;
	}
	bool Player::Is_Alive()
	{
		return is_alive;
	}
	bool Player::Is_Victorious()
	{
		return is_victorious;
	}
	bool Player::Is_Punching()
	{
		return is_punching;
	}
	bool Player::Is_Casting_Beam()
	{
		return is_casting_beam;
	}
	void Player::Print_Hp()
	{
		printf("%f\n", hp);
	}
	int Player::Get_Hp()
	{
		return hp;
	}

	int Player::Get_Mana()
	{
		return mana;
	}

	float Player::Get_MAX_MANA()
	{
		return MAX_MANA;
	}

	float Player::Get_Resistance()
	{
		return resistance;
	}

	sf::Texture Player::Get_Texture()
	{
		return player_texture;
	}

	sf::Texture Player::Get_Mana_Bar_Background_Texture()
	{
		return mana_bar_background_texture;
	}

	sf::Sprite Player::Get_Sprite()
	{
		return player_sprite;
	}

	sf::Sprite Player::Get_Mana_Bar_Background_Sprite()
	{
		return mana_bar_background_sprite;
	}

	sf::Sprite Player::Get_Sprite_Of_Hover_Of_Mana_Cost()
	{
		return sprite_of_hover_of_mana_cost;
	}
	

	void Player::Set_Texture(sf::Texture new_texture)
	{
		//printf("%s \n", "player texture was modified -> player sprite was modified");
		
		//player_sprite.setTexture(new_texture, true);

	}

	void Player::Draw(sf::RenderWindow& window)
	{
		window.draw(sprite_of_resistance_bar);
		window.draw(sprite_of_background_of_resistance_bar);
		window.draw(sprite_of_hover_of_res_gain);

		window.draw(health_bar_sprite);
		window.draw(health_bar_background_sprite);
		window.draw(sprite_of_hover_of_hp_lost);
		//window.draw(sprite_of_hover_of_hp_gain);

		window.draw(player_sprite);

		window.draw(mana_bar_sprite);
		window.draw(mana_bar_background_sprite);
		window.draw(sprite_of_hover_of_mana_cost);
	
	}

	void Player::Set_Visible_Hover_Of_Mana_Cost_Of_Attack_Spell(bool boolean)
	{
		mouse_has_entered_attack_spell_button = boolean;
	}

	void Player::Set_Visible_Hover_Of_Mana_Cost_Of_Resistance_Spell(bool boolean)
	{
		mouse_has_entered_resistance_spell_button = boolean;
	}

	void Player::Set_Visible_Hover_Of_Mana_Cost_Of_Healing_Spell(bool boolean)
	{
		mouse_has_entered_healing_spell_button = boolean;
	}

	void Player::Set_Visible_Hover_Of_Hp_Lost_Sprite(bool boolean)
	{
		display_hover_of_hp_lost = boolean;
	}

	void Player::Set_Visible_Hover_Of_Res_Gain_Of_Res_Spell(bool boolean)
	{
		display_hover_of_res_gain_with_res_spell = boolean;
	}

	void Player::Set_Visible_Hover_Of_Res_Gain_Of_Healing_Spell(bool boolean)
	{
		display_hover_of_res_gain_with_healing_spell = boolean;
	}

	void Player::Set_Victory(bool boolean)
	{
		is_victorious = boolean;
	}

	void Player::Set_Is_Alive(bool boolean)
	{
		is_alive = boolean;
	}

	void Player::Set_Resistance(float res)
	{
		resistance = res;
	}

	void Player::Set_Hp(float hp_)
	{
		hp = hp_;
	}

	void Player::Set_Mana(float mana_)
	{
		mana = mana_;
	}

	void Player::Set_Default_Action(bool boolean)
	{
		is_standing = boolean;
		is_punching = false;
		is_tightening_abs = false;
		is_meditating = false;
		is_casting_beam = false;
		is_casting_res_spell = false;
		has_used_too_much_mana = false;
	}


	/*void Player::Set_Visible_Hover_Of_Hp_Gain_Of_Healing_Spell(bool boolean)
	{
		display_hover_of_hp_gain = boolean;
	}
	*/
	
