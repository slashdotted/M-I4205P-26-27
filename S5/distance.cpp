#include "distance.h"

auto operator""_miles(long double m)
{
    return Distance{m * 1609.34};
}

auto operator""_miles(unsigned long long m)
{
    return Distance{m * 1609.34};
}

auto operator""_km(long double m)
{
    return Distance{m * 1000.0L};
}

auto operator""_km(unsigned long long m)
{
    return Distance{m * 1000.0L};
}
