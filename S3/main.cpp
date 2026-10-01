#include <iostream>
#include <vector>
#include <map>

void esempi_vector()
{
    std::vector<double> valori;
    valori.push_back(3.14);
    valori.push_back(2.62);
    std::cout << "Numero di elementi: " << valori.size() << '\n';
    std::cout << "Capacità: " << valori.capacity() << '\n';
    std::vector<int> numeri{1, 2, 3, 4, 5, 6, 7};
    std::cout << "Numero di elementi: " << numeri.size() << '\n';
    std::cout << "Capacità: " << numeri.capacity() << '\n';

    std::cout << "Elemento 0:" << valori.at(0) << '\n';
    std::cout << "Elemento 0:" << valori[0] << '\n';

    for (const double &v : valori)
    {
        std::cout << v << ',';
    }
    std::cout << '\n';
    for (const auto &v : valori)
    {
        std::cout << v << ',';
    }
    std::cout << '\n';

    // Eliminazione
    auto it{valori.begin()};
    valori.erase(it + 1);
    for (const auto &v : valori)
    {
        std::cout << v << ',';
    }
    std::cout << '\n';

    std::vector<int *> vectptr;
    vectptr.push_back(new int{67});
    vectptr.push_back(new int{33});
    vectptr.push_back(new int{42});
    for (auto &p : vectptr)
    {
        delete p;
    }
    vectptr.clear();
}

void esempi_map()
{
    std::map<std::string, double> prezzi;
    std::cout << "Dimensione: " << prezzi.size() << '\n';
    prezzi["cioccolato"] = 2.5;
    prezzi["latte"] = 1.8;
    prezzi["vino"] = 30.5;
    prezzi.erase("vino");
    if (prezzi.count("latte") == 1)
    {
        std::cout << "Il prezzo del latte è: " << prezzi["latte"] << '\n';
    }
    // NON USARE OPERATORE [] PER VERIFICARE SE ESISTE UNA CHIAVE!!!!
    if (prezzi["pomodori"])
    {
        // Qui ho creato la chiave pomodori associata al valore di default per double (0.0)
    }
    std::map<std::string, std::string> contatti{{"Pinco", "+4158666542"}, {"Pallino", "+4191235234"}};
}

void esempi_eccezioni_1()
{
    std::vector<int> numeri{1, 2, 3, 4, 6};
    std::cout << "numeri[5]=" << numeri[5] << '\n';
    std::cout << "numeri[1600]=" << numeri[1600] << '\n';

    try
    {
        std::cout << "numeri.at(5)=" << numeri.at(5) << '\n';
        std::cout << "numeri.at(1600)=" << numeri.at(1600) << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Errore! " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Errore generico";
    }
}

void esempi_eccezioni_2() /* A DIFFERENZA DI JAVA, NON C'È THROWS ! */
{
    std::vector<int> numeri{1, 2, 3, 4, 6};
    std::cout << "numeri.at(5)=" << numeri.at(5) << '\n';
}

void esempi_eccezioni_3() noexcept
{
    std::vector<int> numeri{1, 2, 3, 4, 6};
    try
    {
        std::cout << "numeri.at(5)=" << numeri.at(5) << '\n';
    }
    catch (const std::out_of_range &e)
    {
        // DEVO GESTIRE QUI L'ECCEZIONE PERCHÉ LA FUNZIONE È DICHIARATA
        // CON NOEXCEPT
    }
}

void esempi_eccezioni_4()
{
    // int *v{new int{3}};
    int v{3};
    std::vector<int> numeri;
    numeri.push_back(v);
    std::cout << "numeri.at(1)=" << numeri.at(1) << '\n';
    // ...
    // delete v;
}

void esempi_eccezioni_5()
{
    throw 42;           // Eccezioni di tipo int
    throw "Ciao mondo"; // Eccezione di tipo const char*
}

int main()
{
    esempi_vector();
    esempi_map();
    esempi_eccezioni_1();

    try
    {
        esempi_eccezioni_2();
    }
    catch (...)
    {
        std::cerr << "Errore in esempi_eccezioni_2\n";
    }

    esempi_eccezioni_3();

    try
    {
        try
        {
            esempi_eccezioni_4();
        }
        catch (const std::out_of_range &e)
        {
            throw; // Rilancia l'eccezione
        }
    }
    catch (...)
    {
    }

    std::cout << "Fine!\n";
    return 0;
}
