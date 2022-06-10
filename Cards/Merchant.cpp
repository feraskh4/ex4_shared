#include "Merchant.h"

Merchant::Merchant()
:   m_name(MERCHANT)
{}

void Merchant::applyEncounter(Player& player)
{
    ostream startMsg;
    int type;
    printMerchantInitialMessageForInteractiveEncounter(startMsg, player.getName(), player.getCoins());
    cout << startMsg << endl;
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

    if(!player.pay(POTION_COST))
    {
        printMerchantInsufficientCoins(startMsg);
        return;
    }

    ostream summary;
    printMerchantSummary(summary, player.getName(), type, cost);
    cout << summary << endl;
}