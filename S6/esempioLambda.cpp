#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

bool confronta(int a, int b)
{
    return a < b;
}

struct Comparatore
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

void ordina(std::vector<int> &list, std::function<bool(int, int)> fn)
{
    std::sort(list.begin(), list.end(), fn);
}

int main()
{
    using namespace std;

    vector<int> lista{5, 7, 2, 435, 234, 5, 2, 32, 46, 3, 543};

    // Con funzione
    // sort(lista.begin(), lista.end(), confronta);

    // Con functor:
    // Comparatore c;
    // sort(lista.begin(), lista.end(), c);
    // oppure
    // sort(lista.begin(), lista.end(), Comparatore{});

    // Con lambda:
    sort(lista.begin(), lista.end(), [](int a, int b)
         { return a < b; });

    for (const auto &v : lista)
    {
        cout << v << ',';
    }

    ordina(lista, Comparatore{});
    Comparatore cmp;
    ordina(lista, cmp);
    ordina(lista, confronta);
    auto compare = [](int a, int b)
    { return a < b; };
    ordina(lista, compare);
    ordina(lista, [](int a, int b)
           { return a < b; });
}
