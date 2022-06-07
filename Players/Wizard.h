#ifndef EX4_WIZZARD_H
#define EX4_WIZZARD_H

#include "Player.h"

class Wizard : public Player
{
    void heal(const int amount) override;
    void printInfo() override;
};

#endif // EX4_WIZZARD_H