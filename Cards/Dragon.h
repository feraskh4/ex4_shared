#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

const string DRAGON = "Dragon";
const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 100;
const int DRAGON_DAMAGE = 0;

class Dragon : public Battle
{
public:
    Dragon();
    
    void applyLossEffect(Player& player) const override;
};

#endif // EX4_DRAGON_H