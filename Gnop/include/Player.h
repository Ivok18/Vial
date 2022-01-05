#ifndef PLAYER
#define PLAYER

#include "BattleActor.h"
#include "SFML/Graphics.hpp"

class Player : public BattleActor
{
protected:

	sf::FloatRect _hitboxOfBasicAtk;
	sf::RectangleShape _viewOfhitBoxOfBasicAtk;

	sf::FloatRect _hitboxOfDash;
	sf::RectangleShape _viewOfHitboxOfDash;


	sf::RectangleShape _healthbarEmpty;
	sf::RectangleShape _healthbar;

	float _baseSpeed;
	float _rotationOfBasicAttack;

	bool _up;
	bool _down;
	bool _left;
	bool _right;
	bool _isAttacking;
	bool _dashing = false;

	float _Yoffset = 3.f;

	float _level = 0;
	sf::Text _levelText;
	float _currentXp = 0;
	float _xpGain = 0;
	float _baseXpToLevelUp = 65;
	float _xpToLevelUp = 100;

	float _baseAtk = 28.3; // 28.3
	float _baseMaxHp = 99.9; // 99.9
	float _maxHp = 101; // 101.1

	sf::CircleShape _range; //range

protected:
	void inits();
		void initSpriteAndTexture();
		void initHitbox();
		void initHitBoxOfBasicAtk();
		void initHitBoxOfDash();
		void initMovement();
		void initStats();

public:
	Player();
	Player(float magicAtk);
	~Player();

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite newSprite);

	sf::Texture& getTexture();
	void setTexture(sf::Texture newTexture);

	sf::FloatRect& getHitbox();
	void setHitBox(sf::FloatRect newHitBox);

	sf::FloatRect& getHitBoxOfBasicAtk();
	void setHitboxOfBasicAtk(sf::FloatRect newHitBoxOfBasicAtk);;

	sf::RectangleShape& getViewOfHitBoxOfBasicAtk();
	void setViewOfHitBoxOfBasicAtk(sf::RectangleShape view);

	sf::FloatRect& getHitboxOfDash();
	void setHitboxOfDash(sf::FloatRect hitbox);

	sf::RectangleShape& getViewOfHitboxOfDash();
	void setViewOfHitboxOfDash(sf::RectangleShape view);

	float getBaseAtk();
	void setBaseAtk(float base);

	float getAtk();
	void setAtk(float newAtk);

	Health& getHealth();
	void setHealth(Health newHealth);

	Health* getHealthPtr();
	void setHealthPtr(Health* newHealthPtr);

	float getBaseMaxHp();
	void setBaseMaxHp(float base);

	float getHp();
	void setHp(float hp);

	float getMaxHp();
	void setMaxHp(float maxHp);


	Mana& getMana();
	void setMana(Mana newMana);

	Mana* getManaPtr();
	void setManaPtr(Mana* newManaPtr);

	float getMagicAtk();
	void setMagicAtk(float newMagicAtk);

	void getDamage(float damage);

	sf::RectangleShape& getHealthBarEmpty();
	void setHealthBarEmpty(sf::RectangleShape healthbarEmpty);

	sf::RectangleShape& getHealthbar();
	void setHealthbar(sf::RectangleShape healthbar);

	float& getYOffset();
	void setYOffset(float newYOffset);

	float getBaseSpeed();
	void setBaseSpeed(float base);

	float getSpeed();
	void setSpeed(float newSpeed);

	float getRotationOfBasicAttack();
	void setRotationOfBasicAttack(float newRotation);

	bool headingUp();
	void isGoingUp(bool boolean);

	bool headingDown();
	void isGoingDown(bool boolean);

	bool headingLeft();
	void isGoingLeft(bool boolean);

	bool headingRight();
	void isGoingRight(bool boolean);

	bool attacking();
	void isAttacking(bool boolean);

	bool dashing();
	void isDashing(bool boolean);

	float getLevel();
	void setLevel(float level);

	float getCurrentXp();
	void setCurrentXp(float currentXp);

	float getXpGain();
	void setXpGain(float gain);

	float getXpToLevelUp();
	void setXpToLevelUp(float xpToUp);

	void levelUp();

	sf::Text& getLevelText();
	void setLevelText(sf::Text text);

	sf::CircleShape& getRange();
	void setRange(sf::CircleShape& range);

	void setPosition(float x, float y);
	void move(float x, float y);

	void update();
	void draw(sf::RenderWindow& gamewindow);

	Damageable* getPtr();
};

#endif


