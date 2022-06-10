#include "Player.h"

Player::Player(const string name) 
{
    m_name = name;
    m_level = DEFAULT_LEVEL;
    m_force = (force > 0) ? force : DEFAULT_FORCE;
    m_hp = (hp > 0) ? hp : DEFAULT_HP;
    m_coins = DEFAULT_COINS;
}

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
}

void Player::heal(const int amount) 
{
    m_hp += (amount > 0) ? amount : 0;
}

void Player::damage(const int amount) 
{
    m_hp -= (amount > 0) ? amount : 0;
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

void Player::printInfo() 
{
    ostream ostream;
    printPlayerInfo(ostream, m_name, m_role, m_level, m_force, m_hp, m_coins);
    cout << ostream << endl;
}

void Player::killPlayer()
{
    damage(m_hp.getCurrentHP);
}

string Player::getName()
{
    return m_name;
}

int Player::getCoins()
{
    return m_coins;
}