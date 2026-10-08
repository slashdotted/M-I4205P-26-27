#include <iostream>
#include "fraction.h"

using namespace std;

void printFraction(const Fraction &f)
{
    cout << f.numerator() << "/" << f.denominator() << endl;
}

int main()
{
    Fraction f1{3, 4};
    // f1.numerator(3);
    // f1.denominator(4);
    printFraction(f1);

    Fraction f2{0, 1};
    printFraction(f2);

    Fraction f3{8};
    printFraction(f3);

    Fraction f4;
    printFraction(f4);

    printFraction(7); // equivale a printFraction(Fraction{7})
    f1 = 89;
    printFraction(89);
    printFraction(3.22); // 3/1
    int s = 3.14;
}