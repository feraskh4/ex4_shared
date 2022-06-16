#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

const string ROGUE = "Rogue";

class Rogue : public Player
{
public:
    Rogue(const string name);
    void addCoins(const int amount) override;
};

#endif // EX4_ROGUE_H