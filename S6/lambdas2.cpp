#include <iostream>

int main()
{
    int a, b, c, d;
    auto l1 = [a, b, c, &d]()
    { return a + b + c + d; }; // Catturo a,b,c per valore, mentre d per riferimento
    auto l2 = [&a, b, &c, d]()
    { return a + b + c + d; }; // Catturo a e c per riferimento, b e d per valore
    auto l3 = [=, &b]()
    { return a + b + c + d; }; // Catturo "tutto" per valore, tranne b che è per riferimento
    auto l4 = [&, c, d]()
    { return a + b + c + d; }; // Catturo "tutto" per riferimento, tranne c e d che sono per valore

    // Lambda mutabili
    auto contatore = [count = 0]() mutable
    {
        return ++count;
    };
    std::cout << contatore() << '\n';
    std::cout << contatore() << '\n';
    std::cout << contatore() << '\n';
    std::cout << contatore() << '\n';
}