#include "Battle.h"

void Battle::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= m_force) 
    {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), m_name);
    } 
    else 
    {
        applyLossEffect(player);
        printLossBattle(player.getName(), m_name);
    }            
}

void Battle::printInfo() const
{
    ostream ostream;
    printCardDetails(ostream, m_name);
    printMonsterDetails(ostream, m_force, m_damageOnDefeat, m_loot, m_name==DRAGON)
    printEndOfCardDetails(ostream);
    cout << ostream << endl;
    
}