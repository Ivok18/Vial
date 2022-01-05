#include "Battle.h"

Battle::Battle()
{
	
	
}

Battle::Battle(Player& player, Monster monster)
{
	_player = player;
	_monster = monster;
}

Battle::~Battle()
{
}

void Battle::start()
{
	do
	{
		std::cout << "HP:" << _player.getHp() << std::endl;
		char battleChoice;
		do
		{
			std::cout << std::endl;
			std::cout << "Attaquer (a) " << std::endl;
			std::cout << "Defendre (d) " << std::endl;
			std::cout << "Fuir (f) " << std::endl;

			battleChoice = _getch();
		}
		while (battleChoice != 'a' && battleChoice != 'd' && battleChoice != 'f');

		std::cout << std::endl;

		int scorePlayer = rand() % 10;
		int scoreMonster = rand() % 10;

		//attack scenario
		if(battleChoice == 'a')
		{
			if (scorePlayer > scoreMonster)
			{
				_monster.setHpLost(_player.getAtk());
				std::cout << _player.getName() << " inflige " << _player.getAtk() << " de degats a " << _monster.getName() << "(" << (_monster.getHp() <= 0 ? 0 : _monster.getHp()) << "hp)" << std::endl << std::endl;
			}

			else if (scorePlayer < scoreMonster)
			{
				_player.setHpLost(_monster.getAtk());
				std::cout << _monster.getName() << "(" << _monster.getHp() << "hp)" << " pare l'attaque et inflige " << _monster.getAtk() << " de degats a " << _player.getName() << std::endl << std::endl;
			}

			else if (scorePlayer == scoreMonster)
			{
				_monster.setHpLost(_player.getAtk() / 2);
				_player.setHpLost(_monster.getAtk() / 2);
				std::cout << "les coups de " << _player.getName() << " et " << _monster.getName() << " s'entrechoquent!" << std::endl;
				std::cout << _player.getName() << " inflige " << _player.getAtk() / 2 << " de degats a " << _monster.getName() << std::endl << std::endl;
				std::cout << _monster.getName() << "(" << _monster.getHp() << "hp)" << " inflige " << _monster.getAtk() / 2 << " de degats a " << _player.getName() << std::endl;
			}

		}

		else if(battleChoice == 'd')
		{
			if(scorePlayer > scoreMonster)
			{
				std::cout << _player.getName() << " pare l'attaque de " << _monster.getName() << std::endl;
			}

			else if (scorePlayer <= scoreMonster)
			{
				_player.setHpLost(_monster.getAtk() / 2);
				std::cout << _player.getName() << " a laisse un point mort dans sa defense" << std::endl;
				std::cout << _monster.getName() << " inflige " << _monster.getAtk() / 2 << " de degats a " << _player.getName() << std::endl;
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
				_player.setHpLost(_monster.getAtk());
				std::cout << _monster.getName() << " barre la route de " << _player.getName() << " et lui inflige " << _monster.getAtk() << " de degats" << std::endl;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(2));

	} while (_monster.getHp() > 0 && _player.getHp() > 0 && !_player.hasFled());

	std::cout << _player.getHp() << std::endl;

	_player.setEscape(false);
}

Player& Battle::getPlayer()
{
	return _player;
}

void Battle::setPlayer(Player& player)
{
	_player = player;
}
