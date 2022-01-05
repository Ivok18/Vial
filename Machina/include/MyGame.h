#ifndef MYGAME
#define MYGAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Monster.h"
#include "Player.h"

constexpr auto speed = 0.09f;

class MyGame
{
protected:
	sf::RenderWindow _gameWindow;
	unsigned _widthOfGameWindow;
	unsigned _heighOfGameWindow;

	sf::Texture _textureOfMap;
	sf::Sprite _spriteOfmap;

	sf::Texture _textureOfRestorationPhase;

	sf::IntRect _playerSpawnPoint;
	sf::IntRect _lootSpawnPoint;

	sf::Texture _textureOfDamageHover;
	sf::Sprite _spriteOfDamageHover;

	sf::Texture _textureOfLore;
	sf::Sprite _spriteOfLore;

	sf::Texture _textureOfSergent;
	sf::Sprite _spriteOfSergent;

	sf::Texture _textureOfSergentQuestion;
	sf::Sprite _spriteOfSergentQuestion;

	sf::Texture _yesTexture;
	sf::Sprite _yesSprite;

	sf::Texture _noTexture;
	sf::Sprite _noSprite;

	sf::Texture _textureOfPath1;
	sf::Sprite _spriteOfPath1;

	sf::Texture _textureOfPath2;
	sf::Sprite _spriteOfPath2;

	sf::Texture _textureOfPath3;
	sf::Sprite _spriteOfPath3;

	sf::Texture _textureOfEvilKing;
	Monster _evilKing;

	sf::Texture _textureOfWin;
	sf::Sprite _spriteOfWin;

	Weapon* _swordLootPtr;

	Sword_ _swordLoot;
	Sword_ _swordModel;
	Weapon* _swordModelPtr;

	Bow _bowLoot;
	Bow _bowModel;
	Weapon* _bowModelPtr;

	Epic _epicHammerLoot;
	Epic _epicHammerModel;
	Weapon* _epicHammerModelPtr;

	HealingPotion _healingPotLoot;
	ForcePotion _forcePotionLoot;

	

	Inventory _inventory;
	Player _player;
	int _nbFights = 0;
	int _nbRestorations = 0;

	sf::Music _startPhaseTheme;
	sf::Music _restorationPhaseTheme;
	sf::Music _battlePhaseTheme;
	sf::Music _bossTheme;
	sf::Music _winTheme;
	sf::SoundBuffer _attackSoundBuffer;
	sf::Sound _attackSound;
	sf::SoundBuffer _warcriesEnemiesSoundBuffer;
	sf::Sound _warcriesEnemiesSound;
	



	std::vector<sf::FloatRect> _spawnPoints;
	sf::FloatRect _enemySpawn;
	sf::RectangleShape _enemySpawnView;
	std::vector<Monster> _enemies;
	float _nbEnemies;
	int _wave = 0;
	int _selectionNaturelleAtk = 10;
	int _selectionNaturelleHp = 100;
	int _selectionNaturelleMaxHp = 100;

	float _totalTimeElapsed = 0.f;

	bool _startPhase = true;
	bool _battlePhase = false;
	bool _playerTurn = false;
	bool _lootPhase = false;
	bool _spawnLoot = false;
	bool _adventurePhase = false;
	bool _restorationPhase = false;
	bool _bossFightPhase = false;
	bool _winPhase = false;
	
	

	

public:
	MyGame();
	~MyGame() = default;

	void inits();
		void initAudio();
		void initMap();
		void initPlayer();
		void initEnemies();
		void initLootLottery();
		void initBoss();

	void run();
		void getInputs();

	void update();
		void updatePlayer();
	void render();

};
#endif

