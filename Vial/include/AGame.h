#ifndef AGAME
#define AGAME

#include "MySettings.h"
#include <box2d/b2_world.h>
#include "../../build/Vial/ThePlayer.h"
#include "../../build/Vial/TerrestrialEnemy.h"
#include "../../build/Vial/FlyingEnemy.h"
#include <SFML/Audio.hpp>





class AGame
{
protected:
	MySettings _settings;
	sf::Clock _clock;
	float _totalTimeElapsed = 0.f;
	float _timerLevelUp = 0.f;
	float _timerDash = 0;
	float _timerArrow = 0;
	float _timerDictacticiel = 0.f;
	
	int _iDash = 0;
	int _iLevelUp = 0;
	int _iArrow = 0;
	int _iPunch = 0;
	int _iGoRed = 0;
	


	sf::Font _fontForLevel;
	sf::Texture _cursorTexture;
	sf::Sprite _cursorSprite; //cursor

	float _money = 0;
	sf::Text _moneyText;
	sf::Font _fontForMoney;
	sf::Texture _textureOfMoney;
	sf::Sprite _spriteOfMoney; //money Ui

	sf::Texture _textureOfEmptyXpBar;
	sf::Sprite _spriteOfEmptyXpBar;
	sf::Texture _textureOfFullXp;
	sf::Sprite _spriteOfFullXp; // xp Ui


	int _wave = 0;
	bool _upgradePhase = false;
	sf::Text _waveText;
	sf::Font _fontForwave; // wabe

	sf::Font _fontForTextLevel; 
	bool _playerHasLeveledUp = false;

	bool _restore = false;
	int _restoreCounter = 0; //restore phase

	int _nbOfAbiliyPoints = 0;
	int _nbSpeedPoints = 0;
	int _nbAttackPoints = 0;
	int _nbMaxHpPoints = 0;  //abilityPoints


	sf::Texture _textureOfIncreaseSpeed;
	sf::Sprite _spriteOfIncreaseSpeed;
	sf::Text _speedPointsText; // speed points

	sf::Texture _textureOfIncreaseAttack;
	sf::Sprite _spriteOfIncreaseAttack;
	sf::Text _attackPointsText; // attack points

	sf::Texture _textureOfIncreaseMaxHp;
	sf::Sprite _spriteOfIncreaseMaxHp;
	sf::Text _maxHpPointsText; // maxHp points

	sf::Texture _textureOfLevelUp;
	sf::Texture _textureOfLevelUp4;
	sf::Texture _textureOfLevelUpAttackRight;
	sf::Texture _textureOfLevelUpAttackLeft;
	sf::Sprite _spriteOfLevelUp; 
	sf::Text _textForLevelUp;
	sf::Font _fontForLevelUp;
	bool _levelUpTextMovingUp = true;
	bool _levelUpTextMovingDown = false;//level Up

	sf::Texture _textureOfStore;
	sf::Sprite _spriteOfStore;
	bool _storeTextMovingUp = true;
	bool _storeTextMovingDown = false; //store
	sf::Texture _textureOfPriceBoxForItems; //store price box 

	sf::Texture _textureOfHealItem;
	sf::Sprite _spriteOfHealItem;
	sf::Sprite _spriteOfBoxPriceHealItem; //heal item price box

	float _priceHealItem = 250;
	sf::Text _healItemPrice;
	sf::Sprite _spriteOfHealItemPriceDecoration; // price heal item;


	sf::Texture _textureOfDashItem;
	sf::Sprite _spriteOfDashItem;
	sf::Sprite _spriteOfBoxPriceDashItem; //dash item price box

	float _priceDashItem = 2000;
	sf::Text _dashItemPrice;
	sf::Sprite _spriteOfDashItemPriceDecoration;// price dash item;


	sf::Texture _textureOfFlyItem;
	sf::Sprite _spriteOfFlyItem;
	sf::Sprite _spriteOfBoxPriceFlyItem; //dash item price box

	float _priceFlyItem = 5000;
	sf::Text _FlyItemPrice;
	sf::Sprite _spriteOfFlyItemPriceDecoration;// price dash item;

	sf::Text _gameOverText;
	bool _gameOver = false; 
	sf::Texture _textureOfGameOver;
	sf::Sprite _spriteOfGameOver;//game over 

	bool _flyIsUnlocked = false;
	bool _dashIsUnlocked = false; //skills
						
