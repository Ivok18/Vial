#ifndef GAME
#define GAME

//GENERIC INCLUDES
#include <SFML/Graphics.hpp>
#include <iostream>

//GAME RELATED INCLUDES
#include "Enemy.h"
#include "Player.h"
#include "Settings.h"
#include "HealthObserver.h"
#include "ManaObserver.h"
#include "Ball.h"
#include "box2d/b2_world.h"
#include <Bloc.h>
#include <SFML/Audio.hpp>



class Game
{
protected:
	//----------------//
	Settings _settings;
	bool _pause = true;
	float totalTimeElapsed = 0.f;
	float _timerLevelUp = 0.f;
	float _timerDictacticiel = 0.f;
	int _iLevelUp = 0;
	int _iWave = 0;
	int _iEnemyRange = 0;
	
	
	b2Vec2 _gravity;
	b2World _world;

	float _money = 100;
	sf::Text _moneyText;
	sf::Font _fontForMoney;
	sf::Texture _textureOfMoney;
	sf::Sprite _spriteOfMoney; //money Ui
	
	sf::Texture _textureOfEmptyXpBar;
	sf::Sprite _spriteOfEmptyXpBar;
	sf::Texture _textureOfFullXp;
	sf::Sprite _spriteOfFullXp; // xp Ui

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
	sf::Sprite _spriteOfLevelUp;
	sf::Text _textForLevelUp;
	sf::Font _fontForLevelUp;
	bool _levelUpTextMovingUp = true;
	bool _levelUpTextMovingDown = false;//level Up

	sf::Texture _textureOfStore;
	sf::Sprite _spriteOfStore;
	bool _storeTextMovingUp = true;
	bool _storeTextMovingDown = false; 
	sf::Texture _textureOfPriceBoxForItems; //store price box 

	sf::Texture _textureOfHealItem;
	sf::Sprite _spriteOfHealItem;
	sf::Sprite _spriteOfBoxPriceHealItem; //heal item price box

	float _priceHealItem = 100;
	sf::Text _healItemPrice;
	sf::Sprite _spriteOfHealItemPriceDecoration; // price heal item;


	sf::Texture _textureOfReductionDamageItem;
	sf::Sprite _spriteOfReductionDamageItem;
	sf::Sprite _spriteOfBoxPriceReductionDamageItem; //reduction dmage item price box

	float _priceReductionDamageItem = 300;
	sf::Text _reductionDamageItemPrice;
	sf::Sprite _spriteOfReductionDamageItemPriceDecoration;
	bool _reductionDamageIsUnlocked = false;// reduction damage item;


	/*sf::Texture _textureOfDefendingWallItem;
	sf::Sprite _spriteOfDefendingWallItem;
	sf::Sprite _spriteOfBoxPriceDefendingWallItem; //defending wall item price box
	*/

	/*float _priceDefendingWallItem = 200;
	sf::Text _defendingWallItemPrice;
	sf::Sprite _spriteOfDefendingWallItemPriceDecoration;
	bool _defendingWallIsUnlocked = false;// price defending wall item;
	*/
	
	sf::Texture _textureOfDictacticielLeftMovement;
	sf::Sprite _spriteOfDictacticielLeftMovement; // dictacticiel

	sf::Texture _textureOfDictacticielRightMovement;
	sf::Sprite _spriteOfDictacticielRightMovement; // dictacticiel

	sf::Texture _textureOfDictacticielUpMovement;
	sf::Sprite _spriteOfDictacticielUpMovement; // dictacticiel

	sf::Texture _textureOfDictacticielDownMovement;
	sf::Sprite _spriteOfDictacticielDownMovement; // dictacticiel

	sf::Texture _textureOfDictacticielAttackMovementWhite;
	sf::Texture _textureOfDictacticielAttackMovementWhite2;
	sf::Texture _textureOfDictacticielAttackMovementRed;
	sf::Texture _textureOfDictacticielAttackMovementRed2;
	sf::Sprite _spriteOfDictacticielAttackMovement; // dictacticiel

	sf::Text _textNextWave; //next wave text

