#ifndef BLOC
#define BLOC
#include "Damageable.h"

class Bloc : public Damageable
{
protected:
	sf::RectangleShape _collider;
	float _width = 16;
	float _height = 60;
	float _price = 5;
	int _id = 0;

protected:
	void inits();
		void initSpriteAndTexture();
		void initHitbox();
		void initStats();

public:
	Bloc();
	~Bloc() = default;

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite newSprite);

	sf::Texture& getTexture();
	void setTexture(sf::Texture newTexture);

	sf::FloatRect& getHitbox();
	void setHitBox(sf::FloatRect newHitBox);

	sf::RectangleShape& getCollider();
	void setCollider(sf::RectangleShape collider);

	float getAtk();
	void setAtk(float newAtk);

	Health& getHealth();
	void setHealth(Health newHealth);

	Health* getHealthPtr();
	void setHealthPtr(Health* newHealthPtr);

	float getPrice();
	void setPrice(float price);

	int getId();
	void setId(int id);
	
	void getDamage(float damage);

	void update();
	void draw(sf::RenderWindow& gameWindow);
};

#endif


