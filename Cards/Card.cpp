#include "Card.h"

const bool WIN = true;

Card::Card() 
{
    /*m_effect = type;
    m_stats.force = stats.force;
    m_stats.loot = stats.loot;
    m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    m_stats.cost = stats.cost;
    m_stats.heal = stats.heal;
    m_stats.buff = stats.buff;*/
}

void Card::applyEncounter(Player& player) const
{
    switch(m_effect) 
    {
        case CardType::Battle:
        {
            // ADD A applySideEffect FUNCTION FOR SUBCLASSES (dragon is auto loss, vampire is force loss, goblin only hp loss...)
            break;
        }
        case CardType::Buff:
        {
            if (player.pay(m_stats.cost)) 
            {
                player.buff(m_stats.buff);
            }
            break;
        }
        case CardType::Heal:
        {
            if (player.pay(m_stats.cost)) 
            {
                player.heal(m_stats.heal);
            }
            break;
        }
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;
    }
}

void Card::printInfo() const
{
    ostream ostream;
    printCardDetails(ostream, m_name);
    printEndOfCardDetails(ostream);
    out << ostream << endl;
}
