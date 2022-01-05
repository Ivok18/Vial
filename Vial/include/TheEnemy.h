#pragma once
#ifndef THE_ENMEY
#define THE_ENEMY

#include <box2d/b2_body.h>
#include "SFML/Graphics.hpp"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"
#include <iostream>
#include "TheHealth.h"



class TheEnemy
{
protected:
	b2BodyDef _bodyDef;
	b2FixtureDef _fixtureDef;
	b2Body* _body;
	b2PolygonShape _shape;
	
	sf::Sprite _sprite; 
	const float SCALE = 30.f;//SFML & Box2D settings

	std::string _type = " ";

	sf::FloatRect _hitbox;
	sf::RectangleShape _hitboxView; // hitbox

	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _facingLeft = false;
	bool _right = false;
	bool _facingRight = false;//movement

	float _Yoffset = 0.f;
	sf::RectangleShape _emptyHealthBar;
	sf::RectangleShape _foreGroundHealthbar; //healthbar settings

	sf::FloatRect _hitboxOfAtk;
	sf::RectangleShape _hitboxOfAtkView;
	bool _attacking = false; //atk hitbox settings

	int _level = 1;
	sf::Font _font;
	sf::Text _levelIndicator; //level

	float _baseXpDrop = 25;
	float _xpDrop; //xp

	float _baseMoneyDrop = 0;
	float _moneyDrop = 0;

	float _atk = 0;
	float _maxAtk = 0;
	float _hp = 0;
	float _maxHp = 0;
	float _speed = 0;
	float _maxSpeed = 0;//stats

public:
	TheEnemy();
	~TheEnemy() = default;


	virtual std::string getType() = 0;
	virtual void setType(std::string type) = 0;

	virtual b2BodyDef& getBodyDef() = 0;
	virtual void setB2BodyDef(b2BodyDef bodyDef) = 0;

	virtual b2FixtureDef& getFixtureDef() = 0;
	virtual void setFixtureDef(b2FixtureDef fixtureDef) = 0;

	virtual b2Body* getBody() = 0;
	virtual void setBody(b2Body* body) = 0;

	virtual b2PolygonShape& getShape() = 0;
	virtual void setShape(b2PolygonShape shape) = 0;

	virtual sf::Texture& getTexture() = 0;
	virtual void setTexture(sf::Texture texture) = 0;

	virtual sf::Sprite& getSprite() = 0;
	virtual void setSprite(sf::Sprite sprite) = 0;

	virtual bool getUpDirection() = 0;
	virtual void setUpDirection(bool boolean) = 0;

	virtual bool getDownDirection() = 0;
	virtual void setDownDirection(bool boolean) = 0;

	virtual bool getLeftDirection() = 0;
	virtual void setLeftDirection(bool boolean) = 0;

	virtual bool getRightDiretion() = 0;
	virtual void setRightDirection(bool boolean) = 0;

	virtual float getYOffset() = 0;
	virtual void setYOffset(float yOffset) = 0;

	virtual sf::RectangleShape& getEmptyHealthbar() = 0;
	virtual void setEmptyHealthbar(sf::RectangleShape emptyHealthbar) = 0;

	virtual sf::RectangleShape& getForegroundHealthbar() = 0;
	virtual void setForegroundHealthbar(sf::RectangleShape foregroundHealthbar) = 0;

	virtual sf::FloatRect& getHitbox() = 0;
	virtual void setHitbox(sf::FloatRect hitbox) = 0;

	virtual sf::RectangleShape& getHitboxView() = 0;
	virtual void setHitboxView(sf::RectangleShape view) = 0;

	virtual sf::FloatRect& getHitboxOfAtk() = 0;
	virtual void setHitboxOfAtk(sf::FloatRect hitboxOfAtk) = 0;

	virtual sf::RectangleShape& getHitboxOfAtkView() = 0;
	virtual void setHitboxOfAtkView(sf::RectangleShape view) = 0;

	virtual bool attacking() = 0;
	virtual void isAttacking(bool boolean) = 0;

	virtual int getLevel() = 0;
	virtual void setLevel(int level) = 0;

	virtual sf::Font& getFont() = 0;
	virtual void setFont(sf::Font font) = 0;

	virtual sf::Text& getLevelIndicator() = 0;
	virtual void setLevelIndicator(sf::Text string) = 0;

	virtual float getMaxHp() = 0;
	virtual void setMaxHp(float maxHp) = 0;

	virtual float getHp() = 0;
	virtual void setHp(float hp) = 0;

	virtual void getDamage(float damage) = 0;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
};
#endif // !THE_ENMEY