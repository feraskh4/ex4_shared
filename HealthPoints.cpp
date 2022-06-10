#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHP)
{
    if (maxHP <=  0) 
    {
        throw InvalidArgument();
    }
    m_maxHP = maxHP;
    m_currentHP = maxHP;
}

int HealthPoints::getCurrentHP() const
{
    return m_currentHP;
}

HealthPoints& HealthPoints::operator+=(const int& amount)
{
    m_currentHP += amount;
    if (m_currentHP > m_maxHP) 
    {
        m_currentHP = m_maxHP;
    }
    else if (m_currentHP < 0)
    {
        m_currentHP = 0;
    }
    return *this;
}

HealthPoints HealthPoints::operator+(const int& amount) const
{
    HealthPoints result(*this);
    result += amount;
    return result;
}

HealthPoints operator+(const int& amount, const HealthPoints& healthPoints)
{
    HealthPoints result = healthPoints;
    result += amount;
    return result;
}

HealthPoints& HealthPoints::operator-=(const int& amount)
{
    *this += (-1) * amount;
    return *this;
}

HealthPoints operator-(const HealthPoints& healthPoints, const int& amount)
{
    HealthPoints result = healthPoints;
    result -= amount;
    return result;
}

bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_currentHP == healthPoints2.m_currentHP;
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 == healthPoints2);
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_currentHP > healthPoints2.m_currentHP;
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1 > healthPoints2 || healthPoints1 == healthPoints2;
}

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 >= healthPoints2);
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1 > healthPoints2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& other)
{
    os << other.m_currentHP << '(' << other.m_maxHP << ')';
    return os;
}