#include "MyGame.h"

#include <chrono>
#include <thread>

MyGame::MyGame() : _widthOfGameWindow(1000), _heighOfGameWindow(700)
{
	_gameWindow.create(sf::VideoMode(_widthOfGameWindow, _heighOfGameWindow), " ");
	
}

void MyGame::inits()
{
	initAudio();
	initMap();
	initPlayer();
}

void MyGame::initAudio()
{
	if(!_startPhaseTheme.openFromFile("data/Audio/call your name.ogg"))
	{
		std::cout << "oups" << std::endl;
	}
	_startPhaseTheme.play();

	if(!_battlePhaseTheme.openFromFile("data/Audio/the reluctant heroes.ogg"))
	{
		std::cout << "ouops" << std::endl;
	}
	if(!_restorationPhaseTheme.openFromFile("data/Audio/dragon quest heaven.ogg"))
	{
		std::cout << "oups" << std::endl;
	}
	if(!_bossTheme.openFromFile("data/Audio/boss theme.ogg"))
	{
		std::cout << "oups" << std::endl;
	}
	if(!_winTheme.openFromFile("data/Audio/win.ogg"))
	{
		std::cout << "QDOQSDF" << std::endl;
	}

	if (!_attackSoundBuffer.loadFromFile("data/Audio/laser gun.wav"))
	{
		std::cout << "oups" << std::endl;
	}
	_attackSound.setBuffer(_attackSoundBuffer);

	if(!_warcriesEnemiesSoundBuffer.loadFromFile("data/Audio/warcry enemies.wav"))
	{
		std::cout << "oupsi" << std::endl;
	}
	_warcriesEnemiesSound.setBuffer(_warcriesEnemiesSoundBuffer);
}

void MyGame::initMap()
{
	float widthOfGameWindow = _widthOfGameWindow;
	float heightOfGameWindow = _heighOfGameWindow;
	float widthOfPlayer = _player.getTexture().getSize().x * _player.getSprite().getScale().x;
	_textureOfMap.loadFromFile("data/map.png");
	_textureOfRestorationPhase.loadFromFile("data/restorationPhaseMap.png");
	_spriteOfmap.setTexture(_textureOfMap);
	

	_textureOfLore.loadFromFile("data/lore.png");

	_playerSpawnPoint.left = widthOfGameWindow / 2 - (3 * widthOfPlayer);
	_playerSpawnPoint.top = heightOfGameWindow / 2 + 80;
	_playerSpawnPoint.width = 0.1;
	_playerSpawnPoint.height = 0.1;

	_lootSpawnPoint.left = widthOfGameWindow / 2;
	_lootSpawnPoint.top = heightOfGameWindow / 2;
	_lootSpawnPoint.width = 0.1;
	_lootSpawnPoint.height = 0.1f;

	//&CO
	_spriteOfLore.setTexture(_textureOfLore);
	_spriteOfLore.setScale(1.f, 0.85f); 
	float widthLore = _spriteOfLore.getScale().x * _textureOfLore.getSize().x;
	float heightLore = _spriteOfLore.getScale().y * _textureOfLore.getSize().y;
	
	_spriteOfLore.setOrigin(widthLore / 2.f, heightLore / 2.f);
	_spriteOfLore.setPosition(widthOfGameWindow / 2.f, heightLore / 2.f - 17.f);
	_spriteOfLore.setColor(sf::Color::Yellow); //lore

	_textureOfSergent.loadFromFile("data/sergent.png");
	_spriteOfSergent.setTexture(_textureOfSergent);
	_spriteOfSergent.setPosition(widthOfGameWindow / 2 , heightOfGameWindow / 2 - 50); //sergent

	_textureOfSergentQuestion.loadFromFile("data/sergentQuestion.png");
	_spriteOfSergentQuestion.setTexture(_textureOfSergentQuestion);
	float widthSergentQuestion = _textureOfSergentQuestion.getSize().x * _spriteOfSergentQuestion.getScale().x;
	float heightSergentQuestion = _textureOfSergentQuestion.getSize().y * _spriteOfSergentQuestion.getScale().y;
	_spriteOfSergentQuestion.setOrigin(widthSergentQuestion / 2.f, heightSergentQuestion / 2.f);
	_spriteOfSergentQuestion.setPosition(_spriteOfSergent.getPosition().x, _spriteOfSergent.getPosition().y);
	_spriteOfSergentQuestion.setScale(1.2f, 1.2f); //sergent question
	
	_yesTexture.loadFromFile("data/yes.png");
	_yesSprite.setTexture(_yesTexture);
	_yesSprite.setPosition(_spriteOfSergentQuestion.getPosition().x - widthSergentQuestion /3.f, _spriteOfSergentQuestion.getPosition().y + widthSergentQuestion /5.f);
	_yesSprite.setScale(1.2f, 1.2f);

	_noTexture.loadFromFile("data/no.png");
	_noSprite.setTexture(_noTexture);
	_noSprite.setPosition(_yesSprite.getPosition().x + 45.f,  _yesSprite.getPosition().y);
	_noSprite.setScale(1.2f, 1.1f);

	_textureOfPath1.loadFromFile("data/path1.png");
	_spriteOfPath1.setTexture(_textureOfPath1);
	_spriteOfPath1.setPosition(-1000, -1000);

	_textureOfPath2.loadFromFile("data/path2.png");
	_spriteOfPath2.setTexture(_textureOfPath2);
	_spriteOfPath2.setPosition(-1000, -1000);

	_textureOfPath3.loadFromFile("data/path3.png");
	_spriteOfPath3.setTexture(_textureOfPath3);
	_spriteOfPath3.setPosition(-1000, -1000);

	_textureOfWin.loadFromFile("data/win.png");
	_spriteOfWin.setTexture(_textureOfWin);
	_spriteOfWin.setPosition(-1000, -1000);

}

