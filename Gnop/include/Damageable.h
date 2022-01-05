#ifndef DAMAGEABLE
#define DAMAGEABLE

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "GameWorldEntity.h"
#include "Health.h"

class Damageable : public GameWorldEntity
{
protected:
	float _atk;
	Health _health;
	Health* _healthPtr;

protected:
	virtual void inits() = 0;
		virtual void initSpriteAndTexture() = 0;
		virtual void initHitbox() = 0;
		virtual void initStats() = 0;

public:
	Damageable();
	Damageable(float atk);
	~Damageable() = default;
	
	virtual sf::Sprite& getSprite() = 0;
	virtual void setSprite(sf::Sprite newSprite) = 0;

	virtual sf::Texture& getTexture() = 0;
	virtual void setTexture(sf::Texture newTexture) = 0;

	virtual sf::FloatRect& getHitbox() = 0;
	virtual void setHitBox(sf::FloatRect newHitBoxOfBasicAtk) = 0;

	virtual float getAtk() = 0;
	virtual void setAtk(float newAtk) = 0;

	virtual Health& getHealth() = 0;
	virtual void setHealth(Health newHealth) = 0;

	virtual Health* getHealthPtr() = 0;
	virtual void setHealthPtr(Health* newHealthPtr) = 0;

	virtual void getDamage(float damage) = 0;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& gameWindow) = 0;
};

#endif


