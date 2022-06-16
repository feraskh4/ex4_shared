#include "Merchant.h"
#include "../utilities.h"

Merchant::Merchant()
:   Card(MERCHANT)
{}

void Merchant::applyEncounter(shared_ptr<Player> player) const
{
    int type;
    printMerchantInitialMessageForInteractiveEncounter(cout, player->getName(), player->getCoins());
    cin >> type;
    while (type != LEAVE && type != HP_POTION && type != FORCE_BOOST)
    {
        printInvalidInput();
        cin >> type;
    }

    int cost = 0;
    if (type == HP_POTION)
    {
        cost = POTION_COST;
    }
    else if (type == FORCE_BOOST)
    {
        cost = BOOST_COST;
    }

    if(!player->pay(cost))
    {
        printMerchantInsufficientCoins(cout);
        return;
    }

    if (type == HP_POTION)
    {
        player->heal(1);
    }
    else if (type == FORCE_BOOST)
    {
        player->buff(1);
    }

    printMerchantSummary(cout, player->getName(), type, cost);
}