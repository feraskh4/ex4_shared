#include "Vampire.h"

Vampire::Vampire()
:   m_name(VAMPIRE), m_force(VAMPIRE_FORCE), m_loot(VAMPIRE_LOOT), m_damageOnDefeat(VAMPIRE_DAMAGE)
{}

void Vampire::applyLossEffect(Player& player) const
{
    player.damage(m_damageOnDefeat);
    player.debuff(VAMPIRE_DEBUFF);
}