#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

const string PITFALL = "Pitfall";
const int PIT_DAMAGE = 10;

class Pitfall : public Card
{
public:
    Pitfall(const string name);
    
    void applyEncounter(Player& player) const override;
};

#endif // EX4_PITFALL_H