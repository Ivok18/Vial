#include "TerrestrialEnemy.h"

TerrestrialEnemy::TerrestrialEnemy()
{
	_textureOfTerrestrialEnemyLeft.loadFromFile("data/terrestrialEnemyLeft.png");
	_textureOfTerrestrialEnemyRight.loadFromFile("data/terrestrialEnemyRight.png");
	_sprite.setTexture(_textureOfTerrestrialEnemyLeft);
	float widthEnemy = _textureOfTerrestrialEnemyLeft.getSize().x * _sprite.getScale().x;
	float heightEnemy = _textureOfTerrestrialEnemyLeft.getSize().y * _sprite.getScale().y;
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

	_hitbox.left = _sprite.getPosition().x - widthEnemy / 2 - 20;
	_hitbox.top = _sprite.getPosition().y - heightEnemy / 2 - 20;;
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

	//_font.loadFromFile(("data/Fonts/arial.ttf"));
	//_levelIndicator.setFont(_font);
	_levelIndicator.setCharacterSize(40);
	_levelIndicator.setFillColor(sf::Color::Black);
	_levelIndicator.setOutlineColor(sf::Color::Black);
	_levelIndicator.setOutlineThickness(1);
	_levelIndicator.setStyle(sf::Text::Bold);
	_levelIndicator.setString(std::to_string(_level)); // level 



	_atk = 0;
	_maxAtk = 100;
	_hp = 100;
	_maxHp = 100;
	_speed = 0;
	_maxSpeed = 0;//stats

	

}


TerrestrialEnemy& TerrestrialEnemy::operator=(TerrestrialEnemy& enemy)
{
	return TerrestrialEnemy();
}

std::string TerrestrialEnemy::getType()
{
	return _type;
}

void TerrestrialEnemy::setType(std::string type)
{
	_type = type;
}


b2BodyDef& TerrestrialEnemy::getBodyDef()
{
	return _bodyDef;
}

void TerrestrialEnemy::setB2BodyDef(b2BodyDef bodyDef)
{
	_bodyDef = bodyDef;
}

b2FixtureDef& TerrestrialEnemy::getFixtureDef()
{
	return _fixtureDef;
}

void TerrestrialEnemy::setFixtureDef(b2FixtureDef fixtureDef)
{
	_fixtureDef = fixtureDef;
}

b2Body* TerrestrialEnemy::getBody()
{
	return _body;
}

void TerrestrialEnemy::setBody(b2Body* body)
{
	_body = body;
}

b2PolygonShape& TerrestrialEnemy::getShape()
{
	return _shape;
}

void TerrestrialEnemy::setShape(b2PolygonShape shape)
{
	_shape = shape;
}

sf::Texture& TerrestrialEnemy::getTexture()
{
	return _textureOfTerrestrialEnemyLeft;
}

void TerrestrialEnemy::setTexture(sf::Texture texture)
{
	_textureOfTerrestrialEnemyLeft = texture;
}

sf::Texture& TerrestrialEnemy::getTextureOfTerrestrialEnemyRight()
{
	return _textureOfTerrestrialEnemyRight;
}

void TerrestrialEnemy::setTextureOfTerrestrialEnemyRight(sf::Texture texture)
{
	_textureOfTerrestrialEnemyRight = texture;
}

sf::Texture& TerrestrialEnemy::getTextureOfTerrestrialEnemyLeft()
{
	return _textureOfTerrestrialEnemyLeft;
}

void TerrestrialEnemy::setTextureOfTerrestrialEnemyleft(sf::Texture texture)
{
	_textureOfTerrestrialEnemyLeft = texture;
}

sf::Sprite& TerrestrialEnemy::getSprite()
{
	return _sprite;
}

void TerrestrialEnemy::setSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

bool TerrestrialEnemy::getUpDirection()
{
	return _up;
}

void TerrestrialEnemy::setUpDirection(bool boolean)
{
	_up = boolean;
}

bool TerrestrialEnemy::getDownDirection()
{
	return _down;
}

void TerrestrialEnemy::setDownDirection(bool boolean)
{
	_down = boolean;
}

bool TerrestrialEnemy::getLeftDirection()
{
	return _left;
}

void TerrestrialEnemy::setLeftDirection(bool boolean)
{
	_left = boolean;
}

bool TerrestrialEnemy::getRightDiretion()
{
	return _right;
}

void TerrestrialEnemy::setRightDirection(bool boolean)
{
	_right = boolean;
}

float TerrestrialEnemy::getYOffset()
{
	return _Yoffset;
}

void TerrestrialEnemy::setYOffset(float yOffset)
{
	_Yoffset = yOffset;
}

sf::RectangleShape& TerrestrialEnemy::getEmptyHealthbar()
{
	return _emptyHealthBar;
}

void TerrestrialEnemy::setEmptyHealthbar(sf::RectangleShape emptyHealthbar)
{
	_emptyHealthBar = emptyHealthbar;
}

sf::RectangleShape& TerrestrialEnemy::getForegroundHealthbar()
{
	return _foreGroundHealthbar;
}

