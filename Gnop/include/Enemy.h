#ifndef ENEMY
#define ENEMY
#include "BattleActor.h"
#include "SFML/Graphics.hpp";

class Enemy : public BattleActor
{
protected:
	sf::Sprite _bodySprite;
	sf::Texture _bodyTexture;

	sf::Sprite _leftWingSprite;
	sf::Texture _leftWingTexture;

	sf::Sprite _rightWingSprite;
	sf::Texture _rightWingTexture;

	sf::Sprite _tailSprite;
	sf::Texture _tailTexture;

	sf::Color _color;

	sf::RectangleShape _healthbarEmpty;
	sf::RectangleShape _healthbar;

	sf::RectangleShape _reactionTimeBarEmpty;
	sf::RectangleShape _reactionTimeBar;

	float _spriteScaleX;
	float _spriteScaleY;
	float _Yoffset = 3.f;
	sf::RectangleShape _hitboxView;

	sf::CircleShape _range; //range

	bool _tracking= false; 
	float _hpLimit; //tracking mode

	std::string _type = "minion";
	

	bool _wingsOpen;

	float _level = 0;
	static int _theLevel;
	sf::Text _levelText;
	float _baseXpDrop = 16.5;
	float _xpDrop; //xp

	float _baseMoneyDrop = 0;
	float _moneyDrop = 0; //money
	
	//float _baseDefense = 0;
	//float _maxDefense = 0;
	//float _defense = 0;

	
	float _baseSpeed = 0;
	float _maxSpeed = 0;
	float _speed = 0;
	
	bool _reacting = false;
	float _iReactionTime = 0;
	float _baseReactionTime = 100;
	float _minReactionTime = 9;
	float _reactionTime = 100;

	bool _playing = false;
	
	

	float _baseAtk = 0;
	float _maxAtk = 0;
	float _atk = 0;

	float _baseMaxHp = 0;
	float _maxHp = 0;
	float _hp = 0;

	static float _groupAtk;
	
	
	

	
	
protected:
	void inits();
		void initSpriteAndTexture();
		void initHitbox();
		void initStats();


public:
	Enemy();
	Enemy(float _magicAtk);
	~Enemy() = default;

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite newSprite);

	sf::Texture& getTexture();
	void setTexture(sf::Texture newTexture);

	sf::FloatRect& getHitbox();
	void setHitBox(sf::FloatRect newHitBox);

	sf::RectangleShape& getHitboxView();
	void setHitboxView(sf::RectangleShape view);

	float getAtk();
	void setAtk(float newAtk);

	float getMaxAtk();
	void setMaxAtk(float maxAtk);

	float getBaseAtk();
	void setBaseAtk(float base);

	static float getGroupAtk();
	static void setGroupAtk(float grpAtk);

	Health& getHealth();
	void setHealth(Health newHealth);

	float getHp();
	void setHp(float hp);

	float getMaxHp();
	void setMaxHp(float maxHp);

	float getBaseMaxHp();
	void setBaseMaxHp(float base);

	Health* getHealthPtr();
	void setHealthPtr(Health* newHealthPtr);

	Mana& getMana();
	virtual void setMana(Mana newMana);

	Mana* getManaPtr();
	void setManaPtr(Mana* newManaPtr);

	float getMagicAtk();
	void setMagicAtk(float newMagicAtk);

	sf::RectangleShape& getHealthBarEmpty();
	void setHealthBarEmpty(sf::RectangleShape healthbarEmpty);

	sf::RectangleShape& getHealthbar();
	void setHealthbar(sf::RectangleShape healthbar);

	sf::RectangleShape& getReactionTimeBarEmpty();
	void setReactionTimeBarEmpty(sf::RectangleShape emptybar);

	sf::RectangleShape& getReactionTimeBar();
	void setReactionTimeBar(sf::RectangleShape bar);

	bool reacting();
	void isReacting(bool boolean);

	float getiReactionTime();
	void setIReactionTime(float i);
	
	
	float& getYOffset();
	void setYOffset(float newYOffset);

	float getSpeed();
	void setSpeed(float speed);

	float getMaxSpeed();
	void setMaxSpeed(float max);

	float getBaseSpeed();
	void setBaseSpeed(float base);

	
	float getReactionTime();
	void setReactionTime(float reactionTime);

	float getMinReactionTime();
	void setMinReactionTime(float min);

	float getBaseReactionTime();
	void setBaseReactionTime(float base);


	float getLevel();
	void setLevel(float level); 

	float getBaseXpDrop();
	void setBaseXpDrop(float xpDrop);

	float getXpDrop();
	float setXpDrop(float xpDrop);

	float getBaseMoneyDrop();
	void setBaseMoneyDrop(float base);

	float getMoneyDrop();
	void setMoneyDrop(float moneyDrop);

	static void levelUp();
	static void reset();
	void boost();

	sf::CircleShape& getRange();
	void setRange(sf::CircleShape & range);

	bool tracking();
	void isTracking(bool boolean);
	
	bool playing();
	void isPlaying(bool boolean);

	float getHpLimit();
	void setHpLimit(float limit);

	std::string getType();
	void setType(std::string type);

	void getDamage(float damage);


	//-----------------//
	//----//
	sf::Sprite& getBodySprite();
	void setBodySprite(sf::Sprite newBodySprite);

	sf::Texture& getBodyTexture();
	void setBodyTexture(sf::Texture newBodyTexture);
	//----//

	//----//
	sf::Sprite& getLeftWingSprite();
	void setLeftWingSprite(sf::Sprite newLeftWingSprite);

	sf::Texture& getLeftWingTexture();
	void setLeftWingTexture(sf::Texture newLeftWingTexture);
	//----//

	//----//
	sf::Sprite& getRightWingSprite();
	void setRightWingSprite(sf::Sprite newRightWingSprite);

	sf::Texture& getRightWingTexture();
	void setRightWingTexture(sf::Texture newRightWingTexture);
	//----//

	//----//
	sf::Sprite& getTailSprite();
	void setTailSprite(sf::Sprite newTailSprite);

	sf::Texture& getTailTexture();
	void setTailTexture(sf::Texture newTailTexture);
	//----//

	float getSpriteScaleX();
	void setSpriteScaleX(float newSpriteScaleX);

	float getSpriteScaleY();
	void setSpriteScaleY(float newSpriteScaleY);

	bool wingsOpen();
	void openWings(bool boolean);

	Enemy* getEnemyPtr();

	//-----------------//
	sf::Color getColor();
	void setColor(sf::Color newColor);

	sf::Text& getLevelText();
	void setLevelText(sf::Text text);

	void update();
	void draw(sf::RenderWindow& gameWindow);

	BattleActor* getPtr();
};

#endif


