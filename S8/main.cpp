#include <iostream>
#include <string>

struct Etichetta
{
    Etichetta() {}
    Etichetta(const Etichetta &)
    {
        std::cout << "Copio etichetta\n";
    }
    Etichetta &operator=(const Etichetta &)
    {
        std::cout << "Copio etichetta\n";
        return *this;
    }
    ~Etichetta() {}
};

struct Scatola
{
    Scatola() : e{new Etichetta} {}
    ~Scatola() { delete e; }
    Scatola(const Scatola &o) : e{new Etichetta{*o.e}} {}
    Scatola &operator=(const Scatola &o)
    {
        std::cout << "Copio la scatola\n";
        *e = *o.e;
        return *this;
    }

    Scatola(Scatola &&o) : e{std::move(o.e)}
    {
        o.e = nullptr;
    }

    Scatola &operator=(Scatola &&o)
    {
        if (this != &o)
        {
            delete e;           // Libero la memoria dell'etichetta corrente
            e = std::move(o.e); // "Rubo" l'allocazione di o
            o.e = nullptr;      // "disattivo" il puntatore di o
        }
        return *this;
    }

private:
    Etichetta *e;
};

Scatola getScatola()
{
    return Scatola{};
}

int main()
{
    Scatola s1{getScatola()}; // RVO
    std::cout << "------------------------\n";
    Scatola s2;
    s2 = getScatola();
}