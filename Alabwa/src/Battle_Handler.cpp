#include "Battle_Handler.h"

Battle_Handler::Battle_Handler()
{
	name = "battle handler";
	player = nullptr;
	monster = nullptr;
	active_battle_actor = nullptr;
	//state = Battle_Handler_State::Waiting_For_Player;
	*active_battle_actor = *player;
	sf::Event an_event = this->event;
}

Battle_Handler::Battle_Handler(Player* player_, Monster* monster_, Battle_Actor* active_battle_actor_)
{

	name = "battle handler";
	player = player_;
	monster = monster_;
	active_battle_actor = active_battle_actor_;
	//state = Battle_Handler_State::Waiting_For_Player;
	*active_battle_actor = *player;
	sf::Event an_event = this->event;

}

Battle_Handler::~Battle_Handler()
{
}

void Battle_Handler::Set_Active_Battle_Actor(Battle_Actor* active_actor_)
{
	active_battle_actor = active_actor_;
}

void Battle_Handler::Start_Battle()
{
	while (player->Is_Alive() && monster->Is_Alive())
	{
		if (active_battle_actor == player)
		{
			//std::cout << termcolor::bright_green; 
			//printf("%s \n", "HP: ");
			//player->Print_Hp();

			//std::cout << termcolor::white
				/*<< "-press 1- Attack \n"
				<< "-press 2- Cast attack spell \n"
				<< "-press 3- Increase defense \n"
				<< "-press 4- Increase magic resistance \n"
				<< "-press 5- Heal\n"
				<< "Choose an action and press enter: ";
				

			char c;
			std::cin >> c;
			std::cout << std::endl;
			switch (c)
			{
			case '1':
				player->Attack_Physically(monster);
				break;
			case '2':
				player->Cast_Attack_Spell(monster);
				break;
			case '3':
				player->Defend();
				break;
			case '4':
				player->Cast_Res_Spell();
				break;
			case '5':
				player->Heal();
				break;

			default:
				break;
			}
			
			Set_Active_Battle_Actor(monster);
			//std::this_thread::sleep_for(std::chrono::seconds{ 2 });
			//state = Battle_Handler_State::Busy;
			//player->Update_State();
			//monster->Update_State();
			*/
		}
		
		
		
		/*
		else if (active_battle_actor == monster)
		{
			std::cout << termcolor::red;
			std::cout << "HP: ";
			monster->Print_Hp();
			std::cout << monster->Get_Name() << std::endl;
			monster->React_To(player);
			Set_Active_Battle_Actor(player); 
			//std::this_thread::sleep_for(std::chrono::seconds{ 2 });
			//state = Battle_Handler_State::Waiting_For_Player;
			//player-> Updtate_State()
			//monster-> Update_State()
		}
		*/
		

	}
	
	
}

Battle_Actor* Battle_Handler::Get_Pointer_To_Active_Battle_Actor()
{
	return active_battle_actor;
}

Player* Battle_Handler::Get_Pointer_To_Player()
{
	return player;
}

Monster* Battle_Handler::Get_Pointer_To_Monster()
{
	return monster;
}

bool Battle_Handler::Process_Events(sf::RenderWindow& window)
{
	return window.pollEvent(this->event);
	
}

sf::Event Battle_Handler::Get_Event()
{
	return this->event;
}




/*void Battle_Handler::Start_Battle()
{
	Set_Active_Battle_Actor(player);
}
*/
/*Battle_Actor Battle_Handler::Get_Active_Battle_Actor()
{
	return active_battle_actor;
}*/