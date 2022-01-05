#ifndef HEALTH
#define HEALTH
#include <vector>

class HealthObserver;

class Health 
{
protected:
	float _hp;
	float _maxHp;
	float _baseMaxHp;

public:
	Health();
	Health(float hp);
	~Health() = default;

	float getHp();
	void setHp(float value);

	float getMaxHp();
	void setMaxHp(float maxHp);

	float getBaseMaxHp();
	void setBaseMaxHp(float base);

	void notifyAll();
	std::vector<HealthObserver*>& getObserversList();

};

#endif


