#include "Player.h"

Player::Player()
{
	inits();
}

Player::Player(float magicAtk)
{
	_magicAtk = magicAtk;
	inits();
}

Player::~Player() = default;

void Player::inits()
{
	initSpriteAndTexture();
	initHitbox();
	initHitBoxOfBasicAtk();
	initHitBoxOfDash();
	initMovement();
	initStats();

}
	void Player::initSpriteAndTexture()
{
	this->_texture.loadFromFile("data/Player/player.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_texture.getSize().x / 2.f, _texture.getSize().y / 2.f);

	_levelText.setCharacterSize(25);
	_levelText.setString(std::to_string(_level)); //level 
}
	void Player::initHitbox()
{
		_hitbox = _sprite.getGlobalBounds();
}
	void Player::initHitBoxOfBasicAtk()
	{
		
		_hitboxOfBasicAtk.width = _texture.getSize().x;
		_hitboxOfBasicAtk.height = _texture.getSize().y / 2.f;
		_viewOfhitBoxOfBasicAtk.setSize(sf::Vector2f(_hitboxOfBasicAtk.width, _hitboxOfBasicAtk.height));
		_viewOfhitBoxOfBasicAtk.setFillColor(sf::Color::Transparent);
		_viewOfhitBoxOfBasicAtk.setOutlineThickness(-3);
		_viewOfhitBoxOfBasicAtk.setOutlineColor(sf::Color::Green);

		_rotationOfBasicAttack = 45.f;
		
	}
	void Player::initHitBoxOfDash()
	{
		float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
		float heightPlayer = _texture.getSize().y * _sprite.getScale().y;

		_hitboxOfDash.left = _sprite.getPosition().x;
		_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
		_hitboxOfDash.width = 5 * widthPlayer;
		_hitboxOfDash.height = heightPlayer;
		_viewOfHitboxOfDash.setSize(sf::Vector2f(_hitboxOfDash.width, _hitboxOfDash.height));
		_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		_viewOfHitboxOfDash.setFillColor(sf::Color::Transparent);
		_viewOfHitboxOfDash.setOutlineThickness(-3);
		_viewOfHitboxOfDash.setOutlineColor(sf::Color::Black); // hitbox

		
	}
	void Player::initMovement()
	{
		_up = false;
		_down = false;
		_left = false;
		_right = false;
		_isAttacking = false;
		_baseSpeed = 5.8f; 
	}
	void Player::initStats()
	{
		_health.setBaseMaxHp(99.9);
		_health.setHp(101);
		_health.setMaxHp(101);
	}

sf::Sprite& Player::getSprite()
{
	return _sprite;
}
void Player::setSprite(sf::Sprite newSprite)
{
	this->_sprite = newSprite;
}

sf::Texture& Player::getTexture()
{
	return _texture;
}
void Player::setTexture(sf::Texture newTexture)
{
	this->_texture = newTexture;
}

sf::FloatRect& Player::getHitbox()
{
	return _hitbox;
}

void Player::setHitBox(sf::FloatRect newHitBox)
{
	_hitbox = newHitBox;
}



sf::FloatRect& Player::getHitBoxOfBasicAtk()
{
	return _hitboxOfBasicAtk;
}
void Player::setHitboxOfBasicAtk(sf::FloatRect newHitBoxOfBasicAtk)
{
	_hitboxOfBasicAtk = newHitBoxOfBasicAtk;
}

sf::FloatRect& Player::getHitboxOfDash()
{
	return _hitboxOfDash;
}

void Player::setHitboxOfDash(sf::FloatRect hitbox)
{
	_hitboxOfDash = hitbox;
}

sf::RectangleShape& Player::getViewOfHitboxOfDash()
{
	return _viewOfHitboxOfDash;
}

void Player::setViewOfHitboxOfDash(sf::RectangleShape view)
{
	_viewOfHitboxOfDash = view;
}

float Player::getBaseAtk()
{
	return _baseAtk;
}

void Player::setBaseAtk(float base)
{
	_baseAtk = base;
}

sf::RectangleShape& Player::getViewOfHitBoxOfBasicAtk()
{
	// TODO: insérer une instruction return ici
	return _viewOfhitBoxOfBasicAtk;
}

void Player::setViewOfHitBoxOfBasicAtk(sf::RectangleShape view)
{
	_viewOfhitBoxOfBasicAtk = view;
}


float Player::getAtk()
{
	return _baseAtk + (1.1 * _level);
}

void Player::setAtk(float newAtk)
{
	_atk = _atk;
}

Health& Player::getHealth()
{
	//TODO	
	return _health;
}

void Player::setHealth(Health newHealth)
{
	//TODO
}

Health* Player::getHealthPtr()
{
	return _healthPtr;
}

void Player::setHealthPtr(Health* newHealthPtr)
{
	_healthPtr = newHealthPtr;
}

float Player::getBaseMaxHp()
{
	return _baseMaxHp;
}

void Player::setBaseMaxHp(float base)
{
	_baseMaxHp = base;
}

float Player::getHp()
{
	return _health.getHp();
}

void Player::setHp(float hp)
{
	_health.setHp(hp);
}

float Player::getMaxHp()
{
	_maxHp = _baseMaxHp + (1.1 * _level);
	return _maxHp;
}

void Player::setMaxHp(float maxHp)
{
	_health.setMaxHp(maxHp);
}

Mana& Player::getMana()
{
	//TODO
	return _mana;
}

void Player::setMana(Mana newMana)
{
	//TODO
}

Mana* Player::getManaPtr()
{
	return _manaPtr;
}

void Player::setManaPtr(Mana* newManaPtr)
{
	//TODO
}

float Player::getMagicAtk()
{
	//TODO
	return 2.f;
}

void Player::setMagicAtk(float newMagicAtk)
{
	//TODO
}

void Player::getDamage(float damage)
{
	//TODO
	float newHp = _health.getHp() - damage;
	_health.setHp(newHp);
}

sf::RectangleShape& Player::getHealthBarEmpty()
{
	// TODO: insérer une instruction return ici
	return _healthbarEmpty;
}

void Player::setHealthBarEmpty(sf::RectangleShape healthbarEmpty)
{
	_healthbarEmpty = healthbarEmpty;
}

sf::RectangleShape& Player::getHealthbar()
{
	// TODO: insérer une instruction return ici
	return _healthbar;
}

void Player::setHealthbar(sf::RectangleShape healthbar)
{
	_healthbar = healthbar;
}

float& Player::getYOffset()
{
	// TODO: insérer une instruction return ici
	return _Yoffset;
}

void Player::setYOffset(float newYOffset)
{
	_Yoffset = newYOffset;
}

float Player::getBaseSpeed()
{
	return _baseSpeed;
}

void Player::setBaseSpeed(float base)
{
	_baseSpeed = base;
}

float Player::getSpeed()
{
	return _baseSpeed + (1.1 * _level);
}
void Player::setSpeed(float newSpeed)
{
	_baseSpeed = newSpeed;
}

float Player::getRotationOfBasicAttack()
{
	return _rotationOfBasicAttack;
}
void Player::setRotationOfBasicAttack(float newRotation)
{
	_rotationOfBasicAttack = newRotation;
}


bool Player::headingUp()
{
	return _up;
}
void Player::isGoingUp(bool boolean)
{
	_up = boolean;
}

bool Player::headingDown()
{
	return _down;
}
void Player::isGoingDown(bool boolean)
{
	_down = boolean;
}

bool Player::headingLeft()
{
	return _left;
}
void Player::isGoingLeft(bool boolean)
{
	_left = boolean;
}

bool Player::headingRight()
{
	return _right;
}
void Player::isGoingRight(bool boolean)
{
	_right = boolean;
}

bool Player::attacking()
{
	return _isAttacking;
}
void Player::isAttacking(bool boolean)
{
	_isAttacking = boolean;
}

bool Player::dashing()
{
	return _dashing;
}

void Player::isDashing(bool boolean)
{
	_dashing = boolean;
}

float Player::getLevel()
{
	return _level;
}

void Player::setLevel(float level)
{
	_level = level;
}

float Player::getCurrentXp()
{
	return _currentXp;
}

void Player::setCurrentXp(float currentXp)
{
	_currentXp = currentXp;
}

float Player::getXpGain()
{
	return _xpGain;
}

void Player::setXpGain(float gain)
{
	_xpGain = gain;
	_currentXp+=_xpGain;
}

float Player::getXpToLevelUp()
{
	return _xpToLevelUp;
}

void Player::setXpToLevelUp(float xpToUp)
{
	_xpToLevelUp = xpToUp;
}

void Player::levelUp()
{
	std::cout << "player before level up! stats" << std::endl;
	std::cout << "atk: " << getAtk() << std::endl;
	std::cout << "hp: " << getMaxHp() << std::endl;
	std::cout << "speed: " << getSpeed() << std::endl;
	std::cout << std::endl << std::endl;
	_level++;
	_xpToLevelUp = _xpToLevelUp + (0.19 * _xpToLevelUp * 0.5 * _level);
	_baseMaxHp += (0.35 * _baseMaxHp + (0.1 * _baseMaxHp)) * 0.23;
	_baseSpeed += 0.1;
	if (getBaseSpeed() >= 12.f)
	{
		setBaseSpeed(12.f);
	}

	_baseAtk += 0.10 * _baseAtk;
	std::cout << std::endl << std::endl;
	std::cout << "player level up! new stats" << std::endl;
	std::cout << "atk: " << getAtk() << std::endl;
	std::cout << "hp: " << getMaxHp() << std::endl;
	std::cout << "speed: " << getSpeed() << std::endl;
	
}

sf::Text& Player::getLevelText()
{
	return _levelText;
}

void Player::setLevelText(sf::Text text)
{
	_levelText = text;
}

sf::CircleShape& Player::getRange()
{
	return _range;
}

void Player::setRange(sf::CircleShape& range)
{
	_range = range;
}

void Player::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}
void Player::move(float x, float y)
{
	_sprite.move(x, y);
}

