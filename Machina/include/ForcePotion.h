#ifndef FORCE_POTION
#define FORCE_POTION
#include "Potion.h"

class ForcePotion :  public Potion
{
protected:
    std::string type;
    int atkToGive;

public:
    ForcePotion();
    ForcePotion(std::string type_, int atkGoTive_);
    ~ForcePotion();


    std::string getNameOfKingdom();
    void setNameOfKingdom(std::string newNameOfKingdom);
    void printNameOfKingdom();

    std::string getType();
    void setType(std::string newType);
    void printType();

    int getAtkToGive();
    void setAtkToGive(int newAtkToGive);
    void printAtkToGive();

    sf::Sprite& getSprite();
    sf::Texture& getLootTexture();

    void Display(sf::RenderWindow& gameWindow);

  
};
#endif // !FORCE_POTION

