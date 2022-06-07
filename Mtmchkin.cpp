#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) 
{
    m_player = Player(playerName);
    m_cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++) 
    {
        m_cardsArray[i] = cardsArray[i];
    }
    m_currentCardIndex = 0;
    m_numOfCards = numOfCards;
    m_gameStatus = GameStatus::MidGame;
}

void Mtmchkin::playNextCard() 
{
    if(getGameStatus() != GameStatus::MidGame) 
    {
        return;
    }

    int& cardIndex = m_currentCardIndex;
    Card& card = m_cardsArray[cardIndex];
    card.printInfo();
    card.applyEncounter(m_player);
    m_player.printInfo();

    if (m_player.getLevel() == 10) 
    {
        m_gameStatus = GameStatus::Win;
        return;
    }
    if (m_player.isKnockedOut()) 
    {
        m_gameStatus = GameStatus::Loss;
        return;
    }

    cardIndex++;
    if (cardIndex >= m_numOfCards) 
    {
        cardIndex = 0;
    }
}

bool Mtmchkin::isOver() 
{
    return m_gameStatus != GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const 
{
    return m_gameStatus;
}

Mtmchkin::Mtmchkin(const Mtmchkin& other) 
{
    m_player = other.m_player;
    delete[] m_cardsArray;
    m_currentCardIndex = other.m_currentCardIndex;
    m_numOfCards = other.m_numOfCards;
    m_gameStatus = other.m_gameStatus;
    m_cardsArray = new Card[other.m_numOfCards];
    for (int i = 0; i < other.m_numOfCards; i++) 
    {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin() 
{
    delete[] m_cardsArray;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other) 
{
    if (this == &other) 
    {
        return *this;
    }
    m_player = other.m_player;
    delete[] m_cardsArray;
    m_currentCardIndex = other.m_currentCardIndex;
    m_numOfCards = other.m_numOfCards;
    m_gameStatus = other.m_gameStatus;
    m_cardsArray = new Card[other.m_numOfCards];
    for (int i = 0; i < other.m_numOfCards; i++) 
    {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    return *this;
}