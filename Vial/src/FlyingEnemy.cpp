#include "FlyingEnemy.h"

FlyingEnemy::FlyingEnemy()
{
	_textureOfFlyingEnemyLeft.loadFromFile("data/flyingEnemyLeft.png");
	_textureOfFlyingEnemyRight.loadFromFile("data/flyingEnemyRight.png");
	_sprite.setTexture(_textureOfFlyingEnemyLeft);
	float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
	float heightEnemy = _textureOfFlyingEnemyLeft.getSize().y * _sprite.getScale().y;
	_sprite.setOrigin(widthEnemy / 2, heightEnemy / 2);
	_sprite.setPosition(1000, 1000);
	_bodyDef.position = b2Vec2(100 / SCALE, 100 / SCALE);
	_bodyDef.type = b2_dynamicBody;
	_shape.SetAsBox(widthEnemy / 2 / SCALE, heightEnemy / 2 / SCALE);
	_fixtureDef.density = 1.f;
	_fixtureDef.shape = &_shape;// SFML & Box2D settings

	_emptyHealthBar.setSize(sf::Vector2f(92, 15));
	float widthHealthbarEmpty = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
	float heightHealthbarEmpty = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
	_emptyHealthBar.setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
	_emptyHealthBar.setOutlineThickness(-1);
	_emptyHealthBar.setOutlineColor(sf::Color::Black);
	_emptyHealthBar.setPosition(-500, -500);
	_foreGroundHealthbar.setSize(sf::Vector2f(widthHealthbarEmpty, heightHealthbarEmpty));
	_foreGroundHealthbar.setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
	_foreGroundHealthbar.setFillColor(sf::Color::Red);
	_foreGroundHealthbar.setPosition(-500, -500); // healthbar

	_hitbox.left = _sprite.getPosition().x - widthEnemy / 2 - 5;
	_hitbox.top = _sprite.getPosition().y - heightEnemy / 2 - 5;
	_hitbox.width = 20 + widthEnemy + 20;
	_hitbox.height = 20 + heightEnemy + 20;
	_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
	_hitboxView.setPosition(_hitbox.left, _hitbox.top);
	_hitboxView.setFillColor(sf::Color::Transparent);
	_hitboxView.setOutlineThickness(-3);
	_hitboxView.setOutlineColor(sf::Color::Red); // hitbox

	_hitboxOfAtk.left = _sprite.getPosition().x + widthEnemy / 2;
	_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
	_hitboxOfAtk.width = widthEnemy / 2;
	_hitboxOfAtk.height = heightEnemy;
	_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));
	_hitboxOfAtkView.setPosition(_hitboxOfAtk.left, _hitboxOfAtk.top);
	_hitboxOfAtkView.setFillColor(sf::Color::Transparent);
	_hitboxOfAtkView.setOutlineThickness(-3);
	_hitboxOfAtkView.setOutlineColor(sf::Color::Red); // atk hitbox

	
	_hitboxOfDash.left = _sprite.getPosition().x - _hitboxOfAtk.width / 2;
	_hitboxOfDash.top = _sprite.getPosition().y;
	_hitboxOfDash.width = _hitboxOfAtk.width;
	_hitboxOfDash.height = 400 * heightEnemy;
	_viewOfHitboxOfDash.setSize(sf::Vector2f(_hitboxOfDash.width, _hitboxOfDash.height));
	_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
	_viewOfHitboxOfDash.setFillColor(sf::Color::Transparent);
	_viewOfHitboxOfDash.setOutlineThickness(-5);
	_viewOfHitboxOfDash.setOutlineColor(sf::Color::Magenta); 	// hitbox of dash

	//_font.loadFromFile(("data/Fonts/arial.ttf"));
	//_levelIndicator.setFont(_font);
	_levelIndicator.setCharacterSize(40);
	_levelIndicator.setFillColor(sf::Color::Black);
	_levelIndicator.setOutlineColor(sf::Color::Black);
	_levelIndicator.setOutlineThickness(1);
	_levelIndicator.setStyle(sf::Text::Bold);
	_levelIndicator.setString(std::to_string(_level)); // level 

	_up = true;
	_maxAtk = 100;
	_maxHp = 100;
}


