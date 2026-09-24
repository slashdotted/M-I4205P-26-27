#include <iostream>
#include <string>

void fn()
{
    // Evitare situazioni in cui allochiamo sullo heap all'inizio di una funzione...
    // auto *titolo{new std::string{"Benvenuti"}};
    std::string titolo{"Benvenuti"};
    int x{32};
    {
        std::string label{"Nuovo elemento"};
    }
    // ... per poi deallocare alla fine della funzione
    // delete titolo;
}

void swap(int x, int y)
{
    std::cout
        << "&x=" << &x << " &y=" << &y << '\n';
    std::cout
        << "x=" << x << " y=" << y << '\n';
    int temp{x};
    x = y;
    y = temp;
    std::cout
        << "x=" << x << " y=" << y << '\n';
}

void swap2(int *x, int *y)
{
    // x e y sono copie di &a e &b
    int temp{*x};
    *x = *y;
    *y = temp;
}

void swap3(int &x, int &y)
{
    std::cout
        << "&x=" << &x << " &y=" << &y << '\n';
    std::cout
        << "x=" << x << " y=" << y << '\n';

    int temp{x};
    x = y;
    y = temp;

    std::cout
        << "x=" << x << " y=" << y << '\n';
}

void fun(int t)
{
    std::cout << "Il valore di t è " << t << '\n';
}

void fun2(int *t)
{
    std::cout << "Il valore di t è " << *t << '\n';
}

void fun3(int &t)
{
    std::cout << "Il valore di t è " << t << '\n';
}

void fun4(const int &t)
{
    std::cout << "Il valore di t è " << t << '\n';
}

int getValore()
{
    return 77;
}

int &getRif()
{
    int u{89};
    return u; // Orrore! Ritorno un riferimento a una variabile locale
}

int &getRif2(int &q)
{
    ++q;
    return q;
}

int main()
{
    {
        // Allocazione sullo stack
        double k;
        double pi{3.14};
        std::string messaggio{"Ciao mondo"}; // oggetto sullo stack
        std::string vuota;                   // oggetto sullo stack
        fn();
        std::cout << "dimensione di un double = " << sizeof(double) << '\n';
        std::cout << "dimensione di un std::string = " << sizeof(std::string) << '\n';
    }
    {
        // Allocazione sullo heap
        double *k{new double};        // Allocazione di memoria sullo heap, indirizzo (puntatore) sullo stack
        double *pi{new double{3.14}}; // Allocazione di memoria sullo heap, indirizzo (puntatore) sullo stack
        std::string *messaggio{new std::string{"Ciao mondo"}};
        std::string *vuota{new std::string};
        auto vuota2{new std::string};
        auto *vuota3{new std::string};
        auto *mioarray{new long[100]}; // Allocazione di un array
        std::cout << "dimensione di un double* = " << sizeof(double *) << '\n';
        // ...
        // Deallocazione
        delete k;
        delete pi;
        delete messaggio;
        delete vuota;
        delete vuota2;
        delete vuota3;
        delete[] mioarray; // Deallocazione di un array
    }
    int a{13};
    int b{42};
    std::cout
        << "&a=" << &a << " &b=" << &b << '\n';
    swap(a, b);
    std::cout
        << "dopo swap(a,b) -> a=" << a << " b=" << b << '\n';
    swap2(&a, &b);
    std::cout
        << "dopo swap2(&a,&b) -> a=" << a << " b=" << b << '\n';
    int *t{nullptr}; // nullptr sostituisce NULL in c++
    int *z{new int{9}};
    delete z;
    // swap2(t, z); // SEGMENTATION FAULT

    int valore;
    std::cout << "&valore=" << &valore << '\n';
    int &numero{valore}; // sia numero che valore referenziano
                         // la STESSA posizione in memoria (stesso indirizzo)
    std::cout << "&numero=" << &numero << '\n';

    swap3(a, b); // passaggio per riferimento

    std::cout
        << "dopo swap3(a,b) -> a=" << a << " b=" << b << '\n';

    fun(a);
    fun2(&a);
    fun3(a);
    fun(b);
    fun2(&b);
    fun3(b);
    fun(67);
    // fun2(&67); // Non posso ottenere l'indirizzo di un literal
    // fun3(67); // Non posso passare per riferimento un literal
    fun4(67); // Posso passare un literal per riferimento se il riferimento è const
    fun(getValore());
    // fun2(&getValore()); // Non posso ottenere l'indirizzo di un valore temporaneo
    // fun3(getValore()); // Non posso passare per riferimento un valore temporaneo
    fun4(getValore()); // Posso passare un valore temporaneo per riferimento se il riferimento è const

    int valori[]{1, 2, 3, 4, 5};

    // Iterazione su un array, con riferimento
    for (int &v : valori)
    {
        ++v;
    }
    for (int &v : valori)
    {
        std::cout << v << ",";
    }

    int &p{getRif()};
    // p non è più valido
    // std::cout << "p=" << p << '\n';

    int &e{getRif2(a)};
    std::cout << '\n'
              << "&e=" << &e << " &a=" << &a << '\n';
}