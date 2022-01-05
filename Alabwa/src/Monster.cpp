#include "Monster.h"

Monster::Monster()
{
	name = "Monster";
	hp = 100;
	atk = 15;
	magic_atk = 0;
	mana = 0;
	resistance = 0.1;

	//states
	has_evolved = false;

	//monster sprite
	monster_texture.loadFromFile("data/Images/minion.png");
	p_monster_texture = &monster_texture;
	monster_sprite.setTexture(*p_monster_texture);
	monster_sprite.setPosition(600, 130);

	//health sprite
	health_bar_texture.loadFromFile("data/Images/health_bar.png");
	p_health_bar_texture = &health_bar_texture;
	health_bar_sprite.setTexture(*p_health_bar_texture);
	health_bar_sprite.setPosition(625, 60);


	health_bar_background_texture.loadFromFile("data/Images/health_bar_background_monster.png");
	p_health_bar_background_texture = &health_bar_background_texture;
	health_bar_background_sprite.setTexture(*p_health_bar_background_texture);
	health_bar_background_sprite.setPosition(625, 60);
	
	//actions
	has_punched= false;
	has_taken_iron_shell = false;
	has_casted_eyesbeam = false;
	has_casted_pentagram_wall = false;
	is_victorious = false;
	is_standing = false;
}
Monster::Monster(Battle_Handler* battle_handler_, std::string name_, float hp_, float atk_, float magic_atk_, float mana_, float resistance_)
{
	pointer_to_battle_handler = battle_handler_;
	name = name_;
	hp = hp_;
	atk = atk_;
	magic_atk = magic_atk_;
	mana = mana_;
	resistance = resistance_;

	//states
	has_evolved = false;

	//monster sprite
	monster_texture.loadFromFile("data/Images/minion.png");
	p_monster_texture = &monster_texture;
	monster_sprite.setTexture(monster_texture);

	//health sprite
	health_bar_texture.loadFromFile("data/Images/health_bar.png");
	p_health_bar_texture = &health_bar_texture;
	health_bar_sprite.setTexture(*p_health_bar_texture);
	health_bar_sprite.setPosition(100, 60);


	health_bar_background_texture.loadFromFile("data/Images/health_bar_background_monster.png");
	p_health_bar_background_texture = &health_bar_background_texture;
	health_bar_background_sprite.setTexture(*p_health_bar_background_texture);
	health_bar_background_sprite.setPosition(600, 90);

	//actions
	has_punched = false;
	has_taken_iron_shell = false;
	has_casted_eyesbeam = false;
	has_casted_pentagram_wall = false;
	
}
Monster::~Monster()
{
}

void Monster::Update()
{
	Update_Health_Sprite();
	Update_Action_Sprite();
	
	
}

