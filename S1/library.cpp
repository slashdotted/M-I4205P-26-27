#include "library.h"
#include <iostream>

namespace supsi
{
    void hello()
    {
        std::cout << "Ciao mondo" << std::endl;
    }

    void saluta(int i)
    {
        std::cout << "Ciao " << i << std::endl;
    }
}