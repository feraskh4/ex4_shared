#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

const string MERCHANT = "Merchant";
const int LEAVE = 0;
const int HP_POTION = 1;
const int FORCE_BOOST = 2;
const int POTION_COST = 5;
const int BOOST_COST = 10;


class Merchant : public Card
{
public:
    Merchant();
    
    void applyEncounter(shared_ptr<Player> player) const override;
};

#endif // EX4_MERCHANT_H