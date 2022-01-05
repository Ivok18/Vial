#include "Player.h"

#include <iostream>

Player::Player()
{

	_textureOfPlayer.loadFromFile("data/player.png");
	_spriteOfPlayer.setTexture(_textureOfPlayer);
	float widthOfPlayer = _textureOfPlayer.getSize().x * _spriteOfPlayer.getScale().x;
	float heightOfPlayer = _textureOfPlayer.getSize().y * _spriteOfPlayer.getScale().y;
	_spriteOfPlayer.setOrigin(widthOfPlayer / 2, heightOfPlayer / 2);

	

	_weaponEquiped = nullptr;
	_name = "player";
	_baseHp = 500.f;
	_hp = _baseHp * _level;
	_maxHp = 500.f;
	_baseAtk = 50.f;
	_atk = _baseAtk * _level;




	_emptyHealthBar.setSize(sf::Vector2f(92, 15));

	float healthBarWidth = _emptyHealthBar.getSize().x * _spriteOfPlayer.getScale().x;
	float healthBarHeight = _emptyHealthBar.getSize().y * _spriteOfPlayer.getScale().y;
	_emptyHealthBar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_emptyHealthBar.setOutlineThickness(-1);
	_emptyHealthBar.setOutlineColor(sf::Color::Black);



	_foreGroundHealthbar.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
	_foreGroundHealthbar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_foreGroundHealthbar.setFillColor(sf::Color::Green);
	_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);

	float maxWidthHealthBar = _emptyHealthBar.getScale().x *
		_emptyHealthBar.getSize().x;

	float newWidthHealthBar = _textureOfPlayer.getSize().x * _spriteOfPlayer.getScale().x;

	_emptyHealthBar.setScale(newWidthHealthBar
		/ maxWidthHealthBar, 1.f);

	_foreGroundHealthbar.setScale(_emptyHealthBar.getScale().x, _emptyHealthBar.getScale().y);
}

Player::Player(Inventory& inventoryPtr, std::string name_, float hp_, float atk_)
{
	_textureOfPlayer.loadFromFile("data/player.png");
	_spriteOfPlayer.setTexture(_textureOfPlayer);
	float widthOfPlayer = _textureOfPlayer.getSize().x * _spriteOfPlayer.getScale().x;
	float heightOfPlayer = _textureOfPlayer.getSize().y * _spriteOfPlayer.getScale().y;
	_spriteOfPlayer.setOrigin(widthOfPlayer / 2, heightOfPlayer / 2);

	_inventory = inventoryPtr;
	_name = name_;
	_baseHp = hp_;
	_maxHp = 100.f;
	_baseAtk = atk_;

	_emptyHealthBar.setSize(sf::Vector2f(92, 15));

	float healthBarWidth = _emptyHealthBar.getSize().x * _spriteOfPlayer.getScale().x;
	float healthBarHeight = _emptyHealthBar.getSize().y * _spriteOfPlayer.getScale().y;
	_emptyHealthBar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_emptyHealthBar.setOutlineThickness(-1);
	_emptyHealthBar.setOutlineColor(sf::Color::Black);



	_foreGroundHealthbar.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
	_foreGroundHealthbar.setOrigin(healthBarWidth / 2.f, healthBarHeight / 2.f);
	_foreGroundHealthbar.setFillColor(sf::Color::Green);
	_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);

	float maxWidthHealthBar = _emptyHealthBar.getScale().x *
		_emptyHealthBar.getSize().x;

	float newWidthHealthBar = _textureOfPlayer.getSize().x * _spriteOfPlayer.getScale().x;

	_emptyHealthBar.setScale(newWidthHealthBar
		/ maxWidthHealthBar, 1.f);

	_foreGroundHealthbar.setScale(_emptyHealthBar.getScale().x, _emptyHealthBar.getScale().y);
}

Player::~Player()
{
}


/*void Player::attack()
{
	std::cout << "player attacks" << std::endl;

}*/

/*void Player::defend()
{
	std::cout << "player defends" << std::endl;
}
*/

/*void Player::_escape()
{
	std::cout << "player fleed" << std::endl;
}
*/




void Player::displayInventory(sf::RenderWindow& gameWindow)
{
	_inventory.draw(gameWindow);
}

/*Inventory* Player::getInventoryPtr()
{
	return inventoryPtr;
}
*/
Inventory& Player::getInventory() 
{
	return _inventory;
}