FlyingEnemy& FlyingEnemy::operator=(FlyingEnemy& enemy)
{
	return FlyingEnemy();
}

std::string FlyingEnemy::getType()
{
	return _type;
}

void FlyingEnemy::setType(std::string type)
{
	_type = type;
}


b2BodyDef& FlyingEnemy::getBodyDef()
{
	return _bodyDef;
}

void FlyingEnemy::setB2BodyDef(b2BodyDef bodyDef)
{
	_bodyDef = bodyDef;
}

b2FixtureDef& FlyingEnemy::getFixtureDef()
{
	return _fixtureDef;
}

void FlyingEnemy::setFixtureDef(b2FixtureDef fixtureDef)
{
	_fixtureDef = fixtureDef;
}

b2Body* FlyingEnemy::getBody()
{
	return _body;
}

void FlyingEnemy::setBody(b2Body* body)
{
	_body = body;
}

b2PolygonShape& FlyingEnemy::getShape()
{
	return _shape;
}

void FlyingEnemy::setShape(b2PolygonShape shape)
{
	_shape = shape;
}

sf::Texture& FlyingEnemy::getTexture()
{
	return _textureOfFlyingEnemyLeft;
}

void FlyingEnemy::setTexture(sf::Texture texture)
{
	_textureOfFlyingEnemyLeft = texture;
}

sf::Texture& FlyingEnemy::getTextureOfFlyingEnemyRight()
{
	return _textureOfFlyingEnemyRight;
}

void FlyingEnemy::setTextureOfFlyingEnemyRight(sf::Texture texture)
{
	_textureOfFlyingEnemyRight = texture;
}


sf::Sprite& FlyingEnemy::getSprite()
{
	return _sprite;
}

void FlyingEnemy::setSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

bool FlyingEnemy::getUpDirection()
{
	return _up;
}

void FlyingEnemy::setUpDirection(bool boolean)
{
	_up = boolean;
}

bool FlyingEnemy::getDownDirection()
{
	return _down;
}

void FlyingEnemy::setDownDirection(bool boolean)
{
	_down = boolean;
}

bool FlyingEnemy::getLeftDirection()
{
	return _left;
}

void FlyingEnemy::setLeftDirection(bool boolean)
{
	_left = boolean;
}

bool FlyingEnemy::getRightDiretion()
{
	return _right;
}

void FlyingEnemy::setRightDirection(bool boolean)
{
	_right = boolean;
}

float FlyingEnemy::getYOffset()
{
	return _Yoffset;
}

void FlyingEnemy::setYOffset(float yOffset)
{
	_Yoffset = yOffset;
}

sf::RectangleShape& FlyingEnemy::getEmptyHealthbar()
{
	return _emptyHealthBar;
}

void FlyingEnemy::setEmptyHealthbar(sf::RectangleShape emptyHealthbar)
{
	_emptyHealthBar = emptyHealthbar;
}

sf::RectangleShape& FlyingEnemy::getForegroundHealthbar()
{
	return _foreGroundHealthbar;
}

void FlyingEnemy::setForegroundHealthbar(sf::RectangleShape foregroundHealthbar)
{
	_foreGroundHealthbar = foregroundHealthbar;
}


sf::FloatRect& FlyingEnemy::getHitbox()
{
	return _hitbox;
}

void FlyingEnemy::setHitbox(sf::FloatRect hitbox)
{
	_hitbox = hitbox;
}

sf::RectangleShape& FlyingEnemy::getHitboxView()
{
	return _hitboxView;
}

void FlyingEnemy::setHitboxView(sf::RectangleShape view)
{
	_hitboxView = view;
}


