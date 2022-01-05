#ifndef PLAYER
#define PLAYER
#include "HealingPotion.h"
#include "Weapon.h"
#include "Inventory.h"
#include <conio.h>
class Player
{
protected:
	Inventory _inventory; // Created by seb
	Weapon* _weaponEquiped;
	std::string _name;
	float _baseHp;
	float _hp;
	float _maxHp;
	float _baseAtk;
	float _atk;
	bool _escape = false;
	float _nbFights = 0;

	bool _up = false;
	bool _down = false;
	bool _left = false;
	bool _right = false;

	sf::Texture _textureOfPlayer;
	sf::Sprite _spriteOfPlayer;

	sf::RectangleShape _emptyHealthBar;
	sf::RectangleShape _foreGroundHealthbar;

	float _Yoffset = 4.f;
	int _xpGain = 0;
	int _xpToLevelUp = 100;
	int _level = 1;

public:
	Player();
	Player(Inventory& inventoryPtr, std::string name_,float hp_, float atk_);
	~Player();

	Inventory& getInventory();

	void setInventory(Inventory& newInventory);
	void displayInventory(sf::RenderWindow& gameWindow);

	float getAtk();
	void setAtk(float newAtk);
	void printAtk();

	float getBaseAtk();
	void setBaseAtk(float atk);


	float getHp();
	void setHp(float newHp);
	void printHp();

	float getBaseHp();
	void setBaseHp(float hp);

	float getMaxHp();
	void setMaxHp(float maxHp);
	void printMaxHp();

	std::string getName();
	void setName(std::string newName);
	void printName();

	sf::Sprite& getSprite();
	sf::Texture& getTexture();

	Weapon* getWeaponEquiped();
	void setWeaponEquiped(Weapon* weapon);

	bool hasFled();
	void setEscape(bool boolean);

	int getNbFights();
	void setNbFights(int nbFights);

	int getLevel();
	void setLevel(int level);

	int getXpGain();
	void setXpGain(int xpGain);

	int getXpToLevelUp();
	void setXpToLevelUp(int xp);

	void drinkHealPotion();
	void drinkForcePotion();
	void equip(sf::RenderWindow& gameWindow);
	void desequip();
	void throwItem();

	void setHpLost(float hp_lost);

	bool up();
	void isGoingUp(bool boolean);

	bool down();
	void isGoingDown(bool boolean);

	bool left();
	void isGoingLeft(bool boolean);

	bool right();
	void isGoingRight(bool boolean);

	void update();
	void draw(sf::RenderWindow& gameWindow);
	


};
#endif