void Player::setInventory(Inventory& newInventory)
{
	_inventory = newInventory;
}
void Player::drinkHealPotion()
{
	/*if(_inventory.findHealPotion() != nullptr)
	{
		HealingPotion* healingPot = _inventory.findHealPotion();
		_hp += healingPot->getHpToGive();
		if (_hp >= _maxHp)
			_hp = _maxHp;

		std::cout << "player drinks healing potion +" << _inventory.findHealPotion()->getHpToGive() << "_hp" << std::endl;
		std::cout << "buuuuuurp" << std::endl;
		_inventory.remove(healingPot);
	}
	*/
}
void Player::drinkForcePotion()
{
	/*if(_inventory.findForcePotion() != nullptr)
	{
		ForcePotion* forcePot = _inventory.findForcePotion();
		_atk += forcePot->getAtkToGive();
		std::cout << "player drinks force potion +" << _inventory.findForcePotion()->getAtkToGive() << "_atk" << std::endl;
		std::cout << "buuuuuurp" << std::endl;
		_inventory.remove(forcePot);
	}
	*/
}
void Player::equip(sf::RenderWindow& gameWindow)
{
	if (_weaponEquiped == nullptr)
	{
		_weaponEquiped->getSprite().setPosition(_spriteOfPlayer.getPosition().x, _spriteOfPlayer.getPosition().y);
		//show _inventory content
		//displayInventory(gameWindow);

		//player has to choose which item he wants to throw
		//std::cout << "item's origin kingdom: ";

		//std::string nameOfKingdom;
		//std::cin >> nameOfKingdom;

		//bool itemFound = false;

		/*for (auto itemPtr : _inventory.getVectorOfItems())
		{
			if (itemPtr->getNameOfKingdom() == nameOfKingdom)
			{
				itemFound = true;
				auto weaponPtr = dynamic_cast<Weapon*>(itemPtr);
				_atk += weaponPtr->getAtk();
				_weaponEquiped = weaponPtr;
				_inventory.remove(weaponPtr);
				std::cout << weaponPtr->getType() << "equiped!" << std::endl;
			}
		}
		*/

		/*if (!itemFound)
		{
			char inventoryChoice_;

			do
			{
				std::cout << "there is no kingdom with such _name, try again, or leave (t/l) \n";

				inventoryChoice_ = _getch();

				if (inventoryChoice_ == 't')
				{
					std::cout << "kingdom _name: ";

					std::string nameOfKingdom;
					std::cin >> nameOfKingdom;

					for (auto itemPtr : _inventory.getVectorOfItems())
					{
						if (itemPtr->getNameOfKingdom() == nameOfKingdom)
						{
							itemFound = true;
							auto weaponPtr = dynamic_cast<Weapon*>(itemPtr);
							_atk += weaponPtr->getAtk();
							_weaponEquiped = weaponPtr;
							_inventory.remove(weaponPtr);
							std::cout << weaponPtr->getType() << "equiped!" << std::endl;
						}
					}

				}
			} while (!itemFound && inventoryChoice_ == 't');
		}
		*/

	}
	else 
	{
		std::cout << _name << " has already a weapon: " << std::endl;
		//_weaponEquiped->Display(gameWindow);
		std::cout << std::endl;
		std::cout << "desequip " << _weaponEquiped->getType() << " first" << std::endl;

	}

	std::cout << "your _inventory:" << std::endl;
	//displayInventory();
}
void Player::desequip()
{
	//show weapon player is using
	std::cout << "are you sure you want to desequip this weapon? (y/other)" << std::endl;
	//_weaponEquiped->Display();

	char choice = _getch();

	if(choice == 'y')
	{
		//remove stats bonus
		//_atk -= _weaponEquiped->getAtk();

		//cast to item pointer
		auto itemPtr = dynamic_cast<Item*>(_weaponEquiped);

		//add to _inventory
		_inventory.add(itemPtr);

		//no more weapon equiped
		_weaponEquiped = nullptr;
	}

	std::cout << "your _inventory:" << std::endl;
	
	//displayInventory();
}
void Player::throwItem()
{
	//show _inventory content
	//displayInventory();

	//player has to choose which item he wants to throw
	std::cout << "item's origin kingdom: ";

	std::string nameOfKingdom;
	std::cin >> nameOfKingdom;

	bool itemFound = false;

	for (auto itemPtr : _inventory.getVectorOfItems())
	{
		if (itemPtr->getNameOfKingdom() == nameOfKingdom)
		{
			itemFound = true;
			_inventory.remove(itemPtr);
		}
	}

	if (!itemFound)
	{
		char inventoryChoice_;

		do
		{
			std::cout << "there is no kingdom with such _name, try again, or leave (t/l) \n";

			inventoryChoice_ = _getch();

			if (inventoryChoice_ == 't')
			{
				std::cout << "kingdom _name: ";

				std::string nameOfKingdom;
				std::cin >> nameOfKingdom;

				for (auto itemPtr : _inventory.getVectorOfItems())
				{
					if (itemPtr->getNameOfKingdom() == nameOfKingdom)
					{
						itemFound = true;
						_inventory.remove(itemPtr);
					}
				}

			}
		} while (!itemFound && inventoryChoice_ == 't');
	}

	std::cout << "votre inventaire:" << std::endl;
	//displayInventory();
}

/*void Player::setInventoryPtr(Inventory* newInventoryPtr)
{
	inventoryPtr = newInventoryPtr;
}
*/
void Player::setHpLost(float hp_lost)
{
	_hp-= hp_lost;

	if (_hp <= 0)
		_hp = 0;
}

bool Player::up()
{
	return _up;
}

void Player::isGoingUp(bool boolean)
{
	_up = boolean;
}

