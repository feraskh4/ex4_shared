#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player
{
    int getAttackStrength() override;
    void printInfo() override;
};

#endif // EX4_WARRIOR_H