#ifndef POTION
#define POTION
#include "Item.h"

class Potion :
    public Item
{
protected:
    std::string type;
    int hpToGive;
    int atkToGive;

    sf::Texture _lootTexture;
   
    
public:
    Potion();
    Potion(std::string type_, int hpToGive_, int atkToGive_);
    ~Potion();

   
    virtual sf::Sprite& getSprite() = 0;
    virtual sf::Texture& getLootTexture() = 0;

    virtual void Display(sf::RenderWindow& gameWindow) = 0;

};
#endif