bool Player::down()
{
	return _down;
}

void Player::isGoingDown(bool boolean)
{
	_down = boolean;
}

bool Player::left()
{
	return _left;
}

void Player::isGoingLeft(bool boolean)
{
	_left = boolean;
}

bool Player::right()
{
	return _right;
}

void Player::isGoingRight(bool boolean)
{
	_right = boolean;
}


void Player::update()
{
	
	if(_weaponEquiped != nullptr)
	{
	
		_weaponEquiped->getSprite().setPosition(_spriteOfPlayer.getPosition().x, _spriteOfPlayer.getPosition().y);
	}

	if (_hp >= _maxHp)
	{
		
		float heightOfPlayer = _textureOfPlayer.getSize().y * _spriteOfPlayer.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_spriteOfPlayer.getPosition().x, _spriteOfPlayer.getPosition().y - heightOfPlayer / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(92, 15));
		//std::cout << "fully alive" << std::endl;à

	}

	else if (_hp < _maxHp && _hp > 0)
	{
		
		float heightOfPlayer = _textureOfPlayer.getSize().y * _spriteOfPlayer.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_spriteOfPlayer.getPosition().x, _spriteOfPlayer.getPosition().y - heightOfPlayer / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(widthOfForegroundHealthBar, heightHealthBar));
	}

	else if (_hp <= 0)
	{

		float heightOfPlayer = _textureOfPlayer.getSize().y * _spriteOfPlayer.getScale().y;
		float heightOfHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;
		_emptyHealthBar.setPosition(_spriteOfPlayer.getPosition().x, _spriteOfPlayer.getPosition().y - heightOfPlayer / 2.f - heightOfHealthBar / 2.f - _Yoffset);
		_foreGroundHealthbar.setPosition(_emptyHealthBar.getPosition().x, _emptyHealthBar.getPosition().y);


		//std::cout << "hp remaining: " << _damageablePtr->getHealth().getHp() << std::endl;
		float maxWidthHealthBar = _emptyHealthBar.getSize().x * _emptyHealthBar.getScale().x;
		float heightHealthBar = _emptyHealthBar.getSize().y * _emptyHealthBar.getScale().y;

		float percentageOfHpRemaining = _hp / _maxHp * 100.f;
		float widthOfForegroundHealthBar = percentageOfHpRemaining / 100.f * maxWidthHealthBar;
		_foreGroundHealthbar.setSize(sf::Vector2f(0, heightHealthBar));
	}

	

}

void Player::draw(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(_spriteOfPlayer);
	gameWindow.draw(_emptyHealthBar);
	gameWindow.draw(_foreGroundHealthbar);
}


float Player::getAtk()
{
	return _baseAtk * _level;
}

void Player::setAtk(float newAtk)
{
	_atk = newAtk;
}

void Player::printAtk()
{
	std::cout << _atk << std::endl;
}

float Player::getBaseAtk()
{
	return _baseAtk;
}

void Player::setBaseAtk(float atk)
{
	_baseAtk = atk;
}

float Player::getHp()
{
	return _hp;
}

void Player::setHp(float newHp)
{
	_hp = newHp;
}

void Player::printHp()
{
	
	std::cout << getHp() << std::endl;
}

float Player::getBaseHp()
{
	return _baseHp;
}

void Player::setBaseHp(float hp)
{
	_baseHp = hp;
}

float Player::getMaxHp()
{
	return _maxHp;
}

void Player::setMaxHp(float maxHp)
{
	_maxHp = maxHp;
}

void Player::printMaxHp()
{
	std::cout << _maxHp << std::endl;
}

std::string Player::getName()
{
	return _name;
}

void Player::setName(std::string newName)
{
	_name = newName;
}

void Player::printName()
{
	std::cout << _name << std::endl;
}

sf::Sprite& Player::getSprite()
{
	return _spriteOfPlayer;
}

sf::Texture& Player::getTexture()
{
	return _textureOfPlayer;
}

Weapon* Player::getWeaponEquiped()
{
	return _weaponEquiped;
}

void Player::setWeaponEquiped(Weapon* weapon)
{
	/*if(_weaponEquiped!=nullptr)
	{
		std::cout << "atk:" << _atk << std::endl;
		_weaponEquiped = weapon;
		_atk += _weaponEquiped->getAtk();
		std::cout << "atk:" << _atk << std::endl;
	}
	*/
}

bool Player::hasFled()
{
	return _escape;
}

void Player::setEscape(bool boolean)
{
	_escape = boolean;
}

int Player::getNbFights()
{
	return _nbFights;
}

void Player::setNbFights(int nbFights)
{
	_nbFights = nbFights;
}

int Player::getLevel()
{
	return _level;
}

void Player::setLevel(int level)
{
	_level = level;
}

int Player::getXpGain()
{
	return _xpGain;
}

void Player::setXpGain(int xpGain)
{
	_xpGain = xpGain;
}

int Player::getXpToLevelUp()
{
	return _xpToLevelUp;
}

void Player::setXpToLevelUp(int xp)
{
	_xpToLevelUp = xp;
}
