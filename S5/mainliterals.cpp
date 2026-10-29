
struct Distance
{
private:
    double m_meters;

public:
    Distance(double meters) : m_meters{meters} {}

    static Distance from_meters(double meters)
    {
        return Distance{meters};
    }

    static Distance from_kilometers(double km)
    {
        return Distance{1000 * km};
    }

    static Distance from_miles(double km)
    {
        return Distance{1600 * km};
    }

    double distance_in_meters() const
    {
        return m_meters;
    }
};

// distance is in km
/*double car_cost(double distance_in_km) {
    return 0.8 * distance_in_km;
}*/

// distance is in miles
double car_cost(double distance_in_miles)
{
    return 0.8 * 1.6 * distance_in_miles;
}

double car_cost(const Distance &d)
{
    return 0.8 * 1000 * d.distance_in_meters();
}

Distance operator""_km(long double distance)
{
    return Distance::from_kilometers(distance);
}

Distance operator""_nm(long double distance)
{
    return Distance::from_meters(distance * 1852);
}

Distance operator""_km(unsigned long long distance)
{
    return Distance::from_kilometers(distance);
}

Distance operator""_nm(unsigned long long distance)
{
    return Distance::from_meters(distance * 1852);
}

int main()
{
    // auto distanza{Distance::from_kilometers(25)};
    auto distanza{25.0_km};
    auto distanza2{25_km};
    car_cost(distanza);
    car_cost(76_km);
}