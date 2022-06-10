#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

const string BARFIGHT = "Barfight";
const int BAR_DAMAGE = 10;

class Barfight : public Card
{
public:
    Barfight();
    
    void applyEncounter(Player& player) const override;
};

#endif // EX4_BARFIGHT_H