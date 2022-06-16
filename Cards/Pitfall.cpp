#include "Pitfall.h"
#include "../utilities.h"

Pitfall::Pitfall()
:   Card(PITFALL)
{}

void Pitfall::applyEncounter(shared_ptr<Player> player) const
{
    bool isRogue =  dynamic_pointer_cast<Rogue>(player) != nullptr;;
    printPitfallMessage(isRogue);
    if (!isRogue)
    {
        player->damage(PIT_DAMAGE);
    }
}