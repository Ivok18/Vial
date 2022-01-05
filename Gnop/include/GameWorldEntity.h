#ifndef GAMEWORLDENTITY
#define GAMEWORLDENTITY
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

class GameWorldEntity
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::FloatRect _hitbox;

protected:
	virtual void inits() = 0;
		virtual void initSpriteAndTexture() = 0;
		virtual void initHitbox() = 0;
	
public:
	GameWorldEntity();
	GameWorldEntity(sf::Texture texture);
	~GameWorldEntity() = default;

	virtual sf::Sprite& getSprite() = 0;
	virtual void setSprite(sf::Sprite newSprite) = 0;

	virtual sf::Texture& getTexture() = 0;
	virtual void setTexture(sf::Texture newTexture) = 0;

	virtual sf::FloatRect& getHitbox() = 0;
	virtual void setHitBox(sf::FloatRect newHitBox) = 0;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& gameWindow) = 0;
};
#endif


