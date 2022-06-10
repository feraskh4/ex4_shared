#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

const string VAMPIRE = "Vampire";
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_DEBUFF = 1;

class Vampire : public Battle
{
public:
    Vampire();
    
    void applyLossEffect(Player& player) const override;
};

#endif // EX4_VAMPIRE_H