#include "Card.h"
#include "../utilities.h"

void Card::printInfo(ostream& os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

ostream& operator<<(ostream& os, const Card& other)
{
    other.printInfo(os);
    return os;
}