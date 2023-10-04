#include "Path.h"

Path::Path() 
{}

void Path::addCity(const City& city) 
{
    cities.push_back(city);
}

double Path::getTotalDistance() const 
{
    double totalDistance = 0.0;
    for (size_t i = 0; i < cities.size() - 1; i++) 
    {
        double dx = cities[i].getX() - cities[i + 1].getX();
        double dy = cities[i].getY() - cities[i + 1].getY();
        totalDistance += sqrt(dx * dx + dy * dy);
    }
    return totalDistance;
}

const std::vector<City>& Path::getCityList() const 
{
    return cities;
}

bool Path::containsCity(const City& city) const 
{
    for (const City& c : cities) 
    {
        if (c.getName() == city.getName()) 
        {
            return true;
        }
    }
    return false;
}