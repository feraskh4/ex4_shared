#include "Treasure.h"
#include "../utilities.h"

Treasure::Treasure()
:   Card(TREASURE)
{}

void Treasure::applyEncounter(shared_ptr<Player> player) const
{
    player->addCoins(TREASURE_REWARD);
    printTreasureMessage();
}