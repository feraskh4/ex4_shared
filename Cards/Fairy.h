#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"
#include "../Players/Wizard.h"

const string FAIRY = "Fairy";
const int FAIRY_HEAL = 10;

class Fairy : public Card
{
public:
    Fairy();
    
    void applyEncounter(shared_ptr<Player> player) const override;
};

#endif // EX4_FAIRY_H