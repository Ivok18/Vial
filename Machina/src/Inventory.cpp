#include "Inventory.h"

Inventory::Inventory()
{
	maxCapacity = 10;
	firstItem = HealingPotion("healing potion", 10);
	firstItemPtr = &firstItem;
	vectorOfItems.push_back(firstItemPtr);

	
}

Inventory::Inventory(HealingPotion firstItem_, Item* firstItemPtr_)
{
	maxCapacity = 10;
	firstItem = firstItem_;
	firstItemPtr = firstItemPtr_;

	/*_inventoryView.setSize(sf::Vector2f(500, 300));
	_inventoryView.setPosition(100, 100);
	_inventoryView.setFillColor(sf::Color::Black);

	float widthOfInventoryView = _inventoryView.getSize().x * _inventoryView.getSize().x;
	float heightOfInventoryView = _inventoryView.getSize().x * _inventoryView.getSize().x;
	_containerView.setSize(sf::Vector2f(0.8f * widthOfInventoryView, 0.6f * heightOfInventoryView));
	_containerView.setFillColor(sf::Color::Cyan);
	*/

}

Inventory::~Inventory()
{
}

std::vector<Item*>& Inventory::getVectorOfItems()
{
	return vectorOfItems;
}

void Inventory::setInventoryItems(std::vector<Item*> newVectorOfItems)
{
	vectorOfItems = newVectorOfItems;
}

int Inventory::getMaxCapacity()
{
	return maxCapacity;
}

void Inventory::setMaxCapacity(int newMaxCapacity)
{
	maxCapacity = newMaxCapacity;
}

void Inventory::printMaxCapacity()
{
	



	std::cout << maxCapacity << std::endl;
}


void Inventory::add(Item* itemPtr)
{
	vectorOfItems.push_back(itemPtr);
	
}

void Inventory::remove(Item* itemPtr)
{
	std::vector<Item*>::iterator it;
	it = vectorOfItems.begin();

	int i = 0;

	while (*it != itemPtr )
	{
		i++;
		it++;
	}

	vectorOfItems.erase(vectorOfItems.begin() + i);
}

HealingPotion* Inventory::findHealPotion()
{
	for (auto itemPtr : vectorOfItems)
	{
		if (itemPtr->getType() == "healing potion")
		{
			//convert to pointer to healing pot and add hp to player
			auto healingPotionPtr = dynamic_cast<HealingPotion*>(itemPtr);
			return healingPotionPtr;
		}
	}

	std::cout << "there is no healing potion in this inventory" << std::endl;
	return nullptr;
}

ForcePotion* Inventory::findForcePotion()
{
	for (auto itemPtr : vectorOfItems)
	{
		if (itemPtr->getType() == "force potion")
		{
			//convert to pointer to healing pot and add hp to player
			auto forcePotionPtr = dynamic_cast<ForcePotion*>(itemPtr);
			return forcePotionPtr;
		}
	}

	std::cout << "there is no force potion in this inventory" << std::endl;
	return nullptr;
}

Sword_* Inventory::findSword(std::string nameOfKingdom)
{
	for (auto itemPtr : vectorOfItems)
	{
		if (itemPtr->getType() == "sword" && itemPtr->getNameOfKingdom() == nameOfKingdom)
		{
			//convert to pointer to healing pot and add hp to player
			auto swordPtr = dynamic_cast<Sword_*>(itemPtr);
			swordPtr->getSprite().setTexture(swordPtr->getLootTexture());
			return swordPtr;
		}
	}

	std::cout << "there is no sword in this inventory" << std::endl;
	return nullptr;
}

Bow* Inventory::findBow(std::string nameOfKingdom)
{
	for (auto itemPtr : vectorOfItems)
	{
		if (itemPtr->getType() == "bow" && itemPtr->getNameOfKingdom() == nameOfKingdom)
		{
			//convert to pointer to healing pot and add hp to player
			auto bowPtr = dynamic_cast<Bow*>(itemPtr);
			return bowPtr;
		}
	}
	std::cout << "there is no bow in this inventory" << std::endl;
	return nullptr;
}

Epic* Inventory::findEpic(std::string nameOfKingdom)
{
	for (auto itemPtr : vectorOfItems)
	{
		if (itemPtr->getType() == "epik" && itemPtr->getNameOfKingdom() == nameOfKingdom)
		{
			//convert to pointer to healing pot and add hp to player
			auto epicPtr = dynamic_cast<Epic*>(itemPtr);
			return epicPtr;
		}

	}

	std::cout << "there is no epik in this inventory" << std::endl;
	return nullptr;
}

void Inventory::update()
{
	/*float widthOfInventoryView = _inventory.getInventoryView().getSize().x * _inventory.getInventoryView().getSize().x;
	float heightOfInventoryView = _inventory.getInventoryView().getSize().y * _inventory.getInventoryView().getSize().y;
	float inventoryViewXpos = _inventory.getInventoryView().getPosition().x;
	float inventoryViewYpos = _inventory.getInventoryView().getPosition().y;
	_inventory.getContainerView().setSize(sf::Vector2f(0.8f * widthOfInventoryView, 0.6f * heightOfInventoryView));
	_inventory.getContainerView().setPosition(inventoryViewXpos + 0.1f * widthOfInventoryView, 0.2f * heightOfInventoryView);
	_inventory.getContainerView().setFillColor(sf::Color(200, 191, 231, 200));
	*/

	_containerView.setPosition(100, 100);
}

sf::RectangleShape& Inventory::getInventoryView()
{
	// TODO: insérer une instruction return ici
	return _inventoryView;
}

sf::RectangleShape& Inventory::getContainerView()
{
	// TODO: insérer une instruction return ici
	return _containerView;
}

void Inventory::draw(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(_inventoryView);
	gameWindow.draw(_containerView);

	/*for (auto itemPtr : vectorOfItems)
	{
		itemPtr->Display(gameWindow);
	}
	std::cout << "capacity " << vectorOfItems.size() << "/" << maxCapacity << std::endl;
	for (auto itemPtr : vectorOfItems)
	{
		itemPtr->Display(gameWindow);
	}
	*/

}