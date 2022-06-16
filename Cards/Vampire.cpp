#include "Vampire.h"

Vampire::Vampire()
: Battle(VAMPIRE_FORCE, VAMPIRE_LOOT, VAMPIRE_DAMAGE, VAMPIRE)
{}

void Vampire::applyLossEffect(Player& player) const
{
    player.damage(m_damageOnDefeat);
    player.debuff(VAMPIRE_DEBUFF);
}