#include "Rogue.h"

void Rogue::addCoins(const int amount)
{
    m_coins += (amount > 0) ? DOUBLE*amount : 0;
}

void Rogue::printInfo() 
{
    ostream ostream;
    printPlayerInfo(ostream, m_name, "Rogue", m_level, m_force, m_hp, m_coins);
    std::cout << ostream << std::endl;
}