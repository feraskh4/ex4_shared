#include "Pitfall.h"

Pitfall::Pitfall()
:   m_name(PITFALL)
{}

void Pitfall::applyEncounter(Player& player)
{
    bool isRogue = player.getRole() == ROGUE;
    printPitfallMessage(isRogue);
    if (!isRogue)
    {
        player.damage(PIT_DAMAGE);
    }
}