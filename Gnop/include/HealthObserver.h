#ifndef HEALTHOBSERVER
#define HEALTHOBSERVER

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Damageable.h"
class HealthObserver // TRANSFERER DANS LA CLASSE ENEMY
{
protected:
	Damageable* _damageablePtr;

	

public:
	HealthObserver();
	HealthObserver(Damageable* damageablePtr);
	~HealthObserver() = default;

	

	HealthObserver* getPtr();
	Damageable* getDamageablePtr();

	void update();
	void draw(sf::RenderWindow& _gameWindow);

};

#endif

