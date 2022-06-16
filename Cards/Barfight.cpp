#include "Barfight.h"
#include "../utilities.h"

Barfight::Barfight()
:   Card(BARFIGHT)
{}

void Barfight::applyEncounter(shared_ptr<Player> player) const
{
    bool isFighter = dynamic_pointer_cast<Fighter>(player) != nullptr;
    printBarfightMessage(isFighter);
    if (!isFighter)
    {
        player->damage(BAR_DAMAGE);
    }
}