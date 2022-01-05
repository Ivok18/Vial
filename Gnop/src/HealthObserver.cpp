#include "HealthObserver.h"

/*HealthObserver::HealthObserver()
{
	_Yoffset = 3.f;
	_damageablePtr= nullptr;
	
}

HealthObserver::HealthObserver(Damageable* damageablePtr)
{
	_Yoffset = 3.f;
	_damageablePtr= damageablePtr;
}

sf::RectangleShape& HealthObserver::getHealthBarEmpty()
{
	return _healthbarEmpty;
}

void HealthObserver::setHealthBarEmpty(sf::RectangleShape healthbarEmpty)
{
	_healthbarEmpty = healthbarEmpty;
}

sf::RectangleShape& HealthObserver::getHealthbar()
{
	return _healthbar;
}

void HealthObserver::setHealthbar(sf::RectangleShape healthbar)
{
	_healthbar = healthbar;
}

float& HealthObserver::getYOffset()
{
	return _Yoffset;
}

void HealthObserver::setYOffset(float newYOffset)
{
	_Yoffset = newYOffset;
}


Damageable* HealthObserver::getDamageablePtr()
{
	return _damageablePtr;
}

void HealthObserver::update()
{
	float hp = _damageablePtr->getHealth().getHp();
	float maxHp = _damageablePtr->getHealth().getMaxHp();
	if (hp >= maxHp)
	{
		float heightOfDamageable = _damageablePtr->getTexture().getSize().y *  _damageablePtr->getSprite().getScale().y;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_damageablePtr->getSprite().getPosition().x, _damageablePtr->getSprite().getPosition().y - heightOfDamageable / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_healthbar.setPosition(_healthbarEmpty.getPosition().x, _healthbarEmpty.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _healthbarEmpty.getSize().x * _healthbarEmpty.getScale().x;
		float heightHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

		
		float percentageOfHpRemaining = hp / maxHp * 100.f;
		//float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_healthbar.setSize(sf::Vector2f(92, 15));
		//std::cout << "fully alive" << std::endl;

	}

	else if (hp < maxHp && hp > 0)
	{

		float heightOfDamageable = _damageablePtr->getTexture().getSize().y *  _damageablePtr->getSprite().getScale().y;
		float heightOfHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;
		_healthbarEmpty.setPosition(_damageablePtr->getSprite().getPosition().x, _damageablePtr->getSprite().getPosition().y - heightOfDamageable / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_healthbar.setPosition(_healthbarEmpty.getPosition().x, _healthbarEmpty.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _healthbarEmpty.getSize().x * _healthbarEmpty.getScale().x;
		float heightHealthBar = _healthbarEmpty.getSize().y * _healthbarEmpty.getScale().y;

		
		float percentageOfHpRemaining = hp / maxHp * 100.f;
		float widthOfhealthbar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_healthbar.setSize(sf::Vector2f(widthOfhealthbar, 15));
		//std::cout << "fully alive" << std::endl;à
	}

}

void HealthObserver::draw(sf::RenderWindow& _gameWindow)
{
	_gameWindow.draw(_healthbarEmpty);
	_gameWindow.draw(_healthbar);
}
*/
