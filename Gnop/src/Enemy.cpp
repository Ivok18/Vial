#include "Enemy.h"

Enemy::Enemy()
{
	//TODO
	
	_wingsOpen = true;
	inits();
}

Enemy::Enemy(float magicAtk)
{
	
	_wingsOpen = true;
	_magicAtk = magicAtk;
	inits();
}

int Enemy::_theLevel = 1;

sf::Sprite& Enemy::getSprite()
{
	// TODO: insérer une instruction return ici
	return _sprite;
}

void Enemy::setSprite(sf::Sprite newSprite)
{
	//TODO	
}

sf::Texture& Enemy::getTexture()
{
	// TODO: insérer une instruction return ici
	return _texture;
}

void Enemy::setTexture(sf::Texture newTexture)
{
	_texture = newTexture;
}

sf::Sprite& Enemy::getBodySprite()
{
	// TODO: insérer une instruction return ici
	return _bodySprite;
}

void Enemy::setBodySprite(sf::Sprite newBodySprite)
{
	_bodySprite = newBodySprite;
}

sf::Texture& Enemy::getBodyTexture()
{
	// TODO: insérer une instruction return ici
	return _bodyTexture;
}

void Enemy::setBodyTexture(sf::Texture newBodyTexture)
{
	_bodyTexture = newBodyTexture;
}

sf::Sprite& Enemy::getLeftWingSprite()
{
	// TODO: insérer une instruction return ici
	return _leftWingSprite;
}

void Enemy::setLeftWingSprite(sf::Sprite newLeftWingSprite)
{
	_leftWingSprite = newLeftWingSprite;
}

sf::Texture& Enemy::getLeftWingTexture()
{
	// TODO: insérer une instruction return ici
	return _leftWingTexture;
}

void Enemy::setLeftWingTexture(sf::Texture newLeftWingTexture)
{
	_leftWingTexture = newLeftWingTexture;
}

sf::Sprite& Enemy::getRightWingSprite()
{
	// TODO: insérer une instruction return ici
	return _rightWingSprite;
}

void Enemy::setRightWingSprite(sf::Sprite newRightWingSprite)
{
	_rightWingSprite = newRightWingSprite;
}

sf::Texture& Enemy::getRightWingTexture()
{
	// TODO: insérer une instruction return ici
	return _rightWingTexture;
}

void Enemy::setRightWingTexture(sf::Texture newRightWingTexture)
{
	_rightWingTexture = newRightWingTexture;
}

sf::Sprite& Enemy::getTailSprite()
{
	// TODO: insérer une instruction return ici
	return _tailSprite;
}

void Enemy::setTailSprite(sf::Sprite newTailSprite)
{
	_tailSprite = newTailSprite;
}

sf::Texture& Enemy::getTailTexture()
{
	// TODO: insérer une instruction return ici
	return _tailTexture;
}

void Enemy::setTailTexture(sf::Texture newTailTexture)
{
	_tailTexture = newTailTexture;
}

float Enemy::getSpriteScaleX()
{
	return _spriteScaleX;
}

void Enemy::setSpriteScaleX(float newSpriteScaleX)
{
	_spriteScaleX = newSpriteScaleX;
	_bodySprite.setScale(_spriteScaleX, _spriteScaleY);
	_leftWingSprite.setScale(_spriteScaleX, _spriteScaleY);
	_rightWingSprite.setScale(_spriteScaleX, _spriteScaleY);
	_tailSprite.setScale(_spriteScaleX, _spriteScaleY);
}

float Enemy::getSpriteScaleY()
{
	return _spriteScaleY;
}

void Enemy::setSpriteScaleY(float newSpriteScaleY)
{
	_spriteScaleY = newSpriteScaleY;
	_bodySprite.setScale(_spriteScaleX, _spriteScaleY);
	_leftWingSprite.setScale(_spriteScaleX, _spriteScaleY);
	_rightWingSprite.setScale(_spriteScaleX, _spriteScaleY);
	_tailSprite.setScale(_spriteScaleX, _spriteScaleY);
}

bool Enemy::wingsOpen()
{
	return _wingsOpen;
}

void Enemy::openWings(bool boolean)
{
	_wingsOpen = boolean;
}

Enemy* Enemy::getEnemyPtr()
{
	return this;
}



