//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <memory>
#include <string>
#include "../Players/Player.h"

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @return
     *      A new instance of Card.
    */
    Card(string name) : m_name(name) {}


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(shared_ptr<Player> player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(ostream& os) const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    friend ostream& operator<<(ostream& os, const Card& other);

protected:
    string m_name;
};


#endif //EX2_Card_H
