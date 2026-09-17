#include <iostream>
#include "library.h"
#include "utils.h"

int somma(int a, int b, int c = 0, int d = 0);

void stampa()
{
    std::cout << "Stampa (senza parametri)" << std::endl;
}

// Overloading con tipo di ritorno diverso non è permesso
/*int stampa() {
    std::cout << "Ciao mondo" << std::endl;
    return 0;
}*/

void stampa(int i)
{
    std::cout << "Stampa (con parametro): " << i << std::endl;
}

void stampa(int i, int j)
{
    std::cout << "Stampa (con due parametri): " << i << " " << j << std::endl;
}

void stampa(int i, int j, int k)
{
    std::cout << "Stampa (con tre parametri): " << i << " " << j << " " << k << std::endl;
}

int somma(int a, int b, int c, int d)
{
    return a + b + c + d;
}

/*int somma(int a, int b, int c)
{
    return somma(a, b, c, 0);
}

int somma(int a, int b)
{
    return somma(a, b, 0);
}*/

double getPi()
{
    return 3.14;
}

int main()
{
    somma(1, 2, 3, 4);
    somma(1, 2, 3); // somma(1,2,3,0);
    somma(1, 2);    // somma(1,2,0,0);

    auto pi{3.14}; // inizializzazione uniforme (evita le narrowing conversions)
    auto e{2.71};  // inferenza del tipo di dato
    double raggio{3};
    auto circonferenza{2 * getPi() * raggio};
    std::cout << "La circonferenza di un cerchio di raggio " << raggio << " è: "
              << circonferenza << std::endl;

    using namespace supsi; // simile a import in Java con *
    using supsi::hello;    // simile a import in Java con nome specifico
    // hello();
    hello();
    stampa();
    stampa(5);
    return 0;
}