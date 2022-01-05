
#ifndef INVENTORY
#define INVENTORY
#include <vector>
#include <SFML/Graphics.hpp>

#include "HealingPotion.h"
#include "ForcePotion.h"
#include "Sword_.h"
#include "Bow.h"
#include "Epic.h"

class Inventory
{
protected:
	std::vector<Item*> vectorOfItems;
	int maxCapacity;
	HealingPotion firstItem;
	Item* firstItemPtr;

	sf::RectangleShape _inventoryView;
	sf::RectangleShape _containerView;

public:
	Inventory();
	Inventory(HealingPotion firstItem, Item* firstItemPtr_);
	~Inventory();

	std::vector<Item*>& getVectorOfItems();
	void setInventoryItems(std::vector<Item*> newVectorOfItems);
	/* here, method "display() is like "printVectorOfItems" */

	int getMaxCapacity();
	void setMaxCapacity(int newMaxCapacity);
	void printMaxCapacity();

	void add(Item* itemPtr);
	void remove(Item* itemPtr);
	
	HealingPotion* findHealPotion();
	ForcePotion* findForcePotion();
	Sword_* findSword(std::string nameOfKingdom);
	Bow* findBow(std::string nameOfKingdom);
	Epic* findEpic(std::string nameOfKingdom);



	void update();

	sf::RectangleShape& getInventoryView();
	sf::RectangleShape& getContainerView();
	void draw(sf::RenderWindow& gameWindow);


};


#endif // !INVENTORY

