#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"

const string BARFIGHT = "Barfight";
const int BAR_DAMAGE = 10;

class Barfight : public Card
{
public:
    Barfight();
    
    void applyEncounter(shared_ptr<Player> player) const override;
};

#endif // EX4_BARFIGHT_H