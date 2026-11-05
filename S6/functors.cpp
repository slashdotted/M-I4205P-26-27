#include <iostream>

struct Test
{
    Test(int i) : m_i{i} {}

    bool equals(int x) const
    {
        return x == m_i;
    }

    bool operator()(int x) const
    {
        return x == m_i;
    }

private:
    int m_i;
};

bool equals_to_17(int i)
{
    return i == 17;
}

bool equals_to_21(int i)
{
    return i == 21;
}

static int valore{7};
bool equals_to(int i)
{
    return i == valore;
}

void foo(Test x)
{
    if (x(78))
    {
        // ...
    }
}

int main()
{
    Test equals_to_13{13};
    if (equals_to_13.equals(13))
    {
        // ...
    }
    if (equals_to_13(13))
    {
    }
    Test equals_to_7{7};
    if (equals_to_7(33))
    {
    }
}