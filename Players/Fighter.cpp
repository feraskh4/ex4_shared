#include "Fighter.h"

int Fighter::getAttackStrength() 
{
    return DOUBLE*m_force + m_level;
}

void Fighter::printInfo() 
{
    ostream ostream;
    printPlayerInfo(ostream, m_name, "Fighter", m_level, m_force, m_hp, m_coins);
    std::cout << ostream << std::endl;
}