void TerrestrialEnemy::setForegroundHealthbar(sf::RectangleShape foregroundHealthbar)
{
	_foreGroundHealthbar = foregroundHealthbar;
}


sf::FloatRect& TerrestrialEnemy::getHitbox()
{
	return _hitbox;
}

void TerrestrialEnemy::setHitbox(sf::FloatRect hitbox)
{
	_hitbox = hitbox;
}

sf::RectangleShape& TerrestrialEnemy::getHitboxView()
{
	return _hitboxView;
}

void TerrestrialEnemy::setHitboxView(sf::RectangleShape view)
{
	_hitboxView = view;
}


sf::FloatRect& TerrestrialEnemy::getHitboxOfAtk()
{
	return _hitboxOfAtk;
}

void TerrestrialEnemy::setHitboxOfAtk(sf::FloatRect hitboxOfAtk)
{
	_hitboxOfAtk = hitboxOfAtk;
}

sf::RectangleShape& TerrestrialEnemy::getHitboxOfAtkView()
{
	return _hitboxOfAtkView;
}

void TerrestrialEnemy::setHitboxOfAtkView(sf::RectangleShape view)
{
	_hitboxOfAtkView = view;
}

float TerrestrialEnemy::getBaseAtk()
{
	return _baseAtk;
}

void TerrestrialEnemy::setBaseAtk(float base)
{
	_baseAtk = base;
}

float TerrestrialEnemy::getAtk()
{

	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float atk = _baseAtk + (alpha / 255 * _maxAtk) + (1.1 * _level);
		_atk = atk;
	}

	return _atk;
}

void TerrestrialEnemy::setAtk(float atk)
{
	_atk = atk;
}

float TerrestrialEnemy::getMaxAtk()
{
	return _maxAtk;
}

void TerrestrialEnemy::setMaxAtk(float max)
{
	_maxAtk = max;
}


bool TerrestrialEnemy::attacking()
{
	return _attacking;
}

void TerrestrialEnemy::isAttacking(bool boolean)
{
	_attacking = boolean;
}

float TerrestrialEnemy::getSpeed()
{
	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float speed = alpha / 255 * _maxSpeed + (1.1 * _level);
		_speed = speed;
	}

	return _speed;
}

void TerrestrialEnemy::setSpeed(float speed)
{
	_speed = speed;
}

float TerrestrialEnemy::getMaxSpeed()
{
	return _maxSpeed;
}

void TerrestrialEnemy::setMaxSpeed(float max)
{
	_maxSpeed = max;
}

int TerrestrialEnemy::getLevel()
{
	_level = _theLevel;
	return _level;
}

void TerrestrialEnemy::setLevel(int level)
{
	_level = level;
}

void TerrestrialEnemy::levelUp()
{
	_theLevel++;
}

void TerrestrialEnemy::reset()
{
	_theLevel = 1;
}

void TerrestrialEnemy::boost()
{
	float alpha = static_cast<float>(_color.a);
	float referenceSpeed = getBody()->GetMass() * 9.8f * 0.05f;

	_baseMaxHp += 0.40 * _baseMaxHp;
	_baseMaxHp+= ((alpha / 255.f) * _baseMaxHp) + (0.55 * _level);

	_baseAtk += 3.5;
	_baseAtk+= ((alpha / 255.f) * _baseAtk) + (0.55 * _level);


	_baseXpDrop += ((0.5 * _baseXpDrop * 1.1 * _level)) / 2;
	_baseXpDrop += ((alpha / 255.f) * _baseXpDrop) + (0.55 * _level);

	_baseMoneyDrop += ((0.5 * _baseMoneyDrop * 1.1 * _level)) / 2;
	_baseMoneyDrop += ((alpha / 255.f) * _baseMoneyDrop) + (0.55 * _level);

	_maxAtk = _baseAtk + (alpha / 255 * _baseAtk) + (0.55 * _level);
	_maxHp = _baseMaxHp + (alpha / 255 * _baseMaxHp) + (0.55 * _level);
	_maxSpeed = (referenceSpeed / 1.5) + 15;
	_hp = _maxHp;
}

float TerrestrialEnemy::getBaseXpDrop()
{
	return _baseXpDrop;
}

void TerrestrialEnemy::setBaseXpDrop(float xpDrop)
{
	_xpDrop = xpDrop;
}

float TerrestrialEnemy::getBaseMoneyDrop()
{
	return _baseMoneyDrop;
}

void TerrestrialEnemy::setBaseMoneyDrop(float base)
{
	_baseMoneyDrop = base;
}

float TerrestrialEnemy::getXpDrop()
{
	float alpha = static_cast<float>(_color.a);
	float xpDrop = _baseXpDrop + (alpha / 255 * _baseXpDrop) + (1.1 * _level);
	_xpDrop = xpDrop;
	return _xpDrop;
}

void TerrestrialEnemy::setXpDrop(float xpDrop)
{
	_xpDrop = xpDrop;
}

float TerrestrialEnemy::getMoneyDrop()
{
	float alpha = static_cast<float>(_color.a);
	float moneyDrop = _baseMoneyDrop + (alpha / 255 * _baseMoneyDrop) + (1.1 * _level);
	_moneyDrop = moneyDrop;
	return _moneyDrop;
}

