#pragma once

class Fraction
{
public:
    Fraction(int num_value = 0, int den_value = 1);
    int numerator() const
    {
        return m_numerator;
    }

    int denominator() const
    {
        return m_denominator;
    }

    void numerator(int value);
    void denominator(int value);

    Fraction &operator+=(const Fraction &o);
    Fraction &operator-=(const Fraction &o);

    // Fraction operator+(const Fraction &o);
    Fraction operator-(const Fraction &o);

     explicit operator double() const
     {
         return (double)m_numerator / m_denominator;
     }

    /*double toDouble() const
    {
        return (double)m_numerator / m_denominator;
    }*/

protected:
    void simplify();
    void normalize();

private:
    int m_numerator{0};
    int m_denominator{1};
};

Fraction operator+(const Fraction &a, const Fraction &b);