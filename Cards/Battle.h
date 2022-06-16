#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

const string DRAGON = "Dragon";

class Battle : public Card
{
public:
    Battle(int force, int loot, int damage, string name);
    
    void applyEncounter(shared_ptr<Player> player) const override;
    void printInfo(ostream& os) const override;
    virtual void applyLossEffect(Player& player) const = 0;

protected:
    int m_force;
    int m_loot;
    int m_damageOnDefeat;
};

#endif // EX4_BATTLE_H