sf::Color Enemy::getColor()
{
	return _color;
}

void Enemy::setColor(sf::Color newColor)
{
	_color = newColor;
	_bodySprite.setColor(_color);
	_leftWingSprite.setColor(_color);
	_rightWingSprite.setColor(_color);
	_leftWingSprite.setColor(_color);
	_tailSprite.setColor(_color);
	
}

sf::Text& Enemy::getLevelText()
{
	return _levelText;
}

void Enemy::setLevelText(sf::Text text)
{
	_levelText = text;
}


sf::FloatRect& Enemy::getHitbox()
{
	// TODO: insérer une instruction return ici
	return _hitbox;
}

void Enemy::setHitBox(sf::FloatRect newHitBox)
{
	//TODO
}

sf::RectangleShape& Enemy::getHitboxView()
{
	return _hitboxView;
}

void Enemy::setHitboxView(sf::RectangleShape view)
{
	_hitboxView = view;
}

float Enemy::getAtk()
{
	
	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float atk = _baseAtk + (alpha / 255 * _maxAtk) + (1.1 * _level);
		_atk = atk;
	}

	return _atk;
	
}

void Enemy::setAtk(float newAtk)
{
	_atk = newAtk;
}

float Enemy::getMaxAtk()
{
	return _maxAtk;
}

void Enemy::setMaxAtk(float maxAtk)
{
	_maxAtk = maxAtk;
}

float Enemy::getBaseAtk()
{
	return _baseAtk;
}

void Enemy::setBaseAtk(float base)
{
	_baseAtk = base;
}

float Enemy::_groupAtk = 0;

float Enemy::getGroupAtk()
{
	return _groupAtk;
}

void Enemy::setGroupAtk(float grpAtk)
{
	_groupAtk = grpAtk;
}

Health& Enemy::getHealth()
{
	return _health;
}

void Enemy::setHealth(Health newHealth)
{
	_health = newHealth;
}

float Enemy::getHp()
{
	return _hp;
}

void Enemy::setHp(float hp)
{
	_hp = hp;
}

float Enemy::getMaxHp()
{
	/*float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float maxHp = _baseMaxHp + (alpha / 255 * _maxHp) + (1.1 * _level);
		_maxHp = maxHp;
	}
	*/

	return _maxHp;
}

void Enemy::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

float Enemy::getBaseMaxHp()
{
	return _baseMaxHp;
}

void Enemy::setBaseMaxHp(float base)
{
	_baseMaxHp = base;
}

Health* Enemy::getHealthPtr()
{
	return _healthPtr;
}

void Enemy::setHealthPtr(Health* newHealthPtr)
{
	_healthPtr = newHealthPtr;
}

Mana& Enemy::getMana()
{
	// TODO: insérer une instruction return ici
	return _mana;
}

void Enemy::setMana(Mana newMana)
{
	_mana = newMana;
}

Mana* Enemy::getManaPtr()
{
	return _manaPtr;
}

void Enemy::setManaPtr(Mana* newManaPtr)
{
	_manaPtr = newManaPtr;
}

float Enemy::getMagicAtk()
{
	return 0.0f;
}

void Enemy::setMagicAtk(float newMagicAtk)
{
	//TODO
}

sf::RectangleShape& Enemy::getHealthBarEmpty()
{
	// TODO: insérer une instruction return ici
	return _healthbarEmpty;
}

void Enemy::setHealthBarEmpty(sf::RectangleShape healthbarEmpty)
{
	_healthbarEmpty = healthbarEmpty;
}

sf::RectangleShape& Enemy::getHealthbar()
{
	// TODO: insérer une instruction return ici
	return _healthbar;
}

void Enemy::setHealthbar(sf::RectangleShape healthbar)
{
	_healthbar = healthbar;
}

sf::RectangleShape& Enemy::getReactionTimeBarEmpty()
{
	return _reactionTimeBarEmpty;
}

void Enemy::setReactionTimeBarEmpty(sf::RectangleShape emptyBar)
{
	_reactionTimeBarEmpty = emptyBar;
}

sf::RectangleShape& Enemy::getReactionTimeBar()
{
	return _reactionTimeBar;
}

