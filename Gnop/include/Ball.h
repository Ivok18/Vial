#ifndef BALL
#define BALL

#include "GameWorldEntity.h"
#include <box2d/b2_body.h>
#include "SFML/Graphics.hpp"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"
constexpr auto SCALE = 30.f;

class Ball : public GameWorldEntity
{
protected:

	b2BodyDef _bodyDef;
	b2FixtureDef _fixtureDef;
	b2Body* _body;
	b2PolygonShape _shape;  //Box2D settings
							
	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _right = false; 
	float _baseSpeed = 6.f;
	float _currentSpeed = 6.f;//movement (speed = 6.9 sans Box2D / avec speed = 25)

	
	sf::CircleShape _collider;
	bool _hasCollidedWithPlayer = false;
	bool _hasCollidedWithEnemy = false; 
	bool _hasCollidedWithEnemyCamp = false;
	bool _hasCollidedWithPlayerCamp = false;//collision settings

	float _atk = 0;
	
	
			

protected:
	void inits();
		void initSpriteAndTexture();
		void initHitbox();
		void initMovement();

public:
	Ball();
	~Ball() = default;

	b2BodyDef& getBodyDef();
	void setB2BodyDef(b2BodyDef bodyDef);

	b2FixtureDef& getFixtureDef();
	void setFixtureDef(b2FixtureDef fixtureDef);

	b2Body* getBody();
	void setBody(b2Body* body);

	b2PolygonShape& getShape();
	void setShape(b2PolygonShape shape);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite newSprite);

	sf::Texture& getTexture();
	void setTexture(sf::Texture newTexture);

	sf::CircleShape& getCollider();
	void setCollider(sf::CircleShape collider);

	sf::FloatRect& getHitbox();
	void setHitBox(sf::FloatRect newHitBox);

	float getCurrentSpeed();
	void setCurrentSpeed(float newSpeed);

	float getBaseSpeed();
	void setBaseSpeed(float speed);

	float getAtk();
	void setAtk(float atk);
	

	bool headingUp();
	void isGoingUp(bool boolean);

	bool headingDown();
	void isGoingDown(bool boolean);

	bool headingLeft();
	void isGoingLeft(bool boolean);

	bool headingRight();
	void isGoingRight(bool boolean);

	bool hasCollidedWithPlayer();
	void setCollisionWithPlayer(bool boolean);

	bool hasCollidedWithEnemy();
	void setCollisionWithEnemy(bool boolean);

	bool hasCollidedWithEnemyCamp();
	void setCollisionWithEnemyCamp(bool boolean);

	bool hasCollidedWithPlayerCamp();
	void setCollisionWithPlayerCamp(bool boolean);



	void move(float x, float y);

	void update();
	void draw(sf::RenderWindow& gameWindow);
};
#endif


