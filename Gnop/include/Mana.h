#ifndef MANA
#define MANA



class ManaObserver;

class Mana 
{
protected:
	float _mana;
	float _maxMana;
public:
	Mana();
	Mana(float mana);
	~Mana() = default;

	

	float getMana();
	void setMana(float mana);

	float getMaxMana();
	void setMaxMana();

	void notifyAll();
	
};

#endif


