#ifndef THEHEALTH
#define THEHEALTH


class TheHealth
{
protected:
	float _maxHp = 100;
	float _hp = _maxHp;

public:
	TheHealth();
	TheHealth(float hp);
	~TheHealth() = default;	

	float getMaxHp();
	void setMaxHp(float maxHp);

	float getHp();
	void setHp(float hp);

};

#endif // !THEHEALTH