sf::FloatRect& FlyingEnemy::getHitboxOfAtk()
{
	return _hitboxOfAtk;
}

void FlyingEnemy::setHitboxOfAtk(sf::FloatRect hitboxOfAtk)
{
	_hitboxOfAtk = hitboxOfAtk;
}

sf::RectangleShape& FlyingEnemy::getHitboxOfAtkView()
{
	return _hitboxOfAtkView;
}

void FlyingEnemy::setHitboxOfAtkView(sf::RectangleShape view)
{
	_hitboxOfAtkView = view;
}

sf::FloatRect& FlyingEnemy::getHitboxOfDash()
{
	return _hitboxOfDash;
}

void FlyingEnemy::setHitboxOfDash(sf::FloatRect hitbox)
{
	_hitboxOfDash = hitbox;
}

sf::RectangleShape& FlyingEnemy::getViewOfHitboxOfDash()
{
	return _viewOfHitboxOfDash;
}

void FlyingEnemy::setViewOfHitboxOfDash(sf::RectangleShape view)
{
	_viewOfHitboxOfDash = view;
}

float FlyingEnemy::getBaseAtk()
{
	return _baseAtk;
}

void FlyingEnemy::setBaseAtk(float base)
{
	_baseAtk = base;
}

float FlyingEnemy::getAtk()
{
	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float atk = _baseAtk + (alpha / 255 * _maxAtk) + (1.2 * _level);
		_atk = atk;
	}

	return _atk;
}

void FlyingEnemy::setAtk(float atk)
{
	_atk = atk;
}

float FlyingEnemy::getMaxAtk()
{
	return _maxAtk;
}

void FlyingEnemy::setMaxAtk(float max)
{
	_maxAtk = max;
}


bool FlyingEnemy::attacking()
{
	return _attacking;
}

void FlyingEnemy::isAttacking(bool boolean)
{
	_attacking = boolean;
}

float FlyingEnemy::getSpeed()
{
	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float speed = alpha / 255 * _maxSpeed + (1.1 * _level);
		_speed = speed;
	}

	return _speed;
}

void FlyingEnemy::setSpeed(float speed)
{
	_speed = speed;
}

float FlyingEnemy::getMaxSpeed()
{
	return _maxSpeed;
}

void FlyingEnemy::setMaxSpeed(float max)
{
	_maxSpeed = max;
}

bool FlyingEnemy::daashing()
{
	return _dashing;
}

void FlyingEnemy::isDaashing(bool boolean)
{
	_dashing = boolean;
}

int FlyingEnemy::getLevel()
{
	_level = _theLevel;
	return _level;
}

void FlyingEnemy::setLevel(int level)
{
	_level = level;
}

int FlyingEnemy::_theLevel = 1;


void FlyingEnemy::levelUp()
{
	_theLevel++;
}

void FlyingEnemy::reset()
{
	_theLevel = 1;
}

void FlyingEnemy::boost()
{
	float alpha = static_cast<float>(_color.a);
	float referenceSpeed = getBody()->GetMass() * 9.8f * 0.01f;

	_baseMaxHp += 0.40 * _baseMaxHp;
	_baseMaxHp += ((alpha / 255.f) * _baseMaxHp) + (0.55 * _level);

	_baseAtk += 3.5;
	_baseAtk += ((alpha / 255.f) * _baseAtk) + (0.55 * _level);

	_baseXpDrop += ((0.5 * _baseXpDrop * 1.1 * _level)) / 2;
	_baseXpDrop += ((alpha / 255.f) * _baseXpDrop) + (0.55 * _level);

	_baseMoneyDrop += ((0.5 * _baseMoneyDrop * 1.1 * _level)) / 2;
	_baseMoneyDrop += ((alpha / 255.f) * _baseMoneyDrop) + (0.55 * _level);

	_maxAtk = _baseAtk + (alpha / 255 * _baseAtk) + (0.55 * _level);
	_maxHp = _baseMaxHp + (alpha / 255 * _baseMaxHp) + (0.55 * _level);
	_maxSpeed = (referenceSpeed / 2) + 10;
	_hp = _maxHp;
}

