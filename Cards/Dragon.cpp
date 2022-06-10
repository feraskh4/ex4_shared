#include "Dragon.h"

Dragon::Dragon()
:   m_name(DRAGON), m_force(DRAGON_FORCE), m_loot(DRAGON_LOOT), m_damageOnDefeat(DRAGON_DAMAGE)
{}

void Dragon::applyLossEffect(Player& player) const
{
    player.killPlayer();
}