	sf::Text _gameOverText;
	bool _gameOver = false;
	sf::Texture _textureOfGameOver;
	sf::Sprite _spriteOfGameOver;//game over 

	sf::Texture _textureOfRestartButton;
	sf::Sprite _spriteOfRestartButton; //restart button

	sf::Text _winText;
	bool _win = false;
	sf::Texture _textureOfWin;
	sf::Sprite _spriteOfWin;//win

	sf::Texture _textureOfStartingDirection;
	sf::Sprite _spriteOfStartingDirectionRight;
	sf::Sprite _spriteOfStartingDirectionUpAndRight;
	sf::Sprite _spriteOfStartingDirectionDownAndRight; // starting directions

	sf::Texture _textureOfWelcomeScreen;
	sf::Sprite _spriteOfWelcomeScreen; //welcome screen

	sf::Text _textAskingToPickDirection; //text asking to pick a direction

	bool _explanationBallHitEnemy = false;
	bool _explanationBallHitEnemySeen = false;
	sf::Text _textOfExplanationBallHitEnemy;

	bool _explanationBallHitPlayer = false;
	bool _explanationBallHitPlayerSeen = false;
	sf::Text _textOfExplanationBallHitPlayer;

	sf::Text _theDefendingWallText;
	bool _explanationBallHitDefendingWall = false;
	bool _explanationBallHitDefendingWallSeen = false;
	sf::Text _textOfExplanationBallHitDefendingWall;
	
	bool _explanationBallHitEnemyCamp = false;
	bool _explanationBallHitEnemyCampSeen = false;
	sf::Text _textOfExplanationBallHitEnemyCamp;

	bool _explanationBallHitPlayerCamp = false;
	bool _explanationBallHitPlayerCampSeen = false;
	sf::Text _textOfExplanationBallHitPlayerCamp;

	bool _explanationBallHitPlayerCamp2 = false;
	bool _explanationBallHitPlayerCampSeen2 = false;
	sf::Text _textOfExplanationBallHitPlayerCamp2;

	bool _explanationPlayerImmune = false;
	bool _explanationPlayerImmuneSeen= false;
	sf::Text _textOfExplanationPlayerImmune;

	bool _explanationEnemiesTargetingPlayer = false;
	bool _explanationEnemiesTargetingPlayerSeen = false;
	sf::Text _textOfExplanationEnemiesTargetingPlayer;

	bool _explanationReactionSpeedEnemy = false;
	bool _explanationReactionSpeedEnemySeen = false;
	sf::Texture _textureOfExplanationReactionSpeedEnemy;
	sf::Sprite _spriteOfExplanationReactionSpeedEnemy;

	sf::Text _theRedZoneText; 
	sf::Text _theGreenZoneText;
	sf::Text _playerCampDescription;
	sf::Text _indicationForApproachingEnemies;

	sf::Texture _textureOfPlayButton;
	sf::Sprite _spriteOfPlayButton;
	

	int _wave = 1;
	sf::Text _waveText;
	sf::Font _fontForwave;
	sf::Font _fontForTextLevel;
	bool _restore = false;
	int _restoreCounter = 0;
	bool _upgradePhase = false;
	bool _startingPhase = true;
	bool _waveIsInProgress = false;//wave
	

	bool _playerHasLeveledUp = false;
	int _nbOfAbiliyPoints = 0;
	int _nbSpeedPoints = 0;
	int _nbAttackPoints = 0;
	int _nbMaxHpPoints = 0;

	
	Player _player;
	std::vector<Player> _playerStorer;
	sf::Texture _textureOflevelUpView;
	sf::Sprite _spriteOfLevelUpView;//player
										
	Ball _ball; 
	int _intersectCounterForPlayer = 0;
	int _intersectCounterForEnemies = 0;
	sf::RectangleShape _ballView; //ball

	sf::RectangleShape _defendingWall;
	bool _defendingWallIsActive = false; //defending wall

	sf::Texture _textureOfPlayerHealingState;
	sf::Sprite _spriteOfPlayerHealingState;
	bool _playerIsHealing = false; // player healing

