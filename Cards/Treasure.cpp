#include "Treasure.h"

Treasure::Treasure()
:   m_name(TREASURE)
{}

void Treasure::applyEncounter(Player& player)
{
    player.pay(TREASURE_REWARD);
    printTreasureMessage();
}