	sf::Texture _textureOfRestartButton;
	sf::Sprite _spriteOfRestartButton;

	b2Vec2 _gravity;
	b2World _world;

	b2BodyDef _groundBodyDef;
	sf::RectangleShape _ground; //ground

	sf::RectangleShape _leftWall;
	b2Body* _leftWallBody;
	b2BodyDef _leftWallBodyDef;
	b2FixtureDef _leftWallFixtureDef; //left wall

	sf::RectangleShape _rightWall;
	b2BodyDef _rightWallBodyDef;
	b2FixtureDef _rightWallFixtureDef; //right wall

	sf::RectangleShape _ceiling;
	b2BodyDef _ceilingBodyDef;
	b2FixtureDef _ceilingFixtureDef; //ceiling

	ThePlayer _player;
	std::vector<ThePlayer> _playerStorer;
	bool _arrowHitTarget = false;
	

	sf::Texture _textureOfPlayerBowRight;
	sf::Texture _textureOfPlayerBowLeft; //long range textures

	sf::Texture _textureOfPlayerPunchRight;
	sf::Texture _textureOfPlayerPunchLeft; //short range textures

	sf::Texture _textureOfArrow;
	sf::Sprite _spriteOfArrow; //arrow 

	sf::Music _mainTheme; // main theme
	sf::Music _gameOverTheme; //game over theme
	sf::Music _winTheme; //win theme

	sf::SoundBuffer _shortRangeAttackBuffer;
	sf::Sound _shortRangeAttack; //short range attack sound

	sf::SoundBuffer _longRangeAttackBuffer;
	sf::Sound _longRangeAttack; //long range attack sound

	sf::SoundBuffer _levelUpEffectBuffer;
	sf::Sound _levelUpEffectSound; //level up sound

	sf::SoundBuffer _moneySpentEffectBuffer;
	sf::Sound _moneySpentEffectSound; // money spent sound

	sf::SoundBuffer _terrestrialSpawnEffectBuffer;
	sf::Sound _terrestrialSpawnEffectSound; // spawn terrestrial sound

	sf::SoundBuffer _flyingSpawnEffectBuffer;
	sf::Sound _flyingSpawnEffectSound; //spawn flying sound

	sf::SoundBuffer _xpGainEffectBuffer;
	sf::Sound _xpGainEffectSound; // xp gain sound

	sf::SoundBuffer _levelUpXpGainEffectBuffer;
	sf::Sound _levelUpXpGainEffectSound; // xp gain with level up sound

	sf::SoundBuffer _dashEffectBuffer;
	sf::Sound _dashEffectSound; // dash sound



	sf::Texture _textureOfDictacticielLeftMovement;
	sf::Sprite _spriteOfDictacticielLeftMovement; // dictacticiel

	sf::Texture _textureOfDictacticielRightMovement;
	sf::Sprite _spriteOfDictacticielRightMovement; // dictacticiel

	sf::Texture _textureOfDictacticielJumpMovement;
	sf::Sprite _spriteOfDictacticielJumpMovement; // dictacticiel

	sf::Texture _textureOfDictacticielAttackMovementWhite;
	sf::Texture _textureOfDictacticielAttackMovementRed;
	sf::Sprite _spriteOfDictacticielAttackMovement; // dictacticiel

	sf::Texture _textureOfDictacticielSwitchMovement;
	sf::Sprite _spriteOfDictacticielSwitchMovement; // dictacticiel

	sf::Text _textNextWave; //next wave text

	sf::Text _winText;
	bool _win = false;
	sf::Texture _textureOfWin;
	sf::Sprite _spriteOfWin;//win







	std::vector<TerrestrialEnemy> _terrestrialEnemies;
	sf::FloatRect _terrestrialEnemiesSpawnpoint;
	sf::FloatRect _terrestrialEnemiesSpawnpoint2;
	std::vector<FlyingEnemy> _flyingEnemies;
	sf::FloatRect _flyingEnemiesSpawnpoint;
	sf::FloatRect _flyingEnemiesSpawnpointLeft;
	int _minAlphaInRange = 5;
	int _maxAlphaInRange = 50;
	float _ultimateAlpha = 255;//enemies
	
public:
	AGame();
	~AGame() = default;

	void updateTheXp();

	void spawnTerrestrialEnemy();
	void spawnFlyingEnemy();

	void gameOver();
	void win();
	void restart();

	void run();
	void getInputs(sf::Event& event);
	void update();
	void render();

};

#endif