void Player::update()
{
	//Update movement
	//UpdateMovement();
	if (_up)
	{
		move(0.f, -_baseSpeed);
	}
	if (_down)
	{
		move(0.f, _baseSpeed);
	}
	if (_left)
	{
		move(-_baseSpeed, 0.f);
	}
	if (_right)
	{
		move(_baseSpeed, 0);
	}

	//UpdateHitboxes()
	if (!_isAttacking)
	{
		_hitboxOfBasicAtk.left = _sprite.getPosition().x - _texture.getSize().x / 2.f;
		_hitboxOfBasicAtk.top = _sprite.getPosition().y - _texture.getSize().y / 2.f;
		_hitboxOfBasicAtk.width = _texture.getSize().x;
		_hitboxOfBasicAtk.height = _texture.getSize().y / 2.f;
		_viewOfhitBoxOfBasicAtk.setPosition(_hitboxOfBasicAtk.left, _hitboxOfBasicAtk.top);
		_viewOfhitBoxOfBasicAtk.setSize(sf::Vector2f(_hitboxOfBasicAtk.width, _hitboxOfBasicAtk.height));
	}
	else if (_isAttacking)
	{
		float tangentOfAngle = 1.f; //constant based on the rotation of player basic attack
		float adjacent = _texture.getSize().y / 2.f;
		float oppose = tangentOfAngle * adjacent;

		_hitboxOfBasicAtk.left = _sprite.getPosition().x;
		_hitboxOfBasicAtk.top = _sprite.getPosition().y - _texture.getSize().y / 2.f;
		_hitboxOfBasicAtk.width = oppose * 2;
		_hitboxOfBasicAtk.height = _texture.getSize().y / 1.5f;
		_viewOfhitBoxOfBasicAtk.setPosition(_hitboxOfBasicAtk.left, _hitboxOfBasicAtk.top);
		_viewOfhitBoxOfBasicAtk.setSize(sf::Vector2f(_hitboxOfBasicAtk.width, _hitboxOfBasicAtk.height));

	}//player attack settings


	if (!_dashing)
	{
		if (!headingRight() && !headingDown() && !headingUp() && !headingLeft())
		{
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
			_hitboxOfDash.left = _sprite.getPosition().x;
			_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfDash.width = 10 * widthPlayer;
			_hitboxOfDash.height = heightPlayer;
			_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		}

		if (headingUp() && (!headingRight() && !headingLeft()))
		{
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
			_hitboxOfDash.left = _sprite.getPosition().x;
			_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfDash.width = 10 * widthPlayer;
			_hitboxOfDash.height = heightPlayer;
			_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		}

		if (headingDown() && (!headingRight() && !headingLeft()))
		{
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
			_hitboxOfDash.left = _sprite.getPosition().x;
			_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfDash.width = 10 * widthPlayer;
			_hitboxOfDash.height = heightPlayer;
			_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		}

		if (headingRight())
		{
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
			_hitboxOfDash.left = _sprite.getPosition().x;
			_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
			_hitboxOfDash.width = 10 * widthPlayer;
			_hitboxOfDash.height = heightPlayer;
			_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		}

		if (headingLeft())
		{
			float widthPlayer = _texture.getSize().x * _sprite.getScale().x;
			float heightPlayer = _texture.getSize().y * _sprite.getScale().y;
			_hitboxOfDash.width = 10 * widthPlayer;
			_hitboxOfDash.height = heightPlayer;
			_hitboxOfDash.left = _sprite.getPosition().x - _hitboxOfDash.width / 2;
			_hitboxOfDash.top = _sprite.getPosition().y - heightPlayer / 2;
			_viewOfHitboxOfDash.setPosition(_hitboxOfDash.left, _hitboxOfDash.top);
		}
		
	}


	//update healthbar state
	float hp = getHp();
	float maxHp = getMaxHp();
	if (hp >= maxHp) //full hp
	{
		float heightOfPlayer = _texture.getSize().y * _sprite.getScale().x;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - heightOfPlayer / 2.f - heightOfHealthBar / 2.f - _Yoffset);
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

		float heightOfEnemyBody = _texture.getSize().y * _sprite.getScale().y;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - heightOfEnemyBody / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_healthbar.setPosition(_healthbarEmpty.getPosition().x, _healthbarEmpty.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _healthbarEmpty.getSize().x * _healthbarEmpty.getScale().x;
		float heightHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

		float percentageOfHpRemaining = hp / maxHp * 100.f;
		float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_healthbar.setSize(sf::Vector2f(widthOfhealthbar, 15));
		//std::cout << "fully alive" << std::endl;à
	}

	//update healthbar position and dimensions
	float heightOfPlayer= _texture.getSize().y * _sprite.getScale().y;
	float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

	float healthBarXposition = _sprite.getPosition().x;
	float healthBarYposition = _sprite.getPosition().y - heightOfPlayer / 2.f - heightOfHealthBar / 2.f - _Yoffset;
	_healthbarEmpty.setPosition(healthBarXposition, healthBarYposition);
	_healthbar.setPosition(healthBarXposition, healthBarYposition);
	_healthbar.setScale(_healthbarEmpty.getScale());
	_healthbar.setFillColor(sf::Color::Green);


	 
	float widthHealthbar = _healthbarEmpty.getSize().x;
	_levelText.setPosition(_healthbarEmpty.getPosition().x - _levelText.getCharacterSize() / 3, healthBarYposition - _levelText.getCharacterSize() / 1.5f);
	_levelText.setString(std::to_string((int)_level)); //udpdate text level position
	
	float heightPlayer = _texture.getSize().y;
	_range.setRadius(heightPlayer);
	_range.setFillColor(sf::Color(214, 214, 214, 100));
	_range.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
	_range.setOrigin(_range.getRadius(), _range.getRadius()); //range
	

	
	

}
void Player::draw(sf::RenderWindow& gamewindow)
{
	gamewindow.draw(_viewOfhitBoxOfBasicAtk);
	gamewindow.draw(_sprite);
	gamewindow.draw(_healthbarEmpty);
	gamewindow.draw(_healthbar);
	//window.draw(_lowerHitboxView);
	//gamewindow.draw(_viewOfHitboxOfDash);
	gamewindow.draw(_levelText);
	//gamewindow.draw(_range);
	
}

Damageable* Player::getPtr()
{
	return this;
}
