#ifndef THEPLAYER
#define THEPLAYER
#include <box2d/b2_body.h>
#include "SFML/Graphics.hpp"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"
constexpr auto SCALE = 30.f;

class ThePlayer
{
protected:
	b2BodyDef _bodyDef;
	b2FixtureDef _fixtureDef;
	b2Body* _body;
	b2PolygonShape _shape;
	sf::Texture _texture;
	sf::Texture _textureOfPlayerLeft;
	sf::Sprite _sprite; //SFML & Box2D settings

	sf::FloatRect _hitbox;
	sf::RectangleShape _hitboxView; // hitbox
	
	bool _up = false;
	bool _strongJump = false;
	bool _levitating = false;
	bool _down = false;
	bool _left = false;
	bool _facingLeft = false;
	bool _right = false;
	bool _facingRight = false;//movement
	sf::RectangleShape _emptyHealthBar;
	sf::RectangleShape _foreGroundHealthbar;
	float _Yoffset = 0.f; //healthbar settings

	sf::FloatRect _hitboxOfAtk;
	sf::RectangleShape _hitboxOfAtkView;
	bool _attacking = false; //atk hitbox settings

	int _level = 1;
	sf::Font _font;
	sf::Text _levelIndicator; // level

	float _baseAtk = 18.9;
	float _atk = 20;
	float _baseSpeed = 0;
	float _speed = 0;
	float _baseMaxHp = 98.9;
	float _maxHp = 100;
	float _hp = _maxHp; //stats

	bool _longRangeMode = false; // modes

	float _currentXp = 1;
	float _xpGain = 0;
	float _baseXpToLevelUp = 65;
	float _xpToLevelUp = 0; ;//xp

	sf::FloatRect _hitboxOfDash;
	sf::RectangleShape _viewOfHitboxOfDash;
	bool _dashing = false; //dash



public:
	ThePlayer();
	~ThePlayer() = default;

	b2BodyDef& getBodyDef();
	void setB2BodyDef(b2BodyDef bodyDef);

	b2FixtureDef& getFixtureDef();
	void setFixtureDef(b2FixtureDef fixtureDef);

	b2Body* getBody();
	void setBody(b2Body* body);

	b2PolygonShape& getShape();
	void setShape(b2PolygonShape shape);

	sf::Texture& getTexture();
	void setTexture(sf::Texture texture);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite sprite);

	bool getUpDirection();
	void setUpDirection(bool boolean);

	bool getDownDirection();
	void setDownDirection(bool boolean);

	bool getLeftDirection();
	void setLeftDirection(bool boolean);

	bool getRightDiretion();
	void setRightDirection(bool boolean);

	bool facingRight();
	void isFacingRight(bool boolean);

	bool facingLeft();
	void isFacingLeft(bool boolean);

	float getYOffset();
	void setYOffset(float yOffset);

	sf::RectangleShape& getEmptyHealthbar();
	void setEmptyHealthbar(sf::RectangleShape emptyHealthbar);

	sf::RectangleShape& getForegroundHealthbar();
	void setForegroundHealthbar(sf::RectangleShape foregroundHealthbar);

	sf::FloatRect& getHitbox();
	void setHitbox(sf::FloatRect hitbox);

	sf::RectangleShape& getHitboxView();
	void setHitboxView(sf::RectangleShape view);

	sf::FloatRect& getHitboxOfAtk();
	void setHitboxOfAtk(sf::FloatRect hitboxOfAtk);

	sf::RectangleShape& getHitboxOfAtkView();
	void setHitboxOfAtkView(sf::RectangleShape view);

	sf::FloatRect& getHitboxOfDash();
	void setHitboxOfDash(sf::FloatRect hitbox);

	sf::RectangleShape& getViewOfHitboxOfDash();
	void setViewOfHitboxOfDash(sf::RectangleShape view);

	sf::Texture getTextureOfPlayerLeft();

	float getBaseAtk();
	void setBaseAtk(float baseAtk);

	float getAtk();
	void setAtk(float atk);

	float getBaseSpeed();
	void setBaseSpeed(float base);

	float getSpeed();
	void setSpeed(float speed);

	bool attacking();
	void isAttacking(bool boolean);

	bool dashing();
	void isDashing(bool boolean);

	float getBaseMaxHp();
	void setBaseMaxHp(float maxHp);

	float getMaxHp();
	void setMaxHp(float maxHp);

	float getHp();
	void setHp(float hp);

	bool LongRangeMode();
	void isInLongRangeMode(bool boolean);

	bool strongJump();
	void setStrongJump(bool boolean);

	bool levitating();
	void setLevitation(bool boolean);

	int getLevel();
	void setLevel(int level);

	sf::Text& getLevelIndicator();
	void setLevelIndicator(sf::Text indic);

	float getCurrentXp();
	void setCurrentXp(float currentXp);

	float getXpGain();
	void setXpGain(float gain);

	void levelUp();


	float getXpToLevelUp();
	void setXpToLevelUp(float xpToUp);

	void getDamage(float damage);

	void reset();

	void update();
	void draw(sf::RenderWindow& window);

};

#endif




