#include "Ball.h"

Ball::Ball()
{
	_texture.loadFromFile("data/Ball/ball.png");
	_sprite.setTexture(_texture);
	float widthBall = _texture.getSize().x * _sprite.getScale().x;
	float heightBall = _texture.getSize().y * _sprite.getScale().y;
	_sprite.setOrigin(widthBall / 2, heightBall / 2);
	_bodyDef.position = b2Vec2(100 / SCALE, 100 / SCALE);
	_sprite.setScale(0.3, 0.3);
	_bodyDef.type = b2_kinematicBody;
	_shape.SetAsBox(widthBall / 2 / SCALE, heightBall / 2 / SCALE);
	_fixtureDef.density = 1.f;
	_fixtureDef.shape = &_shape; // SFML & Box2D settings

	_collider.setRadius(10.f);
	_collider.setOrigin(sf::Vector2f(_collider.getRadius(), _collider.getRadius()));
	_collider.setFillColor(sf::Color::Transparent);
	_collider.setOutlineColor(sf::Color::Black);
	_collider.setOutlineThickness(-3);
	_collider.setPosition(-1000, -1000);
}

void Ball::inits()
{
	initSpriteAndTexture();
	initHitbox();
	initMovement();
}

void Ball::initSpriteAndTexture()
{

}

void Ball::initHitbox()
{
}

void Ball::initMovement()
{
}

b2BodyDef& Ball::getBodyDef()
{
	return _bodyDef;
}

void Ball::setB2BodyDef(b2BodyDef bodyDef)
{
	_bodyDef = bodyDef;
}

b2FixtureDef& Ball::getFixtureDef()
{
	return _fixtureDef;
}

void Ball::setFixtureDef(b2FixtureDef fixtureDef)
{
	_fixtureDef = fixtureDef;
}

b2Body* Ball::getBody()
{
	return _body;
}

void Ball::setBody(b2Body* body)
{
	_body = body;
}

b2PolygonShape& Ball::getShape()
{
	return _shape;
}

void Ball::setShape(b2PolygonShape shape)
{
	_shape = shape;
}

sf::Sprite& Ball::getSprite()
{
	return _sprite;
}

void Ball::setSprite(sf::Sprite newSprite)
{
	_sprite = _sprite;
}

sf::Texture& Ball::getTexture()
{
	return _texture;
}

void Ball::setTexture(sf::Texture newTexture)
{
	_texture = _texture;
}

sf::CircleShape& Ball::getCollider()
{
	return _collider;
}

void Ball::setCollider(sf::CircleShape collider)
{
	_collider = collider;
}

sf::FloatRect& Ball::getHitbox()
{
	return _sprite.getGlobalBounds();
}

void Ball::setHitBox(sf::FloatRect newHitBox)
{
	//?
}

float Ball::getCurrentSpeed()
{
	return _currentSpeed;
}

void Ball::setCurrentSpeed(float newSpeed)
{
	_currentSpeed = newSpeed;
}

float Ball::getBaseSpeed()
{
	return _baseSpeed;
}

void Ball::setBaseSpeed(float speed)
{
	_baseSpeed = speed;
}

float Ball::getAtk()
{
	return _atk;
}

void Ball::setAtk(float atk)
{
	_atk = atk;
}

bool Ball::headingUp()
{
	return _up;
}

void Ball::isGoingUp(bool boolean)
{
	_up = boolean;
}

bool Ball::headingDown()
{
	return _down;
}

void Ball::isGoingDown(bool boolean)
{
	_down = boolean;
}

bool Ball::headingLeft()
{
	return _left;
}

void Ball::isGoingLeft(bool boolean)
{
	_left = boolean;
}

bool Ball::headingRight()
{
	return _right;
}

void Ball::isGoingRight(bool boolean)
{
	_right = boolean;
}

bool Ball::hasCollidedWithPlayer()
{
	return _hasCollidedWithPlayer;
}

void Ball::setCollisionWithPlayer(bool boolean)
{
	_hasCollidedWithPlayer = boolean;
}

bool Ball::hasCollidedWithEnemy()
{
	return _hasCollidedWithEnemy;
}

void Ball::setCollisionWithEnemy(bool boolean)
{
	_hasCollidedWithEnemy = boolean;
}

bool Ball::hasCollidedWithEnemyCamp()
{
	return _hasCollidedWithEnemyCamp;
}

void Ball::setCollisionWithEnemyCamp(bool boolean)
{
	_hasCollidedWithEnemyCamp = boolean;
}

bool Ball::hasCollidedWithPlayerCamp()
{
	return _hasCollidedWithPlayerCamp;
}

void Ball::setCollisionWithPlayerCamp(bool boolean)
{
	_hasCollidedWithPlayerCamp = boolean;
}

void Ball::move(float x, float y)
{
	_collider.move(x, y);
}

void Ball::update()
{
	//_sprite.setPosition(_collider.getPosition().x, _collider.getPosition().y);
	if (_up)
	{
		move(0.f, -_currentSpeed);
	}
	if (_down)
	{
		move(0.f, _currentSpeed);
	}
	if (_left)
	{
		move(-_currentSpeed, 0.f);
	}
	if (_right)
	{
		move(_currentSpeed, 0);
	}
}

void Ball::draw(sf::RenderWindow& gameWindow)
{
	//gameWindow.draw(_sprite);
	gameWindow.draw(_collider);
}