void Monster::Update_Health_Sprite()
{
	if (!is_alive)
	{
		health_bar_sprite.setTextureRect(sf::IntRect(0,0,0,0));
		health_bar_sprite.setTexture(*p_health_bar_texture);
		health_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
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


void Monster::Update_Action_Sprite()
{
	if (is_alive)
	{
		if (is_standing)
		{
			p_monster_texture->loadFromFile("data/Images/minion.png");
			monster_sprite.setTextureRect(sf::IntRect(0, 0, 293, 352));
			monster_sprite.setTexture(*p_monster_texture);

			is_standing = false;
		}

		if (has_punched)
		{
			if (!has_evolved)
			{
				p_monster_texture->loadFromFile("data/Images/minion_Punch.png");
				monster_sprite.setTextureRect(sf::IntRect(0, 0, 261, 325));
				monster_sprite.setTexture(*p_monster_texture);
			}

			if (has_evolved)
			{
				p_monster_texture->loadFromFile("data/Images/great_minion_Punch.png");
				monster_sprite.setTextureRect(sf::IntRect(0, 0, 338, 325));
				monster_sprite.setTexture(*p_monster_texture);
			}

			has_punched = false;
		}

		else if (has_taken_iron_shell)
		{
			p_monster_texture->loadFromFile("data/Images/minion_Iron_Shell.png");
			monster_sprite.setTextureRect(sf::IntRect(0, 0, 269, 288));
			monster_sprite.setTexture(*p_monster_texture);
			has_taken_iron_shell = false;
		}

		else if (has_casted_pentagram_wall) //it is implicit that the monster evolved before casting pentagram wall  so no need to verify it
		{
			//std::this_thread::sleep_for(std::chrono::seconds(2));
			p_monster_texture->loadFromFile("data/Images/great_minion_Pentagram_Wall.png");
			monster_sprite.setTextureRect(sf::IntRect(0, 0, 370, 334));
			monster_sprite.setTexture(*p_monster_texture);
			has_casted_pentagram_wall = false;
		}

		else if (has_casted_eyesbeam)
		{
			p_monster_texture->loadFromFile("data/Images/great_minion_Eyebeam.png");
			monster_sprite.setTextureRect(sf::IntRect(0, 0, 370, 334));
			monster_sprite.setTexture(*p_monster_texture);
			has_casted_eyesbeam = false;
		}

		else if (is_victorious)
		{
			p_monster_texture->loadFromFile("data/Images/minion_Win.png");
			monster_sprite.setPosition(625, 150);
			monster_sprite.setTextureRect(sf::IntRect(0, 0, 249, 327));
			monster_sprite.setTexture(*p_monster_texture);

			//set Ui invisble
			health_bar_background_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			health_bar_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		}
	}
	
	else if(!is_alive)
	{
		monster_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		monster_sprite.setTexture(*p_monster_texture);
	}

}

void Monster::React_To(Battle_Actor* pointer_to_battle_actor_to_react_to)
{

	if (hp > MAX_HP * 0.25)
	{
		int rand_;

		do
		{
			rand_ = rand() % 100;
		} while (rand_ < 0);

		if (rand_ <= 80)
		{
			Attack_Physically(pointer_to_battle_actor_to_react_to);
		}

		else
		{
			Defend();
		}
		
	}

	else if (hp <= MAX_HP * 0.25 && has_evolved == false) //&& hp > MAX_HP * 0.10)
	{
		Mutate();
		Cast_Res_Spell();
	}

	else if(has_evolved)
	{
		int rand_;

		do
		{
			rand_ = rand() % 100;
		} while (rand_ < 0);

		if (rand_ <= 80)
		{
			Cast_Attack_Spell(pointer_to_battle_actor_to_react_to);
		}

		else
		{
			Attack_Physically(pointer_to_battle_actor_to_react_to);
		}
		
	}
}


void Monster::Attack_Physically(Battle_Actor* target)
{
	Punch(target);
}
	void Monster::Punch(Battle_Actor* target)
{
	//std::cout << termcolor::red << name << " throws a Punch on " << target->Get_Name() << std::endl << std::endl;
	if (!has_evolved)
	{
		target->Get_Damage(atk);
	}

	else if (has_evolved)
	{
		target->Get_Damage(magic_atk);

	}
	
	has_punched = true;
}


void Monster::Defend()
{
	if(resistance <= 0.9)
	{
		Get_Iron_Shell();
	}
	
}
	void Monster::Get_Iron_Shell()
{
		//std::cout << termcolor::red << name << " gets it's Iron Shell" << std::endl;
		//std::cout << termcolor::bright_grey << "resistance:" << resistance << "->" << (resistance >= 0.7 ? 0.9 : resistance + 0.3 ) << std::endl << std::endl;
		resistance += 0.3;   if (resistance >= 0.9) { resistance = 0.9; }
		has_taken_iron_shell = true;
}


void Monster::Cast_Attack_Spell(Battle_Actor* target)
{
	if (mana >= 5)
	{
		Cast_Eyesbeam(target);
	}
	
	else
	{
		//std::cout << termcolor::bright_grey << name << "tries to cast Eyesbeam, but it hasn't enough mana" << std::endl;
		//Attack_Physically(target);
	}
}
	void Monster::Cast_Eyesbeam(Battle_Actor* target)
{
		//std::cout << termcolor::red << name << " cast Eyesbeam" << std::endl;
		//std::cout << termcolor::bright_grey << "mana:" << mana << "->" << mana - 5 << std::endl << std::endl;
		mana -= 5;
		target->Get_Damage(magic_atk);
		has_casted_eyesbeam = true;
}


void Monster::Cast_Res_Spell()
{
	if (mana >= 5)
	{
		Cast_Pentagram_Wall();
	}

	else
	{
		//std::cout << termcolor::bright_grey << name << "tries to cast Pentagram Wall , but it hasn't enough mana" << std::endl;
		Get_Iron_Shell();
	}
	
}
	void Monster::Cast_Pentagram_Wall()
{
		//std::cout << termcolor::red << name << " draws Pentagram Wall" << std::endl;
		//std::cout << termcolor::bright_grey << "resistance:" << (resistance >= 0.9 ? resistance + 0 : resistance)  << "->" << (resistance >=0.4 ? 0.9 : resistance + 0.5) << std::endl;
		//std::cout << "mana:" << mana << "->" << mana - 5 << std::endl << std::endl;
		resistance += 0.5;		if (resistance >= 0.9) { resistance = 0.9; }
		mana -= 5;
		has_casted_pentagram_wall = true;
}

	void Monster::Mutate()
	{
		//std::cout << termcolor::red << name << " evolves into Great Mobster" << std::endl;
		name = "Great Mobster";
		//std::cout << termcolor::bright_grey << "atk:" << atk << "->" << atk + 30 << std::endl;
		//std::cout << termcolor::bright_grey << "magic atk:" << magic_atk << "->" << magic_atk + 50 << std::endl;
		//std::cout << "resistance:" << (resistance >= 0.9 ? 0.9 : resistance)  << "->" << (resistance >= 0.6 ? 0.9 : resistance + 0.3) << std::endl;
		//std::cout <<"mana:" << mana << "->" << mana + 100 << std::endl << std::endl;
		atk += 50;
		magic_atk += 50;
		resistance += 0.3;	if (resistance >= 0.9) { resistance = 0.9; }
		mana += 100;
		has_evolved = true;
	}

void Monster::Set_Pointer_To_Battle_Handler(Battle_Handler* new_pointer_)
{
	pointer_to_battle_handler = new_pointer_;
}

void Monster::Print_Name()
{
	//std::cout << name;
}

std::string Monster::Get_Name()
{
	return name;
}

void Monster::Get_Damage(float damage_)
{
	hp = hp - (damage_  - (damage_ * resistance));
	if (hp <= 0)
	{
		is_alive = false;
	}	
}

bool Monster::Is_Alive()
{
	return is_alive;
}

bool Monster::Is_Punching()
{
	return false;
}

void Monster::Print_Hp()
{
	printf("%f\n", hp);
}

int Monster::Get_Hp()
{
	return hp;
}

float Monster::Get_Resistance()
{
	return this->resistance;
}

bool Monster::Is_Victorious()
{
	return is_victorious;
}

float Monster::Get_Mana()
{
	return this->mana;
}

void Monster::Set_Texture(sf::Texture texture)
{
	printf("%s \n", "monster texture was modified -> monster sprite was modified");
	monster_sprite.setTexture(texture);
}

sf::Texture Monster::Get_Texture()
{
	return monster_texture;
}

sf::Sprite Monster::Get_Sprite()
{
	return monster_sprite;
}

void Monster::Draw(sf::RenderWindow& window)
{
	window.draw(health_bar_sprite);
	window.draw(health_bar_background_sprite);
	window.draw(monster_sprite);
}

void Monster::Set_Victory(bool boolean)
{
	is_victorious = boolean;
}

void Monster::Set_Resistance(float res_)
{
	resistance = res_;
}

void Monster::Set_Hp(float hp_)
{
	this->hp = hp_;
}

void Monster::Set_Mana(float mana_)
{
	this->mana = mana_;
}

void Monster::Set_Default_Action(bool boolean)
{
	is_standing = true;
	this->has_casted_eyesbeam = false;
	this->has_casted_pentagram_wall = false;
	this->has_evolved = false;
	this->has_punched = false;
	this->has_taken_iron_shell = false;
}

void Monster::Set_Is_Alive(bool boolean)
{
	is_alive = boolean;
}




