#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"

class Battle : public Card
{
public:
    Battle() {}
    
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
    virtual void applyLossEffect(Player& player) const = 0;

protected:
    int m_force;
    int m_loot;
    int m_damageOnDefeat;
};

#endif // EX4_BATTLE_H