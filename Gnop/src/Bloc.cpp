#include "Bloc.h"


Bloc::Bloc()
{
	_collider.setSize(sf::Vector2f(_width, _height));
	_collider.setOrigin(_width / 2, _height / 2);
	_collider.setFillColor(sf::Color::Cyan);
	_collider.setPosition(-1000, -1000);
}


void Bloc::inits()
{

}

void Bloc::initSpriteAndTexture()
{
}

void Bloc::initHitbox()
{
}

void Bloc::initStats()
{
}

sf::Sprite& Bloc::getSprite()
{
	return _sprite;
}

void Bloc::setSprite(sf::Sprite newSprite)
{
	_sprite = newSprite;
}

sf::Texture& Bloc::getTexture()
{
	return _texture;
}

void Bloc::setTexture(sf::Texture newTexture)
{
	_texture = newTexture;
}

sf::FloatRect& Bloc::getHitbox()
{
	return _hitbox;
}

void Bloc::setHitBox(sf::FloatRect newHitBox)
{
	_hitbox = newHitBox;
}

sf::RectangleShape& Bloc::getCollider()
{
	return _collider;
}

void Bloc::setCollider(sf::RectangleShape collider)
{
	_collider = collider;
}

float Bloc::getAtk()
{
	return 0.0f;
}

void Bloc::setAtk(float newAtk)
{
	//TODO
}

Health& Bloc::getHealth()
{
	return _health;
}

void Bloc::setHealth(Health newHealth)
{
	//TODO
}

Health* Bloc::getHealthPtr()
{
	return nullptr;
}

void Bloc::setHealthPtr(Health* newHealthPtr)
{
	//TODO
}

float Bloc::getPrice()
{
	return _price;
}

void Bloc::setPrice(float price)
{
	_price = price;
}

int Bloc::getId()
{
	return _id;
}

void Bloc::setId(int id)
{
	_id = id;
}


void Bloc::getDamage(float damage)
{

}

void Bloc::update()
{

}

void Bloc::draw(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(_collider);
}
