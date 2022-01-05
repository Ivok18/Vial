#include "OneVersusMuch.h"

#include <string>

OneVersusMuch::OneVersusMuch()
{
	int rand__;
	do
	{
		rand__ = rand() % 5;
	} while (rand__ < 0);

	for (int i = 0; i < rand__; i++)
	{
		_enemies.push_back(std::move(Monster()));
	}
}

OneVersusMuch::OneVersusMuch(Player& player, std::vector<Monster>& monsters)
{
	_enemies = monsters;
}

void OneVersusMuch::start()
{
	
	std::cout << "enemies soldiers incoming!" << std::endl << std::endl;

	while (!_enemies.empty() > 0 && _player.getHp() > 0 && !_player.hasFled())
	{
		std::cout << "HP:" << _player.getHp() << std::endl;
		char battleChoice;
		do
		{
			
			std::cout << "Attaquer (a) " << std::endl;
			std::cout << "Defendre (d) " << std::endl;
			std::cout << "Fuir (f) " << std::endl;

			battleChoice = _getch();
		}
		while (battleChoice != 'a' && battleChoice != 'd' && battleChoice != 'f');

		std::cout << std::endl;

		int scorePlayer = rand() % 10;
		for (auto& enemy : _enemies)
		{
			if(enemy.getHp() > 0)
			{
				std::cout << enemy.getName() << " -> army id:" << enemy.getArmyId() << std::endl;
				int rand__;
				do
				{
					rand__ = rand() % 10;
				} while (rand__ < 0);

				enemy.determineReactionSpeed(rand__);
			}
		}

		std::cout << std::endl;

		//attack scenario
		if (battleChoice == 'a')
		{
			std::cout << "choose target to attack(press armyId)" << std::endl;
			std::string armyIdStr;

			std::cin >> armyIdStr;

			for (auto& enemy : _enemies)
			{
				if(std::stoi(armyIdStr) == enemy.getArmyId())
				{
					std::cout << enemy.getReactionSpeed() << std::endl;
					if (scorePlayer > enemy.getReactionSpeed())
					{
						enemy.setHpLost(_player.getAtk());
						std::cout << _player.getName() << " inflige " << _player.getAtk() << " de degats a " << enemy.getName() << "(" << (enemy.getHp() <= 0 ? 0 : enemy.getHp()) << "hp)" << std::endl << std::endl;
					}

					else if (scorePlayer < enemy.getReactionSpeed())
					{
						_player.setHpLost(enemy.getAtk());
						std::cout << enemy.getName() << "(" << enemy.getHp() << "hp)" << " pare l'attaque et inflige " << enemy.getAtk() << " de degats a " << _player.getName() << std::endl << std::endl;
					}

					else if (scorePlayer == enemy.getReactionSpeed())
					{
						enemy.setHpLost(_player.getAtk() / 2);
						_player.setHpLost(enemy.getAtk() / 2);
						std::cout << "les coups de " << _player.getName() << " et " << enemy.getName() << " s'entrechoquent!" << std::endl;
						std::cout << _player.getName() << " inflige " << _player.getAtk() / 2 << " de degats a " << enemy.getName() << std::endl << std::endl;
						std::cout << enemy.getName() << "(" << enemy.getHp() << "hp)" << " inflige " << enemy.getAtk() / 2 << " de degats a " << _player.getName() << std::endl;
					}
				}

				else
				{
					_player.setHpLost(enemy.getAtk());
					std::cout << enemy.getName() << "(" << enemy.getHp() << "hp)" << " pare l'attaque et inflige " << enemy.getAtk() << " de degats a " << _player.getName() << std::endl << std::endl;
				}
			}
			/*

		}

		else if(battleChoice == 'd')
		{
			if(scorePlayer > scoreMonster)
			{
				std::cout << _player.getName() << " pare l'attaque de " << enemy.getName() << std::endl;
			}

			else if (scorePlayer <= scoreMonster)
			{
				_player.setHpLost(enemy.getAtk() / 2);
				std::cout << _player.getName() << " a laisse un point mort dans sa defense" << std::endl;
				std::cout << enemy.getName() << " inflige " << enemy.getAtk() / 2 << " de degats a " << _player.getName() << std::endl;
			}


		}

		else if(battleChoice == 'f')
		{
			if (scorePlayer > scoreMonster)
			{
				std::cout << _player.getName() << " s'echappe du combat " << std::endl;
				_player.setEscape(true);
			}

			else if (scorePlayer <= scoreMonster)
			{
				_player.setHpLost(enemy.getAtk());
				std::cout << enemy.getName() << " barre la route de " << _player.getName() << " et lui inflige " << enemy.getAtk() << " de degats" << std::endl;
			}
		}
		*/

		
		

		}

		for (auto& enemy : _enemies)
		{
			//enemy dead -> remove from enemies list
			if (enemy.getHp() <= 0)
			{
				auto it = _enemies.begin();
				int i = 0;
				while (_enemies[i].getArmyId() != enemy.getArmyId())
				{
					i++;
				}

				_enemies.erase(it + i);
			}
		}

		if(!_enemies.empty())
		{
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}

	} 

	//std::cout << _player.getHp() << std::endl;

	_player.setEscape(false); 
}

Player& OneVersusMuch::getPlayer()
{
	// TODO: insérer une instruction return ici
	return _player;
}

void OneVersusMuch::setPlayer(Player& player)
{
	_player = player;
}

std::vector<Monster>& OneVersusMuch::getEnemies()
{
	// TODO: insérer une instruction return ici
	return _enemies;
}

void OneVersusMuch::setEnemies(std::vector<Monster>& enemies)
{
	_enemies = enemies;
}
