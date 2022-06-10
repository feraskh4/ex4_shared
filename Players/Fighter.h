#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

const string FIGHTER = "Fighter";

class Fighter : public Player
{
    Fighter(const string name);

    int getAttackStrength() override;
};

#endif // EX4_WARRIOR_H