#include "Fairy.h"
#include "../utilities.h"

Fairy::Fairy()
:   Card(FAIRY)
{}

void Fairy::applyEncounter(shared_ptr<Player> player) const
{
    bool isWizard =  dynamic_pointer_cast<Wizard>(player) != nullptr;
    printFairyMessage(isWizard);
    if (isWizard)
    {
        player->heal(FAIRY_HEAL);
    }
}