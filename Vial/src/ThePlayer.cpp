#include "ThePlayer.h"

#include <iostream>

ThePlayer::ThePlayer()
{
	_texture.loadFromFile("data/player.png");
	_textureOfPlayerLeft.loadFromFile("data/playerLeft.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(-100, -100);
    float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
    float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
    _sprite.setOrigin(widthPlayer / 2, heightPlayer / 2);
    _bodyDef.position = b2Vec2(100 / SCALE, 100 / SCALE);
    _bodyDef.type = b2_dynamicBody;
    _shape.SetAsBox(widthPlayer / 2 / SCALE, heightPlayer / 2 / SCALE);
    _fixtureDef.density = 1.f;
    _fixtureDef.shape = &_shape; // SFML & Box2D settings

	_hitbox.left = _sprite.getPosition().x - widthPlayer / 2 - 20;
	_hitbox.top = _sprite.getPosition().y - heightPlayer / 2 - 20;;
	_hitbox.width = 20 + widthPlayer + 20;
	_hitbox.height = 20 + heightPlayer + 20;
	_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
	_hitboxView.setPosition(_hitbox.left, _hitbox.top);
	_hitboxView.setFillColor(sf::Color::Transparent);
	_hitboxView.setOutlineThickness(-3);
	_hitboxView.setOutlineColor(sf::Color::Green); // hitbox

	_emptyHealthBar.setSize(sf::Vector2f(92, 15));
	float widthHealthbarEmpty = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
	float heightHealthbarEmpty = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
	_emptyHealthBar.setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
	_emptyHealthBar.setOutlineThickness(-1);
	_emptyHealthBar.setOutlineColor(sf::Color::Black);
	_emptyHealthBar.setPosition(-500, -500);
	_foreGroundHealthbar.setSize(sf::Vector2f(widthHealthbarEmpty, heightHealthbarEmpty));
	_foreGroundHealthbar.setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
	_foreGroundHealthbar.setFillColor(sf::Color::Green);
	_foreGroundHealthbar.setPosition(-500, -500); // healthbar

	_hitboxOfAtk.left = _sprite.getPosition().x + widthPlayer / 2;
	_hitboxOfAtk.top = _sprite.getPosition().y - heightPlayer / 2;
	_hitboxOfAtk.width = widthPlayer / 2;
	_hitboxOfAtk.height = heightPlayer;
	_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));
	_hitboxOfAtkView.setPosition(-100, -100);
	_hitboxOfAtkView.setFillColor(sf::Color::Transparent);
	_hitboxOfAtkView.setOutlineThickness(-3);
	_hitboxOfAtkView.setOutlineColor(sf::Color::Green); // atk hitbox

	_font.loadFromFile(("data/Fonts/arial.ttf"));
	_levelIndicator.setFont(_font);
	_levelIndicator.setCharacterSize(40); 
	_levelIndicator.setFillColor(sf::Color::Black);
	_levelIndicator.setOutlineColor(sf::Color::Black);
	_levelIndicator.setOutlineThickness(1);
	_levelIndicator.setStyle(sf::Text::Bold);
	_levelIndicator.setString(std::to_string(_level)); // level 
	_levelIndicator.setPosition(-100, -100);

	
	_hitboxOfDash.left = _sprite.getPosition().x;
	_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
	_hitboxOfDash.width = 5 *widthPlayer;
	_hitboxOfDash.height = heightPlayer;
	_viewOfHitboxOfDash.setSize(sf::Vector2f(_hitboxOfDash.width, _hitboxOfDash.height));
	_viewOfHitboxOfDash.setPosition(-100, -100);
	_viewOfHitboxOfDash.setFillColor(sf::Color::Transparent);
	_viewOfHitboxOfDash.setOutlineThickness(-3);
	_viewOfHitboxOfDash.setOutlineColor(sf::Color::Black); // hitbox

}


b2BodyDef& ThePlayer::getBodyDef()
{
	return _bodyDef;
}

void ThePlayer::setB2BodyDef(b2BodyDef bodyDef)
{
	_bodyDef = bodyDef;
}

b2FixtureDef& ThePlayer::getFixtureDef()
{
    return _fixtureDef;
}

void ThePlayer::setFixtureDef(b2FixtureDef fixtureDef)
{
    _fixtureDef = fixtureDef;
}

b2Body* ThePlayer::getBody()
{
    return _body;
}