void MyGame::initPlayer()
{
	float widthOfGameWindow = _widthOfGameWindow;
	float heightOfGameWindow = _heighOfGameWindow;
	_player.setInventory(_inventory);
	_player.getSprite().setPosition(_playerSpawnPoint.left, _playerSpawnPoint.top);
	do
	{
		_textureOfDamageHover.loadFromFile("data/damageHover.png");
	} while (!_textureOfDamageHover.loadFromFile("data/damageHover.png"));
	
	_spriteOfDamageHover.setTexture(_textureOfDamageHover);
	float widthOfDamageHover = _textureOfDamageHover.getSize().x * _spriteOfDamageHover.getScale().x;
	float heightOfDamageHover = _textureOfDamageHover.getSize().y * _spriteOfDamageHover.getScale().y;
	_spriteOfDamageHover.setOrigin(widthOfDamageHover / 2, heightOfDamageHover / 2);
	_spriteOfDamageHover.setPosition(-100, -100);
}

void MyGame::initEnemies()
{
	do
	{
		_nbEnemies = 1 + rand() % 5; // nbEnemies = nbSpawnPoints
	} while (_nbEnemies <= 0);

	float mapSizeY = _textureOfMap.getSize().y * _spriteOfmap.getScale().y;
	float widthOfGameWindow = _widthOfGameWindow;
	float y =( mapSizeY - (20.f / 100.f) * mapSizeY)  / _nbEnemies; // y is distance between origins of the enemies
	float heightOfGameWindow = _heighOfGameWindow;
	float firstSpawnPointXposition = 4 * widthOfGameWindow / 5;
	float firstSpawnPointYposition = heightOfGameWindow / 4; 


	float h = firstSpawnPointYposition;  //starting spawnPoint y pos
	int i = 0;
	while (i < _nbEnemies)
	{
		sf::FloatRect point(firstSpawnPointXposition, h, 0.1f, 0.1f);
		_spawnPoints.push_back(point);
		h += y;
		i++;
	} //creating enemies spawn point

	int j = 0;
	while (j < _spawnPoints.size())
	{
		Monster enemy;
		float enemyXpos = _spawnPoints[j].left;
		float enemyYpos = _spawnPoints[j].top;
		float heightOfEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;
		float widthOfEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
		_enemies.push_back(std::move(enemy));
		_enemies.back().getSprite().setPosition(enemyXpos, enemyYpos - heightOfEnemy / 2.f);
		_enemies.back().getSprite().setOrigin(widthOfEnemy / 2.f, heightOfEnemy / 2.f);
		j++;
	}

	float widthOfEnemySpawn = _enemies.front().getSprite().getScale().x * _enemies.front().getTexture().getSize().x;
	float heightOfEnemySpawn = 0.f;
	for (auto& enemy : _enemies)
	{
		
		float heightOfEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;
		
		enemy.getTexture().loadFromFile("data/enemy.png");
		enemy.getSprite().setTexture(enemy.getTexture());

		heightOfEnemySpawn += heightOfEnemy;
	}
	
	float heightOfEnemy = _enemies.front().getSprite().getScale().y * _enemies.front().getTexture().getSize().y;
	heightOfEnemySpawn += y * (_nbEnemies - 1) - ((_nbEnemies - 1) * y - (_nbEnemies - 1) * (y - heightOfEnemy));
	//heightOfEnemySpawn += y * (_nbEnemies - 1);

	_enemySpawn.left = _enemies.front().getSprite().getPosition().x - widthOfEnemySpawn / 2;
	_enemySpawn.top = _enemies.front().getSprite().getPosition().y - heightOfEnemy / 2;
	_enemySpawn.width = widthOfEnemySpawn;
	_enemySpawn.height = heightOfEnemySpawn;
	_enemySpawnView.setPosition(_enemySpawn.left, _enemySpawn.top);
	_enemySpawnView.setSize(sf::Vector2f(widthOfEnemySpawn, heightOfEnemySpawn));
	_enemySpawnView.setFillColor(sf::Color::Yellow);
}

