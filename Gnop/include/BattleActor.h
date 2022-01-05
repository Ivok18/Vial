#ifndef BATTLEACTOR
#define BATTLEACTOR
#include "Damageable.h"
#include "Mana.h"

class BattleActor : public Damageable
{
protected:
	Mana _mana;
	Mana* _manaPtr;
	float _magicAtk;
	

protected:
	virtual void inits() = 0;
		virtual void initSpriteAndTexture() = 0;
		virtual void initHitbox() = 0;
		virtual void initStats() = 0;

public:
	BattleActor();
	BattleActor(float magicAtk);
	~BattleActor() = default;


	virtual sf::Sprite& getSprite() = 0;
	virtual void setSprite(sf::Sprite newSprite) = 0;

	virtual sf::Texture& getTexture() = 0;
	virtual void setTexture(sf::Texture newTexture) = 0;

	virtual sf::FloatRect& getHitbox() = 0;
	virtual void setHitBox(sf::FloatRect newHitBox) = 0;

	virtual float getAtk() = 0;
	virtual void setAtk(float newAtk) = 0;

	virtual Health& getHealth() = 0;
	virtual void setHealth(Health newHealth) = 0;

	virtual Health* getHealthPtr() = 0;
	virtual void setHealthPtr(Health* newHealthPtr) = 0;

	virtual Mana& getMana() = 0;
	virtual void setMana(Mana newMana) = 0;

	virtual Mana* getManaPtr() = 0;
	virtual void setManaPtr(Mana* newManaPtr) = 0;

	virtual float getMagicAtk() = 0;
	virtual void setMagicAtk(float newMagicAtk) = 0;

	virtual void getDamage(float damage) = 0;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& gameWindow) = 0;

};

#endif


