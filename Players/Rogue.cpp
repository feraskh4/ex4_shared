#include "Rogue.h"

Rogue::Rogue(const string name)
:   Player(name), m_role(ROGUE)
{}

void Rogue::addCoins(const int amount)
{
    m_coins += (amount > 0) ? DOUBLE*amount : 0;
}