void MyGame::initLootLottery()
{
	int randLoot;
	do
	{
		randLoot = rand() % 5;
	} while (randLoot < 0);

	if (randLoot == 0)
	{
		//_swordLootPtr = &_swordLoot;
		float swordLootWidth = _swordLoot.getSprite().getScale().x * _swordLoot.getLootTexture().getSize().x;
		float swordLootHeight = _swordLoot.getSprite().getScale().y * _swordLoot.getLootTexture().getSize().y;
		_swordLoot.getSprite().setTexture(_swordLoot.getLootTexture());
		_swordLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
		_lootSpawnPoint.width = swordLootWidth;
		_lootSpawnPoint.height = swordLootHeight;
		//std::cout << _lootSpawnPoint.width << std::endl;
		//std::cout << _lootSpawnPoint.height << std::endl;
	}

	else if(randLoot == 1)
	{
		//_swordLootPtr = &_swordLoot;
		float healLootWidth = _healingPotLoot.getSprite().getScale().x * _healingPotLoot.getLootTexture().getSize().x;
		float healLootHeight = _healingPotLoot.getSprite().getScale().y * _healingPotLoot.getLootTexture().getSize().y;
		_healingPotLoot.getSprite().setTexture(_healingPotLoot.getLootTexture());
		_healingPotLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
		_lootSpawnPoint.width = healLootWidth;
		_lootSpawnPoint.height = healLootHeight;
		//std::cout << _lootSpawnPoint.width << std::endl;
		//std::cout << _lootSpawnPoint.height << std::endl;
		//std::cout << "healing potion" << std::endl;
	}

	else if(randLoot == 2)
	{
		//_swordLootPtr = &_swordLoot;
		float bowLootWidth = _bowLoot.getSprite().getScale().x * _bowLoot.getLootTexture().getSize().x;
		float bowLootHeight = _bowLoot.getSprite().getScale().y * _bowLoot.getLootTexture().getSize().y;
		_bowLoot.getSprite().setTexture(_bowLoot.getLootTexture());
		_bowLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
		_lootSpawnPoint.width = bowLootWidth;
		_lootSpawnPoint.height = bowLootHeight;
		//std::cout << _lootSpawnPoint.width << std::endl;
		//std::cout << _lootSpawnPoint.height << std::endl;
		//std::cout << "bow" << std::endl;
	}

	else if(randLoot == 3)
	{
		//_swordLootPtr = &_swordLoot;
		float forcePotLootWidth = _forcePotionLoot.getSprite().getScale().x * _forcePotionLoot.getLootTexture().getSize().x;
		float forcePotLootHeight = _forcePotionLoot.getSprite().getScale().y * _forcePotionLoot.getLootTexture().getSize().y;
		_forcePotionLoot.getSprite().setTexture(_forcePotionLoot.getLootTexture());
		_forcePotionLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
		_lootSpawnPoint.width = forcePotLootWidth;
		_lootSpawnPoint.height = forcePotLootHeight;
		//std::cout << _lootSpawnPoint.width << std::endl;
		//std::cout << _lootSpawnPoint.height << std::endl;
		//std::cout << "force potion" << std::endl;
	}

	else if(randLoot == 4)
	{
		//_swordLootPtr = &_swordLoot;
		int epicLoot = rand() % 11;
		if (epicLoot == 10)
		{
			float epicLootWidth = _epicHammerLoot.getSprite().getScale().x * _epicHammerLoot.getLootTexture().getSize().x;
			float epicLootHeight = _epicHammerLoot.getSprite().getScale().y * _epicHammerLoot.getLootTexture().getSize().y;
			_epicHammerLoot.getSprite().setTexture(_epicHammerLoot.getLootTexture());
			_epicHammerLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
			_lootSpawnPoint.width = epicLootWidth;
			_lootSpawnPoint.height = epicLootHeight;
			//std::cout << _lootSpawnPoint.width << std::endl;
			//std::cout << _lootSpawnPoint.height << std::endl;
			//std::cout << "epic hammer" << std::endl;
		}

		else
		{
			float healLootWidth = _healingPotLoot.getSprite().getScale().x * _healingPotLoot.getLootTexture().getSize().x;
			float healLootHeight = _healingPotLoot.getSprite().getScale().y * _healingPotLoot.getLootTexture().getSize().y;
			_healingPotLoot.getSprite().setTexture(_healingPotLoot.getLootTexture());
			_healingPotLoot.getSprite().setPosition(_lootSpawnPoint.left, _lootSpawnPoint.top);
			_lootSpawnPoint.width = healLootWidth;
			_lootSpawnPoint.height = healLootHeight;
			//std::cout << _lootSpawnPoint.width << std::endl;
			//std::cout << _lootSpawnPoint.height << std::endl;
			//std::cout << "healing potion" << std::endl;
		}
	}
		
}

void MyGame::initBoss()
{
	_nbEnemies = 1;

	sf::FloatRect point(_playerSpawnPoint.left + 400 , _playerSpawnPoint.top, 0.1f, 0.1f);
	_spawnPoints.push_back(point);

	
	_enemies.push_back(std::move(_evilKing));
	_textureOfEvilKing.loadFromFile("data/evilKing.png");
	_enemies.back().getSprite().setTexture(_textureOfEvilKing);
	_enemies.back().setTexture(_textureOfEvilKing);
	float heightOfEvilKing = _textureOfEvilKing.getSize().y * _evilKing.getSprite().getScale().y;
	float widthOfEvilKing = _textureOfEvilKing.getSize().x * _evilKing.getSprite().getScale().x;
	_enemies.back().getSprite().setOrigin(widthOfEvilKing / 2.f, heightOfEvilKing / 2.f);
	_enemies.back().getSprite().setTextureRect(sf::IntRect(0, 0, widthOfEvilKing, heightOfEvilKing)); 
	_enemies.back().getSprite().setPosition(_spawnPoints.back().left, _spawnPoints.back().top);
	_enemies.back().setMaxHp(800);
	_enemies.back().setHp(800);
	_enemies.back().setAtk(45);
	
}

void MyGame::run()
{
	inits();
	while (_gameWindow.isOpen())
	{
		sf::Clock clock;
		clock.restart();

		getInputs();
		update();
		render();

		_totalTimeElapsed += clock.getElapsedTime().asMilliseconds();
	}
}

