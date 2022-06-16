#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
#include <string>
#include "../HealthPoints.h"


const int DOUBLE = 2;
const int DEFAULT_LEVEL = 1; 
const int DEFAULT_HP = 100;
const int DEFAULT_FORCE = 5;
const int DEFAULT_COINS = 10;

using namespace std;

class Player {
public:
    /**
     * @brief C'tor of Player class
     *
     * @param name - The name of the player.
     * @param hp - Amount of health points for player.
     * @param force - Amount of force for player
     * @return
     *      A new instance of Player.
    */
    Player(const string name);

    /**
     * @brief increases the player level by one
     * 
     * @return 
     *      void
     */
    void levelUp();

    /**
     * @brief returns the level of the player
     * 
     * @return 
     *      level of player
     */
    int getLevel();

    /**
     * @brief buffs the player's force
     * 
     * @param amount - the amount of force that will increase for the player
     * 
     * @return 
     *      void
     */
    void buff(const int amount);

    /**
     * @brief debuff the player's force
     * 
     * @param amount - the amount of force that will decrease for the player
     * 
     * @return 
     *      void
     */
    void debuff(const int amount);
    /**
     * @brief increases the player's HP by specific amount
     * 
     * @param amount - the amount of HP that will increase for the player
     * 
     * @return 
     *      void
     */
    virtual void heal(const int amount);

    /**
     * @brief decreases the player's HP by specific amount
     * 
     * @param amount - the amount of HP that will decrease for the player
     * 
     * @return 
     *      void
     */
    void damage(const int amount);

    /**
     * @brief checks if the player's HP is 0
     * 
     * @return 
     *      true - if player's HP is 0
     *      false - if player's HP is not 0
     */
    bool isKnockedOut();

    /**
     * @brief increases the player's coins by a specific amount
     * 
     * @param amount - the amount of coins that will increase for the player
     */
    virtual void addCoins(const int amount);

    /**
     * @brief decreases the player's coins by a specific amount
     * 
     * @param amount - the amount of coins that will decrease for the player
     * 
     * @return 
     *      true - if the player has successfully payed the amount
     *      false - if the amount was higher than the player's coins, so player cannot pay
     */
    bool pay(const int amount);

    /**
     * @brief get the Attack Strength of the player, which is equal to the sum of player's force and player's level
     * 
     * @return 
     *      the player's Attack Strength  
     */
    virtual int getAttackStrength();

    /**
     * @brief ends the player's life :'(
     * 
     * @return void 
     */
    void killPlayer();

    /**
     * @brief returns name of player
     * 
     * @return name of player 
     */
    string getName();

    /**
     * @brief returns amount of coins the player has 
     * 
     * @return amount of coins the player has 
     */
    int getCoins();

    Player(const Player& player) = default;
    Player() = default;
    virtual ~Player() = default;
    Player& operator=(const Player& player) = default;

    friend ostream& operator<<(ostream& os, const Player& other);

protected:
    const string m_name;
    string m_role;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
};

// checks if the name is valid for a player
bool isValidPlayerName(const string name);


#endif // EX2_PLAYER_H