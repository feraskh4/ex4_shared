#include "Goblin.h"

Goblin::Goblin()
:   m_name(GOBLIN), m_force(GOBLIN_FORCE), m_loot(GOBLIN_LOOT), m_damageOnDefeat(GOBLIN_DAMAGE)
{}

void Goblin::applyLossEffect(Player& player) const
{
    player.damage(m_damageOnDefeat);
}