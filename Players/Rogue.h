#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue : public Player
{
    void addCoins(const int amount) override;
    void printInfo() override;
};

#endif // EX4_ROGUE_H