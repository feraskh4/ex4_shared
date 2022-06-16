#include "utilities.h"

#include "Mtmchkin.h"
#include <fstream>

// Mtmchkin Class
Mtmchkin::Mtmchkin(const string& fileName)
{
    fstream source(fileName);
    if (!source)
    {
        throw DeckFileNotFound();
    }
    receiveCardsInfo(source, m_cardsQueue);
    /*try
    {
        
    }
    // MAYBE no need for a catch because it we try & catch when calling mtmchkin c'tor
    catch(const std::exception& e) // catch the exceptions and throw them again
    {
        throw e;
    }*/

    printStartGameMessage();
    m_isGameOver = false;
    m_roundsPlayed = 0;
    m_playersAmount = receiveTeamSize();
    receivePlayersInfo(m_playersQueue, m_playersAmount);
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed+1);
    m_isGameOver = true;
    shared_ptr<Player> player = nullptr;
    shared_ptr<Card> card = nullptr;

    int playersLeft = m_playersQueue.size();
    for (int i = 0; i < playersLeft; i++)
    {
        player = m_playersQueue.front();
        if (player->getLevel() != 10 && !player->isKnockedOut())
        {
            printTurnStartMessage(player->getName());
            card = m_cardsQueue.front();
            card->applyEncounter(player);

            m_cardsQueue.push_back(card);
            m_cardsQueue.pop_front();

            if(player->getLevel() == 10)
            {
                m_winners.push_back(player);
            }
            else if (player->isKnockedOut())
            {
                m_losers.push_front(player);
            }
            else
            {
                m_playersQueue.push_back(player);
                m_isGameOver = false;
            }
        }
        m_playersQueue.pop_front();
    }

    if (m_isGameOver)
    {
        printGameEndMessage();
    }
    m_roundsPlayed++;
}

void Mtmchkin::printLeaderBoard()
{
    printLeaderBoardStartMessage();
    int ranking = 1, size = m_winners.size();
    shared_ptr<Player> player = nullptr;
    for (int i = 0; i < size; i++)
    {
        player = m_winners.front();
        printPlayerLeaderBoard(ranking++, *player);
        m_winners.push_back(player);
        m_winners.pop_front();
    }
    size = m_playersQueue.size();
    for (int i = 0; i < size; i++)
    {
        player = m_playersQueue.front();
        printPlayerLeaderBoard(ranking++, *player);
        m_playersQueue.push_back(player);
        m_playersQueue.pop_front();
    }
    size = m_losers.size();
    for (int i = 0; i < size; i++)
    {
        player = m_losers.front();
        printPlayerLeaderBoard(ranking++, *player);
        m_losers.push_back(player);
        m_losers.pop_front();
    }
}

bool Mtmchkin::isGameOver() const
{
    return m_isGameOver;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsPlayed;
}

// builds a map for each card subclass and its constructor
void buildCardMap(map<string,shared_ptr<Card>(*)()>& cardMap)
{
    cardMap.emplace(DRAGON, buildDragon);
    cardMap.emplace(GOBLIN, buildGoblin);
    cardMap.emplace(VAMPIRE, buildVampire);
    cardMap.emplace(PITFALL, buildPitfall);
    cardMap.emplace(BARFIGHT, buildBarfight);
    cardMap.emplace(FAIRY, buildFairy);
    cardMap.emplace(TREASURE, buildTreasure);
    cardMap.emplace(MERCHANT, buildMerchant);
}

// builds a map for each player subclass and its constructor
void buildPlayersMap(map<string, shared_ptr<Player>(*)(string)>& playerMap)
{
    playerMap.emplace(ROGUE, &buildRogue);
    playerMap.emplace(FIGHTER, &buildFighter);
    playerMap.emplace(WIZARD, &buildWizard);
}

