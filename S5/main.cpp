#include <iostream>
#include "fraction.h"

using namespace std;

void calcola(double v)
{
}

void calcola2(int v)
{
}

void printFraction(const Fraction &f)
{
    cout << f.numerator() << "/" << f.denominator() << endl;
}

void printTwoFractions(const Fraction &f, const Fraction &g)
{
    cout << f.numerator() << "/" << f.denominator() << endl;
    cout << g.numerator() << "/" << g.denominator() << endl;
}

ostream &operator<<(ostream &o, const Fraction &f)
{
    o << f.numerator() << "/" << f.denominator();
    return o;
}

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};
    // printFraction(f1);
    cout << f1 << '\n';
    cout << f2 << '\n';
    f1 += f2; // f1.operator+=(f2);

    Fraction f3;
    f3 = f1;
    f3 += f2;
    cout << f3 << '\n';
    Fraction f4{f1 + f2}; // f1.operator+(f2)
    cout << f4 << '\n';
    Fraction f5{f2 + f1}; // f2.operator+(f1)
    cout << f5 << '\n';

    Fraction f6{f1 + 6}; // operator+(f1, Fraction{6})
    cout << f6 << '\n';

    Fraction f7{6 + f1}; // operator+(Fraction{6}, f1)
    printTwoFractions(f1, f2);
    printTwoFractions(f1, 6); // -> printTwoFractions(f1, Fraction{6});
    printTwoFractions(6, f2); // -> printTwoFractions(Fraction{6}, f2);
    printTwoFractions(3, 2);

    // Fraction f8{f2 - 3};
    // Fraction f9{3 - f2}; // Questo non compila perché operator- è un metodo di Fraction

    calcola(f1);
    calcola(3.14);
    calcola(3);
    calcola2(3);
    calcola2(3.14);

    // Fraction fa{f1 + 6};
    // Ambiguo!
    // f1 + Fraction{6} => operator+(F,F)
    // double(f1) + 6 -> int -> F(int)

    Fraction fa{f1 + Fraction{6}};
}