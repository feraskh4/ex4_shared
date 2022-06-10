#include "Wizard.h"

Wizard::Wizard(const string name)
:   Player(name), m_role(WIZARD)
{}

void Wizard::heal(const int amount) override
{
    m_hp += (amount > 0) ? DOUBLE*amount : 0;
}