#include "fraction.h"

Fraction::Fraction(int num_value, int den_value)
    : m_numerator{num_value}, m_denominator{den_value} // <-- init-list
{
    // m_denominator{den_value}; ERRORE! m_denominator è già inizializzato
    if ((num_value == 0 && den_value == 0) || (den_value == 0))
    {
        throw "Invalid Fraction";
    }
    // Il codice che segue causa un riassegnamento
    /*m_numerator = num_value;
    m_denominator = den_value;
    // oppure
    this->m_denominator = den_value;
    this->m_numerator = num_value;*/
}
/*
Fraction::Fraction(int num_value)
    : Fraction{num_value, 1}
{
    // Fraction{num_value, 1}; // NOOOOOOO! Questo crea un "nuovo" Fraction sullo stack
}

Fraction::Fraction()
    : Fraction{0, 1}
{
    // Fraction{0, 1}; // NOOOOOOO! Questo crea un "nuovo" Fraction sullo stack
}*/

// Metodo non inline
void Fraction::denominator(int value)
{
    m_denominator = value;
}

// Metodo non inline
void Fraction::numerator(int value)
{
    m_numerator = value;
}