float FlyingEnemy::getBaseXpDrop()
{
	return _baseXpDrop;
}

void FlyingEnemy::setBaseXpDrop(float xpDrop)
{
	_xpDrop = xpDrop;
}

float FlyingEnemy::getBaseMoneyDrop()
{
	return _baseMoneyDrop;
}

void FlyingEnemy::setBaseMoneyDrop(float base)
{
	_baseMoneyDrop = base;
}

float FlyingEnemy::getXpDrop()
{
	float alpha = static_cast<float>(_color.a);
	float xpDrop = _baseXpDrop + (alpha / 255 * _baseXpDrop) + (1.1 * _level);
	_xpDrop = xpDrop;
	return _xpDrop;
}

void FlyingEnemy::setXpDrop(float xpDrop)
{
	_xpDrop = xpDrop;
}

float FlyingEnemy::getMoneyDrop()
{
	float alpha = static_cast<float>(_color.a);
	float moneyDrop = _baseMoneyDrop + (alpha / 255 * _baseMoneyDrop) + (1.1 * _level);
	_moneyDrop = moneyDrop;
	return _moneyDrop;
}

void FlyingEnemy::setMoneyDrop(float moneyDrop)
{
	_moneyDrop = moneyDrop;
}

sf::Font& FlyingEnemy::getFont()
{
	return _font;
}

void FlyingEnemy::setFont(sf::Font font)
{
	_font = font;
}

sf::Text& FlyingEnemy::getLevelIndicator()
{
	return _levelIndicator;
}

void FlyingEnemy::setLevelIndicator(sf::Text string)
{
	_levelIndicator = string;
}

float FlyingEnemy::getBaseMaxHp()
{
	return _baseMaxHp;
}

void FlyingEnemy::setBaseMaxHp(float base)
{
	_baseMaxHp = base;
}

float FlyingEnemy::getMaxHp()
{
	return _maxHp;
}

void FlyingEnemy::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

float FlyingEnemy::getHp()
{
	return _hp;
}

void FlyingEnemy::setHp(float hp)
{
	_hp = hp;
}

sf::Color& FlyingEnemy::getColor()
{
	return _color;
}

void FlyingEnemy::setColor(sf::Color color)
{
	_color = color;
	_sprite.setColor(color);
}




void FlyingEnemy::getDamage(float damage)
{
	_hp = _hp - damage;

}