void ThePlayer::setBody(b2Body* body)
{
    _body = body;
}

b2PolygonShape& ThePlayer::getShape()
{
    return _shape;
}

void ThePlayer::setShape(b2PolygonShape shape)
{
    _shape = shape;
}

sf::Texture& ThePlayer::getTexture()
{
	return _texture;
}

void ThePlayer::setTexture(sf::Texture texture)
{
	_texture = texture;
}

sf::Sprite& ThePlayer::getSprite()
{
	return _sprite;
}

void ThePlayer::setSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

bool ThePlayer::getUpDirection()
{
    return _up;
}

void ThePlayer::setUpDirection(bool boolean)
{
    _up = boolean;
}

bool ThePlayer::getDownDirection()
{
	return _down;
}

void ThePlayer::setDownDirection(bool boolean)
{
	_down = boolean;
}

bool ThePlayer::getLeftDirection()
{
	return _left;
}

void ThePlayer::setLeftDirection(bool boolean)
{
	_left = boolean;
}

bool ThePlayer::getRightDiretion()
{
	return _right;
}

void ThePlayer::setRightDirection(bool boolean)
{
	_right = boolean;
}

bool ThePlayer::facingRight()
{
	return _facingRight;
}

void ThePlayer::isFacingRight(bool boolean)
{
	_facingRight = boolean;
}

bool ThePlayer::facingLeft()
{
	return _facingLeft;
}

void ThePlayer::isFacingLeft(bool boolean)
{
	_facingLeft = boolean;
}

float ThePlayer::getYOffset()
{
	return _Yoffset;
}

void ThePlayer::setYOffset(float yOffset)
{
	_Yoffset = yOffset;
}

sf::RectangleShape& ThePlayer::getEmptyHealthbar()
{
	return _emptyHealthBar;
}

void ThePlayer::setEmptyHealthbar(sf::RectangleShape emptyHealthbar)
{
	_emptyHealthBar = emptyHealthbar;
}

sf::RectangleShape& ThePlayer::getForegroundHealthbar()
{
	return _foreGroundHealthbar;
}

void ThePlayer::setForegroundHealthbar(sf::RectangleShape foregroundHealthbar)
{
	_foreGroundHealthbar = foregroundHealthbar;
}

sf::FloatRect& ThePlayer::getHitbox()
{
	return _hitbox;
}

void ThePlayer::setHitbox(sf::FloatRect hitbox)
{
	_hitbox = hitbox;
}

sf::RectangleShape& ThePlayer::getHitboxView()
{
	return _hitboxView;
}

void ThePlayer::setHitboxView(sf::RectangleShape view)
{
	_hitboxView = view;
}

sf::FloatRect& ThePlayer::getHitboxOfAtk()
{
	return _hitboxOfAtk;
}

void ThePlayer::setHitboxOfAtk(sf::FloatRect hitboxOfAtk)
{
	_hitboxOfAtk = hitboxOfAtk;
}

sf::RectangleShape& ThePlayer::getHitboxOfAtkView()
{
	return _hitboxOfAtkView;
}

void ThePlayer::setHitboxOfAtkView(sf::RectangleShape view)
{
	_hitboxOfAtkView = view;
}

sf::FloatRect& ThePlayer::getHitboxOfDash()
{
	return _hitboxOfDash;
}

void ThePlayer::setHitboxOfDash(sf::FloatRect hitbox)
{
	_hitboxOfDash = hitbox;
}

sf::RectangleShape& ThePlayer::getViewOfHitboxOfDash()
{
	return _viewOfHitboxOfDash;
}

void ThePlayer::setViewOfHitboxOfDash(sf::RectangleShape view)
{
	_viewOfHitboxOfDash = view;
}

sf::Texture ThePlayer::getTextureOfPlayerLeft()
{
	return _textureOfPlayerLeft;
}

float ThePlayer::getBaseAtk()
{
	return _baseAtk;
}

void ThePlayer::setBaseAtk(float baseAtk)
{
	_baseAtk = baseAtk;
}

float ThePlayer::getAtk()
{
	_atk = _baseAtk + (1.1 * _level);
	return _atk;
}

void ThePlayer::setAtk(float atk)
{
	_atk = atk;
}

float ThePlayer::getBaseSpeed()
{
	if (_baseSpeed == 0)
	{
		_baseSpeed = _body->GetMass() * 9.8f * 0.05f;
		return _baseSpeed;
	}
	
	return _baseSpeed;
}