void MyGame::getInputs()
{
	sf::Event event;

	while (_gameWindow.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			_gameWindow.close();
		}

		else if(event.type == sf::Event::MouseButtonPressed)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < _enemies.size() ; i++)
				{
					float heightOfEnemy = _enemies[i].getTexture().getSize().y * _enemies[i].getSprite().getScale().y;
					float widthOfEnemy = _enemies[i].getTexture().getSize().x * _enemies[i].getSprite().getScale().x;
					sf::FloatRect enemyBox(_enemies[i].getSprite().getPosition().x - widthOfEnemy / 2.f, _enemies[i].getSprite().getPosition().y - heightOfEnemy / 2.f, widthOfEnemy, heightOfEnemy);
					if (enemyBox.contains(event.mouseButton.x, event.mouseButton.y))
					{
						float enemyEssence;
						float xpGainedFromEnemy;
						if(_wave <= 5)
						{
							enemyEssence = 25;
							xpGainedFromEnemy = 25;
						}

						else
						{
							enemyEssence = static_cast<float>(_enemies[i].getSprite().getColor().a);
							xpGainedFromEnemy = enemyEssence / 255 * 100;
						}
						
						//std::cout << enemyEssence << std::endl;
						_attackSound.play();
						
						_playerTurn = false;
						_enemies[i].setHpLost(_player.getAtk());
						if(_enemies[i].getHp() <= 0)
						{
							auto it = _enemies.begin();
							int j = 0;
							while (_enemies[j].getHp() != _enemies[i].getHp() )
							{
								j++;
								it++;
							}

							_enemies.erase(it);


							_player.setXpGain(_player.getXpGain() + xpGainedFromEnemy * _player.getLevel());
							std::cout << _player.getXpGain() << std::endl;
							if (_player.getXpGain() > _player.getXpToLevelUp())
							{
								std::cout << "level up!" << std::endl;
								_player.getSprite().setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100 + rand() % 125));
								float bonus = static_cast<float>(_player.getSprite().getColor().a) / 255 * 100;
								_player.setLevel(_player.getLevel() + 1);
								std::cout << "level " << _player.getLevel() << std::endl;
								_player.setXpToLevelUp(_player.getXpToLevelUp() * 2);
								_player.setAtk(_player.getAtk() + 5 * bonus);
								_player.setMaxHp(_player.getMaxHp() + 5 * bonus);
								_player.setHp(_player.getMaxHp());
								std::cout << "hp:" << _player.getHp() << std::endl;
								std::cout << "max hp: " <<_player.getMaxHp() << std::endl;
								std::cout << "atk:" << _player.getAtk() << std::endl;

							}
							
							

							/*if(_player.getXpGain() % 1000 && _player.getXpGain() > 0)
							{
								_player.setHp(_player.getHp() * 2);
								_player.setMaxHp(_player.getMaxHp() * 2);
							}
							*/
							_spriteOfDamageHover.setPosition(-100, -100);

							for (auto& enemy : _enemies)
							{
								enemy.getTexture().loadFromFile("data/enemy.png");
								enemy.getSprite().setTexture(enemy.getTexture());
							}

						}

					}

				}

				if(_enemies.empty() && _battlePhase && !_bossFightPhase)
				{
					_lootPhase = true;
					_battlePhase = false;
					//std::cout << "loot phase !";
					_nbFights++;
					_spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
				}

				else if(_enemies.empty() && _battlePhase && _bossFightPhase)
				{
					_winPhase = true;
					_battlePhase = false;
					_lootPhase = false;
					//std::cout << "game won" << std::endl;
					_spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
				}
				

				float yesSpriteXpos = _yesSprite.getPosition().x;
				float yesSpriteYpos = _yesSprite.getPosition().y;
				float yesSpriteWidth = _yesTexture.getSize().x * _yesSprite.getScale().x;
				float yesSpriteHeight = _yesTexture.getSize().y * _yesSprite.getScale().y;
				sf::FloatRect yesBox(yesSpriteXpos, yesSpriteYpos, yesSpriteWidth, yesSpriteHeight);

				float noSpriteXpos = _noSprite.getPosition().x;
				float noSpriteYpos = _noSprite.getPosition().y;
				float noSpriteWidth = _noTexture.getSize().x * _noSprite.getScale().x;
				float noSpriteHeight = _noTexture.getSize().y * _noSprite.getScale().y;
				sf::FloatRect noBox(noSpriteXpos, noSpriteYpos, noSpriteWidth, noSpriteHeight);


				float winSpriteXpos = _spriteOfWin.getPosition().x;
				float wjnSpriteYpos = _spriteOfWin.getPosition().y;
				float winSpriteWidth = _textureOfWin.getSize().x * _spriteOfWin.getScale().x;
				float winSpriteHeight = _textureOfWin.getSize().y * _spriteOfWin.getScale().y;
				sf::FloatRect winBox(winSpriteXpos, wjnSpriteYpos, winSpriteWidth, winSpriteHeight);

				float widthOfInventory = _inventory.getInventoryView().getSize().x;
				float heightOfInventory = _inventory.getInventoryView().getSize().y;
				float inventoryXpos = _inventory.getInventoryView().getPosition().x;
				float inventoryYpos = _inventory.getInventoryView().getPosition().y;

				float swordWidthInInventory = _swordLoot.getSprite().getScale().x * _swordLoot.getInInventoryTexture().getSize().x;
				float swordHeightInInventory = _swordLoot.getSprite().getScale().y * _swordLoot.getInInventoryTexture().getSize().y;
				float swordSpriteXpos = _swordLoot.getSprite().getPosition().x;
				float swordSpriteYpos = _swordLoot.getSprite().getPosition().y;
				sf::FloatRect inventoryBox(inventoryXpos, inventoryYpos, widthOfInventory, heightOfInventory);
				sf::FloatRect swordBox(swordSpriteXpos, swordSpriteYpos, swordWidthInInventory, swordHeightInInventory);


				if (yesBox.contains(event.mouseButton.x, event.mouseButton.y))
				{
					_battlePhase = true;
					_playerTurn = true;
					_spriteOfLore.setPosition(-1000, -1000);
					_spriteOfSergent.setPosition(-1000, -1000);
					_spriteOfSergentQuestion.setPosition(-1000, -1000);
					_yesSprite.setPosition(-1000, -1000);
					_noSprite.setPosition(-1000, -1000);
				}

				else if (noBox.contains(event.mouseButton.x, event.mouseButton.y))
				{
					_gameWindow.close();
				}

				else if(_lootSpawnPoint.contains(event.mouseButton.x, event.mouseButton.y))
				{
					float playerXpos = _player.getSprite().getPosition().x;
					float playerYpos = _player.getSprite().getPosition().y;
					float swordLootWidth = _swordLoot.getSprite().getScale().x * _swordLoot.getLootTexture().getSize().x;
					float swordLootHeight = _swordLoot.getSprite().getScale().y * _swordLoot.getLootTexture().getSize().y;
					float bowLootWidth = _bowLoot.getSprite().getScale().x * _bowLoot.getLootTexture().getSize().x;
					float bowLootHeight = _bowLoot.getSprite().getScale().y * _bowLoot.getLootTexture().getSize().y;

					
					if(_lootSpawnPoint.width == swordLootWidth)
					{
						//std::cout << "sword!" << std::endl;
						_swordModel.getSprite().setTexture(_swordLoot.getOnPlayerTexture());
						_swordModel.getSprite().setPosition(playerXpos, playerYpos);
						//_player.getWeaponEquiped()->getSprite().setPosition(-1000, -1000);
						//_swordModelPtr = &_swordModel;
						//_player.setWeaponEquiped(_swordModelPtr);
						//_player.getWeaponEquiped()->getSprite().setPosition(playerXpos, playerYpos);

						/*int minX = _inventory.getContainerView().getPosition().x;
						int maxX = minX + _inventory.getContainerView().getSize().x;
						int randX;
						do
						{
							randX = minX + rand() % (maxX - minX + 1);
						}
						while (randX < minX);

						int minY = _inventory.getContainerView().getPosition().y;
						int maxY = minY + _inventory.getContainerView().getSize().y;
						int randY;
						do
						{
							randY = minY + rand() % (maxY - minY + 1);
						}
						while (randY < minY);

						_swordLoot.getSprite().setPosition(randX, randY);
						*/
					} //sword

					if(_lootSpawnPoint.width == bowLootWidth)
					{
						//std::cout << "bow!" << std::endl;
						_bowModel.getSprite().setTexture(_bowModel.getOnPlayerTexture());
						_bowModel.getSprite().setPosition(playerXpos, playerYpos);
						//_player.getWeaponEquiped()->getSprite().setPosition(-1000, -1000);
						//_bowModelPtr = &_bowModel;
						//_player.setWeaponEquiped(_bowModelPtr);
						//_player.getWeaponEquiped()->getSprite().setPosition(playerXpos, playerYpos);
					}//bow
				}

				else if(inventoryBox.contains(event.mouseButton.x, event.mouseButton.y))
				{
					/*if(swordBox.contains(event.mouseButton.x, event.mouseButton.y))
					{
						_swordLoot.getSprite().setTexture(_swordLoot.getOnPlayerTexture());
						_swordLoot.getSprite().setPosition(_player.getSprite().getPosition().x, _player.getSprite().getPosition().y);
						_player.setWeaponEquiped(_swordLootPtr);
					}
					*/
				}

				
				else if(winBox.contains(event.mouseButton.x, event.mouseButton.y))
				{
					_gameWindow.close();
				}
			}
		}

		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Key::Z)
			{
				float heightOfPlayer = _player.getSprite().getScale().y * _player.getTexture().getSize().y;;
				_player.isGoingUp(true);

			}

			if (event.key.code == sf::Keyboard::Key::Q)
			{
				float widthOfPlayer = _player.getSprite().getScale().x * _player.getTexture().getSize().x;
				_player.isGoingLeft(true);
			}

			if (event.key.code == sf::Keyboard::Key::S)
			{
				float heightOfPlayer = _player.getSprite().getScale().y * _player.getTexture().getSize().y;;
				_player.isGoingDown(true);
			}

			if (event.key.code == sf::Keyboard::Key::D)
			{
				float widthOfPlayer = _player.getSprite().getScale().x * _player.getTexture().getSize().x;
				_player.isGoingRight(true);
			}


			if (event.key.code == sf::Keyboard::Key::M)
			{
				for (int i = 0; i < _enemies.size() ; i++)
				{
					float enemyEssence;
					float xpGainedFromEnemy;
					if (_wave <= 5)
					{
						enemyEssence = 25;
						xpGainedFromEnemy = 25;
					}

					else
					{
						enemyEssence = static_cast<float>(_enemies[i].getSprite().getColor().a);
						xpGainedFromEnemy = enemyEssence / 255 * 100;
					}

					//std::cout << "xp gain for this enemy: " << enemyEssence << std::endl;
					_attackSound.play();

					_enemies[i].setHpLost(_player.getAtk());
					if (_enemies[i].getHp() <= 0)
					{
						auto it = _enemies.begin();
						int j = 0;
						while (_enemies[j].getHp() != _enemies[i].getHp())
						{
							j++;
							it++;
						}

						_enemies.erase(it);


						_player.setXpGain(_player.getXpGain() + xpGainedFromEnemy * _player.getLevel());
						std::cout << "xp gain: " << _player.getXpGain() << std::endl;
						if (_player.getXpGain() > _player.getXpToLevelUp())
						{
							std::cout << "level up!" << std::endl;
							_player.getSprite().setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100 + rand() % 125));
							float bonus = static_cast<float>(_player.getSprite().getColor().a) / 255 * 100;
							_player.setLevel(_player.getLevel() + 1);
							std::cout << "level " << _player.getLevel() << std::endl;
							_player.setXpToLevelUp(_player.getXpToLevelUp() * 2);
							_player.setAtk(_player.getAtk() + 5 * bonus);
							_player.setMaxHp(_player.getMaxHp() + 5 * bonus);
							_player.setHp(_player.getMaxHp());
							std::cout << "hp:" << _player.getHp() << std::endl;
							std::cout << "max hp: " << _player.getMaxHp() << std::endl;
							std::cout << "atk:" << _player.getAtk() << std::endl;

						}



						/*if(_player.getXpGain() % 1000 && _player.getXpGain() > 0)
						{
							_player.setHp(_player.getHp() * 2);
							_player.setMaxHp(_player.getMaxHp() * 2);
						}
						*/
						_spriteOfDamageHover.setPosition(-100, -100);

						for (auto& enemy : _enemies)
						{
							enemy.getTexture().loadFromFile("data/enemy.png");
							enemy.getSprite().setTexture(enemy.getTexture());
						}

					}

				}

				if (_enemies.empty() && _battlePhase && !_bossFightPhase)
				{
					_lootPhase = true;
					_battlePhase = false;
					//std::cout << "loot phase !";
					_nbFights++;
					_spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
				}

				else if (_enemies.empty() && _battlePhase && _bossFightPhase)
				{
					_winPhase = true;
					_battlePhase = false;
					_lootPhase = false;
					//std::cout << "game won" << std::endl;
					_spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
				}

				_playerTurn = false;
			}

			

			
			
		}

		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Key::Z)
			{
				_player.isGoingUp(false);
			}

			if (event.key.code == sf::Keyboard::Key::Q)
			{
				_player.isGoingLeft(false);
			}

			if (event.key.code == sf::Keyboard::Key::S)
			{
				_player.isGoingDown(false);
			}

			if (event.key.code == sf::Keyboard::Key::D)
			{
				_player.isGoingRight(false);
			}
		}
	}

}

