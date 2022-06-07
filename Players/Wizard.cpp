#include "Wizard.h"


void Wizard::heal(const int amount) 
{
    m_hp += (amount > 0) ? DOUBLE*amount : 0;
}

void Wizard::printInfo() 
{
    ostream ostream;
    printPlayerInfo(ostream, m_name, "Wizard", m_level, m_force, m_hp, m_coins);
    std::cout << ostream << std::endl;
}