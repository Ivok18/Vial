// Deus ex machina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
//#include <conio.h>
#include <thread>
#include "Battle.h"
#include "ForcePotion.h"
#include "MyGame.h"
#include "OneVersusMuch.h"


/*void DisplayGameContext()
{
	std::cout
		<< "Un gigantesque des omnipotent et omniprésent (Deuss), decide de se creer lui meme sous plusieurs formes qui interagissent entre elles (gentils et mechant).\n"
		<< "Les gentils ont un royaume(DiceMania) ou la paix et la democracie sont instaurees.\n"
		<< "Les mechants ont un royaume(Dakhira) et souhaitent conquerir dice mania pour acceder a l'omnipotence de Deuss.\n"
		<< "Afin de contrer dakhira, dicemania monte une armee visant l'espoir de proteger leur nations et lorsque les assaillants se retrouverent au porte de Dicemania, le combat eclata et la guerre fut declaree.\n"
		<< "50 ans plus tard, la guerre fait toujours ravage dans les deux royaumes.\n";

	std::cout << "vous etes un soldat de Dicemania s'appretant a entrer sur un champ de bataille.\n";
	std::cout << "a l'entree, le sergeant major Ded vous demande de vous presenter:\n\n";
	std::cout << "Quel est ton nom soldat? ";
}
void LootLottery(Item* loot, Inventory& lootLottery, Player& player)
{
	int luckyLoot;
	do
	{
		luckyLoot = 1 + rand() % 5;
	} while (luckyLoot < 1);


	if (luckyLoot == 5)
	{

		std::cout << player.getName() << " a recupere cet item sur son adversaire: " << std::endl;

		int normalLoot = rand() % 5;

		if (normalLoot == 0)
		{
			loot = lootLottery.findHealPotion();
		}

		else if (normalLoot == 1)
		{
			loot = lootLottery.findForcePotion();
		}

		else if (normalLoot == 2)
		{
			loot = lootLottery.findBow("extasia");
		}

		else if (normalLoot == 3)
		{
			loot = lootLottery.findSword("lumina");
		}

		else if (normalLoot == 4)
		{
			int epicLoot = rand() % 11;
			if (epicLoot == 10)
			{
				//find epic hammer and assign its adress to lootPtr
				loot = lootLottery.findEpic("epikia");
			}

			else
			{
				loot = lootLottery.findHealPotion();
			}
		}

		if (loot != nullptr)
		{
			loot->Display();
		}

		else
		{
			

			<< "pas normal" << std::endl;
		}


		std::cout << "Voulez-vous le ramasser? (y/other) " << std::endl;


		char lootPhaseChoice = _getch();
		if (lootPhaseChoice == 'y')
		{
			//if player _inventory has a slot available
			if (player.getInventory().getVectorOfItems().size() + 1 <= player.getInventory().getMaxCapacity())
			{
				//add item
				player.getInventory().add(loot);

				//show _inventory
				player.displayInventory();

			}

			else
			{
				std::cout << "player _inventory is full" << std::endl;
				//show options
				std::cout << "(1) throw an item" << std::endl;
				std::cout << "(2) leave" << std::endl;

				char inventoryChoice = _getch();

				//if player choose to throw an item
				if (inventoryChoice == '1')
					player.throwItem();

				std::cout << "ramasser le loot? (y/other) " << std::endl;

				char choice = _getch();

				if (choice == 'y')
				{
					player.getInventory().add(loot);
				}

				std::cout << "votre inventaire:" << std::endl;
				player.displayInventory();
			}

		}
	}
}
char ChooseNextArea()
{
	std::cout << "vous etes a la croisee des chemins, a vous de decider quelle direction vous voulez emprunter, car vous etes maitre de votre destin" << std::endl;

	std::cout
		<< "nord (press n)\n"
		<< "est (press e)\n"
		<< "ouest (press o)\n"
		<< "sud (press s)\n";

	char anotherAdventureChoice = _getch();

	if (anotherAdventureChoice == 'n')
	{
		return 'n';
	}
	else if (anotherAdventureChoice == 'e')
	{
		return 'e';
	}
	else if (anotherAdventureChoice == 'o')
	{
		return 'o';
	}
	else if (anotherAdventureChoice == 's')
	{
		return 's';
	}
	else if (anotherAdventureChoice != 'n' && anotherAdventureChoice != 'e' && anotherAdventureChoice != 'o' && anotherAdventureChoice != 's')
	{
		char adventureChoice_ = _getch();
		do
		{
			std::cout << "you can never back down, that's the path you have chosen." << std::endl;

			std::cout
				<< "nord (press n)\n"
				<< "est (press e)\n"
				<< "ouest (press o)\n"
				<< "sud (press s)\n";

			adventureChoice_ = _getch();

		} while (adventureChoice_ != 'n' && adventureChoice_ != 'e' && adventureChoice_ != 'o' && adventureChoice_ != 's');

		std::cout << "It seems like you doubted the true nature of your journey a moment ago." << std::endl;
		std::cout << "If you truly wish to stop here, you're free to go " << std::endl;
		std::cout << "Everyone can choose it's destiny after all. " << std::endl;
		std::cout << "Find a wife, and raise a family in a peacefull kingdom (press a)" << std::endl;
		std::cout << "Follow the soldier path (press anything)" << std::endl;

		char lifeChoice = _getch();

		if (lifeChoice == 'a')
		{
			return 'a';
		}


		else
		{
			if (adventureChoice_ == 'n')
			{
				return 'n';
			}
			else if (adventureChoice_ == 'e')
			{
				return 'e';
			}
			else if (adventureChoice_ == 'o')
			{
				return 'o';
			}
			else if (adventureChoice_ == 's')
			{
				return 's';
			}
		}

	}
	
}
*/

