#ifndef HEALINGPOTION
#define HEALINGPOTION
#include "Potion.h"

class HealingPotion : public Potion
{
protected:
    std::string type;
    int hpToGive;


public:
    HealingPotion();
    HealingPotion(std::string type_, int hp_);
    ~HealingPotion();

    std::string getNameOfKingdom();
    void setNameOfKingdom(std::string newNameOfKingdom);
    void printNameOfKingdom();

    std::string getType();
    void setType(std::string newType);
    void printType();

    int getHpToGive();
    void setHpToGive(int newHpToGive);
    void printHpToGive();

    sf::Sprite& getSprite() override;
    sf::Texture& getLootTexture() override;
    void Display(sf::RenderWindow& gameWindow);


};
#endif