void TerrestrialEnemy::setMoneyDrop(float moneyDrop)
{
	_moneyDrop = moneyDrop;
}

int TerrestrialEnemy::_theLevel = 1;


sf::Font& TerrestrialEnemy::getFont()
{
	return _font;
}

void TerrestrialEnemy::setFont(sf::Font font)
{
	_font = font;
}

sf::Text& TerrestrialEnemy::getLevelIndicator()
{
	return _levelIndicator;
}

void TerrestrialEnemy::setLevelIndicator(sf::Text string)
{
	_levelIndicator = string;
}

float TerrestrialEnemy::getBaseMaxHp()
{
	return _baseMaxHp;
}

void TerrestrialEnemy::setBaseMaxHp(float base)
{
	_baseMaxHp = base;
}

float TerrestrialEnemy::getMaxHp()
{
	return _maxHp;
}

void TerrestrialEnemy::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

float TerrestrialEnemy::getHp()
{
	return _hp;
}

void TerrestrialEnemy::setHp(float hp)
{
	_hp = hp;
}

sf::Color& TerrestrialEnemy::getColor()
{
	return _color;
}

void TerrestrialEnemy::setColor(sf::Color color)
{
	_color = color;
	_sprite.setColor(color);
	
}




void TerrestrialEnemy::getDamage(float damage)
{
	_hp = _hp - damage;

}

void TerrestrialEnemy::update()
{
	float heightHealthBar = _emptyHealthBar.getSize().y;
	float heightEnemy = _textureOfTerrestrialEnemyLeft.getSize().y;
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
	_levelIndicator.setPosition(_emptyHealthBar.getPosition().x - _levelIndicator.getCharacterSize() / 3, healthBarYposition - _levelIndicator.getCharacterSize() / 1.5f); //update level indicator 


	if (_hp > 0)
	{
		_sprite.setPosition(SCALE * _body->GetPosition().x, SCALE * _body->GetPosition().y);
	}


	if (_up)
	{
		_body->ApplyLinearImpulse(b2Vec2(0.f, -getSpeed()), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
		_up = false;
	}
	if (_left)
	{
		_facingLeft = true;
		_facingRight = false;
		_body->ApplyLinearImpulse(b2Vec2(-getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
	}
	if (_right)
	{
		_facingRight = true;
		_facingLeft = false;
		_body->ApplyLinearImpulse(b2Vec2(getSpeed(), 0.f), b2Vec2(_body->GetPosition().x, _body->GetPosition().y), true);
	}
	if (_facingRight)
	{

		_sprite.setTexture(_textureOfTerrestrialEnemyRight);

	}
	if (_facingLeft)
	{
		_sprite.setTexture(_textureOfTerrestrialEnemyLeft);
	}///update enemy position & movement

	float widthEnemy = _textureOfTerrestrialEnemyLeft.getSize().x * _sprite.getScale().x;
	_hitbox.left = _sprite.getPosition().x - widthEnemy / 2 - 5;
	_hitbox.top = _sprite.getPosition().y - heightEnemy / 2 - 5;;
	_hitbox.width = 5 + widthEnemy + 5;
	_hitbox.height = 5 + heightEnemy + 5;
	_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
	_hitboxView.setPosition(_hitbox.left, _hitbox.top);//hitbox

	_hitboxOfAtkView.setPosition(_hitboxOfAtk.left, _hitboxOfAtk.top);
	_hitboxOfAtkView.setSize(sf::Vector2f(_hitboxOfAtk.width, _hitboxOfAtk.height));
	if (_attacking)
	{

		if (_facingRight)
		{
			//std::cout << "enemy attacking right" << std::endl;
			float widthEnemy = _textureOfTerrestrialEnemyLeft.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x + widthEnemy / 2;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
			_hitboxOfAtk.width = widthEnemy / 2;
			_hitboxOfAtk.height = heightEnemy;

		}

		else if (_facingLeft)
		{
			//std::cout << "enemy attacking left" << std::endl;
			float widthEnemy = _textureOfTerrestrialEnemyLeft.getSize().x * _sprite.getScale().x;
			_hitboxOfAtk.left = _sprite.getPosition().x - widthEnemy;
			_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
			_hitboxOfAtk.width = widthEnemy / 2;
			_hitboxOfAtk.height = heightEnemy;

		}

		_attacking = false;
	}
	else if (!_attacking)
	{
		float widthEnemy = _textureOfTerrestrialEnemyLeft.getSize().x * _sprite.getScale().x;
		_hitboxOfAtk.left = _sprite.getPosition().x - widthEnemy / 4;
		_hitboxOfAtk.top = _sprite.getPosition().y - heightEnemy / 2;
	}// atk hitbox
}

void TerrestrialEnemy::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
	window.draw(_emptyHealthBar);
	window.draw(_foreGroundHealthbar);
	//window.draw(_hitboxOfAtkView);
	window.draw(_levelIndicator);
	//window.draw(_hitboxView);
}
