#include "Goblin.h"

Goblin::Goblin()
:   Battle(GOBLIN_FORCE, GOBLIN_LOOT, GOBLIN_DAMAGE, GOBLIN)
{}

void Goblin::applyLossEffect(Player& player) const
{
    player.damage(m_damageOnDefeat);
}