void ThePlayer::setBaseSpeed(float base)
{
	_baseSpeed = base;
}

float ThePlayer::getSpeed()
{
	_speed = getBaseSpeed() + (1.1 * _level);
	return _speed;
}

void ThePlayer::setSpeed(float speed)
{
	_speed = speed;
}

bool ThePlayer::attacking()
{
	return _attacking;
}

void ThePlayer::isAttacking(bool boolean)
{
	_attacking = boolean;
}

bool ThePlayer::dashing()
{
	return _dashing;
}

void ThePlayer::isDashing(bool boolean)
{
	_dashing = boolean;
}

float ThePlayer::getBaseMaxHp()
{
	return _baseMaxHp;
}

void ThePlayer::setBaseMaxHp(float maxHp)
{
	_baseMaxHp = maxHp;
}

float ThePlayer::getMaxHp()
{
	_maxHp = _baseMaxHp + (1.1 * _level);
	return _maxHp;
}

void ThePlayer::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
	
}

float ThePlayer::getHp()
{
	return _hp;
}

void ThePlayer::setHp(float hp)
{
	_hp = hp;
}

bool ThePlayer::LongRangeMode()
{
	return _longRangeMode;
}

void ThePlayer::isInLongRangeMode(bool boolean)
{
	_longRangeMode = boolean;
}

bool ThePlayer::strongJump()
{
	return _strongJump;
}

void ThePlayer::setStrongJump(bool boolean)
{
	_strongJump = boolean;
}

bool ThePlayer::levitating()
{
	return _levitating;
}

void ThePlayer::setLevitation(bool boolean)
{
	_levitating = boolean;
}

int ThePlayer::getLevel()
{
	return _level;
}

void ThePlayer::setLevel(int level)
{
	_level = level;
}

sf::Text& ThePlayer::getLevelIndicator()
{
	return _levelIndicator;
}

void ThePlayer::setLevelIndicator(sf::Text indic)
{
	_levelIndicator = indic;
}

float ThePlayer::getCurrentXp()
{
	return _currentXp;
}

float ThePlayer::getXpGain()
{
	return _xpGain;
}

void ThePlayer::setXpGain(float gain)
{
	_xpGain = gain;
	_currentXp += _xpGain;
}

float ThePlayer::getXpToLevelUp()
{
	float xpToLevelUp = _baseXpToLevelUp + ( _baseXpToLevelUp * 1.1 * _level);
	_xpToLevelUp = xpToLevelUp;
	return _xpToLevelUp;
}

void ThePlayer::setXpToLevelUp(float xpToUp)
{
	_xpToLevelUp = xpToUp;
}

void ThePlayer::levelUp()
{
	_level++;
	_baseMaxHp += (0.35 * _baseMaxHp + (0.1 * _baseMaxHp)) * 0.23;
	_baseSpeed += 0.1;
	_baseAtk += 0.15 * _baseAtk;
}



void ThePlayer::setCurrentXp(float currentXp)
{
	_currentXp = currentXp;
}


void ThePlayer::getDamage(float damage)
{
	_hp = _hp - damage;
}

void ThePlayer::reset()
{
	_texture.loadFromFile("data/player.png");
	_sprite.setTexture(_texture);
	_level = 1;
	_baseAtk = 18.9;
	_atk = 20;
	_baseSpeed = 0;
	_speed = 0;
	_baseMaxHp = 98.9;
	_maxHp = 100;
	_hp = _maxHp;

	_currentXp = 1;
	_xpGain = 0;
	_baseXpToLevelUp = 65;
	_xpToLevelUp = 0;
}

