#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

const string FAIRY = "Fairy";
const int FAIRY_HEAL = 10;

class Fairy : public Card
{
public:
    Fairy(const string name);
    
    void applyEncounter(Player& player) const override;
};

#endif // EX4_FAIRY_H