void Enemy::setReactionTimeBar(sf::RectangleShape bar)
{
	_reactionTimeBar = bar;
}

bool Enemy::reacting()
{
	return _reacting;
}

void Enemy::isReacting(bool boolean)
{
	_reacting = boolean;
}

float Enemy::getiReactionTime()
{
	return _iReactionTime;
}

void Enemy::setIReactionTime(float i)
{
	_iReactionTime = i;
}

float& Enemy::getYOffset()
{
	// TODO: insérer une instruction return ici
	return _Yoffset;
}

void Enemy::setYOffset(float newYOffset)
{
	_Yoffset = newYOffset;
}

float Enemy::getSpeed()
{

	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float speed = _baseSpeed + (alpha / 255 * _maxSpeed) + (1.1 * _level);
		_speed = speed;
	}

	return _speed;
}

void Enemy::setSpeed(float speed)
{
	_speed = speed;
}

float Enemy::getMaxSpeed()
{
	return _maxSpeed;
}

void Enemy::setMaxSpeed(float max)
{
	_maxSpeed = max;
}

float Enemy::getBaseSpeed()
{
	return _baseSpeed;
}

void Enemy::setBaseSpeed(float base)
{
	_baseSpeed = base;
}

float Enemy::getReactionTime()
{
	float alpha = static_cast<float>(_color.a);
	if (!(_level == 1 && alpha == 255))
	{
		float reactionTime = _baseReactionTime - (alpha / 255 * (_baseReactionTime - _minReactionTime)) - (1.1 * _level);
		_reactionTime = reactionTime;
	}

	return _reactionTime;
}

void Enemy::setReactionTime(float reactionTime)
{
	_reactionTime = reactionTime;
}

float Enemy::getMinReactionTime()
{
	return _minReactionTime;
}

void Enemy::setMinReactionTime(float min)
{
	_minReactionTime = min;
}

float Enemy::getBaseReactionTime()
{
	return _baseReactionTime;
}

void Enemy::setBaseReactionTime(float base)
{
	_baseReactionTime = base;
}

float Enemy::getLevel()
{
	_level = _theLevel;
	return _level;
}

void Enemy::setLevel(float level)
{
	_level = level;
}

float Enemy::getBaseXpDrop()
{
	return _baseXpDrop;
}

void Enemy::setBaseXpDrop(float baseXpDrop)
{
	_baseXpDrop = baseXpDrop;
}



float Enemy::getXpDrop()
{
	float alpha = static_cast<float>(_color.a);
	float xpDrop = _baseXpDrop + (alpha / 255 * _baseXpDrop) + (1.1 * _level);
	_xpDrop = xpDrop;
	return _xpDrop;
}

float Enemy::setXpDrop(float xpDrop)
{
	return _xpDrop = xpDrop;
}

float Enemy::getBaseMoneyDrop()
{
	return _baseMoneyDrop;
}

void Enemy::setBaseMoneyDrop(float base)
{
	_baseMoneyDrop = base;
}

float Enemy::getMoneyDrop()
{
	float alpha = static_cast<float>(_color.a);
	float moneyDrop = _baseMoneyDrop + (alpha / 255 * _baseMoneyDrop) + (1.1 * _level);
	_moneyDrop = moneyDrop;
	return _moneyDrop;
}

void Enemy::setMoneyDrop(float moneyDrop)
{
	_moneyDrop = moneyDrop;
}

void Enemy::levelUp()
{
	_theLevel++;
}

void Enemy::reset()
{
	_theLevel = 1;
}

void Enemy::boost()
{
	float alpha = static_cast<float>(_color.a);
	_baseMaxHp += 0.80 *_baseMaxHp;
	_baseMaxHp += ( (alpha / 255.f)* _baseMaxHp) + (0.55 * _level);

	_baseAtk += 0.35 *_baseAtk; 
	_baseAtk += ((alpha / 255.f) * _baseAtk) + (0.55 * _level);

	//_maxSpeed += 0.35 *_baseSpeed;
	//_baseSpeed += ((alpha / 255.f) * _baseSpeed) + (0.55 * _level);

	_baseXpDrop += ((0.5 * _baseXpDrop * 1.1 * _level)) / 2;
	_baseXpDrop += ((alpha / 255.f) * _baseXpDrop) + (0.55 * _level);

	_baseMoneyDrop += ((0.5 * _baseMoneyDrop * 1.1 * _level)) / 2;
	_baseMoneyDrop += ((alpha / 255.f) * _baseMoneyDrop) + (0.55 * _level);

	_maxAtk = _baseAtk + (alpha / 255 * _baseAtk) + (0.55 * _level);
	_maxHp = _baseMaxHp + (alpha / 255 * _baseMaxHp) + (0.55 * _level);
	_maxSpeed = 1.1 + (alpha / 255 * _baseSpeed) + (0.55 * _level);
	_hp = _maxHp;
}