void MyGame::update()
{

	_gameWindow.clear(sf::Color::White);

	float x = sf::Mouse::getPosition(_gameWindow).x;
	float y = sf::Mouse::getPosition(_gameWindow).y;

	if(_battlePhase)
	{
		if(_startPhaseTheme.getStatus() == 2)
		{
			_startPhaseTheme.stop();
		}
		if(_battlePhaseTheme.getStatus()!=2 && !_bossFightPhase)
		{
			_battlePhaseTheme.play();
		}
		if(_restorationPhaseTheme.getStatus()==2)
		{
			_restorationPhaseTheme.stop();
		}
		//std::cout << "battle" << std::endl;
		_player.update();
		if (_startPhase || _restorationPhase || _lootPhase )
		{
			std::cout << "hp:" << _player.getHp() << std::endl;
			std::cout << "atk:" << _player.getAtk() << std::endl;
			_wave++;
			_spriteOfmap.setTexture(_textureOfMap);
			_player.getSprite().setPosition(_playerSpawnPoint.left, _playerSpawnPoint.top);
			_swordLoot.getSprite().setPosition(-1000, -1000);
			_inventory.getInventoryView().setPosition(-1000, -1000);
			_inventory.getContainerView().setPosition(-1000, -1000);
			_spriteOfPath1.setPosition(-1000, -1000);
			_spriteOfPath2.setPosition(-1000, -1000);
			_spriteOfPath3.setPosition(-1000, -1000);
			_swordLoot.getSprite().setPosition(-1000, -1000);
			_bowLoot.getSprite().setPosition(-1000, -1000);
			_epicHammerLoot.getSprite().setPosition(-1000, -1000);
			_healingPotLoot.getSprite().setPosition(-1000, -1000);
			_forcePotionLoot.getSprite().setPosition(-1000, -1000);

			if (_nbFights + _nbRestorations >= 9	)
			{
				std::cout << _nbFights << std::endl;
				//std::cout << "nb Enemies before init: " << _enemies.size() << std::endl;
				//std::cout << "nb Enemies spawn points before init: " << _spawnPoints.size() << std::endl;

				_bossFightPhase = true;
				if(_bossTheme.getStatus()!=2)
				{
					_battlePhaseTheme.stop();
					_bossTheme.play();
				}
				initBoss();
			}

			else
			{
				//std::cout << "nb Enemies before init: " << _enemies.size() << std::endl;
				//std::cout << "nb Enemies spawn points before init: " << _spawnPoints.size() << std::endl;

				initEnemies();
				int maxAtk = 0;
				int maxHp = 0;

				if(_wave > 5)
				{
					for (auto& enemy : _enemies)
					{
						enemy.getSprite().setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100 + rand() % 125));
						float bonus = static_cast<float>(enemy.getSprite().getColor().a) / 255 * 100;
						enemy.setAtk(bonus + _selectionNaturelleAtk);
						enemy.setMaxHp(bonus + _selectionNaturelleHp);
						enemy.setHp(enemy.getMaxHp());

						if (enemy.getAtk() > maxAtk)
						{
							maxAtk = enemy.getAtk();
						}

						if (enemy.getHp() > maxHp)
						{
							maxHp = enemy.getHp();
						}

					}

					std::cout << "enemies genes selected:" << std::endl;
					std::cout << "most atk" << maxAtk << std::endl;
					std::cout << "most hp" << maxHp << std::endl;
					_selectionNaturelleAtk += maxAtk;
					_selectionNaturelleHp += maxHp;
					
				}
				

					
				
			}
			
			_startPhase = false;
			_restorationPhase = false;
			_lootPhase = false;
			_spawnLoot = false;
			_playerTurn = true;

			if(_bossFightPhase)
			{
				for (auto& enemy : _enemies)
				{
					enemy.getSprite().setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100 + rand() % 125));
					float bonus = static_cast<float>(enemy.getSprite().getColor().a) / 255 * 100;
					int rand_;
					do
					{
						rand_ = 1 + rand() % 4;
					}
					while (rand_ < 1);
					enemy.setAtk(bonus + rand_ *_selectionNaturelleAtk);
					enemy.setMaxHp(bonus + rand_ *_selectionNaturelleHp);
					enemy.setHp(enemy.getMaxHp());
					_evilKing.getSprite().setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100 + rand() % 125));
				}

				//_player.setAtk(100);
				//_player.setMaxHp(200);
				//_player.setHp(_player.getMaxHp());
			}
			
		}

		

		if (_playerTurn)
		{
			if (_enemySpawn.contains(x, y))
			{
				for (auto& enemy : _enemies)
				{
					float enemyWidth = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
					float enemyHeight = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;
					sf::FloatRect enemyBox(enemy.getSprite().getPosition().x - enemyWidth / 2.f, enemy.getSprite().getPosition().y - enemyHeight / 2.f, enemyWidth, enemyHeight);
					if (enemyBox.contains(x, y))
					{
						_spriteOfDamageHover.setPosition(enemy.getSprite().getPosition().x, enemy.getSprite().getPosition().y);
					}
				}

			}

			else
			{
				_spriteOfDamageHover.setPosition(-100, -100);
			}

		}

		else
		{
			
			for (auto& enemy : _enemies)
			{
				if(_warcriesEnemiesSound.getStatus()!=2 && !_bossFightPhase)
				{
					_warcriesEnemiesSound.play();
				}
				//std::cout << "enemy soldier attacks" << std::endl;
				_player.setHpLost(enemy.getAtk());
			}


			_playerTurn = true;

		}


		for (auto& enemy : _enemies)
		{
			enemy.update();
		}

	}
	else if(_lootPhase)
	{
		//std::cout << "loot" << std::endl;
		_player.update();
		updatePlayer();
		if(!_spawnLoot)
		{
			float widthOgGameWindow = _widthOfGameWindow;
			float heightOfGameWindow = _heighOfGameWindow;

			float widthOfPath1 = _textureOfPath1.getSize().x * _spriteOfPath1.getScale().x;
			float heightOfPath1 = _textureOfPath1.getSize().y * _spriteOfPath1.getScale().y;

			float widthOfPath2 = _textureOfPath2.getSize().x * _spriteOfPath2.getScale().x;
			float heightOfPath2 = _textureOfPath2.getSize().y * _spriteOfPath2.getScale().y;

			float widthOfPath3 = _textureOfPath3.getSize().x * _spriteOfPath3.getScale().x;
			float heightOfPath3 = _textureOfPath3.getSize().y * _spriteOfPath3.getScale().y;

			_spriteOfPath1.setPosition(_widthOfGameWindow - widthOfPath1, heightOfGameWindow / 5);
			_spriteOfPath2.setPosition(_widthOfGameWindow - widthOfPath2, _spriteOfPath1.getPosition().y + heightOfPath1 + 50);
			_spriteOfPath3.setPosition(_widthOfGameWindow - widthOfPath3, _spriteOfPath2.getPosition().y + heightOfPath2 + 50);
			
			_inventory.getInventoryView().setSize(sf::Vector2f(widthOgGameWindow, heightOfGameWindow / 6));
			_inventory.getInventoryView().setFillColor(sf::Color::Black);
			_inventory.getInventoryView().setPosition(0, 5 * heightOfGameWindow / 6);

			float widthOfInventoryView = _inventory.getInventoryView().getSize().x * _inventory.getInventoryView().getScale().x;
			float heightOfInventoryView = _inventory.getInventoryView().getSize().y * _inventory.getInventoryView().getScale().y;
			float inventoryViewXpos = _inventory.getInventoryView().getPosition().x;
			float inventoryViewYpos = _inventory.getInventoryView().getPosition().y;
			_inventory.getContainerView().setSize(sf::Vector2f(0.8f * widthOfInventoryView, 0.6f * heightOfInventoryView));
			_inventory.getContainerView().setFillColor(sf::Color(200, 191, 231, 200));
			_inventory.getContainerView().setPosition(inventoryViewXpos + 0.1f * widthOfInventoryView, inventoryViewYpos + 0.2f * heightOfInventoryView);

			initLootLottery();

			
			_spawnLoot = true;
		}

		if( (_player.getSprite().getGlobalBounds().intersects(_spriteOfPath1.getGlobalBounds()) && _lootPhase && !_restorationPhase )
			|| (_player.getSprite().getGlobalBounds().intersects(_spriteOfPath2.getGlobalBounds()) && _lootPhase && !_restorationPhase)
			|| (_player.getSprite().getGlobalBounds().intersects(_spriteOfPath3.getGlobalBounds()) && _lootPhase && !_restorationPhase))
		{
			int rand_;
			do
			{
				rand_ = rand() % 100; //100 is arbitrary
			}
			while (rand_< 0);

			if(rand_ >= 0 && rand_ < 50)
			{
				_battlePhase = true;
			}

			else if(rand_ > 50 && rand_ <= 100)
			{
				_restorationPhase = true;
			}
		}

	}
	if(_restorationPhase)
	{
		if(_battlePhaseTheme.getStatus()==2)
		{
			_battlePhaseTheme.stop();
			_restorationPhaseTheme.play();
		}
		
		_player.update();
		updatePlayer();
		if(_lootPhase)
		{
			_spriteOfmap.setTexture(_textureOfRestorationPhase);
			_player.getSprite().setPosition(_playerSpawnPoint.left, _playerSpawnPoint.top);
			//std::cout << "max hp:" << _player.getMaxHp() << std::endl;
			_player.setHp(_player.getMaxHp());
			_lootPhase = false;
			_nbRestorations++;
			_swordLoot.getSprite().setPosition(-1000, -1000);
			_bowLoot.getSprite().setPosition(-1000, -1000);
			_epicHammerLoot.getSprite().setPosition(-1000, -1000);
			_healingPotLoot.getSprite().setPosition(-1000, -1000);
			_forcePotionLoot.getSprite().setPosition(-1000, -1000);

			if(_nbRestorations > 1)
			{
				_nbRestorations = 1;
			}
		}

		if((_player.getSprite().getGlobalBounds().intersects(_spriteOfPath1.getGlobalBounds()) && _restorationPhase) 
			|| (_player.getSprite().getGlobalBounds().intersects(_spriteOfPath2.getGlobalBounds()) && _restorationPhase)
			|| (_player.getSprite().getGlobalBounds().intersects(_spriteOfPath3.getGlobalBounds()) && _restorationPhase))
			{
				_battlePhase = true;
			}
	}
	if(_winPhase)
	{
		if(_bossTheme.getStatus()==2)
		{
			_bossTheme.stop();
		}
		if(_winTheme.getStatus()!=2)
		{
			_winTheme.play();
		}
		_player.update();
		float widthOfWinTexture = _textureOfWin.getSize().x;
		float heightOfWinTexture = _textureOfWin.getSize().y;
		float widthOfGameWindow = _widthOfGameWindow;
		float heightOfGameWindow = _heighOfGameWindow;
		//_spriteOfWin.setTexture(_textureOfWin);
		//_spriteOfWin.setTextureRect(sf::IntRect(0, 0, widthOfWinTexture, heightOfWinTexture));
		_spriteOfWin.setPosition(widthOfGameWindow / 2 - widthOfWinTexture / 2, heightOfGameWindow / 2 - heightOfWinTexture / 2);
		_player.getSprite().setPosition(-1000, -1000);
	}
	if(_player.getHp() <= 0)
	{
		_gameWindow.close();
	}
	//std::cout << "fights:" << _nbFights << std::endl;
	//std::cout << "restorations:" << _nbRestorations << std::endl;

	
}

