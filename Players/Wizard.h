#ifndef EX4_WIZZARD_H
#define EX4_WIZZARD_H

#include "Player.h"

const string WIZARD = "Wizard";

class Wizard : public Player
{
    Wizard(const string name);
    void heal(const int amount) override;
};

#endif // EX4_WIZZARD_H