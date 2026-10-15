#include "fraction.h"
#include <cmath>

Fraction::Fraction(int num_value, int den_value)
    : m_numerator{num_value}, m_denominator{den_value}
{
    if ((num_value == 0 && den_value == 0) || (den_value == 0))
    {
        throw "Invalid Fraction";
    }
    simplify();
}

void Fraction::denominator(int value)
{
    m_denominator = value;
    simplify();
}

void Fraction::numerator(int value)
{
    m_numerator = value;
    simplify();
}

static int gcd(int a, int b)
{
    if (b == 0)
    {
        return std::abs(a);
    }
    return gcd(b, a % b);
}

void Fraction::simplify()
{
    normalize();
    int divisor{gcd(m_numerator, m_denominator)};
    m_numerator /= divisor;
    m_denominator /= divisor;
}

void Fraction::normalize()
{
    if (m_denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
}

Fraction &Fraction::operator+=(const Fraction &o)
{
    int temp{o.m_numerator * m_denominator};
    m_denominator *= o.m_denominator;
    m_numerator *= o.m_denominator;
    m_numerator += temp;
    simplify();
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &o)
{
    int temp{o.m_numerator * m_denominator};
    m_denominator *= o.m_denominator;
    m_numerator *= o.m_denominator;
    m_numerator -= temp;
    simplify();
    return *this;
}

/*Fraction Fraction::operator+(const Fraction &o)
{
    Fraction temp{*this};
    temp += o;
    return temp;
}*/

Fraction Fraction::operator-(const Fraction &o)
{
    Fraction temp{*this};
    temp -= o;
    return temp;
}

Fraction operator+(const Fraction &a, const Fraction &b)
{
    Fraction temp{a};
    temp += b;
    return temp;
}