int main()
{

	srand(time(nullptr));

	MyGame machina;
	machina.run();

	Player player;
	//DisplayGameContext();
	std::string player_name;
	std::cin >> player_name;
	Inventory playerInventory;
	player.setInventory(playerInventory);
	player.setName(player_name);
	player.setHp(100);
	player.setAtk(9000000);
	std::cout << std::endl;
	std::cout << "Ok " << player.getName() << ", en position" << std::endl << std::endl;
	std::cout << "votre inventaire: " << std::endl;
	//player.displayInventory();
	std::cout << std::endl << std::endl;

	while (player.getNbFights() < 5)
	{
		//TODO --> DESCRIPTION ZONE DE BATAILLE

		//ASK USER TO ENGAGE BATTLE
		std::cout << "Entrer dans le champ de bataille (y/other) " << std::endl;
		char adventureChoice = _getch();

		//BATTLE
		Battle battle(player, Monster());
		if (adventureChoice == 'y')
		{
			battle.start();
		}
		else
		{

			std::cout << "Si tu desertes, tu seras execute." << std::endl;
			std::cout << "Tu veux toujours deserter? (y/..) " << std::endl;
			char adventureChoice_ = _getch();

			if (adventureChoice_ == 'y')
			{
				std::cout << player.getName() << " meurt execute" << std::endl;
				return EXIT_FAILURE;
			}


			else if (adventureChoice_ == 'n')
			{
				std::cout << "Quelle surprise! Allez soldat, va te battre pour Dicemania!" << std::endl << std::endl;
				battle.start();
			}
		}
		player.setHp(battle.getPlayer().getHp());
		//If player is dead, then end program
		if (player.getHp() <= 0)
		{
			std::cout << player.getName() << " meurt au combat " << std::endl;
			return EXIT_FAILURE;
		}
		std::cout << player.getName() << " remporte le combat!" << std::endl;
		std::cout << "hp restants: " << player.getHp() << std::endl;
		player.setNbFights(player.getNbFights() + 1);

		//LOOT PHASE
		Item* lootPtr = nullptr; //item pointer
		//all possible items that can be looted, and their adresses
		HealingPotion healingPot;
		HealingPotion* healingPotPtr = &healingPot;
		ForcePotion forcePot;
		ForcePotion* forcePotPtr = &forcePot;
		Bow bow;
		Bow* bowPtr = &bow;
		Sword_ sword;
		Sword_* swordPtr = &sword;
		Epic epicHammer("epikia", "epik", 30);
		Epic* epicHammerPtr = &epicHammer;
		Inventory lootLottery;
		lootLottery.add(healingPotPtr);
		lootLottery.add(forcePotPtr);
		lootLottery.add(bowPtr);
		lootLottery.add(swordPtr);
		lootLottery.add(epicHammerPtr);
		//LootLottery(lootPtr, lootLottery, player);
		std::cout << "votre inventaire: " << std::endl;
		//player.displayInventory();

		char choice;
		// PREPARATIONS BEFORE GOING TO NEXT ZONE "PHASE"
		do
		{
			std::cout
				<< "continue (press 1)\n"
				<< "inventory (press 2)\n";

			choice = _getch();

			if (choice == '1')
			{
				//Go to next zone
			}
			else if (choice == '2')
			{
				//Access _inventory menu
				char inventoryChoice;
				do
				{
					std::cout <<
						"------------------INVENTORY---------------------\n"
						"drink healing potion (press 1)\n"
						"drink force potion (press 2)\n"
						"equip (press 3)\n"
						"desequip (press 4)\n"
						"throw item (press 5)\n"
						"leave (press 6)\n";

					inventoryChoice = _getch();

					if (inventoryChoice == '1')
					{
						player.drinkHealPotion();
					}
					else if (inventoryChoice == '2')
					{
						player.drinkForcePotion();
					}
					else if (inventoryChoice == '3')
					{
						//player.equip();
					}
					else if (inventoryChoice == '4')
					{
						player.desequip();
					}
					else if (inventoryChoice == '5')
					{
						player.throwItem();
					}
				} while (inventoryChoice != '6');

			}

		} while (choice != '1');
		std::cout << std::endl << std::endl;


		//CHOOSE NEXT AREA "PHASE"
		// n -> north || s -> south || e -> east || o -> west || a -> leave war and raise a family
		//char anotherAdventureChoice = ChooseNextArea();
		/*if (anotherAdventureChoice == 'a')
		{
			//TODO -> random -> heal zone || battle against 1 opponent || battle against 2 opponent
			std::cout << "Farewell, " << player.getName() << std::endl;
		}
		else
		{
			//TODO -> random -> heal zone || battle against 1 opponent || battle against multiple opponents
			int rand_;

			do
			{
				rand_ = 1 + rand() % 100;
			} while (rand_ < 0);

			if (rand_ > 0 && rand_ <= 40)
			{
				//battle against 1 opponent
				Battle battle(player, Monster());
				battle.start();
				//If player is dead, then end program
				if (player.getHp() <= 0)
				{
					std::cout << player.getName() << " meurt au combat " << std::endl;
					return EXIT_FAILURE;
				}
				std::cout << player.getName() << " remporte le combat!" << std::endl;
				std::cout << "hp restants: " << player.getHp() << std::endl;
			}

			else if (rand_ > 40 && rand_ <= 80)
			{
				//TODO -> battle against multiple opponents
				std::vector<Monster> monsters;
				int rand__;
				do
				{
					rand__ = rand() % 5;
				} while (rand__ <= 0);
				for (int i = 0; i < rand__; i++)
				{
					Monster monster;
					monsters.push_back(std::move(monster));
				}
				OneVersusMuch battle;
				battle.setPlayer(player);
				battle.setEnemies(monsters);
				battle.start();
				player.setHp(battle.getPlayer().getHp());
				//If player is dead, then end program
				if (player.getHp() <= 0)
				{
					std::cout << player.getName() << " meurt au combat " << std::endl;
					return EXIT_FAILURE;
				}
				std::cout << player.getName() << " remporte le combat!" << std::endl;
				std::cout << "hp restants: " << player.getHp() << std::endl;
			}

			else if (rand_ > 80 && rand_ <= 100 || rand_ == 0)
			{
				//heal zone
				std::cout << "Tu as trouve des sources chaudes, tu peux te reposer " << std::endl;
				player.setHp(player.getMaxHp());
				std::cout << player.getMaxHp() << " recupere ses forces " << std::endl;
				std::cout << "HP:" << player.getHp() << std::endl;
			}

		}
		player.setNbFights(player.getNbFights() + 1);
		std::cout << "victories: " << player.getNbFights() << std::endl;
	}


	//TODO -> BOSS FIGHT
	std::cout << "boss incoming" << std::endl;
	Battle battle(player, Monster());
	battle.start();
	//If player is dead, then end program
	if (player.getHp() <= 0)
	{
		std::cout << player.getName() << " meurt au combat " << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << player.getName() << " remporte le combat!" << std::endl;
	std::cout << "hp restants: " << player.getHp() << std::endl;



	std::cout << "you saved Dicemania !" << std::endl;

*/
	}
	return EXIT_SUCCESS;
}
