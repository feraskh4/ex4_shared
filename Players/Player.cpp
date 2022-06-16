#include "Player.h"
#include "../utilities.h"
Player::Player(const string name) 
:   m_name(name), m_level(DEFAULT_LEVEL), m_force(DEFAULT_FORCE), m_hp(DEFAULT_HP), m_coins(DEFAULT_COINS)
{}

void Player::levelUp() 
{
    if (m_level < 10) 
    {
        m_level++;
    } 
    else 
    {
        m_level = 10;
    }
}

int Player::getLevel() 
{
    return m_level;
}

void Player::buff(const int amount) 
{
    m_force += (amount > 0) ? amount : 0;
}

void Player::debuff(const int amount) 
{
    m_force -= (amount > 0) ? amount : 0;
    if (m_force < 0)
    {
        m_force = 0;
    }
}

void Player::heal(const int amount) 
{
    m_hp += (amount > 0) ? amount : 0;
    if (m_hp > DEFAULT_HP) 
    {
        m_hp = DEFAULT_HP;
    }
}

void Player::damage(const int amount) 
{
    m_hp -= (amount > 0) ? amount : 0;
    if (m_hp < 0) 
    {
        m_hp = 0;
    }
}

bool Player::isKnockedOut() 
{
    return m_hp == 0;
}

void Player::addCoins(const int amount) 
{
    m_coins += (amount > 0) ? amount : 0;
}

bool Player::pay(const int amount) 
{
    if (m_coins < amount) 
    {
        return false;
    }
    m_coins -= (amount > 0) ? amount : 0;
    return true;
}

int Player::getAttackStrength() 
{
    return m_force + m_level;
}

void Player::killPlayer()
{
    damage(m_hp);
}

string Player::getName()
{
    return m_name;
}

int Player::getCoins()
{
    return m_coins;
}

std::ostream& operator<<(ostream& os, const Player& other)
{
    printPlayerDetails(os, other.m_name, other.m_role, other.m_level, other.m_force,
                       other.m_hp, other.m_coins);
    return os;
}

bool isValidPlayerName(const string name)
{
    // check if letters only, no spaces, 15 letters or less
    int size = name.size();
    
    if (size > 15 || size <= 0)
    {
        return false;
    }
    char letter;
    for (int i = 0; i < size; i++)
    {
        letter = name[i];
        if (!isalpha(letter))
        {  
            return false;
        }
    }
    return true;
}