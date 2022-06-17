#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <algorithm>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <fstream>

#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Battle.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Dragon.h"
#include "Cards/Vampire.h"

const int LINE_SIZE = 256;
const char SPACE = ' ';

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const string& fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard();
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin& other) = delete;
    ~Mtmchkin() = default; // ??
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

private:
    bool m_isGameOver;
    deque<shared_ptr<Card>> m_cardsQueue;
    deque<shared_ptr<Player>> m_playersQueue;
    deque<shared_ptr<Player>> m_winners;
    deque<shared_ptr<Player>> m_losers;
    int m_playersAmount;
    int m_roundsPlayed;

};

void buildCardMap(map<string,shared_ptr<Card>(*)()>& cardMap);
void buildPlayersMap(map<string, shared_ptr<Player>(*)(string)>& playerMap);
void receiveCardsInfo(ifstream& source, deque<shared_ptr<Card>>& cardsQueue);
int receiveTeamSize();
void receivePlayersInfo(deque<shared_ptr<Player>>& playersQueue, const int teamSize);


shared_ptr<Player> buildRogue(const string name);
shared_ptr<Player> buildFighter(const string name);
shared_ptr<Player> buildWizard(const string name);

shared_ptr<Card> buildPitfall();
shared_ptr<Card> buildDragon();
shared_ptr<Card> buildVampire();
shared_ptr<Card> buildGoblin();
shared_ptr<Card> buildFairy();
shared_ptr<Card> buildMerchant();
shared_ptr<Card> buildTreasure();
shared_ptr<Card> buildBarfight();

#endif /* MTMCHKIN_H_ */
