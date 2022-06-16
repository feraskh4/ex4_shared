#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

const string TREASURE = "Treasure";
const int TREASURE_REWARD = 10;

class Treasure : public Card
{
public:
    Treasure();
    
    void applyEncounter(shared_ptr<Player> player) const override;
};

#endif // EX4_TREASURE_H