#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

const string GOBLIN = "Goblin";
const int GOBLIN_FORCE = 6;
const int GOBLIN_LOOT = 2;
const int GOBLIN_DAMAGE = 10;

class Goblin : public Battle
{
public:
    Goblin();
    
    void applyLossEffect(Player& player) const override;
};

#endif // EX4_GOBLIN_H