#ifndef MONSTER
#define MONSTER

#include <iostream>
#include <SFML/Graphics.hpp>

class Monster
{

protected:
	std::string _name;
	float _hp;
	float _maxHp;
	float _atk;
	static int __armyId;
	int armyId;
	int _reactionSpeed;
	int _level;

	sf::Texture _texture;
	sf::Sprite _sprite;

	sf::RectangleShape _emptyHealthBar;
	sf::RectangleShape _foreGroundHealthbar;

	float _Yoffset;
	float _Xoffset;
	
	
	
public:
	Monster();
	Monster(std::string name, float hp, float atk);
	~Monster();

	float getAtk();
	void setAtk(float newAtk);

	float getHp();
	void setHp(float hp);
	
	float getMaxHp();
	void setMaxHp(float maxHp);

	std::string getName();
	int getArmyId();

	int getReactionSpeed();
	void determineReactionSpeed(int reactionSpeed);

	void setHpLost(float hp_lost);

	sf::Texture& getTexture();
	void setTexture(sf::Texture texture);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite sprite);

	sf::Texture* getHealthBarTexture();
	

	sf::Sprite& getHealthBarSprite();
	void setHealthBarSprite(sf::Sprite sprite);

	sf::Texture* getHoverTexture();
	

	sf::Sprite& getHoverSprite();
	void setHoverSprite(sf::Sprite sprite);
	

	void draw(sf::RenderWindow& gameWindow);
	void update();

};

#endif