#include "Dragon.h"

Dragon::Dragon() :
    Battle(DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE, DRAGON)
{}

void Dragon::applyLossEffect(Player& player) const
{
    player.killPlayer();
}
