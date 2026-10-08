#pragma once

class Foo
{
    void bar();
};

class Fraction // con class visibilità predefinita "private"
// struct Fraction // con struct visibilità predefinita "public"
{
public:
    // Visibilità public

    // Con explicit impedisco conversioni implicite (automatiche)
    // da int a Fraction
    // p.es
    // Fraction f;
    // f = 33;
    /*explicit*/ Fraction(int num_value, int den_value = 1); // Costruttore (di conversione)

    // Fraction(int num_value);
    // Fraction();

    Fraction() = default; // "Riattiva" il costruttore di default (che è disabilitato visto che ho già un altro costruttore Fraction)

    // Metodi con implementazione inline
    int numerator() const // const garantisce che il metodo non può modificare lo stato dell'oggetto
    {
        return m_numerator;
    }

    int denominator() const // const garantisce che il metodo non può modificare lo stato dell'oggetto
    {
        return m_denominator;
    }

    void numerator(int value);
    void denominator(int value);

protected:
    // Visibilità protected

private:
    //  Visibilità private
    int m_numerator{0};
    int m_denominator{1}; // Inizializzazione
};