sf::CircleShape& Enemy::getRange()
{
	return _range;
}

void Enemy::setRange(sf::CircleShape& range)
{
	_range = range;
}

bool Enemy::tracking()
{
	return _tracking;
}

void Enemy::isTracking(bool boolean)
{
	_tracking = boolean;
}

bool Enemy::playing()
{
	return _playing;
}

void Enemy::isPlaying(bool boolean)
{
	_playing = boolean;
}

float Enemy::getHpLimit()
{
	return _hpLimit;
}

void Enemy::setHpLimit(float limit)
{
	_hpLimit = limit;
}

std::string Enemy::getType()
{
	return _type;
}

void Enemy::setType(std::string type)
{
	_type = type;
}

void Enemy::getDamage(float damage)
{
	//TODO
	_hp -= damage;
}

void Enemy::update()
{
	float bodyXposition = _bodySprite.getPosition().x;
	float bodyYPosition = _bodySprite.getPosition().y;

	float bodyWidth = _bodyTexture.getSize().x * _spriteScaleX;
	float bodyHeight = _bodyTexture.getSize().y * _spriteScaleY;

	float leftWingWidth = _leftWingTexture.getSize().x * _spriteScaleX;
	float leftWingHeight = _leftWingTexture.getSize().y * _spriteScaleY;

	float rightWingWidth = _rightWingTexture.getSize().x * _spriteScaleX;
	float rightWingHeight = _rightWingTexture.getSize().y * _spriteScaleY;

	float tailWidth = _tailTexture.getSize().x * _spriteScaleX;
	float tailHeight = _tailTexture.getSize().y * _spriteScaleY;

	//CONFIG FOR BOSS SIZED ENEMY
	if (_spriteScaleX >= 1.9 && _spriteScaleY >= 1.9)
	{
		std::cout << "im the boss" << std::endl;
		_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 45.f * _spriteScaleX, bodyYPosition - 40.f * _spriteScaleY);
		_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 22.f * _spriteScaleX, bodyYPosition - 40.f * _spriteScaleY);
		_tailSprite.setPosition(bodyXposition - 50.f * _spriteScaleX, bodyYPosition + bodyHeight / 2.f + tailHeight / 2.f - 66.f * _spriteScaleY);

		/////////////////////////
		if (_wingsOpen)
		{
			_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 45.f * _spriteScaleX, bodyYPosition - 40.f * _spriteScaleY);
			_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 22.f * _spriteScaleX, bodyYPosition - 40.f * _spriteScaleY);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y + 0.5f);

		}

		else if (!_wingsOpen)
		{
			_leftWingSprite.setPosition(_leftWingSprite.getPosition().x + _leftWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_rightWingSprite.setPosition(_rightWingSprite.getPosition().x - _rightWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - 0.5f);
		}
	}

	// CONFIG FOR BIG SIZED ENEMY
	if (_spriteScaleX >= 1.7 && _spriteScaleY >= 1.7
		&& _spriteScaleX < 1.9 && _spriteScaleY < 1.9)
	{
		_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 11.f * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
		_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 12.f * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
		_tailSprite.setPosition(bodyXposition - 16.f * _spriteScaleX, bodyYPosition + bodyHeight / 2.f + tailHeight / 2.f - 25.f * _spriteScaleY);

		/////////////////////////
		if (_wingsOpen)
		{
			_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 11.f * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
			_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 12.f * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y + 0.5f);

		}

		else if (!_wingsOpen)
		{
			_leftWingSprite.setPosition(_leftWingSprite.getPosition().x + _leftWingTexture.getSize().x * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
			_rightWingSprite.setPosition(_rightWingSprite.getPosition().x - _rightWingTexture.getSize().x * _spriteScaleX, bodyYPosition - 10.f * _spriteScaleY);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - 0.5f);
		}
	}

	// CONFIG FOR MEDIUM SIZED ENEMY
	if (_spriteScaleX > 1 && _spriteScaleY > 1
		&& _spriteScaleX < 1.7 && _spriteScaleY < 1.7)
	{
		_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 3.f * _spriteScaleX, bodyYPosition - 2.f * _spriteScaleY);
		_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 4.f * _spriteScaleX, bodyYPosition - 2.f * _spriteScaleY);
		_tailSprite.setPosition(bodyXposition - 5.f * _spriteScaleX, bodyYPosition + bodyHeight / 2.f + tailHeight / 2.f - 10.f * _spriteScaleY);

		/////////////////////////
		if (_wingsOpen)
		{
			_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f - 3.f * _spriteScaleX, bodyYPosition - 2.f * _spriteScaleY);
			_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f - 4.f * _spriteScaleX, bodyYPosition - 2.f * _spriteScaleY);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y + 0.5f);

		}

		else if (!_wingsOpen)
		{
			_leftWingSprite.setPosition(_leftWingSprite.getPosition().x + _leftWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_rightWingSprite.setPosition(_rightWingSprite.getPosition().x - _rightWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - 0.5f);
		}
	}

	// CONFIG FOR LITTLE SIZED
	else if (_spriteScaleX <= 1.1f && _spriteScaleY <= 1.1f)
	{
		_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f, bodyYPosition);
		_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f, bodyYPosition);
		_tailSprite.setPosition(bodyXposition, bodyYPosition + bodyHeight / 2.f + tailHeight / 2.f);

		/////////////////////////
		if (_wingsOpen)
		{
			_leftWingSprite.setPosition(bodyXposition - bodyWidth / 2.f - leftWingWidth / 2.f , bodyYPosition);
			_rightWingSprite.setPosition(bodyXposition + bodyWidth / 2.f + rightWingWidth / 2.f, bodyYPosition);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y + 0.5f);

		}

		else if (!_wingsOpen)
		{
			_leftWingSprite.setPosition(_leftWingSprite.getPosition().x + _leftWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_rightWingSprite.setPosition(_rightWingSprite.getPosition().x - _rightWingTexture.getSize().x * _spriteScaleX, bodyYPosition);
			_bodySprite.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - 0.5f);
		}
	}

	// UPDATE HEALTHBAR STATE
	float hp = getHp();
	float maxHp = _maxHp;

	if (hp >= maxHp) //full hp
	{
		float heightOfEnemyBody = _bodyTexture.getSize().y * _spriteScaleY;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - heightOfEnemyBody / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_healthbar.setPosition(_healthbarEmpty.getPosition().x, _healthbarEmpty.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		//float maxWidthHealthBar = _healthbarEmpty.getSize().x * _healthbarEmpty.getScale().x;
		//float heightHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;


		//float percentageOfHpRemaining = hp / maxHp * 100.f;
		//float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_healthbar.setSize(sf::Vector2f(92, 15));
		//std::cout << "fully alive" << std::endl;

	}

	else if (hp < maxHp && hp > 0) //not full hp
	{
		if (hp <= getHpLimit())
		{
			_tracking = true;
			
		}
		float heightOfEnemyBody = _bodyTexture.getSize().y * _spriteScaleY;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y - heightOfEnemyBody / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_healthbar.setPosition(_healthbarEmpty.getPosition().x, _healthbarEmpty.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _healthbarEmpty.getSize().x * _healthbarEmpty.getScale().x;
		float heightHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

		float percentageOfHpRemaining = hp / maxHp * 100.f;
		float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		if (_spriteScaleX >= 1.9 && _spriteScaleY >= 1.9)
		{
			_healthbar.setSize(sf::Vector2f(widthOfhealthbar / 2.5, 15));
		}
		else if (_spriteScaleX >= 1.7 && _spriteScaleY >= 1.7 &&
			_spriteScaleX < 1.9 && _spriteScaleY < 1.9)
		{
			_healthbar.setSize(sf::Vector2f(widthOfhealthbar / 1.5, 15));
		}
		else
		{
			_healthbar.setSize(sf::Vector2f(widthOfhealthbar, 15));
		}
		//std::cout << "fully alive" << std::endl;à
	}

	else
	{
		std::cout << "die fuck" << std::endl;
	}

	// UPDATE HEALTHBAR POSITION + DIMENSIONS
	float heightOfEnemyBody = _bodyTexture.getSize().y * _spriteScaleY;
	float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

	float healthBarXposition = _bodySprite.getPosition().x;
	float healthBarYposition = _bodySprite.getPosition().y - heightOfEnemyBody / 2.f - heightOfHealthBar / 2.f - _Yoffset;
	_healthbarEmpty.setPosition(healthBarXposition, healthBarYposition);
	_healthbar.setPosition(healthBarXposition, healthBarYposition);
	_healthbar.setScale(_healthbarEmpty.getScale());
	_healthbar.setFillColor(_color);  

	if (_spriteScaleX <=1.1 && _spriteScaleY <=1.1)
	{
		float widthEnemy = _bodyTexture.getSize().x * _spriteScaleX;
		float heightEnemy = _bodyTexture.getSize().y * _spriteScaleY;
		_hitbox.left = _bodySprite.getPosition().x - widthEnemy / 2 - (10 * _spriteScaleX);
		_hitbox.top = _bodySprite.getPosition().y - heightEnemy / 2 - (10 * _spriteScaleY);
		_hitbox.width = widthEnemy;
		_hitbox.height = heightEnemy;
		//_hitboxView.setScale(_spriteScaleX, _spriteScaleY);
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_hitboxView.setFillColor(sf::Color::Transparent);
		_hitboxView.setOutlineColor(_color);

		float widthHealthbar = _healthbarEmpty.getSize().x;
		_levelText.setPosition(_healthbarEmpty.getPosition().x - _levelText.getCharacterSize() / 3 * _spriteScaleX, healthBarYposition - _levelText.getCharacterSize() / 1.5f * _spriteScaleY);
		_levelText.setString(std::to_string((int)getLevel() - 1));//update level indicator position & value

		_range.setRadius(heightEnemy);
		_range.setFillColor(sf::Color(214, 214, 214, 100));
		_range.setPosition(_bodySprite.getPosition().x, _bodySprite.getPosition().y);
		_range.setOrigin(_range.getRadius(), _range.getRadius()); //range
	}

	if (_spriteScaleX > 1 && _spriteScaleY > 1
		&& _spriteScaleX < 1.7 && _spriteScaleY < 1.7)
	{
		//std::cout << " else" << std::endl;
		float widthEnemy = _bodyTexture.getSize().x * _spriteScaleX;
		float heightEnemy = _bodyTexture.getSize().y * _spriteScaleY;
		_hitbox.left = _bodySprite.getPosition().x - widthEnemy / 2 - (18 * _spriteScaleX);
		_hitbox.top = _bodySprite.getPosition().y - heightEnemy / 2 - (25 * _spriteScaleY);
		_hitbox.width = widthEnemy;
		_hitbox.height = heightEnemy;
		_hitboxView.setScale(_spriteScaleX, _spriteScaleY);
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_hitboxView.setFillColor(sf::Color::Transparent);
		_hitboxView.setOutlineColor(_color);

		float widthHealthbar = _healthbarEmpty.getSize().x;
		_levelText.setPosition(_healthbarEmpty.getPosition().x - (12 * _spriteScaleX), healthBarYposition - _levelText.getCharacterSize() / 1.5f * _spriteScaleY - 10 * _spriteScaleY);
		_levelText.setString(std::to_string((int)getLevel() - 1));//update level indicator position & value


		_range.setRadius(heightEnemy);
		_range.setFillColor(sf::Color(214, 214, 214, 100));
		_range.setPosition(_bodySprite.getPosition().x - 11 * _spriteScaleX, _bodySprite.getPosition().y - 12 * _spriteScaleY);
		_range.setOrigin(_range.getRadius(), _range.getRadius()); //range
	}

	else if (_spriteScaleX >= 1.7 && _spriteScaleY >= 1.7
		&& _spriteScaleX < 1.9 && _spriteScaleY < 1.9)
	{
		//std::cout << " else" << std::endl;
		float widthEnemy = _bodyTexture.getSize().x * _spriteScaleX;
		float heightEnemy = _bodyTexture.getSize().y * _spriteScaleY;
		_hitbox.left = _bodySprite.getPosition().x - widthEnemy / 2 - (35 * _spriteScaleX);
		_hitbox.top = _bodySprite.getPosition().y - heightEnemy / 2 - (40 * _spriteScaleY);
		_hitbox.width = widthEnemy;
		_hitbox.height = heightEnemy;
		_hitboxView.setScale(_spriteScaleX, _spriteScaleY);
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_hitboxView.setFillColor(sf::Color::Transparent);
		_hitboxView.setOutlineColor(_color);

		float widthHealthbar = _healthbarEmpty.getSize().x;
		_levelText.setPosition(_healthbarEmpty.getPosition().x - (30 * _spriteScaleX), healthBarYposition - _levelText.getCharacterSize() / 1.5f * _spriteScaleY - 27* _spriteScaleY);
		_levelText.setScale(_spriteScaleX / 1.5, _spriteScaleY / 1.5);
		_levelText.setString(std::to_string((int)getLevel() - 1));//update level indicator position & value
	

		_range.setRadius(heightEnemy);
		_range.setFillColor(sf::Color(214, 214, 214, 100));
		_range.setPosition(_bodySprite.getPosition().x - 28 * _spriteScaleX, _bodySprite.getPosition().y - 25 * _spriteScaleY);
		_range.setOrigin(_range.getRadius(), _range.getRadius()); //range
	}

	
	else if (_spriteScaleX >= 1.9 && _spriteScaleY >= 1.9)
	{
		//std::cout << " else" << std::endl;
		float widthEnemy = _bodyTexture.getSize().x * _spriteScaleX;
		float heightEnemy = _bodyTexture.getSize().y * _spriteScaleY;
		_hitbox.left = _bodySprite.getPosition().x - widthEnemy / 2 - (83 * _spriteScaleX);
		_hitbox.top = _bodySprite.getPosition().y - heightEnemy / 2 - (100* _spriteScaleY);
		_hitbox.width = widthEnemy;
		_hitbox.height = heightEnemy;
		_hitboxView.setScale(_spriteScaleX, _spriteScaleY);
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_hitboxView.setFillColor(sf::Color::Transparent);
		_hitboxView.setOutlineColor(_color);

		float widthHealthbar = _healthbarEmpty.getSize().x;
		_levelText.setPosition(_healthbarEmpty.getPosition().x - (76 * _spriteScaleX), healthBarYposition - _levelText.getCharacterSize() / 1.5f  * _spriteScaleY - 85 * _spriteScaleY);
		_levelText.setScale(_spriteScaleX /1.5, _spriteScaleY/1.5);
		_levelText.setString(std::to_string((int)getLevel() - 1));//update level indicator position & value
		_levelText.setFillColor(sf::Color::Black);
		
		_range.setRadius(heightEnemy);
		_range.setFillColor(sf::Color(214, 214, 214, 100));
		_range.setPosition(_bodySprite.getPosition().x - 75 * _spriteScaleX, _bodySprite.getPosition().y - 80 * _spriteScaleY );
		_range.setOrigin(_range.getRadius(), _range.getRadius()); //range
	}


	

	
	_reactionTimeBarEmpty.setPosition(healthBarXposition, healthBarYposition - 16);
	float reactionTimeBarEmptyX = _reactionTimeBarEmpty.getPosition().x;
	float reactionTimeBarEmptyY = _reactionTimeBarEmpty.getPosition().y;
	_reactionTimeBar.setPosition(reactionTimeBarEmptyX, reactionTimeBarEmptyY);
	_reactionTimeBar.setScale(_reactionTimeBarEmpty.getScale());

	if (_type == "boss" && !_tracking)
	{
		_playing = true;
	}

	if (_reacting)
	{
		_iReactionTime++;
		float maxWidthReactionTimeBar = 0;
		if (_spriteScaleX >= 1.9 && _spriteScaleY >= 1.9)
		{
			maxWidthReactionTimeBar = (_reactionTimeBarEmpty.getSize().x * _reactionTimeBarEmpty.getScale().x) / 2.6;
		}
		else if (_spriteScaleX >= 1.7 && _spriteScaleY >= 1.7 &&
			_spriteScaleX < 1.9 && _spriteScaleY < 1.9)
		{
			maxWidthReactionTimeBar = (_reactionTimeBarEmpty.getSize().x * _reactionTimeBarEmpty.getScale().x) / 1.5;
		}

		if (_spriteScaleX > 1 && _spriteScaleY > 1
			&& _spriteScaleX < 1.7 && _spriteScaleY < 1.7)
		{
			maxWidthReactionTimeBar = (_reactionTimeBarEmpty.getSize().x * _reactionTimeBarEmpty.getScale().x) / 1.05;
		}
		else
		{
			maxWidthReactionTimeBar = _reactionTimeBarEmpty.getSize().x * _reactionTimeBarEmpty.getScale().x;
		}
		float percentageOfReactionTimeBarReached = _iReactionTime / _reactionTime * 100;
		float widthReactionTimeBar = percentageOfReactionTimeBarReached / 100 * maxWidthReactionTimeBar;
		_reactionTimeBar.setSize(sf::Vector2f(widthReactionTimeBar, 15));
	}

	
}

void Enemy::draw(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(_bodySprite);
	gameWindow.draw(_leftWingSprite);
	gameWindow.draw(_rightWingSprite);
	gameWindow.draw(_tailSprite);
	gameWindow.draw(_healthbarEmpty);
	gameWindow.draw(_healthbar);
	//gameWindow.draw(_hitboxView);
	gameWindow.draw(_levelText);
	//gameWindow.draw(_range);
	if (_reacting)
	{
		gameWindow.draw(_reactionTimeBarEmpty);
		gameWindow.draw(_reactionTimeBar);
	}
	
	
	
}

BattleActor* Enemy::getPtr()
{
	return this;
}

void Enemy::inits()
{
	
	initSpriteAndTexture();
	initHitbox();
	initStats();

}
	void Enemy::initSpriteAndTexture()
{
		_spriteScaleX = 1.f;
		_spriteScaleY = 1.f;

		_bodyTexture.loadFromFile("data/Enemy/body.png");
		_bodySprite.setTexture(_bodyTexture);
		_bodySprite.setOrigin(_bodyTexture.getSize().x * _spriteScaleX / 2.f,
			_bodyTexture.getSize().y * _spriteScaleY / 2.f);

		_leftWingTexture.loadFromFile("data/Enemy/leftWing.png");
		_leftWingSprite.setTexture(_leftWingTexture);
		_leftWingSprite.setOrigin(_leftWingTexture.getSize().x * _spriteScaleX / 2.f,
			_leftWingTexture.getSize().y * _spriteScaleY / 2.f);

		_rightWingTexture.loadFromFile("data/Enemy/rightWing.png");
		_rightWingSprite.setTexture(_rightWingTexture);
		_rightWingSprite.setOrigin(_rightWingTexture.getSize().x * _spriteScaleX / 2.f,
			_rightWingTexture.getSize().y * _spriteScaleY / 2.f);

		_tailTexture.loadFromFile("data/Enemy/tail.png");
		_tailSprite.setTexture(_tailTexture);
		_tailSprite.setOrigin(_tailTexture.getSize().x * _spriteScaleX / 2.f,
			_tailTexture.getSize().y * _spriteScaleY / 2.f);

		_levelText.setCharacterSize(25);
		_levelText.setString(std::to_string(_level)); // level 

}
	void Enemy::initHitbox()
{
		float widthEnemy = _bodyTexture.getSize().x * _spriteScaleX;
		float heightEnemy = _bodyTexture.getSize().y * _spriteScaleY;
		_hitbox.left = _bodySprite.getPosition().x - widthEnemy / 2 - 10;
		_hitbox.top = _bodySprite.getPosition().y - heightEnemy / 2 - 10;
		_hitbox.width = 10 + widthEnemy + 10;
		_hitbox.height = 10 + heightEnemy + 10;
		_hitboxView.setSize(sf::Vector2f(_hitbox.width, _hitbox.height));
		_hitboxView.setPosition(_hitbox.left, _hitbox.top);
		_hitboxView.setFillColor(sf::Color::Transparent);
		_hitboxView.setOutlineThickness(-3);
}
	void Enemy::initStats()
{
		
		
}
