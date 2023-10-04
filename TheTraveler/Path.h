#pragma once
#include <vector>
#include "City.h"

class Path 
{
public:

    Path(); // Constructor for Path class
    void addCity(const City& city); // Add a city to the path
    double getTotalDistance() const; // Calculate the total distance of the path
    const std::vector<City>& getCityList() const; // Get the list of cities in the path
    bool containsCity(const City& city) const; // Check if the path contains a specific city

private:

    std::vector<City> cities; // List of cities in the path
};