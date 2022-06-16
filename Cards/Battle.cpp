#include "Battle.h"
#include "../utilities.h"

Battle::Battle(int force, int loot, int damage, string name)
:   Card(name),
    m_force(force),
    m_loot(loot),
    m_damageOnDefeat(damage)
{}

void Battle::applyEncounter(shared_ptr<Player> player) const
{
    if (player->getAttackStrength() >= m_force)
    {
        player->levelUp();
        player->addCoins(m_loot);
        printWinBattle(player->getName(), m_name);
    } 
    else 
    {
        applyLossEffect(*player);
        printLossBattle(player->getName(), m_name);
    }            
}

void Battle::printInfo(ostream& os) const
{
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_damageOnDefeat, m_loot, m_name==DRAGON);
    printEndOfCardDetails(os);
}