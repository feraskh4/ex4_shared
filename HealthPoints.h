#ifndef EX3_HEALTH_POINTS_H
#define EX3_HEALTH_POINTS_H

#include <iostream>
const int DEFAULT_MAX_HP = 100;

class HealthPoints {
public:
    /**
     * @brief Construct a new Health Points object
     * 
     * @param maxHP - the max hp of the player 
     */
    HealthPoints(int maxHP = DEFAULT_MAX_HP);
    HealthPoints(const HealthPoints& other) = default;
    ~HealthPoints() = default;
    HealthPoints& operator=(const HealthPoints& other) = default;

    HealthPoints& operator+=(const int& amount);
    HealthPoints operator+(const int& amount) const;
    HealthPoints& operator-=(const int& amount);
    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& other);

    class InvalidArgument {};

private:
    int m_maxHP;
    int m_currentHP;
};

HealthPoints operator+(const int& amount, const HealthPoints& healthPoints);    

HealthPoints operator-(const HealthPoints& healthPoints, const int& amount);

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoigitnts2);
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);


#endif // EX3_HEALTH_POINTS_H