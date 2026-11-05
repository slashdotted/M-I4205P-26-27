#include <iostream>

int main()
{
    // Esempio di lambda
    auto equals_to_13 = [](int i) -> bool
    {
        return i == 13;
    };

    int valore = 13;
    // valore viene catturato per riferimento
    auto equals_to = [&valore](int i) -> bool
    {
        return i == valore;
    };
    // valore viene catturato per valore (copia)
    auto equals_to_2 = [valore](int i) -> bool
    {
        return i == valore;
    };

    valore = 7;
    auto equals_to_7 = [valore](int i)
    {
        return i == valore;
    };

    if (equals_to_13(55))
    {
        std::cout << "Valore uguale a 13\n";
    }
    if (equals_to(55)) /* confronto con 13 */
    {
        std::cout << "Valore uguale a 55\n";
    }

    valore = 7;
    if (equals_to(7)) /* confronto con 7 */
    {
        std::cout << "Valore uguale a 7\n";
    }
    if (equals_to_2(7)) /* confronto con 13 */
    {
        std::cout << "Valore uguale a 13 (a)\n";
    }
    if (equals_to_2(13)) /* confronto con 13 */
    {
        std::cout << "Valore uguale a 13 (b)\n";
    }

    auto equals_to_6 = [value = 6](int i)
    {
        return i == value;
    };

    auto equals_to_9 = [](int i)
    {
        int value{9};
        return i == value;
    };
}