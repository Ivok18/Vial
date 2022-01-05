#ifndef FLYING_ENEMY
#define FLYING_ENEMY
#include "TheEnemy.h"


class FlyingEnemy :public TheEnemy
{
protected:
	sf::Texture _textureOfFlyingEnemyRight;
	sf::Texture _textureOfFlyingEnemyLeft;

	sf::FloatRect _hitboxOfDash;
	sf::RectangleShape _viewOfHitboxOfDash;
	bool _dashing = false;
	bool _facingDown = false;

	sf::Color _color;
	static int _theLevel;

	float _baseMaxHp = 25;
	float _baseAtk = 5;

public:
	FlyingEnemy();
	~FlyingEnemy() = default;

	FlyingEnemy& operator=(FlyingEnemy & enemy);

	std::string getType();
	void setType(std::string type);

	b2BodyDef& getBodyDef();
	void setB2BodyDef(b2BodyDef bodyDef);

	b2FixtureDef& getFixtureDef();
	void setFixtureDef(b2FixtureDef fixtureDef);

	b2Body* getBody();
	void setBody(b2Body * body);

	b2PolygonShape& getShape();
	void setShape(b2PolygonShape shape);

	sf::Texture& getTexture();
	void setTexture(sf::Texture texture);

	sf::Texture& getTextureOfFlyingEnemyRight();
	void setTextureOfFlyingEnemyRight(sf::Texture texture);

	sf::Texture& getTextureOfFlyingEnemyLeft();
	void setTextureOfFlyingEnemyleft(sf::Texture texture);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite sprite);

	bool getUpDirection();
	void setUpDirection(bool boolean);

	bool getDownDirection();
	void setDownDirection(bool boolean);

	bool getLeftDirection();
	void setLeftDirection(bool boolean);

	bool getRightDiretion();
	void setRightDirection(bool boolean);

	float getYOffset();
	void setYOffset(float yOffset);

	sf::RectangleShape& getEmptyHealthbar();
	void setEmptyHealthbar(sf::RectangleShape emptyHealthbar);

	sf::RectangleShape& getForegroundHealthbar();
	void setForegroundHealthbar(sf::RectangleShape foregroundHealthbar);

	sf::FloatRect& getHitbox();
	void setHitbox(sf::FloatRect hitbox);

	sf::RectangleShape& getHitboxView();
	void setHitboxView(sf::RectangleShape view);

	sf::FloatRect& getHitboxOfAtk();
	void setHitboxOfAtk(sf::FloatRect hitboxOfAtk);

	sf::RectangleShape& getHitboxOfAtkView();
	void setHitboxOfAtkView(sf::RectangleShape view);

	sf::FloatRect& getHitboxOfDash();
	void setHitboxOfDash(sf::FloatRect hitbox);

	sf::RectangleShape& getViewOfHitboxOfDash();
	void setViewOfHitboxOfDash(sf::RectangleShape view);

	float getBaseAtk();
	void setBaseAtk(float base);

	float getAtk();
	void setAtk(float atk);

	float getMaxAtk();
	void setMaxAtk(float max);

	bool attacking();
	void isAttacking(bool boolean);

	float getSpeed();
	void setSpeed(float speed);

	float getMaxSpeed();
	void setMaxSpeed(float max);

	bool daashing();
	void isDaashing(bool boolean);

	int getLevel();
	void setLevel(int level);

	static void levelUp();
	static void reset();

	void boost();

	float getBaseXpDrop();
	void setBaseXpDrop(float xpDrop);

	float getBaseMoneyDrop();
	void setBaseMoneyDrop(float base);

	float getXpDrop();
	void setXpDrop(float xpDrop);

	float getMoneyDrop();
	void setMoneyDrop(float moneyDrop);


	sf::Font& getFont();
	void setFont(sf::Font font);

	sf::Text& getLevelIndicator();
	void setLevelIndicator(sf::Text string);

	float  getBaseMaxHp();
	void setBaseMaxHp(float base);

	float getMaxHp();
	void setMaxHp(float maxHp);

	float getHp();
	void setHp(float hp);

	sf::Color& getColor();
	void setColor(sf::Color color);

	void getDamage(float damage);

	void update();
	void draw(sf::RenderWindow & window);
};

#endif // !FLYING_ENEMY

