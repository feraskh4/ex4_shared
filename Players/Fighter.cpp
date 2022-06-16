#include "Fighter.h"

Fighter::Fighter(const string name)
:   Player(name)
{
    m_role = FIGHTER;
}

int Fighter::getAttackStrength() 
{
    return DOUBLE*m_force + m_level;
}