void ThePlayer::update()
{
	float heightHealthBar = _emptyHealthBar.getSize().y;
	float heightPlayer = _texture.getSize().y;
	float healthBarXposition = _sprite.getPosition().x + 10 * _sprite.getScale().x;
	float healthBarYposition = _sprite.getPosition().y - heightPlayer / 2.f - heightHealthBar / 2.f - _Yoffset;
	_emptyHealthBar.setPosition(healthBarXposition, healthBarYposition);
	_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y); //update healthbar position

	if (_hp >= getMaxHp()) //full hp
	{
		_foreGroundHealthbar.setSize(sf::Vector2f(92, 15));
	}

	else if (_hp < getMaxHp() && _hp > 0) //not full hp but at least alive
	{

		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / getMaxHp() * 100.f;
		float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(widthOfhealthbar, 15));
		
	} //update state healthbar

	float widthHealthbar = _emptyHealthBar.getSize().x;
	_levelIndicator.setPosition(_emptyHealthBar.getPosition().x - _levelIndicator.getCharacterSize() / 3, healthBarYposition - _levelIndicator.getCharacterSize() /1.5f);
	_levelIndicator.setString(std::to_string((int)_level)); //update level indicator position & value

	if (_hp > 0)
	{
		_sprite.setPosition(SCALE * _body->GetPosition().x, SCALE * _body->GetPosition().y);
	}
	
	if (_up)
	{
		float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
		_body->ApplyLinearImpulse(b2Vec2(0.f, -force), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
		_up = false;
	}

	if (_strongJump)
	{
		float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
		_body->ApplyLinearImpulse(b2Vec2(0.f, -force * 4), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
		_levitating = true;
		_strongJump = false;
	}

	if (_levitating)
	{
		float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
		_body->ApplyForce(b2Vec2(0.f, -force * 60), b2Vec2(_body->GetWorldCenter().x, _body->GetWorldCenter().y), true);
	}
	

	if (_left)
	{	
		_facingRight = false;
		_facingLeft = true;
		if (_levitating)
		{
			float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
			_body->ApplyForce(b2Vec2(-force * 15, 0.f), b2Vec2(_body->GetWorldCenter().x, _body->GetWorldCenter().y), true);
		}

		else
		{

			_body->ApplyLinearImpulse(b2Vec2(-getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
		}
	}
	if (_right)
	{
		_facingRight = true;
		_facingLeft = false;
		if (_levitating)
		{
			float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
			_body->ApplyForce(b2Vec2(force * 15,0.f ), b2Vec2(_body->GetWorldCenter().x, _body->GetWorldCenter().y), true);
		}

		else
		{
			
			_body->ApplyLinearImpulse(b2Vec2(getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
		}
	
	}

	if (_down)
	{
		if (_levitating)
		{
			_levitating = false;
		}
		float force = _body->GetMass() * 9.8f; //9.8f is the world gravity. Need to find a way to access it 
		_body->ApplyForce(b2Vec2(0.f, 6 * force), b2Vec2(_body->GetWorldCenter().x, _body->GetWorldCenter().y), true);
	}

	if (!_attacking && !_longRangeMode)
	{
		if (_facingRight)
		{
			_sprite.setTexture(_texture);

		}
		if (_facingLeft)
		{
			_sprite.setTexture(_textureOfPlayerLeft);
		}//update player position & movement
	}
	

	float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
	_hitbox.left = _sprite.getPosition().x - widthPlayer / 2 - 20;
	_hitbox.top = _sprite.getPosition().y - heightPlayer / 2 - 20;;
	_hitbox.width = 20 + widthPlayer + 20;
	_hitbox.height = 20 + heightPlayer + 20;
	_hitboxView.setPosition(_hitbox.left, _hitbox.top);//hitbox


	_hitboxOfAtkView.setPosition(_hitboxOfAtk.left, _hitboxOfAtk.top);
	_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));
	if (_attacking)
	{
		if (_facingRight)
		{
			//std::cout << "player attacking right" << std::endl;
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x + widthPlayer / 2;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfAtk.width = widthPlayer / 2;
			_hitboxOfAtk.height = heightPlayer;
			
			
		}

		else if (_facingLeft)
		{
			//std::cout << "player attacking left" << std::endl;
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x - widthPlayer;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfAtk.width = widthPlayer / 2;
			_hitboxOfAtk.height = heightPlayer;
		} 

	}
	else if (!_attacking)
	{	
		float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
		_hitboxOfAtk.left = _sprite.getPosition().x - widthPlayer / 4;
		_hitboxOfAtk.top = _sprite.getPosition().y - heightPlayer / 2;
		
	}// atk hitbox

	if (!_dashing)
	{
		float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
		float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
		_hitboxOfDash.left = _sprite.getPosition().x;
		_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
		_hitboxOfDash.width = 10 * widthPlayer;
		_hitboxOfDash.height = heightPlayer;
		_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
	}
	
							
}

void ThePlayer::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
	window.draw(_emptyHealthBar);
	window.draw(_foreGroundHealthbar);
	//window.draw(_hitboxOfAtkView);
	//window.draw(_viewOfHitboxOfDash);
	window.draw(_levelIndicator);
	//window.draw(_hitboxView);
}
