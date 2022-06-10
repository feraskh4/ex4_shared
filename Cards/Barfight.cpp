#include "Barfight.h"

Barfight::Barfight()
:   m_name(BARFIGHT)
{}

void Barfight::applyEncounter(Player& player)
{
    bool isFighter = player.getRole() == FIGHTER;
    printBarfightMessage(isFighter);
    if (!isFighter)
    {
        player.damage(BAR_DAMAGE);
    }
}