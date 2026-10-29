#include <iostream>
#include <string>

struct Battery
{
    Battery(const std::string &name) : m_name{new std::string{name}}
    {
        std::cout << "Battery " << *m_name << " created\n";
        ++m_counter;
    }

    // Se non so come copiare, disabilito la copia:
    // Battery(const Battery &other) = delete;
    // Battery &operator=(const Battery &other) = delete;

    // Altrimenti, definisco questi metodi:

    // Costruttore di copia
    Battery(const Battery &other)
        : m_capacity{other.m_capacity},
          m_voltage{other.m_voltage},
          m_name{new std::string{*other.m_name}}
    {
    }

    // Operatore di assegnamento di copia
    Battery &operator=(const Battery &other)
    {
        m_capacity = other.m_capacity;
        m_voltage = other.m_voltage;
        *m_name = *other.m_name;
        return *this;
    }

    ~Battery()
    {
        // Distruttore
        std::cout << "Battery " << *m_name << " destroyed\n";
        --m_counter;
        delete m_name;
    }

    int m_capacity{2500};
    int m_voltage{37};
    std::string *m_name;
    // double m_charge_history[100000]{0.0};
    // 1. Dichiarazione del campo static
    static int m_counter;
};

// 2. Inizializzazione del campo static
int Battery::m_counter{0};

void foo(Battery x)
{
}

int main()
{
    Battery b{"B"}; // Stack
    foo(b);

    std::cout << "sizeof(b)=" << sizeof(b) << '\n';
    std::cout << "&b=" << &b << '\n';
    std::cout << "&b.m_name=" << &b.m_name << '\n';

    std::cout << "Numero di batterie: " << Battery::m_counter << '\n';
    Battery *c{new Battery{"C"}};
    std::cout << "c=" << c << '\n';
    std::cout << "&c->m_name=" << &c->m_name << '\n';

    std::cout << "Numero di batterie: " << Battery::m_counter << '\n';
    delete c;
    std::cout << "Numero di batterie: " << Battery::m_counter << '\n';
    {
        Battery d{"D"};
        std::cout << "Numero di batterie: " << Battery::m_counter << '\n';
    }
    std::cout << "Numero di batterie: " << Battery::m_counter << '\n';

    Battery d{"D"}; // Stack
    d = b;
}