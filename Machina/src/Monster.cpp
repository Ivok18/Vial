#include "Monster.h"

int Monster::__armyId = 0;

Monster::Monster()
{
	_name = "enemy soldier";
	_hp = 100.f;
	_maxHp = 100.f;
	_atk = 10.f;
	__armyId++;
	armyId = __armyId;
	_reactionSpeed = 0;
	_level = 0;

	_texture.loadFromFile("data/enemy.png");
	_sprite.setTexture(_texture);
	float widthOfEnemy = _texture.getSize().x * _sprite.getScale().x;
	float heightOfEnemy = _texture.getSize().y * _sprite.getScale().y;
	_sprite.setOrigin(widthOfEnemy / 2.f, heightOfEnemy / 2.f);

	_Yoffset = 4.f;
	_Xoffset = 0;

	_emptyHealthBar.setSize(sf::Vector2f(92, 15));

	float healthBarWidth = _emptyHealthBar.getSize().x * _sprite.getScale().x;
	float healthBarHeight = _emptyHealthBar.getSize().y * _sprite.getScale().y;
	_emptyHealthBar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_emptyHealthBar.setOutlineThickness(-1);
	_emptyHealthBar.setOutlineColor(sf::Color::Black);
	
	

	_foreGroundHealthbar.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
	_foreGroundHealthbar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_foreGroundHealthbar.setFillColor(sf::Color::Red);
	_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);

	float maxWidthHealthBar = _emptyHealthBar.getScale().x *
		_emptyHealthBar.getSize().x;

	float newWidthHealthBar = _texture.getSize().x * _sprite.getScale().x;

	_emptyHealthBar.setScale(newWidthHealthBar
		/ maxWidthHealthBar, 1.f);

	_foreGroundHealthbar.setScale(_emptyHealthBar.getScale().x, _emptyHealthBar.getScale().y);
	

	
}

Monster::Monster(std::string name, float hp, float atk)
{
	_name = name;
	_hp = hp;
	_maxHp = 100.f;
	_atk = atk;
	__armyId++;
	armyId = __armyId;
	_reactionSpeed = 0;
	_level = 0;

	_texture.loadFromFile("data/enemy.png");
	_sprite.setTexture(_texture);
	float widthOfEnemy = _texture.getSize().x * _sprite.getScale().x;
	float heightOfEnemy = _texture.getSize().y * _sprite.getScale().y;
	_sprite.setOrigin(widthOfEnemy / 2.f, heightOfEnemy / 2.f);

	_Yoffset = 18.f * _sprite.getScale().y;
	_Xoffset = 3.f * _sprite.getScale().x;

	/*_healthBarTexture.loadFromFile("data/healthBarEmpty.png");
	_healthBarTexturePtr = &_healthBarTexture;
	_healthBarSprite.setTexture(_healthBarTexture);
	float healthBarWidth = _healthBarTexture.getSize().x * _sprite.getScale().x;
	float healthBarHeight = _healthBarTexture.getSize().y * _sprite.getScale().y;
	_healthBarSprite.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);

	_hoverTexture.loadFromFile("data/healthBarFull(enemy).png");
	_healthBarTexturePtr = &_hoverTexture;
	_hoverSprite.setTexture(_hoverTexture);
	_hoverSprite.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);

	float maxWidthHealthBar = _healthBarSprite.getScale().x *
		_healthBarTexture.getSize().x;
		

	float newWidthHealthBar = _texture.getSize().x * _sprite.getScale().x;

	_healthBarSprite.setScale(newWidthHealthBar
		/ maxWidthHealthBar, 1.f);
		

	_hoverSprite.setScale(_healthBarSprite.getScale().x, _healthBarSprite.getScale().y);*/

}

Monster::~Monster()
{
}

float Monster::getAtk()
{
	return _atk;
}

void Monster::setAtk(float newAtk)
{
	_atk = newAtk;
}

float Monster::getHp()
{
	return _hp;
}

void Monster::setHp(float hp)
{
	_hp = hp;
}

float Monster::getMaxHp()
{
	return _maxHp;
}

void Monster::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

std::string Monster::getName()
{
	return _name;
}

int Monster::getArmyId()
{
	return armyId;
}

int Monster::getReactionSpeed()
{
	return _reactionSpeed;
}

void Monster::determineReactionSpeed(int reactionSpeed)
{
	_reactionSpeed = reactionSpeed;
}

void Monster::setHpLost(float hp_lost)
{
	_hp -= hp_lost;
}

sf::Texture& Monster::getTexture()
{
	return _texture;
}

void Monster::setTexture(sf::Texture texture)
{
	_texture = texture;
}

sf::Sprite& Monster::getSprite()
{
	return _sprite;
}

void Monster::setSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

sf::Texture* Monster::getHealthBarTexture()
{
	// TODO: insérer une instruction return ici
	//return _healthBarTexturePtr;
	return nullptr;
}


/*sf::Sprite& Monster::getHealthBarSprite()
{
	// TODO: insérer une instruction return ici
	return _healthBarSprite;
}

void Monster::setHealthBarSprite(sf::Sprite sprite)
{
	_healthBarSprite = sprite;
}

sf::Texture* Monster::getHoverTexture()
{
	// TODO: insérer une instruction return ici
	//return _hoverTexturePtr;
	return nullptr;
}

sf::Sprite& Monster::getHoverSprite()
{
	// TODO: insérer une instruction return ici
	return _hoverSprite;
}
*/
void Monster::setHoverSprite(sf::Sprite sprite)
{
	//_hoverSprite = sprite;
}

void Monster::draw(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(_sprite);
	gameWindow.draw(_emptyHealthBar);
	gameWindow.draw(_foreGroundHealthbar);
}

void Monster::update()
{
	if (_hp >= _maxHp)
	{
		float heightOfEnemy = _texture.getSize().y * _sprite.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - heightOfEnemy / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		
		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setTextureRect(sf::IntRect(0,0,maxWidthHealthBar, heightHealthBar));
		//std::cout << "fully alive" << std::endl;à
		
	}

	else if(_hp < _maxHp && _hp > 0)
	{
		float heightOfEnemy = _texture.getSize().y * _sprite.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - heightOfEnemy / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(widthOfForegroundHealthBar, heightHealthBar));
	}

	else if(_hp <= 0)
	{

		float heightOfEnemy = _texture.getSize().y * _sprite.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - heightOfEnemy / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(0, heightHealthBar));
	}
	
	

	

}
