#include "Fairy.h"

Fairy::Fairy()
:   m_name(FAIRY)
{}

void Fairy::applyEncounter(Player& player)
{
    bool isWizard = player.getRole() == WIZARD;
    printFairyMessage(isWizard);
    if (isWizard)
    {
        player.heal(FAIRY_HEAL);
    }
}