void FlyingEnemy::update()
{
	float heightHealthBar = _emptyHealthBar.getSize().y;
	float heightEnemy = _textureOfFlyingEnemyLeft.getSize().y;
	float healthBarXposition = _sprite.getPosition().x + 10 * _sprite.getScale().x;
	float healthBarYposition = _sprite.getPosition().y - heightEnemy / 2.f - heightHealthBar / 2.f - _Yoffset;
	_emptyHealthBar.setPosition(healthBarXposition, healthBarYposition);
	_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y); //update healthbar position


	if (_hp >= _maxHp) //full hp
	{
		_foreGroundHealthbar.setSize(sf::Vector2f(92, 15));
	}
	else if (_hp < _maxHp && _hp > 0) //not full hp but at least alive
	{
		
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(widthOfhealthbar, 15));

	} //update state healthbar

	float widthHealthbar = _emptyHealthBar.getSize().x;
	_levelIndicator.setString(std::to_string(getLevel()-1));
	_levelIndicator.setPosition(_emptyHealthBar.getPosition().x - _levelIndicator.getCharacterSize() / 3, healthBarYposition - _levelIndicator.getCharacterSize() / 1.5f); //update level indicator position


	if (_hp > 0)
	{
		_sprite.setPosition(SCALE * _body->GetPosition().x, SCALE * _body->GetPosition().y);
	}




	if (_up)
	{
		float force = _body->GetMass() * 9.8f;
		//float limiter = 0.001f;
		_body->ApplyForce(b2Vec2(0.f, -force), b2Vec2(_body->GetWorldCenter().x, _body->GetWorldCenter().y), true);
	}
	if (_left)
	{
		_facingLeft = true;
		_facingRight = false;
		_body->ApplyLinearImpulse(b2Vec2(-getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
	}
	if (_down)
	{
		_facingLeft = false;
		_facingRight = false;
		_facingDown = true;
		float force = _body->GetMass() * 9.8f;
		float limiter = 0.001f;
		_body->ApplyLinearImpulse(b2Vec2(0.f, getSpeed()), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
	}
	if (_right)
	{
		_facingRight = true;
		_facingLeft = false;
		_body->ApplyLinearImpulse(b2Vec2(getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
	}
	if (_facingRight)
	{

		_sprite.setTexture(_textureOfFlyingEnemyRight);

	}
	if (_facingLeft)
	{
		_sprite.setTexture(_textureOfFlyingEnemyLeft);
	}
	if (_facingDown)
	{
		float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
		_sprite.setRotation(270);
		_hitbox.left = _sprite.getPosition().x - heightEnemy / 2 - 5;
		_hitbox.top = _sprite.getPosition().y - widthEnemy / 2 - 5;
		_hitbox.width = 5 + heightEnemy + 5;
		_hitbox.height = 5 + widthEnemy + 5;
		_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
	}//update enemy position & movement
	else if (!_facingDown)
	{
		float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
		_hitbox.left = _sprite.getPosition().x - widthEnemy / 2 - 30;
		_hitbox.top = _sprite.getPosition().y - heightEnemy / 2 - 30;;
		_hitbox.width = 30 + widthEnemy + 30;
		_hitbox.height = 30 + heightEnemy + 30;
		_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_sprite.setRotation(0);
	}//hitbox
	
	

	_hitboxOfAtkView.setPosition(_hitboxOfAtk.left, _hitboxOfAtk.top);
	if (_attacking)
	{
		if (_facingRight)
		{
			//std::cout << "enemy attacking right" << std::endl;
			float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x + widthEnemy / 2;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
			_hitboxOfAtk.width = widthEnemy / 2;
			_hitboxOfAtk.height = heightEnemy;
			_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));

		}

		else if (_facingLeft)
		{
			//std::cout << "enemy attacking left" << std::endl;
			float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x - widthEnemy;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
			_hitboxOfAtk.width = widthEnemy / 2;
			_hitboxOfAtk.height = heightEnemy;
			_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));

		}

		else if (_facingDown)
		{
			float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x - heightEnemy / 2;
			_hitboxOfAtk.top = _sprite.getPosition().y + widthEnemy / 2;
			_hitboxOfAtk.width = heightEnemy;
			_hitboxOfAtk.height = heightEnemy;
			_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));
		}

		_attacking = false;
	}
	else if (!_attacking)
	{
		float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
		_hitboxOfAtk.left = _sprite.getPosition().x - widthEnemy / 4;
		_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
	}// atk hitbox

	if (!_dashing)
	{
		float widthEnemy = _textureOfFlyingEnemyLeft.getSize().x * _sprite.getScale().x;
		float heightEnemy = _textureOfFlyingEnemyLeft.getSize().y * _sprite.getScale().y;
		_hitboxOfDash.left = _sprite.getPosition().x - _hitboxOfAtk.width / 2;
		_hitboxOfDash.top = _sprite.getPosition().y;
		_hitboxOfDash.width = _hitboxOfAtk.width;
		_hitboxOfDash.height = 400 * heightEnemy;
		_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		_facingDown = false;
		_down = false;
	}

}

void FlyingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
	window.draw(_emptyHealthBar);
	window.draw(_foreGroundHealthbar);
	//window.draw(_hitboxOfAtkView);
	window.draw(_levelIndicator);
	//window.draw(_hitboxView);
	//window.draw(_viewOfHitboxOfDash);
}