// receives cards from file and prepares the cards Queue
void receiveCardsInfo(fstream& source, deque<shared_ptr<Card>>& cardsQueue)
{
    map<string, shared_ptr<Card>(*)()> cardMap;
    map<string, shared_ptr<Card>(*)()>::iterator mapIt;
    buildCardMap(cardMap);

    string cardName;
    shared_ptr<Card> newCard = nullptr;
    int cardCounter = 0;
    while (!source.eof() && source.peek() != EOF)
    {
        getline(source, cardName);
        cardCounter++;
        mapIt = cardMap.find(cardName);
        if (mapIt == cardMap.end()) // if card name is not in the map keys
        {
            DeckFileFormatError err(cardCounter);
            throw err;
        }
        newCard = mapIt->second();
        cardsQueue.push_back(newCard);
    }
    if (cardCounter < 5)
    {
        throw DeckFileInvalidSize();
    }
}

// receives the team size
int receiveTeamSize()
{
    string input;
    int teamSize = 0;
    while (teamSize < 2 || teamSize > 6)
    {
        printEnterTeamSizeMessage();
        cin >> input;
        // use stoi (string to int and check if teamsize is valid and print fitting msg)
        teamSize = stoi(input);
        // bro find a way to check if u receieved a word with actual letters
        if (teamSize < 2 || teamSize > 6)
        {
            printInvalidTeamSize();
        }
    }
    return teamSize;
}

// receives players info and prepares the player Queue
void receivePlayersInfo(deque<shared_ptr<Player>>& playersQueue, const int teamSize)
{
    map<string, shared_ptr<Player>(*)(string)> playerMap;
    map<string, shared_ptr<Player>(*)(string)>::iterator playerIt;

    buildPlayersMap(playerMap);
    string input, playerName, className;
    bool validPlayer = false, validClass = false;
    for (int i = 0; i < teamSize; i++)
    {
        validPlayer = false;
        validClass = false;
        printInsertPlayerMessage();
        while (!validPlayer || !validClass)
        {
            getline(cin, input);
            stringstream stream(input);
            stream >> playerName;
            stream >> className;
            if (playerName.size() == 0)
            {
                continue;
            }
            validPlayer = isValidPlayerName(playerName);
            if (!validPlayer)
            {
                printInvalidName();
                continue;
            }
            else
            {
                playerIt = playerMap.find(className);
                validClass = (playerIt != playerMap.end());
                if (!validClass)
                {
                    printInvalidClass();
                }
            }
        }
        playersQueue.push_back(playerIt->second(playerName));
    }
}

// functions to return a built class
// maybe put each one in its matching file??

shared_ptr<Player> buildRogue(const string name)
{
    shared_ptr<Player> player(new Rogue(name));
    return player;
}

shared_ptr<Player> buildFighter(const string name)
{
    shared_ptr<Player> player(new Fighter(name));
    return player;
}

shared_ptr<Player> buildWizard(const string name)
{
    shared_ptr<Player> player(new Wizard(name));
    return player;
}

shared_ptr<Card> buildGoblin()
{
    shared_ptr<Card> card(new Goblin());
    return card;
}

shared_ptr<Card> buildVampire()
{
    shared_ptr<Card> card(new Vampire());
    return card;
}


shared_ptr<Card> buildBarfight()
{
    shared_ptr<Card> card(new Barfight());
    return card;
}

shared_ptr<Card> buildFairy()
{
    shared_ptr<Card> card(new Fairy());
    return card;
}

shared_ptr<Card> buildTreasure()
{
    shared_ptr<Card> card(new Treasure());
    return card;
}

shared_ptr<Card> buildMerchant()
{
    /*
    shared_ptr<Merchant> result(new Merchant());
    return dynamic_pointer_cast<Card>(result);
     */
    shared_ptr<Card> card(new Merchant());
    return card;
}

shared_ptr<Card> buildDragon()
{
    shared_ptr<Card> card(new Dragon());
    return card;
}


shared_ptr<Card> buildPitfall()
{
    shared_ptr<Card> card(new Pitfall());
    return card;
}