void MyGame::updatePlayer()
{
	_player.update();
	if (_player.up())
	{
		_player.getSprite().move(0.f, -speed);
	}
	if (_player.down())
	{
		_player.getSprite().move(0.f, speed);
	}
	if (_player.left())
	{
		_player.getSprite().move(-speed, 0.f);
	}
	if (_player.right())
	{
		_player.getSprite().move(speed, 0.f);
	}
	if(_player.getHp() <= 0)
	{
		_gameWindow.close();
	}
}

void MyGame::render()
{
	//draw everything
	_gameWindow.draw(_spriteOfmap);
	_gameWindow.draw(_spriteOfPath1);
	_gameWindow.draw(_spriteOfPath2);
	_gameWindow.draw(_spriteOfPath3);
	for (auto& enemy : _enemies)
	{
		enemy.draw(_gameWindow);
	}
	_gameWindow.draw(_spriteOfDamageHover);
	_gameWindow.draw(_spriteOfLore);
	_gameWindow.draw(_spriteOfSergent);
	_gameWindow.draw(_spriteOfSergentQuestion);
	_gameWindow.draw(_yesSprite);
	_gameWindow.draw(_noSprite);
	_inventory.draw(_gameWindow);
	_swordLoot.Display(_gameWindow);
	_gameWindow.draw(_spriteOfWin);
	_gameWindow.draw(_swordLoot.getSprite());
	_gameWindow.draw(_bowLoot.getSprite());
	_gameWindow.draw(_epicHammerLoot.getSprite());
	_gameWindow.draw(_forcePotionLoot.getSprite());
	_gameWindow.draw(_healingPotLoot.getSprite());
	_player.draw(_gameWindow);

	//display everything
	_gameWindow.display();
}
