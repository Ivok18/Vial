#ifndef PLAYER
#define PLAYER
#include <box2d/b2_body.h>
#include "SFML/Graphics.hpp"

class Player
{
protected:
	b2BodyDef _bodyDef;
	sf::Texture _texture;
	sf::Sprite _sprite;
	
public:
	Player();
	~Player() = default;

	b2BodyDef& getBodyDef();
	void setB2BodyDef(b2BodyDef bodyDef);

	sf::Texture& getTexture();
	void setTexture(sf::Texture texture);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite sprite);

};

#endif


