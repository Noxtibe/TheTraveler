#pragma once
#include <string>

class City 
{
public:

    City(char name, double x, double y);
    char getName() const; // Get the name of the city
    double getX() const; // Get the x-coordinate of the city
    double getY() const; // Get the y-coordinate of the city

private:

    char name;
    double x, y;
};