	bool _okButtonFlipperHasBeenPressed = false; 
	sf::Texture _textureOfFlipperUnlocked;
	sf::Sprite _spriteOfFlipperUnlocked; 
	bool _flipperIsUnlocked = false; 
	bool _flipperUnleashed = false;//flipper skill unlocked


	bool _okButtonDashHasBeenPressed = false;
	sf::Texture _textureOfDashUnlocked;
	sf::Sprite _spriteOfDashUnlocked;
	bool _dashIsUnlocked = false;
	bool _dashUnleashed = false;//Dash skill unlocked

	bool _okButtonRegenHasBeenPressed = false;
	sf::Texture _textureOfRegenUnlocked;
	sf::Sprite _spriteOfRegenUnlocked;
	bool _regenIsUnlocked = false;
	bool _regenUnleashed = false;//Regen skill unlocked
	



	std::vector<Bloc> _blocsInStore;
	std::vector<Bloc> _blocsInBattle;

	Enemy _enemy;
	int _nbEnemies = 0;
	int _minEnemies = 1;
	int _maxEnemies = 3;
	std::vector<sf::FloatRect> _spawnPoints;
	std::vector<Enemy> _enemies; 
	int _minAlphaInRange = 0;
	int _maxAlphaInRange = 45; 
	float _ultimateAlpha = 255;//enemies

	sf::RectangleShape _ground;
	b2BodyDef _groundBodyDef;
	b2FixtureDef _groundFixtureDef; //ground
	
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


	sf::Music _mainTheme; // main theme
	sf::Music _gameOverTheme; //game over theme
	sf::Music _winTheme; //win theme

	sf::SoundBuffer _levelUpEffectBuffer;
	sf::Sound _levelUpEffectSound; //level up sound

	sf::SoundBuffer _levelUpXpGainEffectBuffer;
	sf::Sound _levelUpXpGainEffectSound; // xp gain with level up sound

	sf::SoundBuffer _xpGainEffectBuffer;
	sf::Sound _xpGainEffectSound; // xp gain sound

	sf::SoundBuffer _moneySpentEffectBuffer;
	sf::Sound _moneySpentEffectSound; // money spent sound

	sf::SoundBuffer _attackEffectBuffer;
	sf::Sound _attackEffectSound; // attack sound

	sf::SoundBuffer _bouncingEffectBuffer;
	sf::Sound _bouncingEffectSound; // bouncing sound -> a ecourter

	sf::SoundBuffer _hitEnemyEffectBuffer;
	sf::Sound _hitEnemyEffectSound; // hit enemy sound

	sf::SoundBuffer _increaseAbilityEffectBuffer;
	sf::Sound _increaseAbilityEffectSound; // increase ability sound

	sf::SoundBuffer _dashEffectBuffer;
	sf::Sound _dashEffectSound; // dash sound 

	sf::SoundBuffer _flipperEffectBuffer;
	sf::Sound _flipperEffectSound; // flipper sound 

	sf::SoundBuffer _regenEffectBuffer;
	sf::Sound _regenEffectSound; // regen sound 

	sf::SoundBuffer _ballSmallingEffectBuffer;
	sf::Sound _ballSmallingEffectSound; // ball smalling sound 

	sf::SoundBuffer _ballGrowingEffectBuffer;
	sf::Sound _ballGrowingEffectSound; // ball growing sound 



	

private:
	void inits();
		void initPlayer();
		void initHealthBarPlayer();
		//---//
		void initEnemies();
		void initHealthBarsOfEnemies();
		void initReactionTimeBarsOfEnemies();
		

	void run();
		void getInputs();
			void getPlayerInputs(sf::Event& event);
		void update();
			void updatePositionOfHealthBarPlayer();
		void render();
public:
	Game();
	Game(Player player);
	~Game();


	void gameOver();
	void win();
	void restart();

	bool checkAnyCollisionBetweenBallAndEnemies();
	bool checkPlayerEntersAnyEnemyRange();
	void updateXp();

};

#endif

